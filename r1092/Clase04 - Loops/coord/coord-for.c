#include <stdio.h>
#include <math.h>

int main(void) {
	
	int x,y;
	int cuad;
	double dist;
	
	for(;;) {
		printf("Ingrese coordenadas: ");
		scanf("%d %d", &x, &y);
		
		// Cortar el ciclo infinito
		if(!x && !y) {
			break;
		}
	
		if(x>0 && y>0) {
			cuad=1;
		}
		else if(x<0 && y>0) {
			cuad=2;
		}
		else if(x<0 && y<0) {
			cuad=3;
		}
		else if(x>0 && y<0) {
			cuad=4;
		}
	
		dist = sqrt(pow((double)x,2.0)+pow((double)y,2.0));
		printf("El cuadrante es %d y la distancia %.2f\n", cuad, dist);
	}	
	return 0;		
}

