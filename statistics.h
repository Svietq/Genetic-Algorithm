#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>

namespace ga
{

template <typename T>
class Statistics
{
    Statistics() {}
    Statistics(const Statistics &);
    Statistics & operator=(const Statistics &);

public:
    T pop_size;

    static Statistics & get()
    {
        static Statistics instance;
        return instance;
    }

    std::vector<T> fitness_values;
    void next_generation()
    {
        fitness_values.clear();
    }


};

} //ga



#endif // STATISTICS_H
