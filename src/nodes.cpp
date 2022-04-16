// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)

#include <assert.h>
#include "nodes.hpp"


ReceiverPreferences::ReceiverPreferences(ProbabilityGenerator pg):
probality_gen(pg)
{}

void ReceiverPreferences::add_receiver(IPackageReceiver *r)
{
    // dodanie elementu
    Reciver_list.insert(std::pair<IPackageReceiver*, double>(r,1) );

    int el_numb = Reciver_list.size();
    preferences_t::iterator it;

    for (it = Reciver_list.begin(); it != Reciver_list.end(); it++)
    {
        it->second = 1.0/el_numb ;
    }
}

IPackageReceiver * ReceiverPreferences::choose_receiver()
{
    // Dystrybułanta
    double distributor = probality_gen();
    const_iterator it;

    for (it = Reciver_list.begin(); it != Reciver_list.end(); it++)
    {
        if(it->second >= distributor)
            return it->first;
        distributor -= it->second;
    }
    // Funkcja w przypadku prawidłowej pracy nie powinna nigdy zwracać nullptr
    assert(false);
    return nullptr;
}

const preferences_t&  ReceiverPreferences::get_preferences() const
{
    return Reciver_list;
}

void ReceiverPreferences::remove_receiver(IPackageReceiver *r)
{
    // usunięcie elementu
    //Reciver_list.insert(std::pair<IPackageReceiver*, double>(r,1) );
    const_iterator it;
    bool remove_element = false;
    for (it = Reciver_list.begin(); it != Reciver_list.end(); it++)
    {
        if(it->first == r)
        {
            Reciver_list.erase(it);
            remove_element = true;
            break;
        }
    }
    assert(remove_element);

    // Aktualizowanie tablicy dystrybułanty listy.
    if(!Reciver_list.empty())
    {
        int el_numb = Reciver_list.size();
        preferences_t::iterator it2;

        for (it2 = Reciver_list.begin(); it2 != Reciver_list.end(); it2++)
        {
            it2->second = 1.0/el_numb;
        }
    }
}

PackageSender::PackageSender():
receiver_preferences_(default_probability_generator)
{}

void PackageSender::send_package()
{
    if(Buffer.has_value())
        receiver_preferences_.choose_receiver()->receive_package(std::move(Buffer.value()))    ;
    Buffer.reset();
}

const std::optional<Package> & PackageSender::get_sending_buffer() const
{
    return Buffer;
}

void Storehouse::receive_package(Package &&p) {
    d_->push(std::move(p));
}

ElementID Storehouse::get_id() const {
    return id_;
}

ReceiverType Storehouse::get_receiver_type() const
{
    return ReceiverType::STOREHOUSE;
}
IPackageStockpile::const_iterator Storehouse::cbegin() const
{
    return d_->cbegin();
}
IPackageStockpile::const_iterator Storehouse::cend() const
{
    return d_->cend();
}

IPackageStockpile *Storehouse::get_stock() const{
    return d_.get();
}


Ramp::Ramp(ElementID id, TimeOffset di): id_(id), di_(di){}

void Ramp::deliver_goods(Time t) {
    if(last_delivery_time + di_ == t || t == 1){
        last_delivery_time = t;
        push_package(Package());

    }
}

TimeOffset Ramp::get_delivery_interval() const {
    return di_;
}

ElementID Ramp::get_id() const {
    return id_;
}

void PackageSender::push_package(Package&& package) {
    this->Buffer.emplace(std::move(package));
}


Worker::Worker(ElementID id, TimeOffset pd, std::unique_ptr<IPackageQueue> q): id_(id), pd_(pd), q_(std::move(q)) {}

void Worker::do_work(Time t) {
    if(t == 1){
        start_time = t;
        auto current_product = q_->pop();
        current_product_buffer.emplace(std::move(current_product));
    }
    if (start_time > 0){
        if(start_time + pd_ == t + 1){
            push_package(std::move(current_product_buffer.value()));
            current_product_buffer.reset();
        }
    }
    if(!q_->empty() && !current_product_buffer.has_value()){
        start_time = t;
        auto current_product = q_->pop();
        current_product_buffer.emplace(std::move(current_product));
    }
}

ElementID Worker::get_id() const {
    return id_;
}


TimeOffset Worker::get_processing_duration() const {
    return pd_;
}

Time Worker::get_package_processing_start_time() const {
    return start_time;
}

void Worker::receive_package(class Package && p) {
    q_->push(std::move(p));
}


ReceiverType Worker::get_receiver_type() const
{
    return ReceiverType::WORKER;
}

IPackageStockpile::const_iterator Worker::cbegin() const
{
    return q_->cbegin();
}
IPackageStockpile::const_iterator Worker::cend() const
{
    return q_->cend();
}
IPackageQueue * Worker::get_queue() const
{
    return q_.get();
}

const std::optional<Package>& Worker::get_processing_buffer() const {
    return current_product_buffer;
}



// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)