#ifndef HELPERS_H
#define HELPERS_H

#include "population.h"
#include <iostream>

namespace ga
{

namespace helpers
{

template <typename P, typename T>
void eval_func(P & pop, T func)
{
    for(auto & ind : pop)
    {
        func(ind);
    }
}

template <typename P>
void print(P & pop)
{
    for(const auto & ind : pop)
    {
        for(const auto & chrom : ind)
        {
            for(auto bit : chrom)
            {
                std::cout << bit << ' ';
            }
            std::cout << "| ";
        }
        std::cout << '\n';
    }
}


}

}

#endif // HELPERS_H
