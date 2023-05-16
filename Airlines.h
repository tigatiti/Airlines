#ifndef _AIRLINES
#define _AIRLINES

#include <iostream>
#include <string>
#include <cmath>
#include "LinkedList.h" 
using namespace std;

const int maxSize = 6;

class Airlines
{
    private:
    int adjacencyMatrix[maxSize][maxSize];
    int weightArray[maxSize];
    string airportNames[maxSize];


    ListInterface<int>* notInVertexSet;
    ListInterface<int>* vertexSetPtr;


    public:
    Airlines();
    void computeCheapestFlight();
    int findSmallestVertex();
    bool isInVertexSet (int vertex);
    void printFinalCost();
};

#endif