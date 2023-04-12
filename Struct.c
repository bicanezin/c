/*Defina uma estrutura (struct) chamada FichaCliente com os seguintes campos: nome e rua do tipo vetor de char de 50 posições, número do tipo int, cidade e
estado do tipo vetor de char de 30 posições e CEP do tipo vetor de char de 9 posições. 
Crie uma variável (única) chamada cliente do tipo estrutura FichaCliente e faça a entrada dos dados, imprimindo depois na tela a entrada feita pelo usuário.*/

#include <stdio.h>
#include <locale.h>
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
	fichaCliente cliente;
	setlocale(LC_ALL, "portuguese");
	
	printf("Digite o nome do cliente:");
	gets(cliente.nome);
	
	printf("Digite o endereço do cliente:");
	printf("\nRua:");
	gets(cliente.rua);
	
	fflush(stdin);
	
	printf("Número:");
	scanf("%d", &cliente.num);
	
	fflush(stdin);
	
	printf("Cidade:");
	gets(cliente.cid);
	
	printf("Estado:");
	gets(cliente.est);
	
	printf("CEP (xxxxx-xxx):");
	gets(cliente.cep);
	
	system("cls");
	
	printf("=========== FICHA DO CLIENTE ===========");
	printf("\n\nNome: %s", cliente.nome);
	printf("\n\nEndereço");
	printf("\nRua: %s", cliente.rua);
	printf("\nNúmero: %d", cliente.num);
	printf("\nCidade: %s", cliente.cid);
	printf("\nEstado: %s", cliente.est);
	printf("\nCEP: %s", cliente.cep);
	
	return 0;
}

