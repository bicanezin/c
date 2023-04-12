#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b) { 
    
	int temp = *a;
    *a = *b;
    *b = temp;
}

int particionamento(int *v1, int inicio, int fim, int pivo) {
  int pivoP, troca1, j;
  
    if(inicio < fim) {
    	
        pivo = v1[fim];
        troca1 = inicio - 1;
        j = inicio;
        
        for(j = inicio; j < fim; j++) {
            
			if(v1[j] < pivo) {
              
			  troca1++;
              troca (&v1[j], &v1[troca1]);
              
            }
        }
        troca(&v1[fim], &v1[troca1 + 1]);
        
        return troca1 + 1;
    }
    
    return 0;
} 


void quicksort(int *v1, int inicio, int fim, int pivo) {
	int a, pivoP;
	
	int aux[fim - inicio + 1];
	a = -1; 

	aux[++a] = inicio;
	aux[++a] = fim; 	

	while(a >= 0) {

		fim = aux[a--];
		inicio = aux[a--]; 	
		
		pivoP = particionamento(v1, inicio, fim, pivo);


	    if (pivoP - 1 > inicio )
	    {
	    	aux[++a] = inicio;
	    	aux[++a] = pivoP - 1;
	    }

	    if (pivoP + 1 < fim)
	    {
	    	aux[++a] = pivoP + 1;
	    	aux[++a] = fim;
	    }
	}
	

}

void impressao(int *v1, int tam) {
	int i;
	
	for (i = 0; i < tam; i++) {
		printf("[%d] ", v1[i]);
	}
	
	printf ("\n");
}

void pivoVerific(int  *v1, int pivo) {
	int i, n = -1;
	
	for (i = 0; i < 11; i++) {
		
		if (v1[i] == pivo) {
			n = i;
		}
	}
	
	if (n == -1) {
		printf ("\nErro no valor escolhido! tente novamente \n\n");
		exit(0);
	}

}

int main(){
    int vetor[11] = {1, 105, 34, 302, 201, 100, 65, 505, 12, 4, 5};
    int p, i;
      
    printf ("Vetor Original:\n");
    impressao(vetor, 11);
    
    printf ("Escolha um pivo: ");
    scanf ("%d", &p);
    
    pivoVerific(vetor, p);
    
    quicksort(vetor, 0, 10, p);
    printf ("Vetor Ordenado QuickSort:\n");
	impressao(vetor, 11);
	
	return 0;
    
}
