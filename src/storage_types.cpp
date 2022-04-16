// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)

#include "storage_types.hpp"

PackageQueue::PackageQueue(PackageQueueType queue_t) : queue_type(queue_t) {}

PackageQueueType PackageQueue::get_queue_type() const {
    if (queue_type == PackageQueueType::LIFO){
        return PackageQueueType::LIFO;
    }
    else{
        return PackageQueueType::FIFO;
    }
}

Package PackageQueue::pop() {
    if (queue_type == PackageQueueType::LIFO){
        Package p = std::move(queue.back());
        queue.pop_back();
        return p;
    }
    else{
        Package p = std::move(queue.front());
        queue.pop_front();
        return p;
    }
}

void PackageQueue::push(Package && p) {
    queue.push_back(std::move(p));
}

bool PackageQueue::empty() const {
    return queue.size() == 0;
}

size_type PackageQueue::size() const {
    return queue.size();
}

std::string get_queue_type_in_string(PackageQueueType type) {
    switch(type){
        case PackageQueueType::LIFO:
            return static_cast<std::string>("LIFO");
        case PackageQueueType::FIFO:
            return static_cast<std::string>("FIFO");
        default:
            return static_cast<std::string>("ERROR - typ nieznany");
    }
}

// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)