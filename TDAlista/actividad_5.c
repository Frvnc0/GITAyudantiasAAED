#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char const *argv[])
{

	TDAlista * lista = crearListaVacia();
	int valor = esListaVacia(lista);
	//printf("%d", valor);
	insertarInicio(lista, 5);
 	insertarInicio(lista, 7);
	recorrerLista(lista);
	eliminarInicio(lista);
	recorrerLista(lista);
	buscarDato(lista, 5);

/*
	insertarInicio(lista, 4);
	insertarInicio(lista, 2);
	recorrerLista(lista);
	eliminarInicio(lista);
	insertarInicio(lista, 3);
	recorrerLista(lista);
 */	return 0;
}

