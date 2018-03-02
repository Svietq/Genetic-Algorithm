#include <iostream>
#include "genetic_algorithm.h"

using namespace ga;

int main()
{
    using Population = Population<bool>;
    using Goal = Goal<bool>;
    using Mutation = Mutation<bool>;
    using Crossover = Crossover<bool>;

    run_ga(Population{20, 4, 8},
           fit::fitness<bool>,
           Goal{50},
           Selection<Roulette>{},
           Mutation{50},
           Crossover{1});


}
