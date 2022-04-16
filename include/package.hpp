// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)

#include <set>
#include <iostream>

#include "types.hpp"
#ifndef NET_SIMULATION_PACKAGE_HPP
#define NET_SIMULATION_PACKAGE_HPP


class Package
{
public:
    Package();
    Package(ElementID id_);
    Package(Package&&);
    Package& operator=(Package&&);
    [[nodiscard]] ElementID get_id() const;

    ~Package();
private:
    ElementID id;
    /// Pola statyczne:
    static std::set<ElementID > assigned_IDs;   // Przydzielone obecnie ID
    static std::set<ElementID > freed_IDs;      // Stare adresy ID
};



#endif //NET_SIMULATION_PACKAGE_HPP

// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)