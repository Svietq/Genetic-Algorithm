#ifndef POPULATION_H
#define POPULATION_H

#include <vector>

namespace ga
{

template <typename T = bool>
using Chromosome = std::vector<T>;

template <typename T = bool>
using Individual = std::vector< Chromosome<T> >;

template <typename T = bool>
class Population
{
    using Cont = std::vector< Individual<T> >;
    using Size = typename Cont::size_type;
    Cont cont;
public:
    Population(Size pop_size = 0,
               Size ind_size = 0,
               Size chrom_size = 0)
    {
        cont.resize(pop_size, Individual<T>(ind_size, Chromosome<T>(chrom_size)));
        cont.shrink_to_fit();
    }

    typename Cont::iterator begin() { return cont.begin(); }
    typename Cont::iterator end()   { return cont.end();   }
    const typename Cont::iterator cbegin() { return cont.cbegin(); }
    const typename Cont::iterator cend()   { return cont.cend();   }
};




}

#endif // POPULATION_H
