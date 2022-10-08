#include <stdio.h>
#include "punto.h"


int main(){
	float x1, y1, x2, y2, resultado;
	printf("Calcula la distancia entre dos puntos: \n");
	printf("Ingrese la abscisa del primer punto \n");
	scanf("%f", &x1);
	printf("Ingrese la ordenada del primer punto \n");
	scanf("%f", &y1);
	printf("Ingrese la abscisa del segundo punto \n");
	scanf("%f", &x2);
	printf("Ingrese la ordenada del segundo punto \n");
	scanf("%f", &y2);

	punto punto_uno = crea_punto(x1, y1);
	punto punto_dos = crea_punto(x2, y2);
	
	resultado = distancia_entre_puntos(punto_uno, punto_dos);
	
	printf("La distancia entre los puntos es: %.2f \n", resultado);
	
    return 0;
}

