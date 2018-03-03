#ifndef HELPERS_H
#define HELPERS_H

#include <iostream>
#include <random>
#include <chrono>
#include <type_traits>

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

template<typename T>
class random_generator {
    using distribution_type = typename std::conditional<
            std::is_integral<T>::value,
            std::uniform_int_distribution<T>,
            std::uniform_real_distribution<T>
        >::type;

    int seed = std::chrono::steady_clock::now().time_since_epoch().count();
    T first{};
    T second{};

    std::default_random_engine engine{seed};
    distribution_type distribution{first, second};

public:
    random_generator(T ifirst, T isecond) : first{ifirst}, second{isecond} {}
    auto operator()() -> decltype(distribution(engine)) {
        return distribution(engine);
    }
};

template <typename T>
auto generate(T first, T second) -> decltype(random_generator<T>{first, second}()) {
    return random_generator<T>{first, second}();
}

} //helpers

} //ga

#endif // HELPERS_H
