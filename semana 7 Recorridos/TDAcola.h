#include <stdio.h>
#include <stdlib.h>
#include "TDAlista.h"

// /*------------- Estructuras de Datos -------------*/
// typedef struct nodoGenerico {
	// int dato;
	// struct nodoGenerico* siguiente;
// } nodo;

// /* Crea un nodo 
 // * entrada {int} dato           información del nodo.
 // * retorno {nodo*}              Instancia del nuevo nodo. */
// nodo* crearNodo(int dato)
// {
	// nodo* nuevo = (nodo*)malloc(sizeof(nodo));
	// nuevo->dato = dato;
	// nuevo->siguiente = NULL;
	// return nuevo;
// }

typedef struct {
	int capacidad;
	int size;
	nodo* n_frente;
	nodo* n_final;
} TDAcola;


/*------------- Operaciones -------------*/
/* Crea una nueva instancia de la estructura cola.
 * Entrada(s) {int} capacidad       Capacidad maxima de la cola.
 * Salida  {TDAcola*}           Nueva instacia de una cola. */
TDAcola* crearColaVacia(int capacidad)
{
	TDAcola* cola = (TDAcola*)malloc(sizeof(TDAcola));
	cola->capacidad = capacidad;
	cola->size = 0;
	cola->n_frente = NULL;
	cola->n_final = NULL;
	return cola;
}

/* Verifica si una cola esta vacia o no.
 * Entrada(s) {TDAcola*} cola     
 * Salida  {int}                0 o 1, dependiendo de si es falso o verdadero . */
int esColaVacia(TDAcola* cola)
{
	if (cola->size == 0)
		return 1;
	return 0;
}

/* Agrega a la cola un nuevo dato.
 * Entrada(s) {TDAcola*} cola       Cola en la cual agregar el nuevo elemento.
 * Entrada(s) {int} dato            Dato a agregar. */
void encolar(TDAcola* cola, int dato)
{
	if(cola->size == cola->capacidad) return;

    nodo *nuevoNodo = crearNodo(dato);
    if(cola->n_frente == NULL){
        cola->n_frente = nuevoNodo;
        cola->n_final = nuevoNodo;
        cola->size = 1;
    }
    else{
        cola->n_final->siguiente = nuevoNodo;
        cola->n_final = nuevoNodo;
        cola->size=cola->size+1;
    }
}

/* Desencola (del frente).
 * Entrada(s) {TDAcola*} cola  */
void desencolar(TDAcola* cola)
{
    if(cola->size == 1){
        free(cola->n_frente);
        cola->n_frente = NULL;
        cola->n_final = NULL;
        cola->size = 0;
    }
    else if(cola->size > 1){
        nodo *auxNodo = cola->n_frente;
        cola->n_frente = cola->n_frente->siguiente;
        free(auxNodo);
        cola->size=cola->size-1;
    }
}

/* Devuelve el nodo "frente" de la cola.
 * Entrada(s) {TDAcola*} cola       Cola de la cual obtener el nodo "frente".
 * Salida  {nodo*}              Instancia de un nodo.*/
nodo* frente(TDAcola* cola)
{
    return cola->n_frente;
}

/* Devuelve el nodo "final" de la cola.
 * Entrada(s) {TDAcola*} cola       Cola de la cual obtener el nodo "final".
 * Salida  {nodo*}              Instancia de un nodo.*/
nodo* colaFinal(TDAcola* cola)
{
    return cola->n_final;
}

/* Libera de la memoria un struct cola y los nodos que contenga.
 * Entrada(s) {TDAcola} cola        Cola a liberar.*/
void liberarCola(TDAcola* cola)
{
	while(!esColaVacia(cola)){
		desencolar(cola);
	}
	free(cola);
}
