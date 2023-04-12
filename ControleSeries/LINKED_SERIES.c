/**
* Bianca Maria Bortoloto Canezin
	Turma: ES21
	Função: o programa tem como função fazer o controle de séries
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <errno.h>

typedef struct Item{
	char date[11];
	char name[100] ;
	struct Item* next;
} Item;

Item x;
int cont = 0;

FILE *arquivo;

FILE *abrirArquivo(const char* nome, char mode[3]) { // salvar e carregar arquivo
	
	FILE *arq = fopen(nome, mode);
	
	if(arq == NULL) {
		
		if(errno == ENOFILE) {
			printf("\nErro %d: O arquivo [%s] não foi localizado.\n", errno, nome);
		}
		
		else {
			printf("\nErro %d: %s.\n", errno, strerror(errno));
		}
	}
	
	return arq;
}
	

Item* start() {
	return NULL;
}

Item* insert(Item* list, char *date, char *name){
	
	Item *new = (Item*) malloc (sizeof(Item));
	
	strcpy (new->date, date);
	strcpy (new->name, name);
	
	new->next = list;
	
	return new;
}

void print(Item* list){
	
	while (list != NULL) {
		
		printf ("\n%s;%s\n", list->date, list->name);
		list = list->next;
	}
	printf ("\n");
}

void printRecursive(Item* list) {
	
	if (list == NULL) {
		return;

	} else {
		printf ("\n%s;%s\n", list->date, list->name);
		printRecursive(list->next);
	}	 
}

void printRecursiveInverted(Item* list) {
	
	if (list == NULL) {
		return;
	
	} else {
		printRecursiveInverted(list->next);
		printf ("\n%s;%s\n", list->date, list->name);
	}
}

void destroy(Item* list) {

	list = start();
	free(list);
	cont = 0;
}

Item* save(Item* list) {
	char NameArquivo[40];
	char aux[5] = ".txt";
	Item *pont;
	
	pont = list;
	cont = 0;
	
	printf ("Digite o nome para o arquivo: ");
	fflush (stdin);
	gets(NameArquivo);

	
	strcat(NameArquivo, aux); // junção de duas strings
	
	arquivo = abrirArquivo(NameArquivo, "a");
	
	do {
		fprintf (arquivo, "%s;%s\n", pont->date, pont->name);
		cont++;
		
		pont = pont->next;
		
	} while (pont != NULL);
	
	fclose (arquivo);
}

Item* load(Item* list) {
	char NameArquivo[6];
	char aux[5] = ".txt";
	char date[11], name[100]; 
	
	cont = 0;
	list = start(); // excluindo a lista anterior

	printf ("Digite o nome do arquivo que deseja abrir: \n");
	fflush (stdin);
	gets (NameArquivo);
	printf ("\n");
	
	strcat(NameArquivo, aux); // junção das duas strings

	arquivo = abrirArquivo(NameArquivo, "r");
	
	if(arquivo == NULL) {
		printf ("Arquivo não encontrado!");
		exit (0);
	}

	int i = 0;
	
	do {
		if(i >0){
			printf("%s;%s\n", date, name);
			cont++;
			
			strcpy(x.date, date);
			strcpy(x.name, name);
			
			list = insert(list, x.date, x.name);
		}
		i++;
	} while (fscanf(arquivo, "%[^;];%[^\n]", date, name) == 2);
	
	fclose(arquivo); 
	
}

Item* search(Item* list, char date[11]) {
	
	if (list == NULL) {
		return 0;
		
	} else if (strcmp (date, list->date) == 0) {
		printf ("\n%s;%s", list->date, list->name);
		
	} 
	
	search(list->next, date);	
}

int main () {
	int op;
	char date[11];	
	Item *list;
	
	setlocale (LC_ALL, "portuguese");
	
	list = start();
	
	while (1) {
		
		printf ("\n\nOlá, bem-vindo ao sistema de gerência de séries e filmes!\n");
		printf ("\n O que você deseja fazer?\n");
		printf ("[01] - Inserir um item manualmente;\n");
		printf ("[02] - Carregar um arquivo com os meus itens;\n");
		printf ("[03] - Listar os itens de forma iterativa;\n");
		printf ("[04] - Listar os itens de forma recursiva;\n");
		printf ("[05] - Listar os itens de forma recursiva invertida;\n");
		printf ("[06] - Limpar a lista em memória;\n");
		printf ("[07] - Salvar lista em arquivo texto;\n");
		printf ("[08] - Contar itens em memória;\n");
		printf ("[09] - Procurar item por data;\n");
		printf ("[10] - Sair\n");
		
		scanf ("%d", &op);
		system("cls");
		
		switch (op) {
			
			case 1:
				system("cls");
				printf ("\n ============ INSERÇÃO DE UM ITEM MANUALMENTE ============\n");
			
				printf ("\nDigite uma data: ");
				fflush(stdin);
				gets (x.date);
				
				
				printf ("Digite o título: ");
				fflush(stdin);
				gets (x.name);
				
				cont ++;	
				list = insert(list, x.date, x.name);	
			break;
			
			case 2:
				system("cls");
				printf ("\n ========= CARREGAMENTO DE ITENS A PARTIR DE UM ARQUIVO =========\n");
				
				load(list);
				list = insert(list, x.date, x.name);
				
				printf ("\nArquivo carregado com sucesso!");
			break;	
			
			case 3:
				system("cls");
				printf ("\n ============== LISTAGEM DE FORMA ITERATIVA ==============\n");
				
				print(list);
			break;
			
			case 4:
				system("cls");
				printf ("\n ============== LISTAGEM DE FORMA RECURSIVA ==============\n");	
							
				printRecursive(list);
			break;
			
			case 5:
				system("cls");
				printf ("\n ========= LISTAGEM DE FORMA RECURSIVA INVERTIDA =========\n");
				
				printRecursiveInverted(list);	
			break;
			
			case 6:
				system("cls");
				printf ("\n ============== LIMPEZA DA LISTA EM MEMÓRIA ==============\n");
				
				destroy(list);
				list = start();
				free(list);
				cont = 0;
				
				printf ("\nLista limpa com sucesso!\n\n");	
			break;
			
			case 7:
				system("cls");
				printf ("\n ============ SALVANDO LISTA EM ARQUIVO TEXTO =============\n");
				
				list = save(list);
				
				printf ("\nSalvo com sucesso!\n\n");
			break;
			
			case 8:
				system("cls");
				printf ("\n ============= CONTAGEM DOS ITENS EM MEMÓRIA ==============\n");
				
				printf ("Há %d itens em memória\n", cont);
			break;
			
			case 9: 
				system("cls");
				printf ("\n =============== PROCURA DE ITEM POR DATA =================\n");
				
				printf ("\nDigite uma data: ");
				fflush (stdin);
				gets (date);
				search(list, date);
			break;
			
			case 10:
				system("cls");
				
				list = start();
				free (list);
				
				exit (0);
			
			default:
				system("cls");
				printf ("\nErro na escolha");		
		}	
	}
	
	return 0;
}
