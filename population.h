#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include <algorithm>
#include "helpers.h"
#include "statistics.h"

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
        Basic_Statistics<T>::get().pop_size = pop_size;
    }

    typename Cont::iterator begin() { return cont.begin(); }
    typename Cont::iterator end()   { return cont.end();   }
    const typename Cont::iterator cbegin() const { return cont.cbegin(); }
    const typename Cont::iterator cend()   const { return cont.cend();   }
    Size size() const { return cont.size(); }
    void resize(Size n) { cont.resize(n); }
    Individual<T>& operator[](Size idx){ return cont[idx]; }
    const Individual<T>& operator[](Size idx) const { return cont[idx]; }

};

template<>
inline void Basic_Population<int>::init()
{
    for(auto & ind : cont)
    {
        for(auto & chrom : ind)
        {
            std::generate(chrom.begin(), chrom.end(), helpers::random_generator<int>{0,1});
        }
    }
}


using Population = Basic_Population<int>;

} //ga

#endif // POPULATION_H
