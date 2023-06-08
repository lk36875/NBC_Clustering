#ifndef DATAPOINT_H
#define DATAPOINT_H

#include <Parameter.h>
#include <vector>

class Datapoint
{
public:
    Datapoint(std::vector<Parameter> parameters, int newClass);
    Datapoint(std::string line, std::vector<std::string> parameterTypes,
              std::string unknownValueCode, std::string delimiter, int newId);
    Datapoint(std::string line, std::vector<std::string> parameterTypes,
              std::string unknownValueCode, std::string delimiter, int newId,
              int classToAssign);
    ~Datapoint();
    Parameter operator[](int index);
    int getParameterCount();
    int getClass();
    int getId();

private:
    std::vector<Parameter> parameters;
    int id;
    int referenceClass;
};

#endif
