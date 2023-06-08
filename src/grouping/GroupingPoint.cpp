#include <GroupingPoint.h>

GroupingPoint::GroupingPoint(Datapoint datapoint)
    : datapoint{datapoint}, reverseKPlusNeighbourhoodSize{0},
      kPlusNeighbours{}, assignedClass{-2}, ndfRatio{-1},
      isNdfCalculated{false}, distanceCalculations{0},
      distanceToFurthestNeighbour{0},
      distanceToFurthestPoint{0} {};

GroupingPoint::~GroupingPoint(){};

Datapoint GroupingPoint::getDatapoint()
{
    return datapoint;
}

void GroupingPoint::addNeighbour(int neighbour)
{
    kPlusNeighbours.push_back(neighbour);
}

std::vector<int> GroupingPoint::getKPlusNeighbourhood()
{
    return kPlusNeighbours;
}

int GroupingPoint::getKPlusNeighbourhoodSize()
{
    return kPlusNeighbours.size();
}

int GroupingPoint::getAssignedClass()
{
    return assignedClass;
}

void GroupingPoint::assignClass(int classAssignment)
{
    assignedClass = classAssignment;
}

int GroupingPoint::getReverseKPlusNeighbourhoodSize()
{
    return reverseKPlusNeighbourhoodSize;
}

void GroupingPoint::incrementReverseKPlusNeighbourhoodSize()
{
    reverseKPlusNeighbourhoodSize++;
}

double GroupingPoint::getNdfRatio()
{
    if (isNdfCalculated)
    {
        return ndfRatio;
    }
    throw MissingValueException("NDF ratio has not been calculated for this point yet.");
}

void GroupingPoint::calculateNdfRatio()
{
    ndfRatio = static_cast<double>(getReverseKPlusNeighbourhoodSize()) / getKPlusNeighbourhoodSize();
    isNdfCalculated = true;
}

int GroupingPoint::getNumberOfDistanceCalculations()
{
    return distanceCalculations;
}

void GroupingPoint::incrementNumberOfDistanceCalculations()
{
    distanceCalculations++;
}

void GroupingPoint::setDistanceToFurthestNeighbour(double distance)
{
    distanceToFurthestNeighbour = distance;
}

double GroupingPoint::getDistanceToFurthestNeighbour()
{
    return distanceToFurthestNeighbour;
}

void GroupingPoint::setDistanceToFurthestPoint(double distance)
{
    distanceToFurthestPoint = distance;
}

double GroupingPoint::getDistanceToFurthestPoint()
{
    return distanceToFurthestPoint;
}
