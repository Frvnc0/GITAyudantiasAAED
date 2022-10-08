

typedef struct nodoGenerico{
	int dato;
	struct nodoGenerico *siguiente;
}nodo;

typedef struct listaGenerica{
	nodo *inicio;
}TDAlista;


//Operaciones del TDA
TDAlista * crearListaVacia();  //  !!!! ojo
int esListaVacia(TDAlista* lista);
void insertarInicio(TDAlista *lista, int dato);
void eliminarInicio(TDAlista* lista);
void recorrerLista(TDAlista* lista);
int buscarDato(TDAlista* lista, int dato);
int obtenerNumeroNodos(TDAlista* lista);