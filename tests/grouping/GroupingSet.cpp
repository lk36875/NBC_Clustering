#include <gtest/gtest.h>
#include <GroupingSet.h>
#include <Dataset.h>
#include <vector>
#include <string>
#include <map>

TEST(groupingSetTests, constructor)
{
    std::vector<std::string> datatypes{"int", "double", "bool", "string"};
    Dataset dataset = Dataset("../../data/test.csv",
                              datatypes,
                              "NA", "csv");

    GroupingSet groupingSet = GroupingSet(dataset);

    ASSERT_TRUE(groupingSet.getSize() == 4);

    ASSERT_TRUE(groupingSet[0].getDatapoint().getParameterCount() == 4);
    ASSERT_TRUE(groupingSet[0].getDatapoint().getClass() == 1);

    ASSERT_TRUE(groupingSet[0].getDatapoint()[0].isNumeric());
    ASSERT_FALSE(groupingSet[0].getDatapoint()[0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(groupingSet[0].getDatapoint()[0].getValue()));
    ASSERT_TRUE(std::get<int>(groupingSet[0].getDatapoint()[0].getValue()) == 5);

    ASSERT_TRUE(groupingSet[0].getDatapoint()[1].isNumeric());
    ASSERT_FALSE(groupingSet[0].getDatapoint()[1].isMissing());
    ASSERT_TRUE(std::holds_alternative<double>(groupingSet[0].getDatapoint()[1].getValue()));
    ASSERT_TRUE(std::get<double>(groupingSet[0].getDatapoint()[1].getValue()) == 8.6);

    ASSERT_FALSE(groupingSet[0].getDatapoint()[2].isNumeric());
    ASSERT_FALSE(groupingSet[0].getDatapoint()[2].isMissing());
    ASSERT_TRUE(std::holds_alternative<bool>(groupingSet[0].getDatapoint()[2].getValue()));
    ASSERT_TRUE(std::get<bool>(groupingSet[0].getDatapoint()[2].getValue()));

    ASSERT_FALSE(groupingSet[0].getDatapoint()[3].isNumeric());
    ASSERT_FALSE(groupingSet[0].getDatapoint()[3].isMissing());
    ASSERT_TRUE(std::holds_alternative<std::string>(groupingSet[0].getDatapoint()[3].getValue()));
    ASSERT_TRUE(std::get<std::string>(groupingSet[0].getDatapoint()[3].getValue()) == "adas");

    ASSERT_TRUE(groupingSet[1].getDatapoint().getParameterCount() == 4);
    ASSERT_TRUE(groupingSet[1].getDatapoint().getClass() == 2);

    ASSERT_TRUE(groupingSet[1].getDatapoint()[0].isNumeric());
    ASSERT_FALSE(groupingSet[1].getDatapoint()[0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(groupingSet[1].getDatapoint()[0].getValue()));
    ASSERT_TRUE(std::get<int>(groupingSet[1].getDatapoint()[0].getValue()) == 2);

    ASSERT_TRUE(groupingSet[1].getDatapoint()[1].isNumeric());
    ASSERT_FALSE(groupingSet[1].getDatapoint()[1].isMissing());
    ASSERT_TRUE(std::holds_alternative<double>(groupingSet[1].getDatapoint()[1].getValue()));
    ASSERT_TRUE(std::get<double>(groupingSet[1].getDatapoint()[1].getValue()) == 12.5);

    ASSERT_FALSE(groupingSet[1].getDatapoint()[2].isNumeric());
    ASSERT_FALSE(groupingSet[1].getDatapoint()[2].isMissing());
    ASSERT_TRUE(std::holds_alternative<bool>(groupingSet[1].getDatapoint()[2].getValue()));
    ASSERT_FALSE(std::get<bool>(groupingSet[1].getDatapoint()[2].getValue()));

    ASSERT_FALSE(groupingSet[1].getDatapoint()[3].isNumeric());
    ASSERT_FALSE(groupingSet[1].getDatapoint()[3].isMissing());
    ASSERT_TRUE(std::holds_alternative<std::string>(groupingSet[1].getDatapoint()[3].getValue()));
    ASSERT_TRUE(std::get<std::string>(groupingSet[1].getDatapoint()[3].getValue()) == "sdfsdf");

    ASSERT_TRUE(groupingSet[2].getDatapoint().getParameterCount() == 4);
    ASSERT_TRUE(groupingSet[2].getDatapoint().getClass() == 1);

    ASSERT_TRUE(groupingSet[2].getDatapoint()[0].isNumeric());
    ASSERT_FALSE(groupingSet[2].getDatapoint()[0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(groupingSet[2].getDatapoint()[0].getValue()));
    ASSERT_TRUE(std::get<int>(groupingSet[2].getDatapoint()[0].getValue()) == 6);

    ASSERT_TRUE(groupingSet[2].getDatapoint()[1].isNumeric());
    ASSERT_FALSE(groupingSet[2].getDatapoint()[1].isMissing());
    ASSERT_TRUE(std::holds_alternative<double>(groupingSet[2].getDatapoint()[1].getValue()));
    ASSERT_TRUE(std::get<double>(groupingSet[2].getDatapoint()[1].getValue()) == 1234.124);

    ASSERT_FALSE(groupingSet[2].getDatapoint()[2].isNumeric());
    ASSERT_FALSE(groupingSet[2].getDatapoint()[2].isMissing());
    ASSERT_TRUE(std::holds_alternative<bool>(groupingSet[2].getDatapoint()[2].getValue()));
    ASSERT_FALSE(std::get<bool>(groupingSet[2].getDatapoint()[2].getValue()));

    ASSERT_FALSE(groupingSet[2].getDatapoint()[3].isNumeric());
    ASSERT_FALSE(groupingSet[2].getDatapoint()[3].isMissing());
    ASSERT_TRUE(std::holds_alternative<std::string>(groupingSet[2].getDatapoint()[3].getValue()));
    ASSERT_TRUE(std::get<std::string>(groupingSet[2].getDatapoint()[3].getValue()) == "wpigmpwom");

    ASSERT_TRUE(groupingSet[3].getDatapoint().getParameterCount() == 4);
    ASSERT_TRUE(groupingSet[3].getDatapoint().getClass() == 3);

    ASSERT_TRUE(groupingSet[3].getDatapoint()[0].isNumeric());
    ASSERT_FALSE(groupingSet[3].getDatapoint()[0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(groupingSet[3].getDatapoint()[0].getValue()));
    ASSERT_TRUE(std::get<int>(groupingSet[3].getDatapoint()[0].getValue()) == 10);

    ASSERT_TRUE(groupingSet[3].getDatapoint()[1].isNumeric());
    ASSERT_FALSE(groupingSet[3].getDatapoint()[1].isMissing());
    ASSERT_TRUE(std::holds_alternative<double>(groupingSet[3].getDatapoint()[1].getValue()));
    ASSERT_TRUE(std::get<double>(groupingSet[3].getDatapoint()[1].getValue()) == 141.3134);

    ASSERT_FALSE(groupingSet[3].getDatapoint()[2].isNumeric());
    ASSERT_FALSE(groupingSet[3].getDatapoint()[2].isMissing());
    ASSERT_TRUE(std::holds_alternative<bool>(groupingSet[3].getDatapoint()[2].getValue()));
    ASSERT_TRUE(std::get<bool>(groupingSet[3].getDatapoint()[2].getValue()));

    ASSERT_FALSE(groupingSet[3].getDatapoint()[3].isNumeric());
    ASSERT_FALSE(groupingSet[3].getDatapoint()[3].isMissing());
    ASSERT_TRUE(std::holds_alternative<std::string>(groupingSet[3].getDatapoint()[3].getValue()));
    ASSERT_TRUE(std::get<std::string>(groupingSet[3].getDatapoint()[3].getValue()) == "oawrngaoing");
}

TEST(groupingSetTests, countClassesByIntParameterValue)
{
    std::vector<std::string> datatypes{"int", "bool", "string"};
    Dataset dataset = Dataset("../../data/test5.csv",
                              datatypes,
                              "NA", "csv");

    GroupingSet groupingSet = GroupingSet(dataset);
    std::map<int, double> classesMap;
    double classesCount;
    std::tie(classesMap, classesCount) = groupingSet.countClassesByParameterValue<int>(5, 0);
    ASSERT_EQ(classesCount, 6);
    ASSERT_EQ(classesMap.size(), 3);
    ASSERT_TRUE(classesMap.contains(1));
    ASSERT_TRUE(classesMap.contains(2));
    ASSERT_TRUE(classesMap.contains(3));
    ASSERT_EQ(classesMap[1], 3);
    ASSERT_EQ(classesMap[2], 2);
    ASSERT_EQ(classesMap[3], 1);

    std::tie(classesMap, classesCount) = groupingSet.countClassesByParameterValue<int>(7, 0);
    ASSERT_EQ(classesCount, 8);
    ASSERT_EQ(classesMap.size(), 3);
    ASSERT_TRUE(classesMap.contains(1));
    ASSERT_TRUE(classesMap.contains(2));
    ASSERT_TRUE(classesMap.contains(3));
    ASSERT_EQ(classesMap[1], 3);
    ASSERT_EQ(classesMap[2], 3);
    ASSERT_EQ(classesMap[3], 2);
}

TEST(groupingSetTests, countClassesByBoolParameterValue)
{
    std::vector<std::string> datatypes{"int", "bool", "string"};
    Dataset dataset = Dataset("../../data/test5.csv",
                              datatypes,
                              "NA", "csv");

    GroupingSet groupingSet = GroupingSet(dataset);
    std::map<int, double> classesMap;
    double classesCount;
    std::tie(classesMap, classesCount) = groupingSet.countClassesByParameterValue<bool>(true, 1);
    ASSERT_EQ(classesCount, 6);
    ASSERT_EQ(classesMap.size(), 3);
    ASSERT_TRUE(classesMap.contains(1));
    ASSERT_TRUE(classesMap.contains(2));
    ASSERT_TRUE(classesMap.contains(3));
    ASSERT_EQ(classesMap[1], 3);
    ASSERT_EQ(classesMap[2], 2);
    ASSERT_EQ(classesMap[3], 1);

    std::tie(classesMap, classesCount) = groupingSet.countClassesByParameterValue<bool>(false, 1);
    ASSERT_EQ(classesCount, 8);
    ASSERT_EQ(classesMap.size(), 3);
    ASSERT_TRUE(classesMap.contains(1));
    ASSERT_TRUE(classesMap.contains(2));
    ASSERT_TRUE(classesMap.contains(3));
    ASSERT_EQ(classesMap[1], 3);
    ASSERT_EQ(classesMap[2], 3);
    ASSERT_EQ(classesMap[3], 2);
}

TEST(groupingSetTests, countClassesByStringParameterValue)
{
    std::vector<std::string> datatypes{"int", "bool", "string"};
    Dataset dataset = Dataset("../../data/test5.csv",
                              datatypes,
                              "NA", "csv");

    GroupingSet groupingSet = GroupingSet(dataset);
    std::map<int, double> classesMap;
    double classesCount;
    std::tie(classesMap, classesCount) = groupingSet.countClassesByParameterValue<std::string>("bank", 2);
    ASSERT_EQ(classesCount, 6);
    ASSERT_EQ(classesMap.size(), 3);
    ASSERT_TRUE(classesMap.contains(1));
    ASSERT_TRUE(classesMap.contains(2));
    ASSERT_TRUE(classesMap.contains(3));
    ASSERT_EQ(classesMap[1], 3);
    ASSERT_EQ(classesMap[2], 2);
    ASSERT_EQ(classesMap[3], 1);

    std::tie(classesMap, classesCount) = groupingSet.countClassesByParameterValue<std::string>("bonk", 2);
    ASSERT_EQ(classesCount, 8);
    ASSERT_EQ(classesMap.size(), 3);
    ASSERT_TRUE(classesMap.contains(1));
    ASSERT_TRUE(classesMap.contains(2));
    ASSERT_TRUE(classesMap.contains(3));
    ASSERT_EQ(classesMap[1], 3);
    ASSERT_EQ(classesMap[2], 3);
    ASSERT_EQ(classesMap[3], 2);
}

TEST(groupingSetTests, test0and1s)
{
    std::vector<std::string> datatypes{"int", "int", "int", "bool", "string"};
    Dataset dataset = Dataset("../../data/test8.csv",
                              datatypes,
                              "NA", "csv");

    GroupingSet groupingSet = GroupingSet(dataset);
    std::vector<bool> good_results_01 = {false, false, true, false, false};

    auto vec = groupingSet.getIsOnly0and1();
    for (auto i = 0; i < vec.size(); ++i)
    {
        ASSERT_EQ(vec[i], good_results_01[i]);
    }
}

TEST(groupingSetTests, testMinMax)
{
    std::vector<std::string> datatypes{"double", "int", "int", "bool", "string"};
    Dataset dataset = Dataset("../../data/test8.csv",
                              datatypes,
                              "NA", "csv");

    GroupingSet groupingSet = GroupingSet(dataset);
    std::vector<bool> good_results_01 = {true, false, true, false, false};

    std::vector<std::pair<double, double>> good_results_minmax;
    double negInf = -std::numeric_limits<double>::infinity();
    double posInf = std::numeric_limits<double>::infinity();
    good_results_minmax.resize(5, std::make_pair(negInf, posInf));
    good_results_minmax[0] = std::make_pair(0.1, 1230.1);
    good_results_minmax[1] = std::make_pair(0, 12);

    auto vec2 = groupingSet.getMinMaxValues();
    for (auto i = 0; i < vec2.size(); ++i)
    {
        ASSERT_EQ(vec2[i].first, good_results_minmax[i].first);
        ASSERT_EQ(vec2[i].second, good_results_minmax[i].second);
    }
}
