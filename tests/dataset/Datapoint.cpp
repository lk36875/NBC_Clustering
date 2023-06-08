#include <gtest/gtest.h>
#include <Parameter.h>
#include <Datapoint.h>
#include <vector>

TEST(datapointTests, constructsAndAccesses)
{
    Parameter parameter0 = Parameter(2, true, false);
    Parameter parameter1 = Parameter(5.5, true, true);
    Parameter parameter2 = Parameter(false, false, false);
    Parameter parameter3 = Parameter("Yhwach", false, true);
    Datapoint datapoint = Datapoint(std::vector<Parameter>{parameter0, parameter1, parameter2, parameter3}, 2);
    ASSERT_TRUE(datapoint[0].isNumeric());
    ASSERT_FALSE(datapoint[0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(datapoint[0].getValue()));
    ASSERT_EQ(std::get<int>(datapoint[0].getValue()), 2);
    ASSERT_FALSE(datapoint[3].isNumeric());
    ASSERT_TRUE(datapoint[3].isMissing());
    ASSERT_EQ(datapoint.getClass(), 2);
}

TEST(datapointTests, correctlyReturnsSize)
{
    Parameter parameter0 = Parameter(2, true, false);
    Parameter parameter1 = Parameter(5.5, true, true);
    Parameter parameter2 = Parameter(false, false, false);
    Parameter parameter3 = Parameter("Yhwach", false, true);
    Datapoint datapoint = Datapoint(std::vector<Parameter>{parameter0, parameter1, parameter2, parameter3}, 5);
    ASSERT_EQ(datapoint.getParameterCount(), 4);
    Parameter parameter4 = Parameter("Garou", false, false);
    datapoint = Datapoint(std::vector<Parameter>{parameter0, parameter1, parameter2, parameter3, parameter4}, 5);
    ASSERT_EQ(datapoint.getParameterCount(), 5);
}

TEST(datapointTests, constructsFromLine)
{
    std::vector<std::string> parameterTypes{"int", "double", "bool", "string", "int", "double", "bool", "string", "bool"};
    Datapoint datapoint = Datapoint("5;8.6;true;adas;?;?;?;?;1;3", parameterTypes, "?", ";", 1);

    ASSERT_EQ(datapoint.getParameterCount(), 9);
    ASSERT_EQ(datapoint.getClass(), 3);

    ASSERT_TRUE(datapoint[0].isNumeric());
    ASSERT_FALSE(datapoint[0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(datapoint[0].getValue()));
    ASSERT_EQ(std::get<int>(datapoint[0].getValue()), 5);

    ASSERT_TRUE(datapoint[1].isNumeric());
    ASSERT_FALSE(datapoint[1].isMissing());
    ASSERT_TRUE(std::holds_alternative<double>(datapoint[1].getValue()));
    ASSERT_EQ(std::get<double>(datapoint[1].getValue()), 8.6);

    ASSERT_FALSE(datapoint[2].isNumeric());
    ASSERT_FALSE(datapoint[2].isMissing());
    ASSERT_TRUE(std::holds_alternative<bool>(datapoint[2].getValue()));
    ASSERT_TRUE(std::get<bool>(datapoint[2].getValue()));

    ASSERT_FALSE(datapoint[3].isNumeric());
    ASSERT_FALSE(datapoint[3].isMissing());
    ASSERT_TRUE(std::holds_alternative<std::string>(datapoint[3].getValue()));
    ASSERT_EQ(std::get<std::string>(datapoint[3].getValue()), "adas");

    ASSERT_TRUE(datapoint[4].isNumeric());
    ASSERT_TRUE(datapoint[4].isMissing());

    ASSERT_TRUE(datapoint[5].isNumeric());
    ASSERT_TRUE(datapoint[5].isMissing());

    ASSERT_TRUE(!datapoint[6].isNumeric());
    ASSERT_TRUE(datapoint[6].isMissing());

    ASSERT_TRUE(!datapoint[7].isNumeric());
    ASSERT_TRUE(datapoint[7].isMissing());

    ASSERT_TRUE(!datapoint[8].isNumeric());
    ASSERT_TRUE(!datapoint[8].isMissing());
    ASSERT_TRUE(std::holds_alternative<bool>(datapoint[8].getValue()));
    ASSERT_TRUE(std::get<bool>(datapoint[8].getValue()));
}
