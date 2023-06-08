#include <metrics.h>

namespace metrics
{

    double manhattanVdm(GroupingSet dataset, int x, int y, double categoricalScaling)
    {
        double distance = 0;
        for (int i = 0; i < dataset[0].getDatapoint().getParameterCount(); ++i)
        {
            if (std::holds_alternative<double>(dataset[0].getDatapoint()[i].getValue()))
            {
                distance += calculateDifference<double>(dataset, x, y, i, categoricalScaling);
            }
            else if (std::holds_alternative<int>(dataset[0].getDatapoint()[i].getValue()))
            {
                distance += calculateDifference<int>(dataset, x, y, i, categoricalScaling);
            }
            else if (std::holds_alternative<bool>(dataset[0].getDatapoint()[i].getValue()))
            {
                distance += calculateCategoricalDifference<bool>(dataset, x, y, i, categoricalScaling);
            }
            else
            {
                distance += calculateCategoricalDifference<std::string>(dataset, x, y, i, categoricalScaling);
            }
        }
        return distance;
    }

    template <typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type *>
    double calculateNumericDifference(GroupingSet dataset, int x, int y, int parameter)
    {
        if (dataset[x].getDatapoint()[parameter].isMissing() || dataset[y].getDatapoint()[parameter].isMissing())
        {
            return 1.0;
        }
        double xValue = static_cast<double>(std::get<T>(dataset[x].getDatapoint()[parameter].getValue()));
        double yValue = static_cast<double>(std::get<T>(dataset[y].getDatapoint()[parameter].getValue()));
        auto minMaxVec = dataset.getMinMaxValues();
        double minimum = minMaxVec[parameter].first;
        double maximum = minMaxVec[parameter].second;
        return std::abs((xValue - yValue) / (maximum - minimum));
    }

    template <typename T>
    double calculateCategoricalDifference(GroupingSet dataset, int x, int y, int parameter, double scaling)
    {
        if (dataset[x].getDatapoint()[parameter].isMissing() || dataset[y].getDatapoint()[parameter].isMissing())
        {
            return 2.0;
        }
        std::map<int, double> xClassesCount, yClassesCount;
        double xTotalCount, yTotalCount;
        std::tie(xClassesCount, xTotalCount) = dataset.countClassesByParameterValue<T>(std::get<T>(dataset[x].getDatapoint()[parameter].getValue()), parameter);
        std::tie(yClassesCount, yTotalCount) = dataset.countClassesByParameterValue<T>(std::get<T>(dataset[y].getDatapoint()[parameter].getValue()), parameter);
        double difference = 0;
        for (std::pair<int, int> keyValuePair : xClassesCount)
        {
            difference += std::abs(std::get<1>(keyValuePair) / xTotalCount - yClassesCount[std::get<0>(keyValuePair)] / yTotalCount);
        }
        return difference * scaling;
    }

    template <typename T>
    double calculateDifference(GroupingSet dataset, int x, int y, int parameter, double categoricalDifference)
    {
        return dataset[0].getDatapoint()[parameter].isNumeric() ? calculateNumericDifference<T>(dataset, x, y, parameter)
                                                                : calculateCategoricalDifference<T>(dataset, x, y, parameter, categoricalDifference);
    }
}
