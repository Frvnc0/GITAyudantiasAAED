#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

TDAlista * crearListaVacia(){
	TDAlista *lista = (TDAlista*)malloc(sizeof(TDAlista));
	lista->inicio=NULL;
	return lista;
}

int esListaVacia(TDAlista* lista){
	if (lista->inicio == NULL){
		return 1;
	}
	else{
		return 0;
	}
}


void insertarInicio(TDAlista *lista, int dato){
	nodo *nuevo = (nodo*)malloc(sizeof(nodo));
	nuevo->dato = dato;
	nuevo->siguiente = lista->inicio;
	lista->inicio = nuevo;
}

void eliminarInicio(TDAlista* lista){
	nodo *auxiliar;
	if(!esListaVacia(lista)){
		auxiliar = lista->inicio;
		lista->inicio = lista->inicio->siguiente;
		free(auxiliar);
	}
}

void recorrerLista(TDAlista* lista){
	if(!esListaVacia(lista)){
		nodo *auxiliar = lista->inicio;
		while(auxiliar != NULL){
			printf("%d ", auxiliar->dato);
			auxiliar = auxiliar->siguiente;
		}
		printf("\n");
	}
	else{
		printf("La lista está vacía\n");
	}
}

/////////////////////// Tarea 1
int buscarDato(TDAlista* lista, int dato){
	if(!esListaVacia(lista)){
		nodo *auxiliar = lista->inicio;
		while(auxiliar != NULL){
			if (auxiliar->dato == dato) // recordar que es con string compare en caso de que sea string
			{	
				printf("el numero buscado se encontró y es: %d\n", auxiliar->dato);
				return 1;
			}
			auxiliar = auxiliar->siguiente;
		}
	}
	return 0;
}


/////////////////////// Tarea 2
int obtenerNumeroNodos(TDAlista* lista){
	int contadorNodos = 0;
	if(!esListaVacia(lista)){
		nodo *auxiliar = lista->inicio;
		while(auxiliar != NULL){
			contadorNodos++;
			auxiliar = auxiliar->siguiente;
		}
	}
	return contadorNodos;
	
}
