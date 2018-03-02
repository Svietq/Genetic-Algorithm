#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H

#include "helpers.h"
#include "population.h"
#include "goal.h"
#include "selection.h"

namespace ga
{
using namespace helpers;

template <typename P,
          typename F,
          typename G,
          typename S,
          typename M,
          typename C
          >
void run_ga(P pop, F fit, G goal, S sel/*, M mut, C cros*/)
{
    while(goal(pop))
    {
        print(pop);
        eval_func(pop, fit);
        sel(pop);
//        mut(pop);
//        cros(pop);
    }
}

}

#endif // GENETIC_ALGORITHM_H
