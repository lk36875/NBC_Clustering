#include <Parameter.h>

Parameter::Parameter(parameterType parameterValue, bool isParameterNumeric, bool isParameterMissing)
    : value{parameterValue}, numericFlag{isParameterNumeric}, missingFlag{isParameterMissing} {};

Parameter::Parameter(std::string stringValue, std::string dataType, std::string unknownValueCode)
{
    missingFlag = (stringValue == unknownValueCode);
    if (dataType == "int")
    {
        numericFlag = true;
        value = missingFlag ? 0 : stoi(stringValue);
    }
    else if (dataType == "double")
    {
        numericFlag = true;
        value = missingFlag ? 0.0 : std::stod(stringValue);
    }
    else if (dataType == "bool")
    {
        numericFlag = false;
        bool boolValue;
        std::istringstream(stringValue) >> ((stringValue == "0" || stringValue == "1") ? std::noboolalpha : std::boolalpha) >> boolValue;
        value = missingFlag ? false : boolValue;
    }
    else if (dataType == "string")
    {
        numericFlag = false;
        value = missingFlag ? "" : stringValue;
    }
    else
    {
        throw std::invalid_argument("Specified datatype: " + dataType + " is not supported.");
    }
}

Parameter::~Parameter(){};

bool Parameter::isNumeric()
{
    return numericFlag;
}

parameterType Parameter::getValue(bool ignoreMissing)
{
    if (ignoreMissing)
    {
        return value;
    }
    if (!missingFlag)
    {
        return value;
    }
    else
    {
        throw MissingValueException("Cannot acces value of missing parameter.");
    }
}

bool Parameter::isMissing()
{
    return missingFlag;
}