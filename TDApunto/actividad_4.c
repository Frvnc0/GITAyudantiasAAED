#include <math.h>  
#include <stdio.h>
#include <stdlib.h>
#include "punto.h"


float flotante_aleatorio(){ 
	return 1.0 * rand()/RAND_MAX;
	}
	
	
int main(int argc, char *argv[]){
	
	int N = atoi(argv[1]);
	float distancia = atof(argv[2]);
	int i, j, contador = 0;
	
	punto *a = malloc(N * (sizeof(*a)));
	
	for (i = 0; i < N; i++){
		a[i].x = flotante_aleatorio(); 
		//printf("x(%d) = %f\n",i ,a[i].x);
		a[i].y = flotante_aleatorio();
		//printf("y(%d) = %f\n",i ,a[i].y);		
		} 
		
	for (i = 0; i < N; i++){ 
		for (j = i + 1; j < N; j++){
			if (distancia_entre_puntos(a[i], a[j]) < distancia){ 
				contador++; 
			}
		}
	}
	
	printf("%i pares de puntos con distancia menor que: %.2f\n", contador, distancia);
	return 0;
}

