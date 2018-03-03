#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H

#include "helpers.h"
#include "population.h"
#include "fitness.h"
#include "goal.h"
#include "selection.h"
#include "operators.h"

namespace ga
{

template <typename P,
          typename F,
          typename G,
          typename S,
          typename M,
          typename C
          >
void run_ga(P pop, F fit, G goal, S sel, M mut, C cros)
{
    using namespace helpers;
    print(pop);
//    while(goal(pop))
    {
        eval_func(pop, fit);
        sel(pop);
        mut(pop);
        cros(pop);
    }
}

} //ga

#endif // GENETIC_ALGORITHM_H
