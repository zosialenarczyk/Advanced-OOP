// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)

#include <iostream>
#include "simulation.hpp"


void simulate(Factory& f, TimeOffset d, std::function<void (Factory&, Time)> rf) {

    if (f.is_consistent()) {

        for (TimeOffset turn = 1; turn != d; turn++) {

            f.do_deliveries(turn);
            f.do_package_passing();
            f.do_work(turn);
            rf(f, turn);
        }
    }
    else {
        throw std::logic_error("Consistency error");
    }
}


// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)
