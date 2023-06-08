#include <Dataset.h>

#include <map>

/*
    pathToFile [string] - Path to a file, from which we want to load data
    parameterTypes [vector<string>] - Vector containing names of types for columns in dataset.
                                      Program assumes n+1 columns in file, where n is length of this vector
                                      and number of parameters. Last column is expected to contain class of example.
    unknownValueCode [string] - Chain of characters representing missing value in dataset
    fileFormat [string] - Type of file. Defines the way it is processed. Currently supported: csv
    delimiter [string] - Delimiter seperating values within a line
*/
Dataset::Dataset(std::string pathToFile, std::vector<std::string> parameterTypes,
                 std::string unknownValueCode, std::string fileFormat, std::string delimiter)
{
    pointId = 0;
    if (fileFormat == "csv")
    {
        data = loadDataFromCsv(pathToFile, parameterTypes, unknownValueCode, delimiter);
    }
    else
    {
        throw std::invalid_argument("Specified file format is not supported");
    }
}

std::vector<Datapoint> Dataset::loadDataFromCsv(std::string pathToFile,
                                                std::vector<std::string> parameterTypes,
                                                std::string unknownValueCode,
                                                std::string delimiter)
{

    std::ifstream dataFile(pathToFile);
    std::string line;
    std::vector<Datapoint> datapoints;
    std::map<std::string, int> classMapping;
    int mappedClass = 1;
    while (dataFile >> line)
    {
        size_t found = line.find_last_of(delimiter);
        std::string referenceClass = line.substr(found + 1);
        if (classMapping.contains(referenceClass))
        {
            datapoints.push_back(Datapoint(line, parameterTypes, unknownValueCode, delimiter, getPointId(), classMapping[referenceClass]));
        }
        else
        {
            classMapping.insert({referenceClass, mappedClass});
            datapoints.push_back(Datapoint(line, parameterTypes, unknownValueCode, delimiter, getPointId(), mappedClass));
            mappedClass++;
        }
        incrementPointId();
    }
    return datapoints;
}

Dataset::~Dataset(){};

Datapoint Dataset::operator[](int index)
{
    return data[index];
}

int Dataset::getSize()
{
    return data.size();
}

int Dataset::getPointId()
{
    return pointId;
}

void Dataset::incrementPointId()
{
    pointId++;
}

std::vector<Datapoint>::iterator Dataset::begin()
{
    return data.begin();
}

std::vector<Datapoint>::iterator Dataset::end()
{
    return data.end();
}
