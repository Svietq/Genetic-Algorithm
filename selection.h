#ifndef SELECTION_H
#define SELECTION_H

#include "population.h"
#include <iostream>

namespace ga
{

struct Deterministic {};
struct Roulette {};
struct Rang_tournament {};

template <typename M, typename T = int>
class Selection {};

template <typename T>
class Selection<Deterministic, T>
{
    std::vector<double> probabilities;
    std::vector<double> rests;
    std::vector<int> copies;

    void calculate_probabilities();
    void calculate_copies_and_rests();
    void fill_with_copies(Basic_Population<T> &);
    void fill_with_rests(Basic_Population<T> &);
public:
    Selection(){ std::cout << "Deterministic\n";}
    void operator ()(Basic_Population<T> & pop)
    {
        calculate_probabilities();
        calculate_copies_and_rests();
        fill_with_copies(pop);
        fill_with_rests(pop);
    }
};

#include "deterministic_impl.h"

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
