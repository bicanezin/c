/*faça uma função recursiva que permita somar 
os elementos de um vetor de inteiros*/

#include <stdio.h>
#include <locale.h>

int *pvet = NULL;
int qtd = 0;

int main () {
	
	setlocale(LC_ALL,"portuguese");
	
	entrada();
	soma(qtd);
	printf ("\nA soma dos números: %d\n", soma(qtd));
	
	return 0;
}

void entrada(){
	int i;
	
	printf ("Quantos elementos deseja somar?  ");
	scanf ("%d", &qtd);
	printf ("\n");
	
	pvet = (int*) malloc (qtd * sizeof(int));
	
	for (i = 0; i < qtd; i++) {
		
		printf ("Digite o %dº número: ", i+1);
		scanf ("%d", &pvet[i]);
	}	
}

int soma (int vet) {
	
	if (vet == 0) {
		return 0;
		
	} else {
		return soma(vet-1) + pvet[vet-1];
	}
	
}

