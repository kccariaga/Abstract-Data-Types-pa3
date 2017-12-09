/**
 * Karen Cariaga
 * CruzID: kccariag
 * Assignment: pa2
*/
#include "edge.h"
#include "intVec.h"
#include "loadGraph.h"
#include "dfsTrace1.h"
#include "dfsPhase2.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
*   findSCCs call the functions needed for phase 1 and phase 2
*   Then it prints the output
*
*/
void findSCCs(IntVec * adjList, int n, char * color, int * dTime1, int * fTime1,
              int * parent1, IntVec finishStk1,int * dTime2, int * fTime2,
               int * parent2, int * scc, IntVec * trList){
    int ** A;
    printf("\nDFS on G: \n");

    printAdjVerts(adjList, n);
    printf("\n");
    A = makeAdjMatrix(adjList, n);
    printAdjMatrix(A, n);
    printf("\n");

    dfsSweep(adjList, n, color,dTime1, fTime1, parent1, finishStk1);
    printTable(n, color, dTime1, fTime1, parent1, finishStk1);
    for (int i = 1; i <=n; i++){
        free(A[i]);
    }
    free(A);

// -------------------------Phase 2 ----------------------------------------- //
    printf("______________________________________________________________\n");
    printf("\nDFS on G^T:\n");
    printAdjVerts(trList, n);
    printf("\n");
    A = makeAdjMatrix(trList, n);
    printAdjMatrix(A, n);
    printf("\n");

    dfsSweepT(trList, n, color, dTime2,fTime2, parent2, finishStk1, scc);
    printTable2(n, color, dTime2, fTime2, parent2, scc);

    for (int i = 1; i <=n; i++){
        free(A[i]);
    }
    free(A);

}

int main(int argc, char* argv[]){
    int n; /*Number of nodes aka elements in the "array of intVecs" */
    int edgeCount;/*counts number of edges*/
    int flag;
    FILE *fp;
    char * fgetsRet;
    char line[1024];
    char inFile[10];

    if (argc == 3){
        fp = fopen(argv[2],"r");
        if (strcmp(argv[1],"-U") == 0){
            flag = 1;
            printf("flag -U passed\n");
        }
    }
    else{
	    flag = 0;
	    if (strcmp(argv[1],"-") == 0){
            printf("Enter the file name:\n");
            scanf("%s",inFile);
            argv[1] = inFile;
        }
	    fp = fopen(argv[1],"r");
    }

    fgetsRet = fgets(line, 1024,fp);

    //Get the number of nodes and create an array of that size
    sscanf(line, "%d", &n);
    IntVec * adjList = malloc((n+1) * sizeof(IntVec));

    if (fp != NULL ) {
        /*Makes an array of empty vectors*/
        printf("File has been opened\n");
        for (int i= 1; i <= n; i++){
            adjList[i] = intMakeEmptyVec();
        }
        fgets(line,1024,fp);/*Read first line*/
        /*Read the rest of the file and assign values to edges*/

        edgeCount = pushEdges(fgetsRet, line, adjList, n, fp, flag);
        fclose(fp);
    }
    else{
        fprintf(stderr, "No file Received\n");
        exit(1);
    }

/*****************files is read after this point*****************************/
    char * color = malloc((n+1) * sizeof(IntVec));
    int * dTime1 = malloc((n+1) * sizeof(IntVec));
    int * fTime1 = malloc((n+1) * sizeof(IntVec));
    int * parent1 = malloc((n+1) * sizeof(IntVec));
    IntVec finishStk1 = intMakeEmptyVecN(n);

    //Phase 2
    IntVec * trList;
    trList = transposeGraph(adjList, n);
    int * dTime2 = malloc((n+1) * sizeof(IntVec));
    int * fTime2 = malloc((n+1) * sizeof(IntVec));
    int * parent2 = malloc((n+1) * sizeof(IntVec));
    int * scc = malloc((n+1) * sizeof(IntVec));
    printf("n = %d\nm = %d\n",n, edgeCount );
    findSCCs(adjList, n, color, dTime1, fTime1, parent1,finishStk1, dTime2, fTime2,
            parent2, scc, trList);

    free(color);
    free(dTime1);
    free(fTime1);
    free(parent1);
    free(dTime2);
    free(fTime2);
    free(parent2);
    free(scc);
    freeVector(finishStk1);
    freeAdjList(adjList,n);
    freeAdjList(trList, n);
    return 0;
}


