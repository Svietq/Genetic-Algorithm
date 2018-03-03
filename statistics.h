#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>

namespace ga
{

template <typename T>
class Statistics
{
    Statistics() {}
    Statistics(const Statistics&);
    Statistics& operator=(const Statistics&);

public:
    static Statistics& get()
    {
        static Statistics instance;
        return instance;
    }

    std::vector<T> fitness_values;
};

} //ga



#endif // STATISTICS_H
