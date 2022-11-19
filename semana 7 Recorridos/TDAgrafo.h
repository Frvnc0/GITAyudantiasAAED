#include <stdio.h>
#include <stdlib.h>
#include "TDAcola.h"

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
			printf("%d ", grafo->adyacencias[i][j]);
		}
		printf("\n");
	}
}

int adyacenciaNodos(TDAgrafo * grafo, int vertA, int vertB)
{
	if (grafo->adyacencias[vertA - 1][vertB - 1] == 1) {
		return 1;
	}
	return 0;
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

/* Devuelve la lista de adyacencias un vertice dado.
 * Entrada(s)  {TDAgrafo*} grafo         Grafo a utilizar.
 * Entrada(s)  {int}       vertice       Vertice en el cual buscar las adyacencias.
 * Salida {TDAlista*}              Lista de adyacencias.*/
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


/* Verifica si una secuencia es un ciclo dentro del grafo.
 * Entrada(s)  {TDAgrafo*} grafo         Grafo a utilizar.
 * Entrada(s)  {TDAlista*} lista         Secuencia de vertices.
 * Salida {int}                    0 o 1 dependiendo de si es no un ciclo.*/
int esCiclo(TDAgrafo* grafo, TDAlista* secuencia)
{
	int vertice = secuencia->inicio->dato;
	int primerVertice = vertice;
	eliminarInicio(secuencia);

	nodo *aux = secuencia->inicio;
	while(aux != NULL){
		if(!adyacenciaNodos(grafo, vertice, aux->dato)){
			return 0;
		}

		vertice = aux->dato;
		aux = aux->siguiente;
	}

	return(primerVertice == vertice);
}

/* Libera de la memoria un grafo dado.
 * Entrada(s)  {TDAgrafo*} grafo         Grafo a liberar.*/
void liberarGrafo(TDAgrafo* grafo)
{
	for(int i = 0; i < grafo->cvertices; ++i){
		free(grafo->adyacencias[i]);
	}
	free(grafo->adyacencias);
	free(grafo);
}

/* Recorre en anchura un grafo dado.
 * Entrada(s)   {TDAgrafo*} grafo      Grafo a recorrer.
 * Entrada(s)   {int}       vertice    Vertice de inicio.*/
void RecorridoAnchura(TDAgrafo *grafo, int vertice)
{
//actividad
}

