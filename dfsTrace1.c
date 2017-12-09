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


void dfsSweep(IntVec * adjList, int n, char * color, int * dTime1, int * fTime1, int * parent1, IntVec finishStk1){
    time = 0;

    for (int i = 1; i < (n+1); i++){
        color[i] = 'W';
    }
    for (int v = 1; v <= n; v++){
        if (color[v] == 'W'){
            parent1[v] = -1;
            dfs(adjList,color, v, dTime1, fTime1, parent1, finishStk1);
        }
    }
}

void dfs(IntVec * adjList, char * color, int v, int * dTime1, int * fTime1, int * parent1, IntVec finishStk1){
    int w;
    IntVec remAdj;
    int counter;

    color[v] = 'G';
    time++;
    dTime1[v] = time;
    remAdj = adjList[v];
    counter = intSize(remAdj);
    while (counter > 0){
        w = intData(remAdj, counter);
        if (color[w] == 'W'){
            parent1[w] = v;
            dfs(adjList, color, w, dTime1, fTime1, parent1,finishStk1);
        }
        else{
            break;
        }
        counter--;
    }
    time++;
    fTime1[v] = time;
    color[v] = 'B';
    intVecPush(finishStk1, v);
}

void printTable(int n, char * color,int * dTime1,int * fTime1,int * parent1, IntVec finishStk1){

    printf("V\t color\t dTime\t fTime\t parent\t\n");
    for (int i = 1; i < (n+1); i++)
    {
        printf("%d\t %c\t %d\t %d\t %d\t\n", i,color[i], dTime1[i], fTime1[i], parent1[i]);
    }
    printf("\nFSTK: ");
    for (int j = 1; j <= n; j++){
        printf(" %d ", intData(finishStk1, j));
    }
    printf("\n");
}




