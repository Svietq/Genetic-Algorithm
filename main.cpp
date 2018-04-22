#include <iostream>
#include "genetic_algorithm.h"

using namespace ga;

int main()
{
    run_ga(Population{15, 3, 10},
           fit::sum<int>,
           Goal{50},
           Selection<Deterministic>{},
           Mutation{50},
           Crossover{1});

    for( auto x : Statistics::get().fitness_values)
    {
        std::cout << x << " ";
    }
    std::cout << '\n';

}
