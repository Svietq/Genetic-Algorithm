#ifndef FITNESS_H
#define FITNESS_H

#include <numeric>
#include <functional>
#include "population.h"
#include "statistics.h"

namespace ga
{

namespace fit
{

template <typename T = int>
int sum(const Individual<T> & ind)
{
    int res = 0;
    for(auto chrom : ind)
    {
        res += std::accumulate(chrom.begin(), chrom.end(), 0);
    }
    Statistics<int>::get().fitness_values.push_back(res);
    return res;
}

} //fit

} //ga

#endif // FITNESS_H
