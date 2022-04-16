// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)
#include <list>
#include <string>
#include "types.hpp"
#include "package.hpp"
#ifndef NET_SIMULATION_STORAGE_TYPES_HPP
#define NET_SIMULATION_STORAGE_TYPES_HPP


using size_type = unsigned int;

enum class PackageQueueType{
    LIFO, FIFO
};

std::string get_queue_type_in_string(PackageQueueType type);

class IPackageStockpile{
public:
    virtual void push(Package&&) = 0;
    virtual bool empty() const = 0;
    virtual size_type size() const = 0;

    typedef std::list<Package>::const_iterator const_iterator;
    virtual const_iterator cbegin() const = 0;
    virtual const_iterator cend() const = 0;
    virtual const_iterator begin() const = 0;
    virtual const_iterator end() const = 0;

    virtual ~IPackageStockpile() = default;
};

class IPackageQueue : public IPackageStockpile{
public:
    virtual Package pop() = 0;
    virtual PackageQueueType get_queue_type() const = 0;
};

class PackageQueue : public IPackageQueue{
public:
    PackageQueue(PackageQueueType queue_t);
    PackageQueueType get_queue_type() const override;
    Package pop() override;
    void push(Package&&) override;
    bool empty() const override;
    size_type size() const override;
    const_iterator cbegin() const override { return queue.cbegin(); }
    const_iterator cend() const override { return queue.cend(); }
    const_iterator begin() const override { return queue.begin(); }
    const_iterator end() const override { return queue.end(); }

private:
    std::list<Package> queue;
    PackageQueueType queue_type;
};

#endif //NET_SIMULATION_STORAGE_TYPES_HPP
// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)