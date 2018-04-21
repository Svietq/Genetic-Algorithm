#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../genetic_algorithm.h"

using namespace testing;
using namespace ga;

TEST(Fitness, sum)
{
    auto pop = Population{15,3,5};
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
