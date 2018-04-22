#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>

namespace ga
{

template <typename T>
class Basic_Statistics
{
    Basic_Statistics() {}
    Basic_Statistics(const Basic_Statistics &);
    Basic_Statistics & operator=(const Basic_Statistics &);

public:
    T pop_size;

    static Basic_Statistics & get()
    {
        static Basic_Statistics instance;
        return instance;
    }

    std::vector<T> fitness_values;
    void next_generation()
    {
        fitness_values.clear();
    }


};

using Statistics = Basic_Statistics<int>;

} //ga



#endif // STATISTICS_H
