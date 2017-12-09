/**
 * Karen Cariaga
 * CruzID: kccariag
 * Assignment: pa3
*/
#include "edge.h"
#include "intVec.h"
#include "loadGraph.h"
#include "dfsTrace1.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//global time variable
int time2;

/**
*   This function is similar to dfsSweep where it recursively calls the dfsT function
    until the search is done
    dfsSweepT, will call the dfsT function starting from the top of the finishStack
*   It begins by initializing the char * color array to 'W'.
*   W - Undiscovered Vertex
*   G - Vertex is discovered and there are other vertices to discover
*   B - Vertex is discovered and is completely searched
*   Precondition: Adjacency list is created, dTime1, fTime1, parent1, and finishStk1
*                   is initialized.
*   Postcondition:
*           /time/ = 0;
*           char * color[] = 'W'
*           v = intTop(finishStk1)
*           intVecPop(finishStk1);
*/
void dfsSweepT(IntVec * adjList, int n, char * color, int * dTime2, int * fTime2, int * parent2, IntVec finishStk1, int * scc);

/**
*   dfsT is essentially the same as dfs. it begins the search by initially setting
*   the color[v] to gray, denoting that
*   the vertex v is discovered and dfs will search for other vertices to be discovered
*   (in this case it is  vertex w)
*   The difference is that it takes in a variable as leader and sets the SCC array
*   to that vertex.
*   Preconditions: = same as dfsSweep and additionally color[] must be initialized to  'W'
*   Postconditions:
*           dTime++
*           fTime++
*           When the search is done the vector, v, is completely empty
*           scc[v] = leader;
*
*/
void dfsT(IntVec * adjList, char * color, int v, int leader, int * scc, int * dTime2, int * fTime2, int * parent2, IntVec finishStk1);

//prints the second table
void printTable2(int n, char * color,int * dTime2,int * fTime2,int * parent2, int * scc);
