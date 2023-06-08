#ifndef METRICS_H
#define METRICS_H

#include <GroupingSet.h>
#include <algorithm>
#include <cmath>
#include <map>

namespace metrics
{

    double manhattanVdm(GroupingSet dataset, int index1, int index2, double categoricalScaling = 1.0);

    // Template only allows arithmetic types (integer, floating point, etc.)
    template <typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type * = nullptr>
    double calculateNumericDifference(GroupingSet dataset, int x, int y, int parameter);

    template <typename T>
    double calculateCategoricalDifference(GroupingSet dataset, int x, int y, int parameter, double scaling);

    template <typename T>
    double calculateDifference(GroupingSet dataset, int x, int y, int parameter, double categoricalScaling);

    double gower(GroupingSet dataset, int index1, int index2, double unused = 0);

    template <typename T>
    void calculateNumericalDifference(GroupingSet dataset, int x, int y, int i, double &numerator, int &denominator);

    void calculateNominalDifference(GroupingSet dataset, int x, int y, int i, double &numerator, int &denominator);

    void calculateBinaryDifference(GroupingSet dataset, int x, int y, int i, double &numerator, int &denominator);

    template <typename T>
    double getDouble(parameterType value);
    bool isBinary(parameterType value, GroupingSet dataset, int parameter);
    int getInt(parameterType value);

}

#endif