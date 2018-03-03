#ifndef FITNESS_H
#define FITNESS_H

#include <numeric>
#include <functional>
#include "population.h"

namespace ga
{

namespace fit
{

template <typename T = bool>
int fitness(const Individual<T> & ind)
{
    int res = 0;
    for(auto chrom : ind)
    {
        res += std::accumulate(chrom.begin(), chrom.end(), 0);
    }
    return res;
}

} //fit

} //ga

#endif // FITNESS_H
