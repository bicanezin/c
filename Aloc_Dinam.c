/*Usando a estrutura do Exercício 1 (aulas passada), 
faça um programa que pergunte quantos registros o usuário gostaria de armazenar,
e faça a alocação dinâmica de um vetor com essa quantidade de registros. 
Em seguida, faça um menu para que o usuário possa inserir registros ou listar todos os cadastrados.*/

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
		printf("\n A quantidade não pode ser menor que um!\n");
		return -1;
	}
	
	cliente = (fichaCliente*) malloc (qtd * sizeof (cliente));
	
	if (cliente == NULL) {
		printf ("\n Erro na alocação de memória!\n");
		return 0;
	}
	
	for (i = 0; i <qtd; i++){
	
		printf("Digite o nome do %dº cliente:", i+1);
		gets(cliente[i].nome);
	
		fflush(stdin);
		
		printf("Digite o endereço do cliente:");
		printf("\nRua:");
		gets(cliente[i].rua);
	
		fflush(stdin);
	
		printf("Número:");
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
		printf("\nEndereço:");
		printf("\nRua: %s", cliente[i].rua);
		printf("\nNúmero: %d", cliente[i].num);
		printf("\nCidade: %s", cliente[i].cid);
		printf("\nEstado: %s", cliente[i].est);
		printf("\nCEP: %s", cliente[i].cep);
		printf("\n-------------------------\n");
	}
	
	free(cliente);	
	
	return 0;
}

