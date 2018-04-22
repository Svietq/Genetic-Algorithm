#ifndef DETERMINISTIC_IMPL_H
#define DETERMINISTIC_IMPL_H

#include "selection.h"
#include <cmath>

template<>
void Selection<Deterministic, int>::calculate_probabilities()
{
    const auto & fitness_values = Statistics::get().fitness_values;
    const double sum = std::accumulate(fitness_values.begin(), fitness_values.end(), 0.0);
    const double min = * std::min_element(fitness_values.begin(), fitness_values.end());
    const double den = sum - min;

    for(auto fitness_value : fitness_values)
    {
        probabilities.emplace_back( (fitness_value - min) /  den );
    }
}

template<>
void Selection<Deterministic, int>::calculate_copies_and_rests()
{
    const int POP_SIZE = Statistics::get().pop_size;

    for(auto probability : probabilities)
    {
        rests.emplace_back( std::fmod( POP_SIZE * probability, 1) );
        copies.emplace_back( POP_SIZE * probability );
    }
}

template<>
void Selection<Deterministic, int>::fill_with_copies(Basic_Population<int> & pop)
{
    const int POP_MULTIPLICITY = 2;
    const int POP_SIZE = Statistics::get().pop_size;
    auto ptr = pop.end();
    pop.resize( POP_SIZE * POP_MULTIPLICITY );
    // - POP_SIZE/POP_MULTIPLICITY;

    for(std::size_t i = 0; i<copies.size(); ++i)
    {
        std::fill_n( ptr, copies[i], pop[i] );
        ptr += copies[i];
    }

}

template<>
void Selection<Deterministic, int>::fill_with_rests(Basic_Population<int> & pop)
{
    const int POP_MULTIPLICITY = 2;
    const int POP_SIZE = Statistics::get().pop_size;
    const int free_places = POP_SIZE - std::accumulate(copies.begin(), copies.end(), 0);
    const int LOWEST_VALUE = 0;

    for(int i=free_places; i>0; --i)
    {
        const auto max = std::max_element(rests.begin(), rests.end());
        const auto dist = std::distance(rests.begin(), max);
        pop[ POP_SIZE * POP_MULTIPLICITY - i ] = Individual<int>{ pop[dist].begin(), pop[dist].end() };
        *max = LOWEST_VALUE;
    }

//    pop.erase( pop.begin(), pop.end() - pop.size()/POP_MULTIPLICITY); //go back to the initial size
}


#endif // DETERMINISTIC_IMPL_H
