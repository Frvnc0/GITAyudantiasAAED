
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

