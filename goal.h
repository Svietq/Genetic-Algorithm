#ifndef GOAL_H
#define GOAL_H

#include "population.h"
#include "statistics.h"

namespace ga
{

template <typename T = int>
class Basic_Goal
{
    int desired_cost = 0;
    int calc_cost()
    {
        const auto & fitness_values = Basic_Statistics<int>::get().fitness_values;
        return std::accumulate(fitness_values.begin(), fitness_values.end(), 0);
    }

public:
    Basic_Goal(int icost = 0) : desired_cost{icost} {}
    bool operator()(const Basic_Population<T> &)
    {
        return desired_cost >= calc_cost();
    }
};

using Goal = Basic_Goal<int>;

} //ga

#endif // GOAL_H
