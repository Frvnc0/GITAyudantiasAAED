#include <stdio.h>
#include <stdlib.h>
#include "TDAgrafo.h"

int main() 
{
	
	TDAgrafo* grafo;
	grafo = leerGrafoNoDirigidoPonderado("grafo8ponderado.in");
	printf("Matriz de adyacencia: \n");
	imprimirMatrizAdyacencia(grafo);
	printf("----------\n");
	
	
	Dijkstra(grafo, 2); 
	
//	imprimirArreglosDijkstra(grafo->cvertices);
	

	return 0;
}



