#ifndef OPERATORS_H
#define OPERATORS_H

#include "population.h"

namespace ga
{

template <typename T = int>
class Basic_Mutation
{
    double rate = 0;
public:
    Basic_Mutation(double irate = 0) : rate{irate} {}
    void operator()(const Basic_Population<T> & )
    {

    }

};

using Mutation = Basic_Mutation<int>;

template <typename T = int>
class Basic_Crossover
{
    int points = 0;
public:
    Basic_Crossover(int ipoints = 0) : points{ipoints} {}
    void operator()(const Basic_Population<T> & )
    {

    }
};

using Crossover = Basic_Crossover<int>;

} //ga

#endif // OPERATORS_H
