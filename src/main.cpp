#include "tower_sim.hpp"

int main(int argc, char** argv)
{

    ContextInitializer contextInitializer {argc, argv};
    TowerSimulation simulation { contextInitializer};
    simulation.launch();

    return 0;
}