// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)

#ifndef NET_SIMULATION_NODES_HPP
#define NET_SIMULATION_NODES_HPP

#include "config.hpp"
#include "storage_types.hpp"

#include <map>
#include <memory>
#include <map>
#include "types.hpp"
#include "storage_types.hpp"
#include "helpers.hpp"

enum class ReceiverType
{
    WORKER,
    STOREHOUSE
};


class IPackageReceiver
{

public:
    virtual void receive_package(Package&& p) = 0;
    virtual ElementID get_id() const = 0 ;

#if (defined EXERCISE_ID && EXERCISE_ID != EXERCISE_ID_NODES)
    virtual ReceiverType get_receiver_type() const = 0;
#endif
    virtual IPackageStockpile::const_iterator cbegin() const = 0;
    virtual IPackageStockpile::const_iterator cend() const = 0;
};


using preferences_t = std::map<IPackageReceiver*, double>;
using const_iterator = preferences_t::const_iterator;

class ReceiverPreferences {

protected:
    ProbabilityGenerator probality_gen; // funkcjia zwracająca prawdopodobieństwo ( liczba typu double ) w zakresie od 0 do 1
public:
    // Wg. diagramu UML pole te miało być publiczne:
    preferences_t Reciver_list;

    ReceiverPreferences() : probality_gen(probability_generator) {};
    ReceiverPreferences(ProbabilityGenerator pg);
    void add_receiver(IPackageReceiver* r);
    void remove_receiver(IPackageReceiver* r);
    IPackageReceiver* choose_receiver();
    const preferences_t& get_preferences() const;

    auto begin() { return this->Reciver_list.begin(); }
    auto end() { return this->Reciver_list.end(); }
    auto cbegin() { return this->Reciver_list.cbegin(); }
    auto cend() { return this->Reciver_list.cend(); }
};

class PackageSender{
protected:
    std::optional<Package> Buffer;
    void push_package(Package&& package);
public:
    // Wg. diagramu UML pole te miało być publiczne:
    ReceiverPreferences receiver_preferences_;

    PackageSender(); // Dodano konstruktor ( nie ma go w UML ) w celu konfiguracji r_pref
    PackageSender(PackageSender&&) = default;
    ~PackageSender() = default;

    void send_package();
    const std::optional<Package>& get_sending_buffer() const;
};

class Storehouse: public IPackageReceiver{

protected:
    ElementID id_;
    std::unique_ptr<IPackageStockpile> d_;

public:
    Storehouse(ElementID id, std::unique_ptr<IPackageStockpile> d = std::make_unique<PackageQueue>(PackageQueueType::FIFO)) : id_(id), d_(std::move(d)) {};
    void receive_package(Package &&p) override;
    ElementID get_id() const override ;

    ReceiverType get_receiver_type() const override;

    IPackageStockpile::const_iterator cbegin() const override;
    IPackageStockpile::const_iterator cend() const override;
    //raportowanie
    IPackageStockpile* get_stock() const;
};

class Ramp: public PackageSender{

protected:
    ElementID id_;
    TimeOffset di_;
    Time last_delivery_time = 1;

public:
    Ramp(ElementID id, TimeOffset di);
    void deliver_goods(Time t);
    TimeOffset get_delivery_interval() const;
    ElementID get_id() const;

};

class Worker: public PackageSender, public IPackageReceiver{

protected:
    ElementID id_;
    TimeOffset pd_;
    Time start_time = 0;
    std::unique_ptr<IPackageQueue> q_;
    std::optional<Package> current_product_buffer;

public:
    Worker(ElementID id, TimeOffset pd, std::unique_ptr<IPackageQueue> q);
    TimeOffset get_processing_duration() const;
    Time get_package_processing_start_time() const;
    void do_work(Time t);

    // Nadpisane funkcje z IPackageReceiver
    void receive_package(Package &&p) override;
    ElementID get_id() const override ;

    ReceiverType get_receiver_type() const override;

    IPackageStockpile::const_iterator cbegin() const override;
    IPackageStockpile::const_iterator cend() const override;

    // Raportowanie
    IPackageQueue* get_queue() const;
    const std::optional<Package>& get_processing_buffer() const;
};


#endif //NET_SIMULATION_NODES_HPP

// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)