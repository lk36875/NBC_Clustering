#include <metrics.h>
#include <iostream>

namespace metrics
{

    double gower(GroupingSet dataset, int x, int y, double unused)
    {
        double numerator = 0;
        int denominator = 0;

        for (int i = 0; i < dataset[0].getDatapoint().getParameterCount(); ++i)
        {
            // missing
            if (dataset[x].getDatapoint()[i].isMissing() || dataset[y].getDatapoint()[i].isMissing())
            {
                continue;
            }
            // check data type
            auto datapointVal = dataset[x].getDatapoint()[i].getValue();
            if (std::holds_alternative<double>(datapointVal))
            {
                calculateNumericalDifference<double>(dataset, x, y, i, numerator, denominator);
            }
            else if (std::holds_alternative<std::string>(datapointVal))
            {
                calculateNominalDifference(dataset, x, y, i, numerator, denominator);
            }
            else if (std::holds_alternative<bool>(datapointVal) || std::holds_alternative<int>(datapointVal))
            {
                calculateBinaryDifference(dataset, x, y, i, numerator, denominator);
            }
        }

        // 1-gower
        if (denominator == 0)
        {
            return 1;
        }
        return 1 - numerator / denominator;
    }

    template <typename T>
    void calculateNumericalDifference(GroupingSet dataset, int x, int y, int i, double &numerator, int &denominator)
    {
        auto dataPoint1 = dataset[x].getDatapoint()[i];
        auto dataPoint2 = dataset[y].getDatapoint()[i];
        // xval, yval are not missing
        double xValue = getDouble<T>(dataPoint1.getValue());
        double yValue = getDouble<T>(dataPoint2.getValue());

        auto minMaxVec = dataset.getMinMaxValues();
        double minimum = minMaxVec[i].first;
        double maximum = minMaxVec[i].second;

        if ((maximum - minimum) != 0)
        {
            numerator += (1 - (std::abs(xValue - yValue) / (maximum - minimum)));
        }
        else
        {
            numerator += 1;
        }
        denominator++;
    };

    void calculateNominalDifference(GroupingSet dataset, int x, int y, int i, double &numerator, int &denominator)
    {
        std::string xValue = std::get<std::string>(dataset[x].getDatapoint()[i].getValue());
        std::string yValue = std::get<std::string>(dataset[y].getDatapoint()[i].getValue());
        if (xValue == yValue)
        {
            numerator++;
        }
        denominator++;
    };
    void calculateBinaryDifference(GroupingSet dataset, int x, int y, int i, double &numerator, int &denominator)
    {
        const auto &value1 = dataset[x].getDatapoint()[i].getValue();
        if (!isBinary(value1, dataset, i))
        {
            calculateNumericalDifference<int>(dataset, x, y, i, numerator, denominator);
        }
        else
        {
            const auto &value2 = dataset[y].getDatapoint()[i].getValue();
            int xValue = getInt(value1);
            int yValue = getInt(value2);
            if (xValue == 1 && yValue == 1)
            {
                numerator++;
                denominator++;
            }
            else if (xValue == 1 || yValue == 1)
            {
                denominator++;
            }
        }
    };

    template <typename T>
    double getDouble(parameterType value)
    {
        return static_cast<double>(std::get<T>(value));
    }

    bool isBinary(parameterType value, GroupingSet dataset, int parameter)
    {
        if (std::holds_alternative<int>(value))
        {
            return dataset.getIsOnly0and1()[parameter];
        }
        return true;
    }

    int getInt(parameterType value)
    {
        int result;
        if (std::holds_alternative<int>(value))
        {
            int &int_value = std::get<int>(value);
            result = int_value;
        }
        else if (std::holds_alternative<bool>(value))
        {
            bool &bool_value = std::get<bool>(value);
            result = static_cast<int>(bool_value);
        }
        return result;
    }

}
