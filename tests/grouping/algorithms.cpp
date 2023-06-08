#include <gtest/gtest.h>
#include <Dataset.h>
#include <GroupingSet.h>
#include <algorithms.h>
#include <metrics.h>

double euclideanDistance(GroupingSet dataset, int x, int y, double unused)
{
    double distance = 0;
    for (int i = 0; i < dataset[0].getDatapoint().getParameterCount(); ++i)
    {
        double temp = std::get<double>(dataset[x].getDatapoint()[i].getValue());
        temp -= std::get<double>(dataset[y].getDatapoint()[i].getValue());
        distance += (temp * temp);
    }
    return std::sqrt(distance);
}

TEST(groupingTests, calculateKPlusNeighbourhoods)
{
    std::vector<std::string> datatypes{"double", "double"};
    Dataset dataset = Dataset("../../data/lecture_data.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);

    grouping::calculateKPlusNeighbourhoods(set, 3, euclideanDistance, 1);

    ASSERT_EQ(set[0].getKPlusNeighbourhoodSize(), 3);
    ASSERT_EQ(set[0].getReverseKPlusNeighbourhoodSize(), 2);
    ASSERT_EQ(set[0].getNdfRatio(), 2.0 / 3);
    ASSERT_EQ(set[0].getNumberOfDistanceCalculations(), (set.getSize() - 1) * 2);
    double difference = std::abs(set[0].getDistanceToFurthestNeighbour() - 2.69072);
    ASSERT_TRUE(difference < 0.00001);
    difference = std::abs(set[0].getDistanceToFurthestPoint() - 8.25409);
    ASSERT_TRUE(difference < 0.00001);
    ASSERT_TRUE(std::find(set[0].getKPlusNeighbourhood().begin(),
                          set[0].getKPlusNeighbourhood().end(), 2) !=
                set[0].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[0].getKPlusNeighbourhood().begin(),
                          set[0].getKPlusNeighbourhood().end(), 1) !=
                set[0].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[0].getKPlusNeighbourhood().begin(),
                          set[0].getKPlusNeighbourhood().end(), 7) !=
                set[0].getKPlusNeighbourhood().end());

    ASSERT_EQ(set[1].getKPlusNeighbourhoodSize(), 3);
    ASSERT_EQ(set[1].getReverseKPlusNeighbourhoodSize(), 1);
    ASSERT_EQ(set[1].getNdfRatio(), 1.0 / 3);
    ASSERT_EQ(set[1].getNumberOfDistanceCalculations(), (set.getSize() - 1) * 2);
    difference = std::abs(set[1].getDistanceToFurthestNeighbour() - 3.98246);
    ASSERT_TRUE(difference < 0.00001);
    difference = std::abs(set[1].getDistanceToFurthestPoint() - 6.63099);
    ASSERT_TRUE(difference < 0.00001);
    ASSERT_TRUE(std::find(set[1].getKPlusNeighbourhood().begin(),
                          set[1].getKPlusNeighbourhood().end(), 0) !=
                set[1].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[1].getKPlusNeighbourhood().begin(),
                          set[1].getKPlusNeighbourhood().end(), 2) !=
                set[1].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[1].getKPlusNeighbourhood().begin(),
                          set[1].getKPlusNeighbourhood().end(), 7) !=
                set[1].getKPlusNeighbourhood().end());

    ASSERT_EQ(set[2].getKPlusNeighbourhoodSize(), 3);
    ASSERT_EQ(set[2].getReverseKPlusNeighbourhoodSize(), 3);
    ASSERT_EQ(set[2].getNdfRatio(), 1);
    ASSERT_EQ(set[2].getNumberOfDistanceCalculations(), (set.getSize() - 1) * 2);
    difference = std::abs(set[2].getDistanceToFurthestNeighbour() - 1.772);
    ASSERT_TRUE(difference < 0.00001);
    difference = std::abs(set[2].getDistanceToFurthestPoint() - 9.45939);
    ASSERT_TRUE(difference < 0.00001);
    ASSERT_TRUE(std::find(set[2].getKPlusNeighbourhood().begin(),
                          set[2].getKPlusNeighbourhood().end(), 0) !=
                set[2].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[2].getKPlusNeighbourhood().begin(),
                          set[2].getKPlusNeighbourhood().end(), 7) !=
                set[2].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[2].getKPlusNeighbourhood().begin(),
                          set[2].getKPlusNeighbourhood().end(), 5) !=
                set[2].getKPlusNeighbourhood().end());

    ASSERT_EQ(set[3].getKPlusNeighbourhoodSize(), 3);
    ASSERT_EQ(set[3].getReverseKPlusNeighbourhoodSize(), 3);
    ASSERT_EQ(set[3].getNdfRatio(), 1);
    ASSERT_EQ(set[3].getNumberOfDistanceCalculations(), (set.getSize() - 1) * 2);
    difference = std::abs(set[3].getDistanceToFurthestNeighbour() - 2.0);
    ASSERT_TRUE(difference < 0.00001);
    difference = std::abs(set[3].getDistanceToFurthestPoint() - 12.0503);
    ASSERT_TRUE(difference < 0.0001);
    ASSERT_TRUE(std::find(set[3].getKPlusNeighbourhood().begin(),
                          set[3].getKPlusNeighbourhood().end(), 8) !=
                set[3].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[3].getKPlusNeighbourhood().begin(),
                          set[3].getKPlusNeighbourhood().end(), 9) !=
                set[3].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[3].getKPlusNeighbourhood().begin(),
                          set[3].getKPlusNeighbourhood().end(), 4) !=
                set[3].getKPlusNeighbourhood().end());

    ASSERT_EQ(set[4].getKPlusNeighbourhoodSize(), 3);
    ASSERT_EQ(set[4].getReverseKPlusNeighbourhoodSize(), 3);
    ASSERT_EQ(set[4].getNdfRatio(), 1);
    ASSERT_EQ(set[4].getNumberOfDistanceCalculations(), (set.getSize() - 1) * 2);
    difference = std::abs(set[4].getDistanceToFurthestNeighbour() - 2.0);
    ASSERT_TRUE(difference < 0.00001);
    difference = std::abs(set[4].getDistanceToFurthestPoint() - 10.0603);
    ASSERT_TRUE(difference < 0.0001);
    ASSERT_TRUE(std::find(set[4].getKPlusNeighbourhood().begin(),
                          set[4].getKPlusNeighbourhood().end(), 9) !=
                set[4].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[4].getKPlusNeighbourhood().begin(),
                          set[4].getKPlusNeighbourhood().end(), 8) !=
                set[4].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[4].getKPlusNeighbourhood().begin(),
                          set[4].getKPlusNeighbourhood().end(), 3) !=
                set[4].getKPlusNeighbourhood().end());

    ASSERT_EQ(set[5].getKPlusNeighbourhoodSize(), 3);
    ASSERT_EQ(set[5].getReverseKPlusNeighbourhoodSize(), 4);
    ASSERT_EQ(set[5].getNdfRatio(), 4.0 / 3);
    ASSERT_EQ(set[5].getNumberOfDistanceCalculations(), (set.getSize() - 1) * 2);
    difference = std::abs(set[5].getDistanceToFurthestNeighbour() - 1.64012);
    ASSERT_TRUE(difference < 0.00001);
    difference = std::abs(set[5].getDistanceToFurthestPoint() - 11.0318);
    ASSERT_TRUE(difference < 0.0001);
    ASSERT_TRUE(std::find(set[5].getKPlusNeighbourhood().begin(),
                          set[5].getKPlusNeighbourhood().end(), 6) !=
                set[5].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[5].getKPlusNeighbourhood().begin(),
                          set[5].getKPlusNeighbourhood().end(), 11) !=
                set[5].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[5].getKPlusNeighbourhood().begin(),
                          set[5].getKPlusNeighbourhood().end(), 7) !=
                set[5].getKPlusNeighbourhood().end());

    ASSERT_EQ(set[6].getKPlusNeighbourhoodSize(), 3);
    ASSERT_EQ(set[6].getReverseKPlusNeighbourhoodSize(), 3);
    ASSERT_EQ(set[6].getNdfRatio(), 1);
    ASSERT_EQ(set[6].getNumberOfDistanceCalculations(), (set.getSize() - 1) * 2);
    difference = std::abs(set[6].getDistanceToFurthestNeighbour() - 2.43311);
    ASSERT_TRUE(difference < 0.00001);
    difference = std::abs(set[6].getDistanceToFurthestPoint() - 12.0503);
    ASSERT_TRUE(difference < 0.0001);
    ASSERT_TRUE(std::find(set[6].getKPlusNeighbourhood().begin(),
                          set[6].getKPlusNeighbourhood().end(), 5) !=
                set[6].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[6].getKPlusNeighbourhood().begin(),
                          set[6].getKPlusNeighbourhood().end(), 11) !=
                set[6].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[6].getKPlusNeighbourhood().begin(),
                          set[6].getKPlusNeighbourhood().end(), 7) !=
                set[6].getKPlusNeighbourhood().end());

    ASSERT_EQ(set[7].getKPlusNeighbourhoodSize(), 3);
    ASSERT_EQ(set[7].getReverseKPlusNeighbourhoodSize(), 7);
    ASSERT_EQ(set[7].getNdfRatio(), 7.0 / 3);
    ASSERT_EQ(set[7].getNumberOfDistanceCalculations(), (set.getSize() - 1) * 2);
    difference = std::abs(set[7].getDistanceToFurthestNeighbour() - 1.64012);
    ASSERT_TRUE(difference < 0.00001);
    difference = std::abs(set[7].getDistanceToFurthestPoint() - 9.62549);
    ASSERT_TRUE(difference < 0.00001);
    ASSERT_TRUE(std::find(set[7].getKPlusNeighbourhood().begin(),
                          set[7].getKPlusNeighbourhood().end(), 11) !=
                set[7].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[7].getKPlusNeighbourhood().begin(),
                          set[7].getKPlusNeighbourhood().end(), 2) !=
                set[7].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[7].getKPlusNeighbourhood().begin(),
                          set[7].getKPlusNeighbourhood().end(), 5) !=
                set[7].getKPlusNeighbourhood().end());

    ASSERT_EQ(set[8].getKPlusNeighbourhoodSize(), 3);
    ASSERT_EQ(set[8].getReverseKPlusNeighbourhoodSize(), 3);
    ASSERT_EQ(set[8].getNdfRatio(), 1);
    ASSERT_EQ(set[8].getNumberOfDistanceCalculations(), (set.getSize() - 1) * 2);
    difference = std::abs(set[8].getDistanceToFurthestNeighbour() - 1.58114);
    ASSERT_TRUE(difference < 0.00001);
    difference = std::abs(set[8].getDistanceToFurthestPoint() - 11.5156);
    ASSERT_TRUE(difference < 0.0001);
    ASSERT_TRUE(std::find(set[8].getKPlusNeighbourhood().begin(),
                          set[8].getKPlusNeighbourhood().end(), 3) !=
                set[8].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[8].getKPlusNeighbourhood().begin(),
                          set[8].getKPlusNeighbourhood().end(), 9) !=
                set[8].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[8].getKPlusNeighbourhood().begin(),
                          set[8].getKPlusNeighbourhood().end(), 4) !=
                set[8].getKPlusNeighbourhood().end());

    ASSERT_EQ(set[9].getKPlusNeighbourhoodSize(), 3);
    ASSERT_EQ(set[9].getReverseKPlusNeighbourhoodSize(), 3);
    ASSERT_EQ(set[9].getNdfRatio(), 1);
    ASSERT_EQ(set[9].getNumberOfDistanceCalculations(), (set.getSize() - 1) * 2);
    difference = std::abs(set[9].getDistanceToFurthestNeighbour() - 1.04403);
    ASSERT_TRUE(difference < 0.00001);
    difference = std::abs(set[9].getDistanceToFurthestPoint() - 11.0887);
    ASSERT_TRUE(difference < 0.0001);
    ASSERT_TRUE(std::find(set[9].getKPlusNeighbourhood().begin(),
                          set[9].getKPlusNeighbourhood().end(), 8) !=
                set[9].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[9].getKPlusNeighbourhood().begin(),
                          set[9].getKPlusNeighbourhood().end(), 3) !=
                set[9].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[9].getKPlusNeighbourhood().begin(),
                          set[9].getKPlusNeighbourhood().end(), 4) !=
                set[9].getKPlusNeighbourhood().end());

    ASSERT_EQ(set[10].getKPlusNeighbourhoodSize(), 3);
    ASSERT_EQ(set[10].getReverseKPlusNeighbourhoodSize(), 1);
    ASSERT_EQ(set[10].getNdfRatio(), 1.0 / 3);
    ASSERT_EQ(set[10].getNumberOfDistanceCalculations(), (set.getSize() - 1) * 2);
    difference = std::abs(set[10].getDistanceToFurthestNeighbour() - 2.5632);
    ASSERT_TRUE(difference < 0.00001);
    difference = std::abs(set[10].getDistanceToFurthestPoint() - 11.1759);
    ASSERT_TRUE(difference < 0.0001);
    ASSERT_TRUE(std::find(set[10].getKPlusNeighbourhood().begin(),
                          set[10].getKPlusNeighbourhood().end(), 6) !=
                set[10].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[10].getKPlusNeighbourhood().begin(),
                          set[10].getKPlusNeighbourhood().end(), 7) !=
                set[10].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[10].getKPlusNeighbourhood().begin(),
                          set[10].getKPlusNeighbourhood().end(), 11) !=
                set[10].getKPlusNeighbourhood().end());

    ASSERT_EQ(set[11].getKPlusNeighbourhoodSize(), 4);
    ASSERT_EQ(set[11].getReverseKPlusNeighbourhoodSize(), 4);
    ASSERT_EQ(set[11].getNdfRatio(), 1);
    ASSERT_EQ(set[11].getNumberOfDistanceCalculations(), (set.getSize() - 1) * 2);
    difference = std::abs(set[11].getDistanceToFurthestNeighbour() - 1.50333);
    ASSERT_TRUE(difference < 0.00001);
    difference = std::abs(set[11].getDistanceToFurthestPoint() - 11.0018);
    ASSERT_TRUE(difference < 0.0001);
    ASSERT_TRUE(std::find(set[11].getKPlusNeighbourhood().begin(),
                          set[11].getKPlusNeighbourhood().end(), 5) !=
                set[11].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[11].getKPlusNeighbourhood().begin(),
                          set[11].getKPlusNeighbourhood().end(), 6) !=
                set[1].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[11].getKPlusNeighbourhood().begin(),
                          set[11].getKPlusNeighbourhood().end(), 7) !=
                set[11].getKPlusNeighbourhood().end());
    ASSERT_TRUE(std::find(set[11].getKPlusNeighbourhood().begin(),
                          set[11].getKPlusNeighbourhood().end(), 10) !=
                set[11].getKPlusNeighbourhood().end());
}

TEST(groupingTests, buildGroup)
{
    std::vector<std::string> datatypes{"double", "double"};
    Dataset dataset = Dataset("../../data/lecture_data.csv",
                              datatypes,
                              "NA", "csv");
    GroupingSet set = GroupingSet(dataset);

    grouping::calculateKPlusNeighbourhoods(set, 3, euclideanDistance, 1);

    set[0].assignClass(-1);
    set[1].assignClass(-1);

    grouping::buildGroup(set, 2, 1);

    ASSERT_EQ(set[0].getAssignedClass(), 1);
    ASSERT_EQ(set[1].getAssignedClass(), -1);
    ASSERT_EQ(set[2].getAssignedClass(), 1);
    ASSERT_EQ(set[3].getAssignedClass(), -2);
    ASSERT_EQ(set[4].getAssignedClass(), -2);
    ASSERT_EQ(set[5].getAssignedClass(), 1);
    ASSERT_EQ(set[6].getAssignedClass(), 1);
    ASSERT_EQ(set[7].getAssignedClass(), 1);
    ASSERT_EQ(set[8].getAssignedClass(), -2);
    ASSERT_EQ(set[9].getAssignedClass(), -2);
    ASSERT_EQ(set[10].getAssignedClass(), 1);
    ASSERT_EQ(set[11].getAssignedClass(), 1);
}

TEST(groupingTests, nbc)
{
    std::vector<std::string> datatypes{"double", "double"};
    Dataset dataset = Dataset("../../data/lecture_data.csv",
                              datatypes,
                              "NA", "csv");

    GroupingSet set = grouping::nbc(dataset, 3, euclideanDistance).first;

    ASSERT_EQ(set[0].getAssignedClass(), 1);
    ASSERT_EQ(set[1].getAssignedClass(), -1);
    ASSERT_EQ(set[2].getAssignedClass(), 1);
    ASSERT_EQ(set[3].getAssignedClass(), 2);
    ASSERT_EQ(set[4].getAssignedClass(), 2);
    ASSERT_EQ(set[5].getAssignedClass(), 1);
    ASSERT_EQ(set[6].getAssignedClass(), 1);
    ASSERT_EQ(set[7].getAssignedClass(), 1);
    ASSERT_EQ(set[8].getAssignedClass(), 2);
    ASSERT_EQ(set[9].getAssignedClass(), 2);
    ASSERT_EQ(set[10].getAssignedClass(), 1);
    ASSERT_EQ(set[11].getAssignedClass(), 1);
}
