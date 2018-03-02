#include <iostream>
#include "genetic_algorithm.h"

using namespace ga::sel;

int main()
{
//    ga::sel::Selection<int>::create(ga::sel::Selection<int>::Method::Deterministic, 5);

    Selection<Roulette>{};
}
