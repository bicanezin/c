/*
 * FILA SIMPLES COM LIMITE DE 10 INSER��ES 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int cont = 0;

typedef struct Pessoa{
	char nome[50];
	int idade;
	struct Pessoa* prox;
} Pessoa;

typedef struct Fila{
	Pessoa* inicio;
	Pessoa* fim;
} Fila;

Fila* criarFila(){
	Fila* q = (Fila*) malloc(sizeof(Fila));
	q->inicio = NULL;
	q->fim = NULL;
	return q;
}

void inserir(Fila* q, char *nome, int idade){

	if(cont < 10)
	{
		Pessoa *new = (Pessoa*) malloc(sizeof(Pessoa));
	
		strcpy(new->nome, nome);
		new->idade = idade;
		new->prox = NULL;
		
		if(q->fim != NULL){
			q->fim->prox = new;
		}
		else{
			q->inicio = new;
		}
		q->fim = new;
		
		cont++;
	}	
	else
		printf("[ERRO] O limite de insercoes ja foi atingido!\n");
}

int filaVazia(Fila * q){
	return (q->inicio == NULL);
}

void imprimirFila(Fila * q){
	Pessoa * p;
	p = q->inicio;
	
	if(filaVazia(q)){
		printf("Esta fila est� vazia!\n");
	}
	else{
		while(p != NULL){
			printf("Nome..: %s\tIdade.: %d\n", p->nome, p->idade);
			p = p->prox;
		}
	}
}

Pessoa* buscarIdade(Fila * q, int idade){
	Pessoa * p;
	for(p = q->inicio; p != NULL; p = p->prox){
		if(p->idade == idade){
			return p;
		}
	}
	return NULL;
}

void liberarFila(Fila * q){
	Pessoa * p = q->inicio;
	while(p != NULL){
		Pessoa * t = p->prox;
		free(p);
		p = t;
	}
	free(q);
	printf("Lista liberada!\n");
}

int removerFila(Fila * q){
	Pessoa * t;
	int v;
	if(filaVazia(q)){
		printf("\nFila j� vazia!\n");
		return 0;
	}
	t = q->inicio;
	v = t->idade;
	q->inicio = t->prox;
	if(q->inicio == NULL)
		q->fim = NULL;
	free(t);
	return v;
}

void furaFila(Fila* q, char *nome, int idade)
{
	if(cont < 10)
	{
		Pessoa *new = (Pessoa*) malloc(sizeof(Pessoa));
	
		strcpy(new->nome, nome);
		new->idade = idade;
		new->prox = q->inicio;
		
		if(q->fim != NULL){
			q->inicio = new;
		}
		else{
			q->fim->prox = new;
		}
		q->fim = new;
		
		cont++;
	}
	else
		printf("[ERRO] O limite de insercoes ja foi atingido!\n");	
}

int main(){
	setlocale(LC_ALL,"portuguese");
	Fila* filaSimples;
	Pessoa* buscar = NULL;
	int removido;
	
	filaSimples = criarFila();	
	
	inserir(filaSimples, "Eduardo", 18);
	inserir(filaSimples, "Bianca", 18);
	inserir(filaSimples, "Diogo", 26);
	inserir(filaSimples, "Estr.D", 29);
		
	
	printf("======= Imprimindo a fila ======= \n\n");
	imprimirFila(filaSimples);

	
	printf("\n\n======= Removendo uma idade ======= \n");
	removido = removerFila(filaSimples);
	printf("\nA idade removida foi: %d\n", removido);

	
	printf("\n\n======= Imprimindo a fila apos remover ======= \n\n");
	imprimirFila(filaSimples);


	printf("\n\n======= Furando a fila =======\n");
	furaFila(filaSimples, "UTFPR", 99);
	printf("\nRegistro incluido na fila!\n");


	printf("\n\n======= Imprimindo a fila apos fura fila ======= \n\n");
	imprimirFila(filaSimples);


	printf("\n\n======= Buscar idade ======= \n\n");
	buscar = buscarIdade(filaSimples, 18);
	if(buscar != NULL)
		printf("Nome..: %s\tIdade.: %d\n", buscar->nome, buscar->idade);		
	else
		printf("Nao foi encontada a idade procurada!");	

		
	printf("\n\n======= Liberando a fila ======= \n\n");		
	liberarFila(filaSimples);
		
	return 0;
}
