// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)

#include <iostream>
#include "factory.hpp"
#include "types.hpp"
#include "nodes.hpp"

#ifndef NET_SIMULATION_SIMULATION_HPP
#define NET_SIMULATION_SIMULATION_HPP

void simulate(Factory& f, TimeOffset d, std::function<void (Factory&, Time)> rf);

#endif //NET_SIMULATION_SIMULATION_HPP

// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)
