#include "../genetic_algorithm.h"

using namespace testing;
using namespace ga;

class FitnessTest : public ::testing::Test
{
protected:
    Population pop{15,3,5};

};

TEST_F(FitnessTest, SumWorks)
{
    for(auto & ind : pop)
    {
        int res = 0;
        for(const auto & chrom : ind)
        {
            res += std::accumulate(chrom.begin(), chrom.end(), 0);
        }

        EXPECT_EQ(res, fit::sum(ind)) << "Sum of bits is not calculated properly";
    }
}

TEST_F(FitnessTest, IsResultPushedToFitnessValues)
{
    for(auto & ind : pop)
    {
        const auto result = fit::sum(ind);
        EXPECT_EQ(result, Statistics::get().fitness_values.back()) << "Result of fitness function has not been pushed to fitness_values vector properly";
    }
}
