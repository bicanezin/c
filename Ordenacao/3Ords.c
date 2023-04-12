#include <stdio.h>
#include <string.h>
#include <locale.h>

struct tabela {
	char nome[20];
	int idade;
	
}; typedef struct tabela Tabela;

void impressao(Tabela *vet);
void bubbleSortC(int tam, Tabela *vet);
void bubbleSortD(int tam, Tabela *vet);
void selecaoC(int tam, Tabela *vet);
void selecaoD(int tam, Tabela *vet);
void insercaoC(int tam, Tabela *vet);
void insercaoD(int tam, Tabela *vet);

int main () {
	setlocale(LC_ALL, "portuguese");

	Tabela vet[7] = {
	{"Jessica", 22}, 
	{"Lucas", 24}, 
	{"Joseff", 22}, 
	{"Johnny", 38}, 
	{"Albert", 20}, 
	{"Bernard", 18}, 
	{"Guilherme", 31}};
	
	printf ("\nImpressão do vetor original: \n");
	impressao (vet);
	
	bubbleSortC(7, vet);
	printf ("\nOrdenação (por idade) método bolha crescente: \n");
	impressao (vet);
	
	bubbleSortD(7, vet);
	printf("\nOrdenação (por idade) método bolha decrescente: \n");
	impressao (vet);
	
	selecaoC(7, vet);
	printf("\nOrdenação (por idade) método seleção crescente: \n");
	impressao (vet);
	
	selecaoD(7, vet);
	printf("\nOrdenação (por idade) método seleção decrescente: \n");
	impressao (vet);
	
	insercaoC(7, vet);
	printf("\nOrdenação (por idade) método inserção crescente: \n");
	impressao (vet);
	
	insercaoD(7, vet);
	printf("\nOrdenação (por idade) método inserção decrescente: \n");
	impressao (vet);
	
	return 0;
}

void impressao(Tabela *vet) {
	int i;
	
	for (i = 0; i < 7; i++) {
		printf ("\nNome: %s\t  Idade: %d", vet[i].nome, vet[i].idade);		
	}
	
	printf ("\n--------------------------------");
}

void bubbleSortC(int tam, Tabela *vet) {
    int i, j;
	Tabela aux;

    for(i = 0; i < tam; i++){
    	
        for(j = 0; j < tam-1; j++) {
        	
            if(vet[j].idade > vet[j+1].idade) {
            	
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}

void bubbleSortD(int tam, Tabela *vet) {
    int i, j;
	Tabela aux;

    for(i = 0; i < tam; i++){
    	
        for(j = 0; j < tam; j++) {
        	
            if(vet[j+1].idade > vet[j].idade) {
            	
                aux = vet[j+1];
                vet[j+1] = vet[j];
                vet[j] = aux;
                
                j++;
            }
        }
    }
}

void selecaoC(int tam, Tabela *vet) {
	int i, j, min;
	Tabela aux;
	
	for (i = 0; i < tam-1; i++) {
		min = i;
		
		for (j = i+1; j < tam; j++) {
			
			if (vet[j].idade < vet[min].idade) {
				min = j;
			}
		}
		
		if (min != i) {
			
			aux = vet[i];
			vet[i] = vet[min];
			vet[min] = aux;
		}
	}
	
}

void selecaoD(int tam, Tabela *vet) {
	int i, j, min;
	Tabela aux;
	
	for (i = 0; i < tam-1; i++) {
		min = i;
		
		for (j = i+1; j < tam+1; j++) {
			
			if (vet[j].idade > vet[min].idade) {
				min = j;
			}
		}
		
		aux = vet[i];
		vet[i] = vet[min];
		vet[min] = aux;
	}
	
}

void insercaoC(int tam, Tabela *vet) {
	int i, j;
	Tabela pivo;
	
    for(i = 1; i < tam; i++) {
    	
        pivo = vet[i];
        
        for (j = i - 1; j >= 0 && vet[j].idade > pivo.idade; j--) {
        	
            vet[j+1] = vet[j];
        }
        vet[j+1] = pivo;
    }
}

void insercaoD(int tam, Tabela *vet) {
	int i, j;
	Tabela pivo;
	
	for (i = 1; i < tam; i++) {
		
		pivo = vet[i];
		
		for (j = i - 1; j >= 0 && vet[j].idade < pivo.idade; j--) {
			
			vet[j+1] = vet[j];
		}
		vet[j+1] = pivo;
	}
}
