#include <stdio.h>
#include <stdlib.h>
#include "TDAgrafo.h"

int main(int argc, char *argv[]) 
{

	TDAgrafo* grafo;

	grafo = leerGrafoNoDirigido(argv[1]);
	
	if (grafo!=NULL){
		printf("Matriz de adyacencia: \n");
		imprimirMatrizAdyacencia(grafo);
		printf("----------\n");
	}

	return 0;
}



