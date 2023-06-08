#include <algorithms.h>
#include <chrono>
#include <iostream>
using namespace std::chrono;

namespace grouping
{

    std::pair<GroupingSet, std::pair<long long, long long>> nbc(Dataset dataset, int k, double metric(GroupingSet, int, int, double), double categoricalScaling)
    {
        auto timer_kpnn_start = std::chrono::steady_clock::now();
        GroupingSet workingSet = GroupingSet(dataset);
        calculateKPlusNeighbourhoods(workingSet, k, metric, categoricalScaling);
        auto timer_kpnn_end = std::chrono::steady_clock::now();

        auto timer_grouping_start = std::chrono::steady_clock::now();
        int currentlyAssignedClass = 1;
        for (int i = 0; i < workingSet.getSize(); ++i)
        {
            if (workingSet[i].getAssignedClass() == -2)
            {
                if (workingSet[i].getNdfRatio() >= 1.0)
                {
                    buildGroup(workingSet, i, currentlyAssignedClass);
                    currentlyAssignedClass++;
                }
                else
                {
                    workingSet[i].assignClass(-1);
                }
            }
        }
        auto timer_grouping_end = std::chrono::steady_clock::now();

        long long timer_grouping_duration = std::chrono::duration_cast<std::chrono::milliseconds>(timer_grouping_end - timer_grouping_start).count();
        long long timer_kpnn_duration = std::chrono::duration_cast<std::chrono::milliseconds>(timer_kpnn_end - timer_kpnn_start).count();
        return std::make_pair(workingSet, std::make_pair(timer_kpnn_duration, timer_grouping_duration));
    }

    void calculateKPlusNeighbourhoods(GroupingSet &set, int k, double metric(GroupingSet, int, int, double), double categoricalScaling, double epsilon)
    {
        for (int i = 0; i < set.getSize(); ++i)
        {
            std::vector<std::pair<int, double>> distances;
            for (int j = 0; j < set.getSize(); ++j)
            {
                if (i != j)
                {
                    distances.push_back(std::make_pair(j, metric(set, i, j, categoricalScaling)));
                    set[i].incrementNumberOfDistanceCalculations();
                    set[j].incrementNumberOfDistanceCalculations();
                }
            }
            std::sort(distances.begin(), distances.end(), [](std::pair<int, double> x, std::pair<int, double> y) -> bool
                      { return std::get<1>(x) < std::get<1>(y); });
            int j = 0;
            while (std::get<1>(distances[j]) < std::get<1>(distances[k - 1]) ||
                   (std::abs(std::get<1>(distances[j]) - std::get<1>(distances[k - 1])) < epsilon))
            { // Less or equal
                set[i].addNeighbour(std::get<0>(distances[j]));
                set[std::get<0>(distances[j])].incrementReverseKPlusNeighbourhoodSize();
                j++;
            }
            set[i].setDistanceToFurthestNeighbour(std::get<1>(distances[j - 1]));
            set[i].setDistanceToFurthestPoint(std::get<1>(distances[distances.size() - 1]));
        }
        for (GroupingPoint &point : set)
        {
            point.calculateNdfRatio();
        }
    }

    void buildGroup(GroupingSet &set, int seed, int classToAssign)
    {
        std::queue<int> seeds;
        set[seed].assignClass(classToAssign);
        seeds.push(seed);
        while (!seeds.empty())
        {
            if (set[seeds.front()].getNdfRatio() >= 1)
            {
                for (int neighbour : set[seeds.front()].getKPlusNeighbourhood())
                {
                    if (set[neighbour].getAssignedClass() == -2)
                    {
                        set[neighbour].assignClass(classToAssign);
                        seeds.push(neighbour);
                    }
                    else if (set[neighbour].getAssignedClass() == -1)
                    {
                        set[neighbour].assignClass(classToAssign);
                    }
                }
            }
            seeds.pop();
        }
    }
}
