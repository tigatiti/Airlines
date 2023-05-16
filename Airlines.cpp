#include "Airlines.h"
  
Airlines::Airlines()
{
    //ROW 0 SFO
    airportNames[0] = "SFO";
    adjacencyMatrix[0][0] = 9999;
    adjacencyMatrix[0][1] = 120;
    adjacencyMatrix[0][2] = 150;
    adjacencyMatrix[0][3] = 9999;
    adjacencyMatrix[0][4] = 9999;
    adjacencyMatrix[0][5] = 500;

   //ROW 1 LAX

    airportNames[1] = "LAX";
    adjacencyMatrix[1][0] = 120;
    adjacencyMatrix[1][1] = 9999;
    adjacencyMatrix[1][2] = 9999;
    adjacencyMatrix[1][3] = 75;
    adjacencyMatrix[1][4] = 9999;
    adjacencyMatrix[1][5] = 350;


   //ROW 2 LAS
    airportNames[2] = "LAS";
    adjacencyMatrix[2][0] = 150;
    adjacencyMatrix[2][1] = 9999;
    adjacencyMatrix[2][2] = 9999;
    adjacencyMatrix[2][3] = 9999;
    adjacencyMatrix[2][4] = 250;
    adjacencyMatrix[2][5] = 9999;

   //ROW 3 PHX
    airportNames[3] = "PHX";
    adjacencyMatrix[3][0] = 9999;
    adjacencyMatrix[3][1] = 75;
    adjacencyMatrix[3][2] = 9999;
    adjacencyMatrix[3][3] = 9999;
    adjacencyMatrix[3][4] = 150;
    adjacencyMatrix[3][5] = 9999;

   //ROW 4 DEN
    airportNames[4] = "DEN";
    adjacencyMatrix[4][0] = 9999;
    adjacencyMatrix[4][1] = 250;
    adjacencyMatrix[4][2] = 150;
    adjacencyMatrix[4][3] = 9999;
    adjacencyMatrix[4][4] = 9999;
    adjacencyMatrix[4][5] = 9999;

   //ROW 5 JFK
    airportNames[5] = "JFK";
    adjacencyMatrix[5][0] = 500;
    adjacencyMatrix[5][1] = 350;
    adjacencyMatrix[5][2] = 9999;
    adjacencyMatrix[5][3] = 9999;
    adjacencyMatrix[5][4] = 9999;
    adjacencyMatrix[5][5] = 9999;


    notInVertexSet = new LinkedList<int>();    
    vertexSetPtr = new LinkedList<int>();      
}


void Airlines::computeCheapestFlight()
{
    int numVerticies = maxSize;        
    for(int v = 0; v < numVerticies; v++)
    {
        weightArray[v] = adjacencyMatrix[0][v];
    }


    vertexSetPtr->insert(1,0);      

    for(int v = 0; v < numVerticies; v++)
    {
        notInVertexSet->insert(v, weightArray[v]);
    }

    for(int i = 1; i < numVerticies; i++)
    {
        int v = findSmallestVertex();
        //cout << v << endl;
        for ( int i = 1; i <= notInVertexSet->getLength(); i++)
        {
            
            if(weightArray[i] > weightArray[v]+adjacencyMatrix[v][i])
            {

            weightArray[i] = weightArray[v]+adjacencyMatrix[v][i];
            }
        }
    }

    printFinalCost();
}



int Airlines::findSmallestVertex()
{
    int currentSmallest = 500;
    int position = -1;

    for( int i = 1; i <= notInVertexSet->getLength(); i++)
    {
        if( weightArray[i] < currentSmallest && !isInVertexSet(i))
        {   
            currentSmallest = weightArray[i];
            position = i;
        }
    }

    // Check if a valid position was found
    if(position != -1) {
        vertexSetPtr->insert(vertexSetPtr->getLength()+1, position); // add point to Vertex Set after calling it.
    }
    return position;
}



//check if the position already in the vertexSet
bool Airlines::isInVertexSet(int vertex)
{

    for(int i = 1; i<= vertexSetPtr->getLength(); i++)
    {
        if(vertexSetPtr->getEntry(i) == vertex)
        {
            return true;
        }
    }
    return false;
}


void Airlines::printFinalCost()
{
    for(int i = 1; i < maxSize; i++)
    {
        cout << "The cheapest route from SFO to " << airportNames[i] <<" is " << weightArray[i] << endl;
    }
}
