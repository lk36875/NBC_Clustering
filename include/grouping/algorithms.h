#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <Dataset.h>
#include <vector>
#include <utility>
#include <GroupingSet.h>
#include <queue>
#include <algorithm>

namespace grouping
{
    std::pair<GroupingSet, std::pair<long long, long long>> nbc(Dataset dataset, int k, double (*metric)(GroupingSet, int, int, double), double categoricalScaling = 1.0);

    void calculateKPlusNeighbourhoods(GroupingSet &set, int k, double metric(GroupingSet, int, int, double), double categoricalScaling, double epsilon = 1.0 / 10000000);

    void buildGroup(GroupingSet &set, int seed, int classToAssign);
}
#endif
