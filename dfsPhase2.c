/**
 * Karen Cariaga
 * CruzID: kccariag
 * Assignment: pa3
*/
#include "edge.h"
#include "intVec.h"
#include "loadGraph.h"
#include "dfsPhase2.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void dfsSweepT(IntVec * adjList, int n, char * color, int * dTime2, int * fTime2, int * parent2, IntVec finishStk1, int * scc){
    time2 = 0;
    int v;
    int count = n;

    for (int i = 1; i < (n+1); i++){
        color[i] = 'W';
    }

    while (count > 0){
        v = intTop(finishStk1);
        intVecPop(finishStk1);
        if(color[v] == 'W'){
            parent2[v] = -1;
            dfsT(adjList, color, v ,v, scc, dTime2, fTime2, parent2, finishStk1);
        }
        count--;
    }
}


void dfsT(IntVec * adjList, char * color, int v, int leader, int * scc, int * dTime2, int * fTime2, int * parent2, IntVec finishStk1){
    int w;
    IntVec remAdj;
    int counter;

    color[v] = 'G';
    scc[v] = leader;
    time2++;
    dTime2[v] = time2;
    remAdj = adjList[v];
    counter = intSize(remAdj);
    while (counter > 0){
        w = intData(remAdj, counter);
        if (color[w] == 'W'){
            parent2[w] = v;
            dfsT(adjList, color, w ,leader, scc, dTime2, fTime2, parent2,finishStk1);
        }
        else{
            break;
        }
        counter--;
    }
    time2++;
    fTime2[v] = time2;
    color[v] = 'B';

    //intVecPush(finishStk1, v);
}


void printTable2(int n, char * color,int * dTime2,int * fTime2,int * parent2, int * scc){
    printf("\n");
    printf("V\t color2\t dTime2\t fTime2\t parent2\tdfstRoot2\t\n");
    for (int i = 1; i < (n+1); i++)
    {
        printf("%d\t %c\t %d\t %d\t %d\t\t %d\t\n", i,color[i], dTime2[i], fTime2[i], parent2[i], scc[i]);
    }

}

