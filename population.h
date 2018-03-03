#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include <algorithm>
#include "helpers.h"

namespace ga
{

template <typename T>
using Chromosome = std::vector<T>;

template <typename T>
using Individual = std::vector< Chromosome<T> >;

template <typename T>
class Basic_Population
{
    using Cont = std::vector< Individual<T> >;
    using Size = typename Cont::size_type;
    Cont cont;

    void init(){}

public:
    Basic_Population(Size pop_size = 0,
                     Size ind_size = 0,
                     Size chrom_size = 0)
    {
        cont.resize(pop_size, Individual<T>(ind_size, Chromosome<T>(chrom_size)));
        cont.shrink_to_fit();
        init();
    }

    typename Cont::iterator begin() { return cont.begin(); }
    typename Cont::iterator end()   { return cont.end();   }
    const typename Cont::iterator cbegin() const { return cont.cbegin(); }
    const typename Cont::iterator cend()   const { return cont.cend();   }
};

template<>
inline void Basic_Population<bool>::init()
{
    for(auto & ind : cont)
    {
        for(auto & chrom : ind)
        {
            std::generate(chrom.begin(), chrom.end(), helpers::random_generator<int>{0,1});
        }
    }
}


using Population = Basic_Population<bool>;

} //ga

#endif // POPULATION_H
