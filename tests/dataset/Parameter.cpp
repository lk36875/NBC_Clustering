#include <gtest/gtest.h>
#include <Parameter.h>
#include <variant>
#include <string>
#include <MissingValueException.h>

TEST(parameterTests, constructorInt)
{
    Parameter parameter = Parameter(2, true, false);
    ASSERT_TRUE(parameter.isNumeric());
    ASSERT_FALSE(parameter.isMissing());
    parameterType value = parameter.getValue();
    ASSERT_TRUE(std::holds_alternative<int>(value));
    ASSERT_TRUE(std::get<int>(value) == 2);
}

TEST(parameterTests, constructorDouble)
{
    Parameter parameter = Parameter(5.5, true, false);
    ASSERT_TRUE(parameter.isNumeric());
    ASSERT_FALSE(parameter.isMissing());
    parameterType value = parameter.getValue();
    ASSERT_TRUE(std::holds_alternative<double>(value));
    ASSERT_TRUE(std::get<double>(value) == 5.5);
}

TEST(parameterTests, constructorBool)
{
    Parameter parameter = Parameter(false, false, false);
    ASSERT_FALSE(parameter.isNumeric());
    ASSERT_FALSE(parameter.isMissing());
    parameterType value = parameter.getValue();
    ASSERT_TRUE(std::holds_alternative<bool>(value));
    ASSERT_FALSE(std::get<bool>(value));
}

TEST(parameterTests, constructorString)
{
    Parameter parameter = Parameter("Ala ma kota", false, false);
    ASSERT_FALSE(parameter.isNumeric());
    ASSERT_FALSE(parameter.isMissing());
    parameterType value = parameter.getValue();
    ASSERT_TRUE(std::holds_alternative<std::string>(value));
    ASSERT_TRUE(std::get<std::string>(value) == "Ala ma kota");
}

TEST(parameterTests, throwsWhenAccessingMissingValue)
{
    Parameter parameter = Parameter("Ala ma kota", false, true);
    ASSERT_FALSE(parameter.isNumeric());
    ASSERT_TRUE(parameter.isMissing());
    EXPECT_THROW(parameter.getValue(), MissingValueException);
}

TEST(parameterTests, constructorFromStringInt)
{
    Parameter parameter = Parameter(std::string("2"), std::string("int"), std::string("?"));
    ASSERT_TRUE(parameter.isNumeric());
    ASSERT_FALSE(parameter.isMissing());
    parameterType value = parameter.getValue();
    ASSERT_TRUE(std::holds_alternative<int>(value));
    ASSERT_TRUE(std::get<int>(value) == 2);
}

TEST(parameterTests, constructorFromStringDouble)
{
    Parameter parameter = Parameter(std::string("5.5"), std::string("double"), std::string("?"));
    ASSERT_TRUE(parameter.isNumeric());
    ASSERT_FALSE(parameter.isMissing());
    parameterType value = parameter.getValue();
    ASSERT_TRUE(std::holds_alternative<double>(value));
    ASSERT_TRUE(std::get<double>(value) == 5.5);
}

TEST(parameterTests, constructorFromStringBool)
{
    Parameter parameter = Parameter(std::string("false"), std::string("bool"), std::string("?"));
    ASSERT_FALSE(parameter.isNumeric());
    ASSERT_FALSE(parameter.isMissing());
    parameterType value = parameter.getValue();
    ASSERT_TRUE(std::holds_alternative<bool>(value));
    ASSERT_FALSE(std::get<bool>(value));
}

TEST(parameterTests, constructorFromStringString)
{
    Parameter parameter = Parameter(std::string("Ala ma kota"), std::string("string"), std::string("?"));
    ASSERT_FALSE(parameter.isNumeric());
    ASSERT_FALSE(parameter.isMissing());
    parameterType value = parameter.getValue();
    ASSERT_TRUE(std::holds_alternative<std::string>(value));
    ASSERT_TRUE(std::get<std::string>(value) == "Ala ma kota");
}

TEST(parameterTests, constructorFromStringIntMissing)
{
    Parameter parameter = Parameter(std::string("?"), std::string("int"), std::string("?"));
    ASSERT_TRUE(parameter.isNumeric());
    ASSERT_TRUE(parameter.isMissing());
}

TEST(parameterTests, constructorFromStringDoubleMissing)
{
    Parameter parameter = Parameter(std::string("?"), std::string("double"), std::string("?"));
    ASSERT_TRUE(parameter.isNumeric());
    ASSERT_TRUE(parameter.isMissing());
}

TEST(parameterTests, constructorFromStringBoolMissing)
{
    Parameter parameter = Parameter(std::string("?"), std::string("bool"), std::string("?"));
    ASSERT_FALSE(parameter.isNumeric());
    ASSERT_TRUE(parameter.isMissing());
}

TEST(parameterTests, constructorFromStringStringMissing)
{
    Parameter parameter = Parameter(std::string("?"), std::string("string"), std::string("?"));
    ASSERT_FALSE(parameter.isNumeric());
    ASSERT_TRUE(parameter.isMissing());
}

TEST(parameterTests, constructorFromStringInvalidTypeThrows)
{
    EXPECT_THROW(Parameter(std::string("oogaa"), std::string("Grimmjow"), std::string("booga")), std::invalid_argument);
}
