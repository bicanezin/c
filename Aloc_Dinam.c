/*Usando a estrutura do Exerc�cio 1 (aulas passada), 
fa�a um programa que pergunte quantos registros o usu�rio gostaria de armazenar,
e fa�a a aloca��o din�mica de um vetor com essa quantidade de registros. 
Em seguida, fa�a um menu para que o usu�rio possa inserir registros ou listar todos os cadastrados.*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define TAM 50
#define TAM2 30
#define TAM3 9

struct fichaCliente {
	char nome[TAM];
	char rua[TAM];
	char cid[TAM2];
	char est[TAM2];
	char cep[TAM3]; // xxxxx-xxx 
	int num;
}; typedef struct fichaCliente fichaCliente;

int main () {
	
	int qtd, i;
	fichaCliente * cliente;
	setlocale(LC_ALL, "portuguese");
	
	printf ("\n Quantos clientes deseja cadastrar? ");
	scanf("%d", &qtd);
	
	fflush(stdin);
	
	if (qtd <= 0) {
		printf("\n A quantidade n�o pode ser menor que um!\n");
		return -1;
	}
	
	cliente = (fichaCliente*) malloc (qtd * sizeof (cliente));
	
	if (cliente == NULL) {
		printf ("\n Erro na aloca��o de mem�ria!\n");
		return 0;
	}
	
	for (i = 0; i <qtd; i++){
	
		printf("Digite o nome do %d� cliente:", i+1);
		gets(cliente[i].nome);
	
		fflush(stdin);
		
		printf("Digite o endere�o do cliente:");
		printf("\nRua:");
		gets(cliente[i].rua);
	
		fflush(stdin);
	
		printf("N�mero:");
		scanf("%d", &cliente[i].num);
	
		fflush(stdin);
	
		printf("Cidade:");
		gets(cliente[i].cid);
	
		printf("Estado:");
		gets(cliente[i].est);
	
		fflush(stdin);
		
		printf("CEP (xxxxx-xxx):");
		gets(cliente[i].cep);
	
		system("cls");
		
	}


	
	printf("\n=========== FICHAS DOS CLIENTES ===========\n");
	
	for (i = 0; i < qtd; i++) {
	
		printf("\nNome: %s", cliente[i].nome);
		printf("\nEndere�o:");
		printf("\nRua: %s", cliente[i].rua);
		printf("\nN�mero: %d", cliente[i].num);
		printf("\nCidade: %s", cliente[i].cid);
		printf("\nEstado: %s", cliente[i].est);
		printf("\nCEP: %s", cliente[i].cep);
		printf("\n-------------------------\n");
	}
	
	free(cliente);	
	
	return 0;
}

