#include <stdio.h> 
#include <math.h>
#include "punto.h"



punto crea_punto(float x, float y){
	punto nuevo_punto;
	nuevo_punto.x = x;
	nuevo_punto.y = y;
	return nuevo_punto;
}


float distancia_entre_puntos(punto a, punto b){ 
	float dx = a.x - b.x; 
	float dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}	


float distancia_origen(punto a){
	punto origen = crea_punto(0.0, 0.0);
	return distancia_entre_puntos(origen, a);
}

