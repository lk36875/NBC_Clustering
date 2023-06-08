#include <gtest/gtest.h>
#include <metrics.h>
#include <Dataset.h>
#include <GroupingSet.h>

TEST(manhattanVdmTests, calculateStringDifference)
{
    std::vector<std::string> datatypes{"int", "double", "bool", "string"};
    Dataset dataset = Dataset("../../data/test6.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);

    ASSERT_EQ(metrics::calculateCategoricalDifference<std::string>(set, 1, 5, 3, 1.0), 1.0 / 3);
}

TEST(manhattanVdmTests, calculateBoolDifference)
{
    std::vector<std::string> datatypes{"int", "double", "bool", "string"};
    Dataset dataset = Dataset("../../data/test6.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);

    ASSERT_EQ(metrics::calculateCategoricalDifference<bool>(set, 0, 5, 2, 1.0), 0);
}

TEST(manhattanVdmTests, calculateCategoricalIntDifference)
{
    std::vector<std::string> datatypes{"int", "double", "bool", "string"};
    Dataset dataset = Dataset("../../data/test6.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);

    ASSERT_EQ(metrics::calculateCategoricalDifference<int>(set, 1, 5, 0, 1.0), 0);
}

TEST(manhattanVdmTests, calculateNumericIntDifference)
{
    std::vector<std::string> datatypes{"int", "double", "bool", "string"};
    Dataset dataset = Dataset("../../data/test6.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);

    ASSERT_EQ(metrics::calculateNumericDifference<int>(set, 1, 5, 0), 1.0 / 3);
}

TEST(manhattanVdmTests, calculateIntDifference)
{
    std::vector<std::string> datatypes{"int", "double", "bool", "string"};
    Dataset dataset = Dataset("../../data/test6.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);

    ASSERT_EQ(metrics::calculateDifference<int>(set, 1, 5, 0, 1.0), 1.0 / 3);
}

TEST(manhattanVdmTests, calculateDoubleDifference)
{
    std::vector<std::string> datatypes{"int", "double", "bool", "string"};
    Dataset dataset = Dataset("../../data/test6.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);

    ASSERT_EQ(metrics::calculateNumericDifference<double>(set, 1, 5, 1), 0.2);
}

TEST(manhattanVdmTests, manhattanVdm)
{
    std::vector<std::string> datatypes{"int", "double", "bool", "string"};
    Dataset dataset = Dataset("../../data/test6.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);

    ASSERT_EQ(metrics::manhattanVdm(set, 1, 5), 0.2 + 2.0 / 3);
}

TEST(manhattanVdmTests, missingValues)
{
    std::vector<std::string> datatypes{"int", "string", "string"};
    Dataset dataset = Dataset("../../data/test_gower_NA_lecture_67.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);

    ASSERT_EQ(metrics::manhattanVdm(set, 1, 7), 3);
}

TEST(manhattanVdmTests, manhattanVdmScaling)
{
    std::vector<std::string> datatypes{"int", "double", "bool", "string"};
    Dataset dataset = Dataset("../../data/test6.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);

    ASSERT_EQ(metrics::manhattanVdm(set, 1, 5, 1.0 / 2), 1.0 / 3 + 0.2 + 1.0 / 6);
}
