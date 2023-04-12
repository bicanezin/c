#include <stdio.h>
#include <locale.h>

int tam;
//int comp;

void bubble(int tam, int v[]){
    int i, j, aux;
    
    for(i = 0; i < tam; i++){
    	
        for(j = 0; j < tam-1; j++){
        	
            if(v[j] > v[j+1]){
            	
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                j++; 
               
            }
            
           // comp++;
        }
    }
}

void impressao(int tam, int v[]){
	int j;
	
    for(j = 0; j < tam ; j++){
        printf("[%d] ", v[j]);
    }
    
    printf("\n");
}


int main(){
    int v[5] = {10, 35, 7, 0, 22};
    setlocale(LC_ALL, "portuguese");
    	
	printf ("O vetor original: \n");
	impressao(5, v);
	
	bubble(5, v);
	printf ("\nO vetor ordenado: \n");
	impressao(5, v);
	
	//printf ("\n\nComparações: %d", comp);
    
}
