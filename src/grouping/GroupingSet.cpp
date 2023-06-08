#include <GroupingSet.h>
#include <limits>
#include <vector>
#include <utility>

GroupingSet::GroupingSet(Dataset dataset)
{
    for (Datapoint point : dataset)
    {
        points.push_back(GroupingPoint(point));
    }

    double negInf = -std::numeric_limits<double>::infinity();
    double posInf = std::numeric_limits<double>::infinity();
    int length = points[0].getDatapoint().getParameterCount();
    minMaxValues.resize(length, std::make_pair(negInf, posInf));
    isOnly0and1.resize(length, false);

    // check 0 and 1, then check for double and ints in the rest of groupingset

    for (int param = 0; param < points[0].getDatapoint().getParameterCount(); ++param)
    {
        if (std::holds_alternative<int>(points[0].getDatapoint()[param].getValue(true)))
        {
            isOnly0and1[param] = only0and1(param);
        }
    }

    // calculate minmax
    for (int param = 0; param < points[0].getDatapoint().getParameterCount(); ++param)
    {
        if (isOnly0and1[param] == true)
        {
            continue;
        }
        if (std::holds_alternative<int>(points[0].getDatapoint()[param].getValue(true)))
        {
            minMaxValues[param] = calculateMinMax<int>(param);
        }
        else if (std::holds_alternative<double>(points[0].getDatapoint()[param].getValue(true)))
        {
            minMaxValues[param] = calculateMinMax<double>(param);
        }
    }
}

GroupingSet::~GroupingSet(){};

GroupingPoint &GroupingSet::operator[](int index)
{
    return points[index];
}

int GroupingSet::getSize()
{
    return points.size();
}

std::vector<GroupingPoint>::iterator GroupingSet::begin()
{
    return points.begin();
}

std::vector<GroupingPoint>::iterator GroupingSet::end()
{
    return points.end();
}

bool GroupingSet::only0and1(int parameter)
{
    for (GroupingPoint point : points)
    {
        if (point.getDatapoint()[parameter].isMissing())
        {
            continue;
        }
        int value = std::get<int>(point.getDatapoint()[parameter].getValue());
        if (value != 1 and value != 0)
        {
            return false;
        }
    }
    return true;
}

template <typename T>
std::pair<double, double> GroupingSet::calculateMinMax(int parameter)
{
    double maxVal = -std::numeric_limits<double>::infinity();
    double minVal = std::numeric_limits<double>::infinity();

    for (GroupingPoint point : points)
    {
        auto param = point.getDatapoint()[parameter];
        if (param.isMissing())
        {
            continue;
        }
        T value = std::get<T>(param.getValue());
        if (value < minVal)
        {
            minVal = value;
        }
        if (value > maxVal)
        {
            maxVal = value;
        }
    }

    return std::make_pair(minVal, maxVal);
}

std::vector<std::pair<double, double>> GroupingSet::getMinMaxValues()
{
    return minMaxValues;
}

std::vector<bool> GroupingSet::getIsOnly0and1()
{
    return isOnly0and1;
}