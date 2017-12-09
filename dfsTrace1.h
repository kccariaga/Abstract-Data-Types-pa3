/**
 * Karen Cariaga
 * CruzID: kccariag
 * Assignment: pa3
*/
#include "edge.h"
#include "intVec.h"
#include "loadGraph.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//global time variable for dfsTrace1
int time;

/**
*   This function recursively calls the dfs function until the search is done
*   It starts from vertex 1 and works to vertex n
*   It begins by initializing the char * color array to 'W'.
*   W - Undiscovered Vertex
*   G - Vertex is discovered and there are other vertices to discover
*   B - Vertex is discovered and is completely searched
*   Precondition: Adjacency list is created, dTime1, fTime1, parent1, and finishStk1
*                   is initialized.
*   Postcondition:
*           /time/ = 0;
*           char * color[] = 'W'
*
*
*/
void dfsSweep(IntVec * adjList, int n, char * color, int * dTime1, int * fTime1, int * parent1, IntVec finishStk1);

/**
*   dfs begins the search by initially setting the color[v] to gray, denoting that
*   the vertex v is discovered and dfs will search for other vertices to be discovered
*   (in this case it is  vertex w)
*   Preconditions: = same as dfsSweep and additionally color[] must be initialized to  'W'
*   Postconditions:
*           dTime++
*           fTime++
*           When the search is done the vector, v, is pushed into the finishing stack
*           intVecPush(finishStk1, v);
*
*/
void dfs(IntVec * adjList, char * color, int v, int * dTime1, int * fTime1, int * parent1, IntVec finishStk1);

//Prints Table
void printTable(int n, char * color,int * dTime1,int * fTime1,int * parent1, IntVec finishStk1);



