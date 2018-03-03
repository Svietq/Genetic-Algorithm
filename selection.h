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
    Selection(){ std::cout << "Deterministic\n";}
    void operator ()(const Basic_Population<T> & )
    {

    }
};

template <typename T>
class Selection<Roulette, T>
{
public:
    Selection(){ std::cout << "Roulette\n";}
    void operator ()(const Basic_Population<T> & )
    {

    }
};

template <typename T>
class Selection<Rang_tournament, T>
{
public:
    Selection(){ std::cout << "Rang_tournament\n";}
    void operator ()(const Basic_Population<T> & )
    {

    }
};

} //ga

#endif // SELECTION_H
