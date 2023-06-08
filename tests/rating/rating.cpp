#include <gtest/gtest.h>
#include <rating.h>

TEST(ratingTests, binomialCoefficient)
{
    ASSERT_EQ(rating::binomialCoefficient(5, 2), 10);
    ASSERT_EQ(rating::binomialCoefficient(23, 5), 33649);
}

TEST(ratingTests, truePositivesAndTrueNegatives)
{
    std::vector<std::string> datatypes{"int"};
    Dataset dataset = Dataset("../../data/test7.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);

    set[0].assignClass(0);
    set[1].assignClass(0);
    set[2].assignClass(0);
    set[3].assignClass(0);
    set[4].assignClass(0);
    set[5].assignClass(1);
    set[6].assignClass(2);
    set[7].assignClass(2);
    set[8].assignClass(0);
    set[9].assignClass(1);
    set[10].assignClass(1);
    set[11].assignClass(1);
    set[12].assignClass(1);
    set[13].assignClass(1);
    set[14].assignClass(2);
    set[15].assignClass(2);
    set[16].assignClass(2);

    int truePositives, trueNegatives;
    std::tie(truePositives, trueNegatives) = rating::truePositivesAndTrueNegatives(set);

    ASSERT_EQ(truePositives, 20);
    ASSERT_EQ(trueNegatives, 72);
}

TEST(ratingTests, truePositives)
{
    std::vector<std::string> datatypes{"int"};
    Dataset dataset = Dataset("../../data/test7.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);

    set[0].assignClass(0);
    set[1].assignClass(0);
    set[2].assignClass(0);
    set[3].assignClass(0);
    set[4].assignClass(0);
    set[5].assignClass(1);
    set[6].assignClass(2);
    set[7].assignClass(2);
    set[8].assignClass(0);
    set[9].assignClass(1);
    set[10].assignClass(1);
    set[11].assignClass(1);
    set[12].assignClass(1);
    set[13].assignClass(1);
    set[14].assignClass(2);
    set[15].assignClass(2);
    set[16].assignClass(2);

    ASSERT_EQ(rating::truePositives(set), 20);
}

TEST(ratingTests, trueNegatives)
{
    std::vector<std::string> datatypes{"int"};
    Dataset dataset = Dataset("../../data/test7.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);

    set[0].assignClass(0);
    set[1].assignClass(0);
    set[2].assignClass(0);
    set[3].assignClass(0);
    set[4].assignClass(0);
    set[5].assignClass(1);
    set[6].assignClass(2);
    set[7].assignClass(2);
    set[8].assignClass(0);
    set[9].assignClass(1);
    set[10].assignClass(1);
    set[11].assignClass(1);
    set[12].assignClass(1);
    set[13].assignClass(1);
    set[14].assignClass(2);
    set[15].assignClass(2);
    set[16].assignClass(2);

    ASSERT_EQ(rating::trueNegatives(set), 72);
}

TEST(ratingTests, rand)
{
    std::vector<std::string> datatypes{"int"};
    Dataset dataset = Dataset("../../data/test7.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);

    set[0].assignClass(0);
    set[1].assignClass(0);
    set[2].assignClass(0);
    set[3].assignClass(0);
    set[4].assignClass(0);
    set[5].assignClass(1);
    set[6].assignClass(2);
    set[7].assignClass(2);
    set[8].assignClass(0);
    set[9].assignClass(1);
    set[10].assignClass(1);
    set[11].assignClass(1);
    set[12].assignClass(1);
    set[13].assignClass(1);
    set[14].assignClass(2);
    set[15].assignClass(2);
    set[16].assignClass(2);

    ASSERT_EQ(rating::rand(set), 92.0 / 136);
}

TEST(ratingTests, noisePoints)
{
    std::vector<std::string> datatypes{"int"};
    Dataset dataset = Dataset("../../data/test7.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);

    set[0].assignClass(0);
    set[1].assignClass(0);
    set[2].assignClass(0);
    set[3].assignClass(0);
    set[4].assignClass(0);
    set[5].assignClass(1);
    set[6].assignClass(-1);
    set[7].assignClass(-1);
    set[8].assignClass(0);
    set[9].assignClass(1);
    set[10].assignClass(1);
    set[11].assignClass(1);
    set[12].assignClass(1);
    set[13].assignClass(1);
    set[14].assignClass(-1);
    set[15].assignClass(-1);
    set[16].assignClass(-1);

    ASSERT_EQ(rating::rand(set), 92.0 / 136);
}
