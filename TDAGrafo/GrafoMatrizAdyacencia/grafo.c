#include <stdio.h>
#include <stdlib.h>

struct graph{
    int edges;
    int **adjMatrix;
};

struct graph *createVoidGraph(int nEdges){
    struct graph *graphReturn = (struct graph*)malloc(sizeof(struct graph));

    int **adjMatrixReturn =(int**)malloc(sizeof(int*)*nEdges);
    for (int i = 0; i < nEdges; i++)
    {
        adjMatrixReturn[i] = (int*)malloc(sizeof(int)*nEdges);
        for (int j = 0; j < nEdges; j++)
        {
            adjMatrixReturn[i][j] = 0;
        }
    }
    graphReturn->adjMatrix = adjMatrixReturn;
    graphReturn->edges = nEdges;
    return graphReturn;
};

void showGraph (struct graph *graphInput){

    for (int i = 0; i < graphInput->edges; i++)
    {
        for (int j = 0; j < graphInput->edges; j++)
        {
            printf("%d ", graphInput->adjMatrix[i][j]);

        }
        printf("\n");
    }
}

void insertNode(struct graph *graphInput, int adj1, int adj2){
    graphInput->adjMatrix[adj1][adj2];
    graphInput->adjMatrix[adj2][adj1];
}


int main (int argc, char *argv[]){

    struct graph *myGraph = createVoidGraph(4);
    showGraph(myGraph);

    return 0;
}