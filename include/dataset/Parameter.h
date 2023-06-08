#ifndef PARAMETER_H
#define PARAMETER_H

#include <variant>
#include <string>
#include <MissingValueException.h>
#include <sstream>

using parameterType = std::variant<int, double, bool, std::string>;

class Parameter
{
public:
    Parameter(std::string stringValue, std::string dataType, std::string unknownValueCode);
    Parameter(parameterType parameterValue, bool isParameterNumeric, bool isParameterMissing);
    ~Parameter();
    bool isNumeric();
    parameterType getValue(bool ignoreMissing = false);
    bool isMissing();

private:
    bool numericFlag;
    parameterType value;
    bool missingFlag;
};

#endif