// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)
#include <iostream>
#include <assert.h>

#include "package.hpp"

/// Pola statyczne:
std::set<ElementID > Package::assigned_IDs;   // Przydzielone obecnie ID
std::set<ElementID > Package::freed_IDs;      // Stare adresy ID

Package::Package()
{
    if(freed_IDs.empty())
    {
        ElementID id_candidate = 1;
        while (true)
        {
            if(not assigned_IDs.count(id_candidate)){
                // Nie znaleziono elementu w zbiorze
                id = id_candidate;
                assigned_IDs.insert(id_candidate);
                break;
            }else{
                id_candidate ++;
            }
        }
    }else{
        id = *freed_IDs.begin(); // najmniejszy element
        freed_IDs.erase(freed_IDs.begin());
        assigned_IDs.insert(id);
    }
}

Package::Package(ElementID id_):
id(id_)
{
    assigned_IDs.insert(id_);
}

Package::Package(Package && other):
id(other.id)
{
    other.id = 0; // 0 - wartość specjalna oznaczająca, że wartość id ma być nie nir usuwana z assigned_IDs
}

Package& Package::operator=(Package && other)
{
     ElementID old_id = this->id;

     assigned_IDs.erase(assigned_IDs.find(old_id));
    freed_IDs.insert(old_id);

    id = other.id;
    other.id = 0;
    return *this;
}


ElementID Package::get_id() const
{
    return id;
}


Package::~Package()
{
    if(id != 0)
    {
        assert(assigned_IDs.find(id) != assigned_IDs.end());
        assigned_IDs.erase(assigned_IDs.find(id));
        freed_IDs.insert(id);
    }
}
// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)