#ifndef GROUPINGSET_H
#define GROUPINGSET_H

#include <Dataset.h>
#include <GroupingPoint.h>
#include <Datapoint.h>
#include <vector>
#include <iostream>
#include <map>

class GroupingSet
{

public:
    GroupingSet(Dataset dataset);
    ~GroupingSet();
    GroupingPoint &operator[](int index);
    int getSize();
    std::vector<GroupingPoint>::iterator begin();
    std::vector<GroupingPoint>::iterator end();
    bool only0and1(int parameter);
    template <typename T>
    std::pair<double, double> calculateMinMax(int parameter);

    std::vector<std::pair<double, double>> getMinMaxValues();
    std::vector<bool> getIsOnly0and1();

    // Template must be defined in header, otherwise compiler gets confused
    template <typename T>
    std::pair<std::map<int, double>, double> countClassesByParameterValue(T value, int parameter)
    {
        std::map<int, double> classesCount;
        double totalCount = 0;
        for (GroupingPoint point : points)
        {
            if (!classesCount.contains(point.getDatapoint().getClass()))
            {
                classesCount.insert({point.getDatapoint().getClass(), 0});
            }
            if (!point.getDatapoint()[parameter].isMissing() && std::get<T>(point.getDatapoint()[parameter].getValue()) == value)
            {
                totalCount++;
                classesCount[point.getDatapoint().getClass()]++;
            }
        }
        return {classesCount, totalCount};
    }

private:
    std::vector<GroupingPoint> points;
    std::vector<std::pair<double, double>> minMaxValues;
    std::vector<bool> isOnly0and1;
};

#endif
