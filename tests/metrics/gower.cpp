#include <gtest/gtest.h>
#include <metrics.h>
#include <Dataset.h>
#include <GroupingSet.h>

TEST(gowerTests, calculateNumericalDifference)
{
    std::vector<std::string> datatypes{"int", "double", "int", "bool", "string"};
    Dataset dataset = Dataset("../../data/test_gower.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);
    double numerator = 0;
    int denominator = 0;

    metrics::calculateNumericalDifference<int>(set, 0, 1, 0, numerator, denominator);

    ASSERT_EQ(numerator, 0.9);
    ASSERT_EQ(denominator, 1);

    double numerator2 = 0;
    int denominator2 = 0;

    metrics::calculateNumericalDifference<double>(set, 0, 1, 1, numerator2, denominator2);

    ASSERT_EQ(numerator2, 0.9);
    ASSERT_EQ(denominator2, 1);
}

TEST(gowerTests, calculateNominalDifference)
{
    std::vector<std::string> datatypes{"int", "double", "int", "bool", "string"};
    Dataset dataset = Dataset("../../data/test_gower.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);
    double numerator = 0;
    int denominator = 0;

    metrics::calculateNominalDifference(set, 0, 2, 4, numerator, denominator);

    ASSERT_EQ(numerator, 1);
    ASSERT_EQ(denominator, 1);

    double numerator2 = 0;
    int denominator2 = 0;

    metrics::calculateNominalDifference(set, 0, 1, 4, numerator2, denominator2);

    ASSERT_EQ(numerator2, 0);
    ASSERT_EQ(denominator2, 1);
}

TEST(gowerTests, calculateBinaryDifference)
{
    std::vector<std::string> datatypes{"int", "double", "int", "bool", "string"};
    Dataset dataset = Dataset("../../data/test_gower.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);
    double numerator = 0;
    int denominator = 0;

    metrics::calculateBinaryDifference(set, 0, 2, 2, numerator, denominator);

    ASSERT_EQ(numerator, 0);
    ASSERT_EQ(denominator, 1);

    double numerator2 = 0;
    int denominator2 = 0;

    metrics::calculateBinaryDifference(set, 0, 2, 3, numerator2, denominator2);

    ASSERT_EQ(numerator2, 0);
    ASSERT_EQ(denominator2, 1);
}

TEST(gowerTests, lectureNA67)
{
    std::vector<std::string> datatypes{"int", "string", "string"};
    Dataset dataset = Dataset("../../data/test_gower_NA_lecture_67.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);

    ASSERT_EQ(metrics::gower(set, 0, 6), 1 - 0.485);
    ASSERT_EQ(metrics::gower(set, 1, 6), 1 - 0.985);
    ASSERT_EQ(metrics::gower(set, 0, 7), 1 - 0);
    ASSERT_EQ(metrics::gower(set, 1, 7), 1 - 1);
}

TEST(gowerTests, lectureNA89)
{
    std::vector<std::string> datatypes{"int", "int", "string"};
    Dataset dataset = Dataset("../../data/test_gower_NA_lecture_89.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);

    ASSERT_EQ(metrics::gower(set, 0, 8), 1 - 1.97 / 2);
    ASSERT_EQ(metrics::gower(set, 1, 8), 1 - 0.97 / 2);
    ASSERT_EQ(metrics::gower(set, 1, 9), 1 - 0.97);
    ASSERT_EQ(metrics::gower(set, 2, 9), 1 - 0.77);
}

TEST(gowerTests, stringGower)
{
    std::vector<std::string> datatypes{"string", "string", "string"};
    Dataset dataset = Dataset("../../data/test_gower2.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);

    ASSERT_EQ(metrics::gower(set, 0, 1), 1 - (1 + 0 + 1) / 3.);
    ASSERT_EQ(metrics::gower(set, 0, 2), 1 - (0 + 1 + 1) / 3.);
    ASSERT_EQ(metrics::gower(set, 0, 3), 1 - (0 + 0 + 1) / 3.);
    ASSERT_EQ(metrics::gower(set, 1, 7), 1 - (1 + 0 + 0) / 3.);
    ASSERT_EQ(metrics::gower(set, 2, 7), 1 - (0 + 0 + 0) / 3.);
    ASSERT_EQ(metrics::gower(set, 3, 7), 1 - (0 + 0 + 0) / 3.);
}