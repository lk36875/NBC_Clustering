#include <gtest/gtest.h>
#include <GroupingPoint.h>
#include <Parameter.h>
#include <Datapoint.h>
#include <MissingValueException.h>

TEST(groupingPointTests, constructor)
{
    Parameter parameter0 = Parameter(2, true, false);
    Parameter parameter1 = Parameter(5.5, true, true);
    Parameter parameter2 = Parameter(false, false, false);
    Parameter parameter3 = Parameter("Yhwach", false, true);
    Datapoint datapoint = Datapoint(std::vector<Parameter>{parameter0, parameter1, parameter2, parameter3}, 2);
    GroupingPoint groupingPoint = GroupingPoint(datapoint);
    ASSERT_TRUE(groupingPoint.getDatapoint()[0].isNumeric());
    ASSERT_FALSE(groupingPoint.getDatapoint()[0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(groupingPoint.getDatapoint()[0].getValue()));
    ASSERT_EQ(std::get<int>(groupingPoint.getDatapoint()[0].getValue()), 2);
    ASSERT_FALSE(groupingPoint.getDatapoint()[3].isNumeric());
    ASSERT_TRUE(groupingPoint.getDatapoint()[3].isMissing());
    ASSERT_EQ(groupingPoint.getDatapoint().getClass(), 2);
    ASSERT_EQ(groupingPoint.getReverseKPlusNeighbourhoodSize(), 0);
    ASSERT_EQ(groupingPoint.getKPlusNeighbourhood().size(), 0);
    ASSERT_EQ(groupingPoint.getKPlusNeighbourhoodSize(), 0);
    ASSERT_EQ(groupingPoint.getAssignedClass(), -2);
    ASSERT_EQ(groupingPoint.getNumberOfDistanceCalculations(), 0);
    ASSERT_EQ(groupingPoint.getDistanceToFurthestNeighbour(), 0);
    ASSERT_EQ(groupingPoint.getDistanceToFurthestPoint(), 0);
    EXPECT_THROW(groupingPoint.getNdfRatio(), MissingValueException);
}

TEST(groupingPointTests, addNeighbour)
{
    Parameter parameter0 = Parameter(2, true, false);
    Parameter parameter1 = Parameter(5.5, true, true);
    Parameter parameter2 = Parameter(false, false, false);
    Parameter parameter3 = Parameter("Yhwach", false, true);
    Datapoint datapoint = Datapoint(std::vector<Parameter>{parameter0, parameter1, parameter2, parameter3}, 2);
    GroupingPoint groupingPoint = GroupingPoint(datapoint);
    groupingPoint.addNeighbour(5);
    ASSERT_EQ(groupingPoint.getKPlusNeighbourhoodSize(), 1);
    ASSERT_EQ(groupingPoint.getKPlusNeighbourhood().size(), 1);
    ASSERT_EQ(groupingPoint.getKPlusNeighbourhood()[0], 5);
}

TEST(groupingPointTests, incrementReverseKPlusNeighbourhoodSize)
{
    Parameter parameter0 = Parameter(2, true, false);
    Parameter parameter1 = Parameter(5.5, true, true);
    Parameter parameter2 = Parameter(false, false, false);
    Parameter parameter3 = Parameter("Yhwach", false, true);
    Datapoint datapoint = Datapoint(std::vector<Parameter>{parameter0, parameter1, parameter2, parameter3}, 2);
    GroupingPoint groupingPoint = GroupingPoint(datapoint);
    ASSERT_EQ(groupingPoint.getReverseKPlusNeighbourhoodSize(), 0);
    groupingPoint.incrementReverseKPlusNeighbourhoodSize();
    ASSERT_EQ(groupingPoint.getReverseKPlusNeighbourhoodSize(), 1);
}

TEST(groupingPointTests, calculateNdfRatio)
{
    Parameter parameter0 = Parameter(2, true, false);
    Parameter parameter1 = Parameter(5.5, true, true);
    Parameter parameter2 = Parameter(false, false, false);
    Parameter parameter3 = Parameter("Yhwach", false, true);
    Datapoint datapoint = Datapoint(std::vector<Parameter>{parameter0, parameter1, parameter2, parameter3}, 2);
    GroupingPoint groupingPoint = GroupingPoint(datapoint);
    groupingPoint.incrementReverseKPlusNeighbourhoodSize();
    groupingPoint.addNeighbour(69);
    groupingPoint.addNeighbour(420);
    EXPECT_THROW(groupingPoint.getNdfRatio(), MissingValueException);
    groupingPoint.calculateNdfRatio();
    ASSERT_EQ(groupingPoint.getNdfRatio(), 0.5);
}

TEST(groupingPointTests, incrementNumberOfDistanceCalculations)
{
    Parameter parameter0 = Parameter(2, true, false);
    Parameter parameter1 = Parameter(5.5, true, true);
    Parameter parameter2 = Parameter(false, false, false);
    Parameter parameter3 = Parameter("Yhwach", false, true);
    Datapoint datapoint = Datapoint(std::vector<Parameter>{parameter0, parameter1, parameter2, parameter3}, 2);
    GroupingPoint groupingPoint = GroupingPoint(datapoint);
    ASSERT_EQ(groupingPoint.getNumberOfDistanceCalculations(), 0);
    groupingPoint.incrementNumberOfDistanceCalculations();
    ASSERT_EQ(groupingPoint.getNumberOfDistanceCalculations(), 1);
}

TEST(groupingPointTests, setDistanceToFurthestNeighbour)
{
    Parameter parameter0 = Parameter(2, true, false);
    Parameter parameter1 = Parameter(5.5, true, true);
    Parameter parameter2 = Parameter(false, false, false);
    Parameter parameter3 = Parameter("Yhwach", false, true);
    Datapoint datapoint = Datapoint(std::vector<Parameter>{parameter0, parameter1, parameter2, parameter3}, 2);
    GroupingPoint groupingPoint = GroupingPoint(datapoint);
    ASSERT_EQ(groupingPoint.getDistanceToFurthestNeighbour(), 0);
    groupingPoint.setDistanceToFurthestNeighbour(13.5);
    ASSERT_EQ(groupingPoint.getDistanceToFurthestNeighbour(), 13.5);
}

TEST(groupingPointTests, setDistanceToFurthestPoint)
{
    Parameter parameter0 = Parameter(2, true, false);
    Parameter parameter1 = Parameter(5.5, true, true);
    Parameter parameter2 = Parameter(false, false, false);
    Parameter parameter3 = Parameter("Yhwach", false, true);
    Datapoint datapoint = Datapoint(std::vector<Parameter>{parameter0, parameter1, parameter2, parameter3}, 2);
    GroupingPoint groupingPoint = GroupingPoint(datapoint);
    ASSERT_EQ(groupingPoint.getDistanceToFurthestPoint(), 0);
    groupingPoint.setDistanceToFurthestPoint(15.9);
    ASSERT_EQ(groupingPoint.getDistanceToFurthestPoint(), 15.9);
}
