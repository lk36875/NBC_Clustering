#include <gtest/gtest.h>
#include <Dataset.h>
#include <vector>

TEST(datasetTests, constructor1)
{
    std::vector<std::string> datatypes{"int", "double", "bool", "string"};
    Dataset dataset = Dataset("../../data/test.csv",
                              datatypes,
                              "NA", "csv");

    ASSERT_TRUE(dataset.getSize() == 4);

    ASSERT_TRUE(dataset[0].getParameterCount() == 4);
    ASSERT_TRUE(dataset[0].getClass() == 1);

    ASSERT_TRUE(dataset[0][0].isNumeric());
    ASSERT_FALSE(dataset[0][0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(dataset[0][0].getValue()));
    ASSERT_TRUE(std::get<int>(dataset[0][0].getValue()) == 5);

    ASSERT_TRUE(dataset[0][1].isNumeric());
    ASSERT_FALSE(dataset[0][1].isMissing());
    ASSERT_TRUE(std::holds_alternative<double>(dataset[0][1].getValue()));
    ASSERT_TRUE(std::get<double>(dataset[0][1].getValue()) == 8.6);

    ASSERT_FALSE(dataset[0][2].isNumeric());
    ASSERT_FALSE(dataset[0][2].isMissing());
    ASSERT_TRUE(std::holds_alternative<bool>(dataset[0][2].getValue()));
    ASSERT_TRUE(std::get<bool>(dataset[0][2].getValue()));

    ASSERT_FALSE(dataset[0][3].isNumeric());
    ASSERT_FALSE(dataset[0][3].isMissing());
    ASSERT_TRUE(std::holds_alternative<std::string>(dataset[0][3].getValue()));
    ASSERT_TRUE(std::get<std::string>(dataset[0][3].getValue()) == "adas");

    ASSERT_TRUE(dataset[1].getParameterCount() == 4);
    ASSERT_TRUE(dataset[1].getClass() == 2);

    ASSERT_TRUE(dataset[1][0].isNumeric());
    ASSERT_FALSE(dataset[1][0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(dataset[1][0].getValue()));
    ASSERT_TRUE(std::get<int>(dataset[1][0].getValue()) == 2);

    ASSERT_TRUE(dataset[1][1].isNumeric());
    ASSERT_FALSE(dataset[1][1].isMissing());
    ASSERT_TRUE(std::holds_alternative<double>(dataset[1][1].getValue()));
    ASSERT_TRUE(std::get<double>(dataset[1][1].getValue()) == 12.5);

    ASSERT_FALSE(dataset[1][2].isNumeric());
    ASSERT_FALSE(dataset[1][2].isMissing());
    ASSERT_TRUE(std::holds_alternative<bool>(dataset[1][2].getValue()));
    ASSERT_FALSE(std::get<bool>(dataset[1][2].getValue()));

    ASSERT_FALSE(dataset[1][3].isNumeric());
    ASSERT_FALSE(dataset[1][3].isMissing());
    ASSERT_TRUE(std::holds_alternative<std::string>(dataset[1][3].getValue()));
    ASSERT_TRUE(std::get<std::string>(dataset[1][3].getValue()) == "sdfsdf");

    ASSERT_TRUE(dataset[2].getParameterCount() == 4);
    ASSERT_TRUE(dataset[2].getClass() == 1);

    ASSERT_TRUE(dataset[2][0].isNumeric());
    ASSERT_FALSE(dataset[2][0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(dataset[2][0].getValue()));
    ASSERT_TRUE(std::get<int>(dataset[2][0].getValue()) == 6);

    ASSERT_TRUE(dataset[2][1].isNumeric());
    ASSERT_FALSE(dataset[2][1].isMissing());
    ASSERT_TRUE(std::holds_alternative<double>(dataset[2][1].getValue()));
    ASSERT_TRUE(std::get<double>(dataset[2][1].getValue()) == 1234.124);

    ASSERT_FALSE(dataset[2][2].isNumeric());
    ASSERT_FALSE(dataset[2][2].isMissing());
    ASSERT_TRUE(std::holds_alternative<bool>(dataset[2][2].getValue()));
    ASSERT_FALSE(std::get<bool>(dataset[2][2].getValue()));

    ASSERT_FALSE(dataset[2][3].isNumeric());
    ASSERT_FALSE(dataset[2][3].isMissing());
    ASSERT_TRUE(std::holds_alternative<std::string>(dataset[2][3].getValue()));
    ASSERT_TRUE(std::get<std::string>(dataset[2][3].getValue()) == "wpigmpwom");

    ASSERT_TRUE(dataset[3].getParameterCount() == 4);
    ASSERT_TRUE(dataset[3].getClass() == 3);

    ASSERT_TRUE(dataset[3][0].isNumeric());
    ASSERT_FALSE(dataset[3][0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(dataset[3][0].getValue()));
    ASSERT_TRUE(std::get<int>(dataset[3][0].getValue()) == 10);

    ASSERT_TRUE(dataset[3][1].isNumeric());
    ASSERT_FALSE(dataset[3][1].isMissing());
    ASSERT_TRUE(std::holds_alternative<double>(dataset[3][1].getValue()));
    ASSERT_TRUE(std::get<double>(dataset[3][1].getValue()) == 141.3134);

    ASSERT_FALSE(dataset[3][2].isNumeric());
    ASSERT_FALSE(dataset[3][2].isMissing());
    ASSERT_TRUE(std::holds_alternative<bool>(dataset[3][2].getValue()));
    ASSERT_TRUE(std::get<bool>(dataset[3][2].getValue()));

    ASSERT_FALSE(dataset[3][3].isNumeric());
    ASSERT_FALSE(dataset[3][3].isMissing());
    ASSERT_TRUE(std::holds_alternative<std::string>(dataset[3][3].getValue()));
    ASSERT_TRUE(std::get<std::string>(dataset[3][3].getValue()) == "oawrngaoing");
}

TEST(datasetTests, constructor2)
{
    std::vector<std::string> datatypes{"int", "double", "bool", "string"};
    Dataset dataset = Dataset("../../data/test2.csv",
                              datatypes,
                              "NA", "csv");

    ASSERT_TRUE(dataset.getSize() == 4);

    ASSERT_TRUE(dataset[0].getParameterCount() == 4);
    ASSERT_TRUE(dataset[0].getClass() == 1);

    ASSERT_TRUE(dataset[0][0].isNumeric());
    ASSERT_FALSE(dataset[0][0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(dataset[0][0].getValue()));
    ASSERT_TRUE(std::get<int>(dataset[0][0].getValue()) == 5);

    ASSERT_TRUE(dataset[0][1].isNumeric());
    ASSERT_FALSE(dataset[0][1].isMissing());
    ASSERT_TRUE(std::holds_alternative<double>(dataset[0][1].getValue()));
    ASSERT_TRUE(std::get<double>(dataset[0][1].getValue()) == 8.6);

    ASSERT_FALSE(dataset[0][2].isNumeric());
    ASSERT_FALSE(dataset[0][2].isMissing());
    ASSERT_TRUE(std::holds_alternative<bool>(dataset[0][2].getValue()));
    ASSERT_TRUE(std::get<bool>(dataset[0][2].getValue()));

    ASSERT_FALSE(dataset[0][3].isNumeric());
    ASSERT_FALSE(dataset[0][3].isMissing());
    ASSERT_TRUE(std::holds_alternative<std::string>(dataset[0][3].getValue()));
    ASSERT_TRUE(std::get<std::string>(dataset[0][3].getValue()) == "adas");

    ASSERT_TRUE(dataset[1].getParameterCount() == 4);
    ASSERT_TRUE(dataset[1].getClass() == 2);

    ASSERT_TRUE(dataset[1][0].isNumeric());
    ASSERT_FALSE(dataset[1][0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(dataset[1][0].getValue()));
    ASSERT_TRUE(std::get<int>(dataset[1][0].getValue()) == 2);

    ASSERT_TRUE(dataset[1][1].isNumeric());
    ASSERT_FALSE(dataset[1][1].isMissing());
    ASSERT_TRUE(std::holds_alternative<double>(dataset[1][1].getValue()));
    ASSERT_TRUE(std::get<double>(dataset[1][1].getValue()) == 12.5);

    ASSERT_FALSE(dataset[1][2].isNumeric());
    ASSERT_FALSE(dataset[1][2].isMissing());
    ASSERT_TRUE(std::holds_alternative<bool>(dataset[1][2].getValue()));
    ASSERT_FALSE(std::get<bool>(dataset[1][2].getValue()));

    ASSERT_FALSE(dataset[1][3].isNumeric());
    ASSERT_FALSE(dataset[1][3].isMissing());
    ASSERT_TRUE(std::holds_alternative<std::string>(dataset[1][3].getValue()));
    ASSERT_TRUE(std::get<std::string>(dataset[1][3].getValue()) == "sdfsdf");

    ASSERT_TRUE(dataset[2].getParameterCount() == 4);
    ASSERT_TRUE(dataset[2].getClass() == 1);

    ASSERT_TRUE(dataset[2][0].isNumeric());
    ASSERT_FALSE(dataset[2][0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(dataset[2][0].getValue()));
    ASSERT_TRUE(std::get<int>(dataset[2][0].getValue()) == 6);

    ASSERT_TRUE(dataset[2][1].isNumeric());
    ASSERT_FALSE(dataset[2][1].isMissing());
    ASSERT_TRUE(std::holds_alternative<double>(dataset[2][1].getValue()));
    ASSERT_TRUE(std::get<double>(dataset[2][1].getValue()) == 1234.124);

    ASSERT_FALSE(dataset[2][2].isNumeric());
    ASSERT_FALSE(dataset[2][2].isMissing());
    ASSERT_TRUE(std::holds_alternative<bool>(dataset[2][2].getValue()));
    ASSERT_FALSE(std::get<bool>(dataset[2][2].getValue()));

    ASSERT_FALSE(dataset[2][3].isNumeric());
    ASSERT_FALSE(dataset[2][3].isMissing());
    ASSERT_TRUE(std::holds_alternative<std::string>(dataset[2][3].getValue()));
    ASSERT_TRUE(std::get<std::string>(dataset[2][3].getValue()) == "wpigmpwom");

    ASSERT_TRUE(dataset[3].getParameterCount() == 4);
    ASSERT_TRUE(dataset[3].getClass() == 3);

    ASSERT_TRUE(dataset[3][0].isNumeric());
    ASSERT_FALSE(dataset[3][0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(dataset[3][0].getValue()));
    ASSERT_TRUE(std::get<int>(dataset[3][0].getValue()) == 10);

    ASSERT_TRUE(dataset[3][1].isNumeric());
    ASSERT_FALSE(dataset[3][1].isMissing());
    ASSERT_TRUE(std::holds_alternative<double>(dataset[3][1].getValue()));
    ASSERT_TRUE(std::get<double>(dataset[3][1].getValue()) == 141.3134);

    ASSERT_FALSE(dataset[3][2].isNumeric());
    ASSERT_FALSE(dataset[3][2].isMissing());
    ASSERT_TRUE(std::holds_alternative<bool>(dataset[3][2].getValue()));
    ASSERT_TRUE(std::get<bool>(dataset[3][2].getValue()));

    ASSERT_FALSE(dataset[3][3].isNumeric());
    ASSERT_FALSE(dataset[3][3].isMissing());
    ASSERT_TRUE(std::holds_alternative<std::string>(dataset[3][3].getValue()));
    ASSERT_TRUE(std::get<std::string>(dataset[3][3].getValue()) == "oawrngaoing");
}

TEST(datasetTests, constructor3)
{
    std::vector<std::string> datatypes{"int", "double", "bool", "string"};
    Dataset dataset = Dataset("../../data/test3.csv",
                              datatypes,
                              "NA", "csv");

    ASSERT_TRUE(dataset.getSize() == 4);

    ASSERT_TRUE(dataset[0].getParameterCount() == 4);
    ASSERT_TRUE(dataset[0].getClass() == 1);

    ASSERT_TRUE(dataset[0][0].isNumeric());
    ASSERT_FALSE(dataset[0][0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(dataset[0][0].getValue()));
    ASSERT_TRUE(std::get<int>(dataset[0][0].getValue()) == 5);

    ASSERT_TRUE(dataset[0][1].isNumeric());
    ASSERT_FALSE(dataset[0][1].isMissing());
    ASSERT_TRUE(std::holds_alternative<double>(dataset[0][1].getValue()));
    ASSERT_TRUE(std::get<double>(dataset[0][1].getValue()) == 8.6);

    ASSERT_FALSE(dataset[0][2].isNumeric());
    ASSERT_FALSE(dataset[0][2].isMissing());
    ASSERT_TRUE(std::holds_alternative<bool>(dataset[0][2].getValue()));
    ASSERT_TRUE(std::get<bool>(dataset[0][2].getValue()));

    ASSERT_FALSE(dataset[0][3].isNumeric());
    ASSERT_TRUE(dataset[0][3].isMissing());

    ASSERT_TRUE(dataset[1].getParameterCount() == 4);
    ASSERT_TRUE(dataset[1].getClass() == 2);

    ASSERT_TRUE(dataset[1][0].isNumeric());
    ASSERT_FALSE(dataset[1][0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(dataset[1][0].getValue()));
    ASSERT_TRUE(std::get<int>(dataset[1][0].getValue()) == 2);

    ASSERT_TRUE(dataset[1][1].isNumeric());
    ASSERT_TRUE(dataset[1][1].isMissing());

    ASSERT_FALSE(dataset[1][2].isNumeric());
    ASSERT_FALSE(dataset[1][2].isMissing());
    ASSERT_TRUE(std::holds_alternative<bool>(dataset[1][2].getValue()));
    ASSERT_FALSE(std::get<bool>(dataset[1][2].getValue()));

    ASSERT_FALSE(dataset[1][3].isNumeric());
    ASSERT_FALSE(dataset[1][3].isMissing());
    ASSERT_TRUE(std::holds_alternative<std::string>(dataset[1][3].getValue()));
    ASSERT_TRUE(std::get<std::string>(dataset[1][3].getValue()) == "sdfsdf");

    ASSERT_TRUE(dataset[2].getParameterCount() == 4);
    ASSERT_TRUE(dataset[2].getClass() == 1);

    ASSERT_TRUE(dataset[2][0].isNumeric());
    ASSERT_TRUE(dataset[2][0].isMissing());

    ASSERT_TRUE(dataset[2][1].isNumeric());
    ASSERT_FALSE(dataset[2][1].isMissing());
    ASSERT_TRUE(std::holds_alternative<double>(dataset[2][1].getValue()));
    ASSERT_TRUE(std::get<double>(dataset[2][1].getValue()) == 1234.124);

    ASSERT_FALSE(dataset[2][2].isNumeric());
    ASSERT_FALSE(dataset[2][2].isMissing());
    ASSERT_TRUE(std::holds_alternative<bool>(dataset[2][2].getValue()));
    ASSERT_FALSE(std::get<bool>(dataset[2][2].getValue()));

    ASSERT_FALSE(dataset[2][3].isNumeric());
    ASSERT_FALSE(dataset[2][3].isMissing());
    ASSERT_TRUE(std::holds_alternative<std::string>(dataset[2][3].getValue()));
    ASSERT_TRUE(std::get<std::string>(dataset[2][3].getValue()) == "wpigmpwom");

    ASSERT_TRUE(dataset[3].getParameterCount() == 4);
    ASSERT_TRUE(dataset[3].getClass() == 3);

    ASSERT_TRUE(dataset[3][0].isNumeric());
    ASSERT_FALSE(dataset[3][0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(dataset[3][0].getValue()));
    ASSERT_TRUE(std::get<int>(dataset[3][0].getValue()) == 10);

    ASSERT_TRUE(dataset[3][1].isNumeric());
    ASSERT_FALSE(dataset[3][1].isMissing());
    ASSERT_TRUE(std::holds_alternative<double>(dataset[3][1].getValue()));
    ASSERT_TRUE(std::get<double>(dataset[3][1].getValue()) == 141.3134);

    ASSERT_FALSE(dataset[3][2].isNumeric());
    ASSERT_TRUE(dataset[3][2].isMissing());

    ASSERT_FALSE(dataset[3][3].isNumeric());
    ASSERT_FALSE(dataset[3][3].isMissing());
    ASSERT_TRUE(std::holds_alternative<std::string>(dataset[3][3].getValue()));
    ASSERT_TRUE(std::get<std::string>(dataset[3][3].getValue()) == "oawrngaoing");
}

TEST(datasetTests, allowsReplacingDelimiter)
{
    std::vector<std::string> datatypes{"int", "double", "bool", "string"};
    Dataset dataset = Dataset("../../data/test4.csv",
                              datatypes,
                              "NA", "csv", ";");

    ASSERT_TRUE(dataset.getSize() == 4);

    ASSERT_TRUE(dataset[0].getParameterCount() == 4);
    ASSERT_TRUE(dataset[0].getClass() == 1);

    ASSERT_TRUE(dataset[0][0].isNumeric());
    ASSERT_FALSE(dataset[0][0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(dataset[0][0].getValue()));
    ASSERT_TRUE(std::get<int>(dataset[0][0].getValue()) == 5);

    ASSERT_TRUE(dataset[0][1].isNumeric());
    ASSERT_FALSE(dataset[0][1].isMissing());
    ASSERT_TRUE(std::holds_alternative<double>(dataset[0][1].getValue()));
    ASSERT_TRUE(std::get<double>(dataset[0][1].getValue()) == 8.6);

    ASSERT_FALSE(dataset[0][2].isNumeric());
    ASSERT_FALSE(dataset[0][2].isMissing());
    ASSERT_TRUE(std::holds_alternative<bool>(dataset[0][2].getValue()));
    ASSERT_TRUE(std::get<bool>(dataset[0][2].getValue()));

    ASSERT_FALSE(dataset[0][3].isNumeric());
    ASSERT_FALSE(dataset[0][3].isMissing());
    ASSERT_TRUE(std::holds_alternative<std::string>(dataset[0][3].getValue()));
    ASSERT_TRUE(std::get<std::string>(dataset[0][3].getValue()) == "adas");

    ASSERT_TRUE(dataset[1].getParameterCount() == 4);
    ASSERT_TRUE(dataset[1].getClass() == 2);

    ASSERT_TRUE(dataset[1][0].isNumeric());
    ASSERT_FALSE(dataset[1][0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(dataset[1][0].getValue()));
    ASSERT_TRUE(std::get<int>(dataset[1][0].getValue()) == 2);

    ASSERT_TRUE(dataset[1][1].isNumeric());
    ASSERT_FALSE(dataset[1][1].isMissing());
    ASSERT_TRUE(std::holds_alternative<double>(dataset[1][1].getValue()));
    ASSERT_TRUE(std::get<double>(dataset[1][1].getValue()) == 12.5);

    ASSERT_FALSE(dataset[1][2].isNumeric());
    ASSERT_FALSE(dataset[1][2].isMissing());
    ASSERT_TRUE(std::holds_alternative<bool>(dataset[1][2].getValue()));
    ASSERT_FALSE(std::get<bool>(dataset[1][2].getValue()));

    ASSERT_FALSE(dataset[1][3].isNumeric());
    ASSERT_FALSE(dataset[1][3].isMissing());
    ASSERT_TRUE(std::holds_alternative<std::string>(dataset[1][3].getValue()));
    ASSERT_TRUE(std::get<std::string>(dataset[1][3].getValue()) == "sdfsdf");

    ASSERT_TRUE(dataset[2].getParameterCount() == 4);
    ASSERT_TRUE(dataset[2].getClass() == 1);

    ASSERT_TRUE(dataset[2][0].isNumeric());
    ASSERT_FALSE(dataset[2][0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(dataset[2][0].getValue()));
    ASSERT_TRUE(std::get<int>(dataset[2][0].getValue()) == 6);

    ASSERT_TRUE(dataset[2][1].isNumeric());
    ASSERT_FALSE(dataset[2][1].isMissing());
    ASSERT_TRUE(std::holds_alternative<double>(dataset[2][1].getValue()));
    ASSERT_TRUE(std::get<double>(dataset[2][1].getValue()) == 1234.124);

    ASSERT_FALSE(dataset[2][2].isNumeric());
    ASSERT_FALSE(dataset[2][2].isMissing());
    ASSERT_TRUE(std::holds_alternative<bool>(dataset[2][2].getValue()));
    ASSERT_FALSE(std::get<bool>(dataset[2][2].getValue()));

    ASSERT_FALSE(dataset[2][3].isNumeric());
    ASSERT_FALSE(dataset[2][3].isMissing());
    ASSERT_TRUE(std::holds_alternative<std::string>(dataset[2][3].getValue()));
    ASSERT_TRUE(std::get<std::string>(dataset[2][3].getValue()) == "wpigmpwom");

    ASSERT_TRUE(dataset[3].getParameterCount() == 4);
    ASSERT_TRUE(dataset[3].getClass() == 3);

    ASSERT_TRUE(dataset[3][0].isNumeric());
    ASSERT_FALSE(dataset[3][0].isMissing());
    ASSERT_TRUE(std::holds_alternative<int>(dataset[3][0].getValue()));
    ASSERT_TRUE(std::get<int>(dataset[3][0].getValue()) == 10);

    ASSERT_TRUE(dataset[3][1].isNumeric());
    ASSERT_FALSE(dataset[3][1].isMissing());
    ASSERT_TRUE(std::holds_alternative<double>(dataset[3][1].getValue()));
    ASSERT_TRUE(std::get<double>(dataset[3][1].getValue()) == 141.3134);

    ASSERT_FALSE(dataset[3][2].isNumeric());
    ASSERT_FALSE(dataset[3][2].isMissing());
    ASSERT_TRUE(std::holds_alternative<bool>(dataset[3][2].getValue()));
    ASSERT_TRUE(std::get<bool>(dataset[3][2].getValue()));

    ASSERT_FALSE(dataset[3][3].isNumeric());
    ASSERT_FALSE(dataset[3][3].isMissing());
    ASSERT_TRUE(std::holds_alternative<std::string>(dataset[3][3].getValue()));
    ASSERT_TRUE(std::get<std::string>(dataset[3][3].getValue()) == "oawrngaoing");
}
