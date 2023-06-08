#include <Datapoint.h>

Datapoint::Datapoint(std::vector<Parameter> parameters, int newClass)
    : parameters{parameters}, referenceClass{newClass}, id(0){};

Datapoint::Datapoint(std::string line, std::vector<std::string> parameterTypes,
                     std::string unknownValueCode, std::string delimiter, int newId)
{
    id = newId;
    for (std::string dataType : parameterTypes)
    {
        size_t pos = line.find(delimiter);
        if (pos == std::string::npos)
        {
            throw std::invalid_argument("Specified file has invalid format. Some parameters are neither present nor marked as missing.");
        }
        std::string value = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        parameters.push_back(Parameter(value, dataType, unknownValueCode));
    }
    referenceClass = stoi(line);
}

Datapoint::Datapoint(std::string line, std::vector<std::string> parameterTypes,
                     std::string unknownValueCode, std::string delimiter, int newId,
                     int classToAssign)
{
    id = newId;
    for (std::string dataType : parameterTypes)
    {
        size_t pos = line.find(delimiter);
        if (pos == std::string::npos)
        {
            throw std::invalid_argument("Specified file has invalid format. Some parameters are neither present nor marked as missing.");
        }
        std::string value = line.substr(0, pos);
        line.erase(0, pos + delimiter.length());
        parameters.push_back(Parameter(value, dataType, unknownValueCode));
    }
    referenceClass = classToAssign;
}

Datapoint::~Datapoint(){};

Parameter Datapoint::operator[](int index)
{
    return parameters[index];
}

int Datapoint::getParameterCount()
{
    return parameters.size();
}

int Datapoint::getClass()
{
    return referenceClass;
}

int Datapoint::getId()
{
    return id;
}