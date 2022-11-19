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

struct graph* readNodirGraph(char *nombreArchivo){
	FILE*pf;		   //para abrir archivo
	pf = fopen(nombreArchivo,"r");
	int n_vertices, m_aristas;
	int i,j,k;
	if (pf ==NULL){
		printf("Error de archivo\n");
		return NULL;
	}else{
		//Cantidad de nodos y aristas
		fscanf(pf, "%d %d", &n_vertices,&m_aristas); 		
		struct graph* G =createVoidGraph(n_vertices);	
		//dependiendo de las lineas de archivo, 
		// 1 para grafo no dirigido no ponderado
		for(k=0;k<m_aristas;k++){
			fscanf(pf,"%d %d",&i, &j); // interesante nota que se realiza la asignacion de manera simetrica
            G->adjMatrix[i-1][j-1] = 1;
			G->adjMatrix[j-1][i-1] = 1;
		}
		fclose(pf);
		return  G;	
	}
}

void dfsVisit(struct graph *gInput, int u, int *pred, int* color){

    color[u] = 1; // gray
    for (int i = 0; i < gInput->edges; i++)
    {
        int v = gInput->adjMatrix[u][i];
        if (v == 1 && color[i] == 0){ // !!!!! aquií hay un bug, color[i] == 0
            printf("v: %d, u: %d, color: %d", u,i,color[i]);
            pred[i] = u;
            dfsVisit(gInput,i,pred,color);
        }
    }
    color[u] = 2; //black

}



int *DFS(struct graph *gInput){
	int *colors = (int*)malloc(sizeof(int) * gInput->edges);
	int *pred = (int*)malloc(sizeof(int) * gInput->edges);
    

	for (int i = 0; i < gInput->edges; i++)
	{
		colors[i] = 0; // white
		pred[i] = -1; // no pred
	}


	for (int i = 0; i < gInput->edges; i++)
	{
        if (colors[i] == 0){
            dfsVisit(gInput,i,pred,colors);
        }
	}	
    return pred;
}



int main (int argc, char *argv[]){

    struct graph *myGraph = readNodirGraph("Grafo.in");
    showGraph(myGraph);
    int *pred = DFS(myGraph);

    for (int i = 0; i < myGraph->edges; i++)
    {
        printf("El predecesor del nodo %d, corresponde al nodo %d",i+1, pred[i]+1);
    }
    



    return 0;
}