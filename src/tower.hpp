#pragma once

#include "waypoint.hpp"

#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>

class Airport;
class Aircraft;
class Terminal;

class Tower
{
private:
    //using AircraftToTerminal      = std::vector<std::pair<const Aircraft*, size_t>>;
    using AircraftToTerminal      = std::unordered_map<const Aircraft*, size_t>;
    //using AircraftAndTerminalIter = AircraftToTerminal::iterator;

    Airport& airport;
    // aircraft may reserve a terminal
    // if so, we need to save the terminal number in order to liberate it when the craft leaves
    AircraftToTerminal reserved_terminals = {};

    static WaypointQueue get_circle() ;

    /*AircraftAndTerminalIter find_craft_and_terminal(const Aircraft& aircraft)
    {
        return std::find_if(reserved_terminals.begin(), reserved_terminals.end(),
                            [&aircraft](const auto& x) { return x.first == &aircraft; });
    }*/

public:
    Tower(Airport& airport_) : airport { airport_ } {}

    // produce instructions for aircraft
    WaypointQueue get_instructions(Aircraft& aircraft);
    void arrived_at_terminal(const Aircraft& aircraft);
    WaypointQueue reserve_terminal(Aircraft& aircraft);
    void delete_crashed_aircraft(const Aircraft& aircraft);
};
