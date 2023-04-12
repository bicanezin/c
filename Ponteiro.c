/*Na fun��o main crie tr�s vari�veis inteiras chamadas Raiz, A e Num, e um ponteiro do tipo inteiro chamado Exp inicializado com NULL.
Fa�a Exp receber o endere�o de A. Pergunte ao usu�rio um n�mero e armazene em Num, depois chame uma fun��o chamada Contas passando a vari�vel Raiz por
refer�ncia, o ponteiro Exp e a vari�vel Num por Valor. Esta fun��o deve calcular a Raiz do valor armazenado em Num e armazenar em Raiz, calcular o valor de Num
elevado a 2 e armazenar no endere�o apontado por Exp. Depois na fun��o principal imprima o valor da vari�vel Raiz e o valor apontado por Exp */

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
	
	printf("Digite um n�mero inteiro: ");
	scanf("%d", &num);
	
	Contas (&raiz, exp, num);
	
	printf("\nValor da raiz desse n�mero: %d\n", raiz);
	printf("Valor apontado pelo ponteiro: %d\n", *exp);
	
	return 0;
}

void Contas (int* r, int *pont, int n) {
	*r = sqrt (n);
	*pont = pow (n, 2);
}
