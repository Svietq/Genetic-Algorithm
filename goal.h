#ifndef GOAL_H
#define GOAL_H

#include "population.h"

namespace ga
{

template <typename T = bool>
class Basic_Goal
{
    int desired_cost = 0;
    int calc_cost(const Basic_Population<T> & pop)
    {
        /*placeholder*/
        return 50;
    }

public:
    Basic_Goal(int icost = 0) : desired_cost{icost} {}
    bool operator()(const Basic_Population<T> & pop)
    {
        return desired_cost >= calc_cost(pop);
    }
};

using Goal = Basic_Goal<bool>;

}

#endif // GOAL_H
