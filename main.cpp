#include <iostream>
#include "Airlines.h"
#include "Airlines.cpp"
#include "Node.cpp"
#include "ListInterface.h"
#include "PrecondViolatedExcep.h"
#include "PrecondViolatedExcep.cpp"
#include "LinkedList.cpp"

using namespace std;
int main()
{
  Airlines graph;

  graph.computeCheapestFlight();
  return 0;
}