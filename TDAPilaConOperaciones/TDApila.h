
typedef struct nodoGenerico{
	int dato;
	struct nodoGenerico* siguiente;
}nodo;


typedef struct {
	int capacidad;
	int size;
	nodo *tope;
}TDApila;


/*
Entrada: capacidad de la pila
Salida: una pila vacia, es decir, cero elementos
Descripción: función que permite crear una pila vacía
*/
TDApila* crearPilaVacia(int capacidad){
	TDApila *pila = (TDApila*)malloc(sizeof(TDApila));
	pila->capacidad = capacidad;
	pila->size = 0;
	pila->tope = NULL;
	return pila;
}


/*
Entrada: pila
Salida: 1 en caso de ser vacía, 0 caso contrario
Descripción: función que permite determinar si una pila está vacía
*/
int esPilaVacia(TDApila *pila){
	if(pila->size == 0){
		return 1;
	}
	else{
		return 0;
	}
}








/*
entrada: pila y elemento a apilar
salida: pila con nuevo elemento
descripción: se verifica el tamaño de la pila y si todo está ok
se añade un nuevo nodo con su elemento y respetivo elemento siguiente
Se añade en el tope
*/
void apilar(TDApila* pila, int dato){
	if(pila->size < pila->capacidad){
		if(pila->size == 0){
			nodo *nuevo = (nodo*)malloc(sizeof(nodo));
			nuevo->dato = dato;
			nuevo->siguiente = NULL;
			pila->tope = nuevo;
			pila->size++;
	}
		else {
			nodo *nuevo = (nodo*)malloc(sizeof(nodo));
			nuevo->dato = dato;
			nuevo->siguiente = pila->tope;
			pila->tope = nuevo;
			pila->size++;
	}
}
}

/*
entrada: pila 
salida: pila con un elemento menos
descripción: se verifica el tamaño de la pila y si todo está ok
se elimina el elemento ubicado en el tope
*/
void desapilar(TDApila *pila){
	if(pila->size > 1){
		nodo *auxiliar;
		auxiliar = pila->tope;
		pila->tope = pila->tope->siguiente;
		pila->size--;
		free(auxiliar);	
	}
	else if(pila->size == 1){
		nodo *auxiliar;
		auxiliar = pila->tope;
		pila->tope = NULL;
		pila->size = 0;
		free(auxiliar);	
	}
}

/*
entrada: pila 
salida: nodo tope
descripción: se accede al tope para mostrar su contenido
*/
nodo* tope(TDApila *pila){
	if(!esPilaVacia(pila)){
		return pila->tope;
	}
	else
		return NULL;
}

/*
entrada: pila 
salida: se muestra por pantalla los elementos de la pila
descripción: sse elimina y agrega los elementos de la pila con el fin
de poder acceder a todos los valores de la pila
*/
void recorrer(TDApila *pila){
	TDApila *final;
	final = crearPilaVacia(pila->capacidad);
	nodo *valor, *valor2;
	if(!esPilaVacia(pila)){
		while(pila->tope!=NULL){
				/*
				utilizar desapilar y tope, hay que tener control solo en 
				el tope
				*/
				valor = tope(pila);
				printf("%d ", valor->dato );
				apilar(final, valor->dato);
				desapilar(pila);
		}	
		while(final->tope != NULL){
			valor2 = tope(final);
			apilar(pila, valor2->dato);
			desapilar(final);
		}
		printf("\n");	
	}
}

/*
entrada: pila y elemento a buscar
salida: uno en caso de estar el valor, 0 en caso contrario
descripción: similar a recorrer, 
a medida que se recorre se consulta pr el valor leido
*/
int buscar(TDApila *pila, int numBuscado){
	TDApila *final;
	final = crearPilaVacia(pila->capacidad);
	nodo *valor, *valor2;
	int verificador = 0;
	if(!esPilaVacia(pila)){
		while(pila->tope!=NULL){
				/*
				utilizar desapilar y tope, hay que tener control solo en 
				el tope
				*/
				valor = tope(pila);
				printf("%d ", valor->dato );
				if(numBuscado == valor->dato){
					
					verificador = 1;
				}
				apilar(final, valor->dato);
				desapilar(pila);
		}	
		while(final->tope != NULL){
			valor2 = tope(final);
			apilar(pila, valor2->dato);
			desapilar(final);
		}
		
		if (verificador == 1)
		{
			printf("true\n");
			return 1;
		}
		else{
			printf("false\n");
			return 0;
		}
		printf("\n");	
	}
}


