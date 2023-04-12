#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include <locale.h>

int main(){
	
	setlocale(LC_ALL, "portuguese");
	
    Point * p1 = point_create(2.0, 1.0);
    Point * p2 = point_create(3.4, 2.1);
    
    printf("\nImprimindo ponto p1:\n");
    point_print(p1);
    
    printf("\nImprimindo ponto p2:\n");
    point_print(p2);
    
    printf("\n\nImprimindo a distância entre os pontos:\n");
    point_distance(p1, p2);
    
    printf("\n\nLimpando memória.\n");
    point_free(p1);
    point_free(p2);
    
    return 0;
}


