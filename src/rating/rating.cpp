#include <rating.h>
#include <vector>
#include <GroupingSet.h>
#include <GroupingPoint.h>
#include <algorithm>

namespace rating
{

    double rand(GroupingSet groupingSet)
    {
        int truePositives, trueNegatives;
        std::tie(truePositives, trueNegatives) = truePositivesAndTrueNegatives(groupingSet);
        return (static_cast<double>(truePositives) + trueNegatives) /
               (groupingSet.getSize() >= 2 ? binomialCoefficient(groupingSet.getSize(), 2) : 0);
    }

    int truePositives(GroupingSet groupingSet)
    {
        return std::get<0>(truePositivesAndTrueNegatives(groupingSet));
    }

    int trueNegatives(GroupingSet groupingSet)
    {
        return std::get<1>(truePositivesAndTrueNegatives(groupingSet));
    }

    std::pair<int, int> truePositivesAndTrueNegatives(GroupingSet groupingSet)
    {
        int numberOfReferenceClasses = (*std::max_element(groupingSet.begin(), groupingSet.end(), [](GroupingPoint x, GroupingPoint y) -> bool
                                                          { return x.getDatapoint().getClass() < y.getDatapoint().getClass(); }))
                                           .getDatapoint()
                                           .getClass() +
                                       1;
        int numberOfAssignedClasses = (*std::max_element(groupingSet.begin(), groupingSet.end(), [](GroupingPoint x, GroupingPoint y) -> bool
                                                         { return x.getAssignedClass() < y.getAssignedClass(); }))
                                          .getAssignedClass() +
                                      1;
        std::vector<std::vector<int>> clusteringMatrix(numberOfAssignedClasses + 1, std::vector<int>(numberOfReferenceClasses, 0));
        for (GroupingPoint point : groupingSet)
        {
            clusteringMatrix[(point.getAssignedClass() + clusteringMatrix.size()) % clusteringMatrix.size()]
                            [(point.getDatapoint().getClass() + clusteringMatrix.size()) % clusteringMatrix.size()]++;
        }
        int truePositives = 0;
        std::vector<int> rowTotals(numberOfReferenceClasses, 0);
        std::vector<int> columnTotals(numberOfAssignedClasses + 1, 0);
        for (int i = 0; i < clusteringMatrix.size(); ++i)
        {
            for (int j = 0; j < clusteringMatrix[0].size(); ++j)
            {
                truePositives += clusteringMatrix[i][j] >= 2 ? binomialCoefficient(clusteringMatrix[i][j], 2) : 0;
                rowTotals[j] += clusteringMatrix[i][j];
                columnTotals[i] += clusteringMatrix[i][j];
            }
        }
        int truePositivesPlusFalsePositives = 0;
        for (int value : rowTotals)
        {
            truePositivesPlusFalsePositives += value >= 2 ? binomialCoefficient(value, 2) : 0;
        }
        int truePositivesPlusFalseNegatives = 0;
        for (int value : columnTotals)
        {
            truePositivesPlusFalseNegatives += value >= 2 ? binomialCoefficient(value, 2) : 0;
        }
        int allPairs = groupingSet.getSize() >= 2 ? binomialCoefficient(groupingSet.getSize(), 2) : 0;
        int trueNegatives = allPairs - truePositivesPlusFalsePositives - truePositivesPlusFalseNegatives + truePositives;
        return {truePositives, trueNegatives};
    }

    int binomialCoefficient(const int n, const int k)
    {
        std::vector<int> aSolutions(k);
        aSolutions[0] = n - k + 1;

        for (int i = 1; i < k; ++i)
        {
            aSolutions[i] = aSolutions[i - 1] * (n - k + 1 + i) / (i + 1);
        }

        return aSolutions[k - 1];
    }
}
