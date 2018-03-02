#ifndef OPERATORS_H
#define OPERATORS_H

#include "population.h"

namespace ga
{

template <typename T = bool>
class Mutation
{
    double rate = 0;
public:
    Mutation(double irate = 0) : rate{irate} {}
    void operator()(const Population<T> & pop)
    {

    }

};

template <typename T = bool>
class Crossover
{
    int points = 0;
public:
    Crossover(int ipoints = 0) : points{ipoints} {}
    void operator()(const Population<T> & pop)
    {

    }
};

}

#endif // OPERATORS_H
