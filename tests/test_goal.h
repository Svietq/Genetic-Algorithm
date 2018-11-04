#include "../genetic_algorithm.h"

using namespace testing;
using namespace ga;

class GoalTest : public ::testing::Test
{
protected:
    const int desired_cost = 50;
    Population pop{15,3,5};
    Goal goal{desired_cost};

};

TEST_F(GoalTest, CheckCost)
{
    const auto sum_of_fitness_values = std::accumulate(Statistics::get().fitness_values.begin(), Statistics::get().fitness_values.end(), 0);
    bool goal_result = goal(pop);
    EXPECT_EQ(goal_result, desired_cost>=sum_of_fitness_values) << "Cost is not checked properly";
}
