// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)
#ifndef NET_SIMULATION_REPORTS_HPP
#define NET_SIMULATION_REPORTS_HPP

#include <iostream>
#include "factory.hpp"

void generate_structure_report(const Factory& f, std::ostream& os);
void generate_simulation_turn_report(const Factory& f, std::ostream& os, Time t);

class SpecificTurnsReportNotifier {
protected:
    std::set<Time> turns_;
public:
    SpecificTurnsReportNotifier(std::set<Time> turns);
    bool should_generate_report(Time t);

};

class IntervalReportNotifier {
protected:
    TimeOffset to_;
public:
    IntervalReportNotifier(TimeOffset to);
    bool should_generate_report(Time t);
};

#endif //NET_SIMULATION_REPORTS_HPP
// 35: Rafa (401991) Szota(401281)  Lenarczyk(402763)