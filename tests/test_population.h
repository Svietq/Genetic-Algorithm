#include "../genetic_algorithm.h"

using namespace testing;
using namespace ga;

class PopulationTest : public ::testing::Test
{
protected:
    Population pop{15,3,5};

};

TEST_F(PopulationTest, CheckPopulationSizes)
{
    EXPECT_EQ(pop.size(), 15) << "Number of individuals is not set properly";
    for(const auto & ind : pop)
    {
        ASSERT_EQ(ind.size(), 3) << "Number of chromosomes is not set properly";
        for(const auto & chrom : ind)
        {
            ASSERT_EQ(chrom.size(), 5) << "Number of bits is not set properly";
        }
    }
}

TEST_F(PopulationTest, CheckBitsValues)
{
    for(const auto & ind : pop)
    {
        for(const auto & chrom : ind)
        {
            for(auto bit : chrom)
            {
                ASSERT_TRUE( bit==0 || bit==1 ) << "Wrong value of a bit";
            }
        }
    }
}
