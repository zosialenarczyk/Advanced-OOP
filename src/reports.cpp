// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)
#include "reports.hpp"
#include <iostream>

void generate_structure_report(const Factory &f, std::ostream &os) {

    os << "\n";
    os << "== LOADING RAMPS ==" << std::endl;
    os << "\n";

    for(auto ramp = f.ramp_cbegin(); ramp != f.ramp_cend(); ++ramp){
        os << "LOADING RAMP #" << ramp->get_id() << std::endl;

        os << "  Delivery interval: " << ramp->get_delivery_interval() << std::endl;

        os << "  Receivers:" << std::endl;
        std::list<ElementID> workers;
        for (auto it = ramp->receiver_preferences_.Reciver_list.cbegin(); it != ramp->receiver_preferences_.Reciver_list.cend(); ++it) {
            workers.push_back(it->first->get_id());
        }
        workers.sort();
        for(auto w : workers){
            os << "    worker #" << w << std::endl;
        }

        os << "\n";
    }


    os << "\n";
    os << "== WORKERS ==" << std::endl;
    os << "\n";

    std::list<ElementID> workers_id;
    for(auto worker = f.worker_cbegin(); worker != f.worker_cend(); ++worker){
        workers_id.push_back(worker->get_id());
    }

    workers_id.sort();

    for(auto i  = workers_id.cbegin(); i != workers_id.cend(); ++i) {
        for (auto worker = f.worker_cbegin(); worker != f.worker_cend(); ++worker) {
            if (worker->get_id() == *i) {
                os << "WORKER #" << worker->get_id() << std::endl;
                os << "  Processing time: " << worker->get_processing_duration() << std::endl;
                os << "  Queue type: " ;
                if (worker->get_queue()->get_queue_type() == PackageQueueType::LIFO) {
                    os << "LIFO" << std::endl;
                } else{
                    os << "FIFO" << std::endl;
                }
                os << "  Receivers:" << std::endl;

                // sortowanie odbiorców:
                std::list<ElementID> other_workers;
                std::list<ElementID > storehouses;
                for (auto it = worker->receiver_preferences_.Reciver_list.cbegin(); it != worker->receiver_preferences_.Reciver_list.cend(); ++it) {
                    if (it->first->get_receiver_type() == ReceiverType::WORKER) {
                        other_workers.push_back(it->first->get_id());
                    } else if (it->first->get_receiver_type() == ReceiverType::STOREHOUSE) {
                        storehouses.push_back(it->first->get_id());
                    }
                }
                other_workers.sort();
                storehouses.sort();
                for(auto s : storehouses){
                    os << "    storehouse #" << s << std::endl;
                }
                for(auto w : other_workers){
                    os << "    worker #" << w << std::endl;
                }

                os << "\n";
                break;
            }
        }
    }

    os << "\n";
    os << "== STOREHOUSES ==" << std::endl;
    os << "\n";

    std::list<ElementID> storehouses_id;
    for(auto s = f.storehouse_cbegin(); s != f.storehouse_cend(); ++s){
        storehouses_id.push_back(s->get_id());
    }

    storehouses_id.sort();

    for(auto i  = storehouses_id.cbegin(); i != storehouses_id.cend(); ++i) {
        for(auto storehouse = f.storehouse_cbegin(); storehouse != f.storehouse_cend(); ++storehouse){
            if(storehouse->get_id() == *i){
                os << "STOREHOUSE #" << storehouse->get_id() << std::endl;
                os << "\n";
                break;
            }
        }
    }
}

void generate_simulation_turn_report(const Factory &f, std::ostream &os, Time t) {
    os << "=== [ Turn: " << t << " ] ===" << std::endl;
    os << "\n";
    os << "== WORKERS ==" << std::endl;
    os << "\n";

    std::list<ElementID> workers_id;
    for(auto worker = f.worker_cbegin(); worker != f.worker_cend(); ++worker){
        workers_id.push_back(worker->get_id());
    }

    workers_id.sort();

    for(auto i  = workers_id.cbegin(); i != workers_id.cend(); ++i) {
        for(auto worker = f.worker_cbegin(); worker != f.worker_cend(); ++ worker){
            if(worker->get_id() == *i){
                os << "WORKER #" << worker->get_id() << std::endl;

                os << "  PBuffer: ";
                if (!worker->get_processing_buffer().has_value()){
                    os << "(empty)" << std::endl;
                } else{
                    os << "#" << worker->get_processing_buffer()->get_id() << " (pt = " << t + 1 - worker->get_package_processing_start_time() << ")" << std::endl;
                }

                os << "  Queue: ";
                if (worker->get_queue()->size() == 0) {
                    os << "(empty)" << std::endl;
                } else {
                    for (auto it = worker->get_queue()->cbegin(); it != worker->get_queue()->cend(); ++ it){
                        os << "#" << it->get_id();
                        if(it == std::prev(worker->get_queue()->cend())){
                            os << std::endl;
                            break;
                        }
                        os << ", ";
                    }
                }

                os << "  SBuffer: ";
                if (!worker->get_sending_buffer().has_value()){
                    os << "(empty)" << std::endl;
                } else{
                    os << "#" << worker->get_sending_buffer()->get_id() <<std::endl;
                }
                os << "\n";
                break;
            }
        }
    }



    os << "\n";
    os << "== STOREHOUSES ==" << std::endl;
    os << "\n";

    std::list<ElementID> storehouses_id;
    for(auto s = f.storehouse_cbegin(); s != f.storehouse_cend(); ++s){
        storehouses_id.push_back(s->get_id());
    }

    storehouses_id.sort();

    for(auto i  = storehouses_id.cbegin(); i != storehouses_id.cend(); ++i) {
        for(auto storehouse = f.storehouse_cbegin(); storehouse != f.storehouse_cend(); ++storehouse){
            if(storehouse->get_id() == *i){
                os << "STOREHOUSE #" << storehouse->get_id() << std::endl;
                os << "  Stock: ";
                if(storehouse->get_stock()->size() == 0){
                    os << "(empty)" << std::endl;
                    os << "\n";
                } else {
                    for(auto it = storehouse->get_stock()->cbegin(); it != storehouse->get_stock()->cend(); ++ it){
                        os << "#" << it->get_id();
                        if(it == std::prev(storehouse->get_stock()->cend())){
                            os << std::endl;
                            os << "\n";
                            break;
                        }
                        os << ", ";
                    }
                }
                break;
            }
        }
    }
}

SpecificTurnsReportNotifier::SpecificTurnsReportNotifier(std::set<Time> turns): turns_(turns) {}

bool SpecificTurnsReportNotifier::should_generate_report(Time t) {
    return turns_.count(t) != 0;
}

IntervalReportNotifier::IntervalReportNotifier(TimeOffset to): to_(to) {}

bool IntervalReportNotifier::should_generate_report(Time t) {
    if (to_ == 1) {
        return true;
    } else return t % to_ == 1;
}

// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)