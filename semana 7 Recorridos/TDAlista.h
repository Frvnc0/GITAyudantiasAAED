#include <stdio.h>
#include <stdlib.h>

/*------------- Estructura de Datos -------------*/

typedef struct nodoGenerico {
	int dato;
	struct nodoGenerico* siguiente;
} nodo;

/* Crea un nodo 
 * entrada {int} dato           información del nodo.
 * retorno {nodo*}              Instancia del nuevo nodo. */
nodo* crearNodo(int dato)
{
	nodo* nuevo = (nodo*)malloc(sizeof(nodo));
	nuevo->dato = dato;
	nuevo->siguiente = NULL;
	return nuevo;
}

typedef struct listaGenerica {
	nodo* inicio;
} TDAlista;


/*------------- Operaciones -------------*/
TDAlista* crearListaVacia()
{
	TDAlista* lista=(TDAlista*)malloc(sizeof(TDAlista));
	lista->inicio=NULL;
	return lista;
}

int esListaVacia(TDAlista* lista)
{
	if (lista->inicio == NULL)
		return 1;
	else
		return 0;
}

void recorrerLista(TDAlista* lista)
{
	if (!esListaVacia(lista))
	{
		nodo* auxiliar=lista->inicio;
		while (auxiliar!=NULL)
		{
			printf("%d ",auxiliar->dato);
			auxiliar=auxiliar->siguiente;
		}
		printf("\n");
	}
	else
		printf("La lista está vacía\n");
}

void insertarInicio(TDAlista* lista, int dato)
{
	nodo* nuevo = crearNodo(dato);
	nuevo->siguiente = lista->inicio;
	lista->inicio = nuevo;
}

void eliminarInicio(TDAlista* lista)
{
	nodo* auxiliar;
	if(!esListaVacia(lista))
	{
		auxiliar=lista->inicio;
		lista->inicio=lista->inicio->siguiente;
		free(auxiliar);
	}
}

/* Libera de la memoria los struct de lista y los nodos.
 * Entrada(s) {TDAlista} lista      Lista a liberar.*/
void liberarLista(TDAlista* lista)
{
	while(!esListaVacia(lista)){
		eliminarInicio(lista);
	}
	free(lista);
}

/* Retorna el indice/posición del dato en el arreglo.
 * En caso de que no exista retorna -1.
 * Entrada(s)  {TDAlista} lista      
 * Entrada(s)  {int}      dato       
 * retorno {int}                 Indice de la posición.*/
int buscarDato(TDAlista* lista, int dato)
{
	nodo* aux = lista->inicio;
	int index = 0;
	while(aux != NULL){
		if(aux->dato == dato){
			return index;
		}
		aux = aux->siguiente;
		index=index+1;
	}
	return -1;
}

/* Cuenta el numero de nodos en la lista.
 * Entrada(s)  {TDAlista} lista   
 * retorno {int}                 Numero de nodos en la lista.*/
int obtenerNumeroNodos(TDAlista* lista)
{
	nodo* aux = lista->inicio;
	int total = 0;
	while(aux != NULL){
		total=total+1;
		aux = aux->siguiente;
	}
	return(total);
}

/* Agregar un elemento al final de la lista.
 * Entrada(s)  {TDAlista} lista      
 * Entrada(s)  {int}      dato       */
void insertarNodoFinal(TDAlista* lista, int dato)
{
	if(!esListaVacia(lista)){
		nodo *aux = lista->inicio;
		while(aux->siguiente != NULL){
			aux = aux->siguiente;
		}
		nodo* nuevo = crearNodo(dato);
		aux->siguiente = nuevo;
	}
	else{
		insertarInicio(lista, dato);
	}
}

/* Agregar un elemento despues de otro.
 * Entrada(s)  {TDAlista} lista         
 * Entrada(s)  {int}      dato          Dato a agregar.
 * Entrada(s)  {int}      datoAnterior  Dato a buscar.*/
void insertarNodoDespues(TDAlista* lista, int dato, int datoAnterior)
{
	if(esListaVacia(lista)) return;

	nodo *aux = lista->inicio;
	nodo *nuevo;
	while(aux != NULL){
		if(aux->dato == datoAnterior){
			nuevo = crearNodo(dato);
			nuevo->siguiente = aux->siguiente;
			aux->siguiente = nuevo;
			break;
		}
		aux = aux->siguiente;
	}
}

/* Elimina el ultimo elemento de la lista.
 * Entrada(s)  {TDAlista} lista      */
void eliminarFinal(TDAlista* lista)
{
	if(esListaVacia(lista)) return;

	nodo *aux1 = lista->inicio;
	nodo *aux2 = aux1->siguiente;

	if(aux2 == NULL){
		free(aux1);
		lista->inicio = NULL;
	}
	else{
		while(aux2->siguiente != NULL){
			aux1 = aux1->siguiente;
			aux2 = aux1->siguiente;
		}

		aux1->siguiente = NULL;
		free(aux2);
	}
}

/* Buscar un elemento por su dato y eliminarlo (si existe).
 * Entrada(s)  {TDAlista} lista      
 * Entrada(s)  {int}      dato       Dato a buscar.
 */
void eliminarDato(TDAlista* lista, int dato)
{
	nodo* anterior = NULL;
	nodo* aux = lista->inicio;
	while(aux != NULL){
		if(aux->dato == dato){
			if(anterior == NULL){
				lista->inicio = aux->siguiente;
			}
			else{
				anterior->siguiente = aux->siguiente;
			}
			free(aux);
			break;
		}
		anterior = aux;
		aux = aux->siguiente;
	}
}

/* Obtiene un nodo de la lista dada su posicion en este (las posisciones parten en 1).
 * En caso de que la posicion no exista, retorna NULL.
 * Entrada(s)  {TDAlista} lista     
 * retorno {nodo*}               Nodo buscado.
 */
nodo* obtenerNodo(TDAlista* lista, int posicion)
{
	if(esListaVacia(lista)) return NULL;

	nodo *aux = lista->inicio;
	int pos = 1;
	while(aux != NULL){
		if(pos == posicion){
			return aux;
		}
		pos=pos+1;
		aux = aux->siguiente;
	}
	return NULL;
}