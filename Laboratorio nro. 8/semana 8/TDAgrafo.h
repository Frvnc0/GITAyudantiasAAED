#include <stdio.h>
#include <stdlib.h>
#include "TDAlista.h"

#define INFINITO 123456789  //o podria ser un numero mayor a la suma de todas las aristas

int* d_padre;
int* d_distancia;
int* d_visto;

/*------------- estructura de datos -------------*/

typedef struct matrizGrafo {
	int cvertices;
	int** adyacencias;
} TDAgrafo;


/*----------------- operaciones -----------------*/

TDAgrafo* crearGrafoVacio(int vertices)
{
	TDAgrafo* grafo = (TDAgrafo*)malloc(sizeof(TDAgrafo));
	grafo->cvertices = vertices;
	grafo->adyacencias = (int**)malloc(vertices * sizeof(int*));
	int i,j;

	for (i = 0; i < vertices; i++) {
		grafo->adyacencias[i] = (int*)malloc(vertices * sizeof(int));
		//Inicializa en cero
		for(j=0;j<vertices;j++){
			grafo->adyacencias[i][j] = 0;
		}
	}

	return grafo;
}

void imprimirMatrizAdyacencia(TDAgrafo* grafo)
{
	int i, j;

	for (i = 0; i < grafo->cvertices; i++) {
		for (j = 0; j < grafo->cvertices; j++) {
			printf("%2d ", grafo->adyacencias[i][j]);
		}
		printf("\n");
	}
}

int adyacenciaNodos(TDAgrafo * grafo, int vertA, int vertB)
{
	return grafo->adyacencias[vertA - 1][vertB - 1];
}


//NoDirigido NoPonderado
TDAgrafo* leerGrafoNoDirigido(char *nombreArchivo){
	//para abrir archivo
	FILE*pf;
	pf = fopen(nombreArchivo, "r");
	int n_vertices, m_aristas;
	int i, j, k;

	if (pf == NULL){
		printf("Error de archivo\n");
		return NULL;
	}
	else{
		//Cantidad de nodos y aristas
		fscanf(pf, "%d %d", &n_vertices, &m_aristas);
		TDAgrafo *G = crearGrafoVacio(n_vertices);

		//dependiendo de las lineas de archivo,
		// 1 para grafo no dirigido no ponderado
		for(k=0; k < m_aristas; ++k){
			fscanf(pf,"%d %d",&i, &j);
			G->adyacencias[i-1][j-1] = 1;
			G->adyacencias[j-1][i-1] = 1;
		}
		fclose(pf);

		return  G;
	}
}

/* Crea un grafo no dirigido ponderado a partir de datos de un archivo.
 * @param {char*} nombreArchivo     String que contiene el nombre del archivo.
 * @return {TDAgrafo*}              TDA del grafo. */
TDAgrafo* leerGrafoNoDirigidoPonderado(char *nombreArchivo){
	//para abrir archivo
	FILE*pf;
	pf = fopen(nombreArchivo, "r");
	int n_vertices, m_aristas;
	int i, j, k, p;
	if (pf == NULL){
		return NULL;
	}
	else{
		//Cantidad de nodos y aristas
		fscanf(pf, "%d %d", &n_vertices, &m_aristas);
		TDAgrafo *G = crearGrafoVacio(n_vertices);
		// 1 para grafo no dirigido no ponderado
		for(k=0; k < m_aristas; ++k){
			fscanf(pf,"%d %d %d",&i, &j, &p);
			G->adyacencias[i-1][j-1] = p;
			G->adyacencias[j-1][i-1] = p;
		}
		fclose(pf);
		return  G;
	}
}

/* Devuelve la lista de adyacencias un vertice dado.
 * @param {TDAgrafo*} grafo         Grafo a utilizar.
 * @param {int}       vertice       Vertice en el cual buscar las adyacencias.
 * @return {TDAlista*}              Lista de adyacencias.*/
TDAlista* obtenerAdyacentes(TDAgrafo* grafo, int vertice)
{
	if(vertice > grafo->cvertices)
		return NULL;

	TDAlista *lista = crearListaVacia();

	for(int i = 0; i < grafo->cvertices; ++i){
		if(adyacenciaNodos(grafo, vertice, i+1)){
			insertarInicio(lista, i+1);
		}
	}

	return(lista);
}


/* Libera de la memoria un grafo dado.
 * @param {TDAgrafo*} grafo         Grafo a liberar. */
void liberarGrafo(TDAgrafo* grafo)
{
	for(int i = 0; i < grafo->cvertices; ++i){
		free(grafo->adyacencias[i]);
	}
	free(grafo->adyacencias);
	free(grafo);
}


int quedanSinVisitar(int* d_visto, int cvertices){
	for(int i=0;i<cvertices; i++){
		if (d_visto[i]==0)
			return(1);
	}
	return(0);
}

int extraerMinimo(int* d_distancia,int* d_visto, int cvertices){
	int minimo=9999;
	int indiceMinimo=-1;
	
	for(int i=0;i<cvertices; i++){
		if (d_visto[i]==0 &&d_distancia[i]<minimo){			
			minimo=d_distancia[i];
			indiceMinimo=i;
		}	
	}	
	
	return(indiceMinimo + 1);	
}

// Actividad semana 8

void Dijkstra(TDAgrafo* grafo, int s){       	// Dijkstra(G, s)              	… se parte con s
	
	d_padre=(int*)malloc(sizeof(int)*grafo->cvertices);
	d_visto=(int*)malloc(sizeof(int)*grafo->cvertices);
	d_distancia=(int*)malloc(sizeof(int)*grafo->cvertices);


}	



void imprimirArreglosDijkstra(int cvertices){
	printf("\n vertices : ");
	for (int l=0; l<cvertices;l++){
		printf("%d ", (l + 1));
	}
	printf("\n d_padre : ");
	for (int l=0; l<cvertices;l++){
		printf("%d ", (d_padre[l] + 1));
	}
	printf("\n d_distancia : ");
	for (int l=0; l<cvertices;l++){
		printf("%d ",d_distancia[l]);
	}
	printf("\n d_visto : ");
	for (int l=0; l<cvertices;l++){
		printf("%d ",d_visto[l]);
	}
	printf("\n ");
	

}