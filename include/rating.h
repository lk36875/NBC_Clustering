#ifndef RATING_H
#define RATING_H

#include <GroupingSet.h>
#include <utility>

namespace rating
{

    double rand(GroupingSet groupingSet);

    int truePositives(GroupingSet groupingSet);

    int trueNegatives(GroupingSet groupingSet);

    int binomialCoefficient(const int n, const int k);

    // {truePositives, trueNegatives}
    std::pair<int, int> truePositivesAndTrueNegatives(GroupingSet groupingSet);
}

#endif
