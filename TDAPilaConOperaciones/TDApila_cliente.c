#include <stdio.h>
#include <stdlib.h>
#include "TDApila.h"

int main(int argc, char const *argv[])
{

	TDApila *newPila;
	newPila = crearPilaVacia(5);
	nodo *top;

	apilar(newPila, 5);

	top = tope(newPila);
	printf("tope: %d \n", top->dato);

	apilar(newPila, 6);
	top = tope(newPila);
	printf("tope: %d \n", top->dato);

	apilar(newPila, 8);
	top = tope(newPila);
	printf("tope: %d \n", top->dato);

	desapilar(newPila);
	top = tope(newPila);
	printf("tope: %d \n", top->dato);

	return 0;
}