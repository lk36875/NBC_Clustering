#ifndef GROUPINGPOINT_H
#define GROUPINGPOINT_H

#include <Datapoint.h>
#include <vector>
#include <MissingValueException.h>

class GroupingPoint
{

public:
    GroupingPoint(Datapoint datapoint);
    ~GroupingPoint();
    Datapoint getDatapoint();
    void addNeighbour(int neighbourIndex);
    std::vector<int> getKPlusNeighbourhood();
    int getKPlusNeighbourhoodSize();
    int getAssignedClass();
    void assignClass(int classValue);
    int getReverseKPlusNeighbourhoodSize();
    void incrementReverseKPlusNeighbourhoodSize();
    double getNdfRatio();
    void calculateNdfRatio();
    int getNumberOfDistanceCalculations();
    void incrementNumberOfDistanceCalculations();
    void setDistanceToFurthestNeighbour(double distance);
    double getDistanceToFurthestNeighbour();
    void setDistanceToFurthestPoint(double distance);
    double getDistanceToFurthestPoint();

private:
    Datapoint datapoint;
    int reverseKPlusNeighbourhoodSize;
    std::vector<int> kPlusNeighbours;
    int assignedClass;
    double ndfRatio;
    bool isNdfCalculated;
    int distanceCalculations;
    double distanceToFurthestNeighbour;
    double distanceToFurthestPoint;
};

#endif
