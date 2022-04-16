// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)

#ifndef NET_SIMULATION_FACTORY_HPP
#define NET_SIMULATION_FACTORY_HPP


#include <list>
#include <cassert>
#include <istream>
#include <ostream>
#include <string>
#include <sstream>
#include <map>

#include <algorithm>
#include <array>
#include <functional>
#include <iomanip>
#include <iostream>

#include "nodes.hpp"
#include "types.hpp"
#include "storage_types.hpp"
#include "helpers.hpp"


template <class Node>
class NodeCollection{

protected:
    std::list<Node> nodes;
public:
    using list = typename std::list<Node>;
    using iterator = typename list::iterator;
    using const_iterator = typename list::const_iterator;

    void add_node(Node&& node){
        nodes.push_back(std::move(node));
    }

    void remove_by_id(ElementID id)
    {
        const_iterator el_to_remove = std::find_if(nodes.cbegin(), nodes.cend(), [id](const Node& i){ return i.get_id() == id; } );

        if (el_to_remove != nodes.cend() ){
            nodes.erase(el_to_remove);
        }

    }
    NodeCollection<Node>::iterator find_by_id(ElementID id)
    {
        NodeCollection<Node>::const_iterator it;
        if(std::is_same_v<Node, Ramp>)
        {
            for(it = nodes.begin();it!=nodes.end;it++)
            {
                auto el_ptr = dynamic_cast<Ramp*>(it);
                if(id == el_ptr->get_id())
                {
                    return it;
                }
            }
        }else if(std::is_same_v<Node, Worker>)
        {
            for(it = nodes.begin();it!=nodes.end;it++)
            {
                auto el_ptr = dynamic_cast<Worker*>(it);
                if(id == el_ptr->get_id())
                {
                    return it;
                }
            }
        }else if(std::is_same_v<Node, Storehouse>)
        {
            for(it = nodes.begin();it!=nodes.end;it++)
            {
                auto el_ptr = dynamic_cast<Storehouse*>(it);
                if(id == el_ptr->get_id())
                {
                    return it;
                }
            }
        }
    }

    NodeCollection<Node>::const_iterator find_by_id(ElementID id) const
    {
        NodeCollection<Node>::iterator it;
        if(std::is_same_v<Node, Ramp>)
        {
            for(it = nodes.begin();it!=nodes.end;it++)
            {
                auto el_ptr = dynamic_cast<Ramp*>(it);
                if(id == el_ptr->get_id())
                {
                    return it;
                }
            }
        }else if(std::is_same_v<Node, Worker>)
        {
            for(it = nodes.begin();it!=nodes.end;it++)
            {
                auto el_ptr = dynamic_cast<Worker*>(it);
                if(id == el_ptr->get_id())
                {
                    return it;
                }
            }
        }else if(std::is_same_v<Node, Storehouse>)
        {
            for(it = nodes.begin();it!=nodes.end;it++)
            {
                auto el_ptr = dynamic_cast<Storehouse*>(it);
                if(id == el_ptr->get_id())
                {
                    return it;
                }
            }
        }
    }


    const_iterator cbegin() const { return nodes.cbegin(); }
    const_iterator cend() const { return nodes.cend(); }
    const_iterator begin() const { return nodes.begin(); }
    const_iterator end() const  { return nodes.end(); }
    iterator begin() { return nodes.begin(); }
    iterator end() { return nodes.end(); }

};



enum class NodeColor { UNVISITED, VISITED, VERIFIED };

class Factory{

private:
    NodeCollection<Ramp> Ramps;
    NodeCollection<Worker> Workers;
    NodeCollection<Storehouse> Storehouses;

public:
    void add_ramp(Ramp&&);
    void remove_ramp(ElementID id);

    NodeCollection<Ramp>::iterator find_ramp_by_id(ElementID id);
    NodeCollection<Ramp>::const_iterator find_ramp_by_id(ElementID id) const;
    NodeCollection<Ramp>::const_iterator ramp_cbegin() const;
    NodeCollection<Ramp>::const_iterator ramp_cend() const;

    void add_worker(Worker&&);
    void remove_worker(ElementID id);

    NodeCollection<Worker>::iterator find_worker_by_id(ElementID id);
    NodeCollection<Worker>::const_iterator find_worker_by_id(ElementID id) const;
    NodeCollection<Worker>::const_iterator worker_cbegin() const;
    NodeCollection<Worker>::const_iterator worker_cend() const;

    void add_storehouse(Storehouse&&);
    void remove_storehouse(ElementID id);

    NodeCollection<Storehouse>::iterator find_storehouse_by_id(ElementID id);
    NodeCollection<Storehouse>::const_iterator find_storehouse_by_id(ElementID id) const;
    NodeCollection<Storehouse>::const_iterator storehouse_cbegin() const;
    NodeCollection<Storehouse>::const_iterator storehouse_cend() const;

    // Sprawdzania spójności sieci:
    bool is_consistent() const;
    bool has_reachable_storehouse(const PackageSender* sender,
                                  std::map<const PackageSender*,
                                  NodeColor>& node_colors) const;

    void do_deliveries(Time);
    void do_package_passing();
    void do_work(Time);

private:
    template<typename Node>
    void remove_receiver(NodeCollection<Node>& collection, ElementID id)
    {

        //auto looked_for_iter = collection.find_by_id(id);
        for(auto iter = collection.begin();iter != collection.end();iter++)
        {
            for(auto& preferenc: iter->receiver_preferences_.Reciver_list )
            {
                if(preferenc.first->get_id() == id )
                {
                    iter->receiver_preferences_.remove_receiver(preferenc.first);
                    break;
                }
            }
        }
    }
};

enum class ElementType
{
    RAMP,
    WORKER,
    STOREHOUSE,
    LINK
};

struct ParsedLineData
{
    ElementType element_type;
    std::map<std::string ,std::string> parameters;
};

/// Wczytanie pliku
Factory load_factory_structure(std::istream& is);
ParsedLineData parse_line(std::string& line);
ElementType get_El_type(std::string& str);
ElementType get_el_type_small(std::string& str);

/// Zapis do pliku
void save_factory_structure(Factory& factory, std::ostream& os);

struct rarpot_and_id
{
    std::string str;
    ElementID id;
};


#endif //NET_SIMULATION_FACTORY_HPP

// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)