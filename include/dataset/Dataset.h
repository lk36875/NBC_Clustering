#ifndef DATASET_H
#define DATASET_H

#include <Datapoint.h>
#include <vector>
#include <string>
#include <fstream>

class Dataset
{
public:
    Dataset(std::string pathToFile, std::vector<std::string> parameterTypes,
            std::string unknownValueCode, std::string fileFormat,
            std::string delimiter = ",");
    ~Dataset();
    Datapoint operator[](int index);
    std::vector<Datapoint>::iterator begin();
    std::vector<Datapoint>::iterator end();
    int getSize();
    int getPointId();
    void incrementPointId();

private:
    int pointId;
    std::vector<Datapoint> data;
    std::vector<Datapoint> loadDataFromCsv(std::string pathToFile,
                                           std::vector<std::string> parameterTypes,
                                           std::string unknownValueCode,
                                           std::string delimiter);
};

#endif