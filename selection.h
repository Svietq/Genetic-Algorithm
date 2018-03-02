#ifndef SELECTION_H
#define SELECTION_H

#include "population.h"
#include <iostream>

namespace ga
{

struct Deterministic {};
struct Roulette {};
struct Rang_tournament {};

template <typename M, typename T = bool>
class Selection {};

template <typename T>
class Selection<Deterministic, T>
{
public:
    Selection(){ std::cout << "Deterministic";}
    void operator ()(const Population<T> & pop)
    {

    }
};

template <typename T>
class Selection<Roulette, T>
{
public:
    Selection(){ std::cout << "Roulette";}
    void operator ()(const Population<T> & pop)
    {

    }
};

template <typename T>
class Selection<Rang_tournament, T>
{
public:
    Selection(){ std::cout << "Rang_tournament";}
    void operator ()(const Population<T> & pop)
    {

    }
};

}

#endif // SELECTION_H
