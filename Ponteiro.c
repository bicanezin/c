/*Na função main crie três variáveis inteiras chamadas Raiz, A e Num, e um ponteiro do tipo inteiro chamado Exp inicializado com NULL.
Faça Exp receber o endereço de A. Pergunte ao usuário um número e armazene em Num, depois chame uma função chamada Contas passando a variável Raiz por
referência, o ponteiro Exp e a variável Num por Valor. Esta função deve calcular a Raiz do valor armazenado em Num e armazenar em Raiz, calcular o valor de Num
elevado a 2 e armazenar no endereço apontado por Exp. Depois na função principal imprima o valor da variável Raiz e o valor apontado por Exp */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

void Contas (int *r, int *pont, int n);

int main () {
	int raiz, a, num;
	int *exp = NULL;
	
	setlocale (LC_ALL, "portuguese");
	
	exp = &a;
	
	printf("Digite um número inteiro: ");
	scanf("%d", &num);
	
	Contas (&raiz, exp, num);
	
	printf("\nValor da raiz desse número: %d\n", raiz);
	printf("Valor apontado pelo ponteiro: %d\n", *exp);
	
	return 0;
}

void Contas (int* r, int *pont, int n) {
	*r = sqrt (n);
	*pont = pow (n, 2);
}
