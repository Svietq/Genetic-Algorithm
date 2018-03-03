#include <iostream>
#include "genetic_algorithm.h"

using namespace ga;

int main()
{
    run_ga(Population{20, 4, 8},
           fit::fitness<bool>,
           Goal{50},
           Selection<Roulette>{},
           Mutation{50},
           Crossover{1});

}
