#include <stdio.h>
#include <stdlib.h>

#define TAM 9

typedef struct Pessoa{
	int idade;
}Pessoa;

int vetHash[TAM];

int funcaoHash(int idade){
	return(idade%TAM);
}

void iniciarHash(int *vet){
	int i;
	for(i = 0; i < TAM; i++)
		vet[i] = 0;
}

void inserirHash(int *vet, int idade){
	int i = 0;
	int codHash = funcaoHash(idade);
	int hashAux = codHash;
	
	if(vet[codHash] == 0){
		printf("\nInserido com sucesso na posicao %d\n",codHash);
        vet[codHash] = idade;
        return;
	}
	
	hashAux++;
	
	while(hashAux != codHash){
		printf("Posicao %d ja ocupada\n",hashAux);
		if(hashAux < TAM){
			if(vet[hashAux] == 0){
				vet[codHash] = idade;
				return;
			}
			
			hashAux++;
			
			else{
				hashAux = 0;
			}				
		}
	}
	printf("Nao ha posicoes disponiveis!\n");
}

void imprimirHash(int *vet){
	int i = 0;
	for(i = 0; i < TAM; i++)
		printf("%d\n",vet[i]);
}

void buscar(int *vet, int indice){
	if(indice > TAM || indice < 0){
        printf("\nPosicao nao encontrada!");
        return;
    }
    else{
        printf("%d",vet[indice]);
    }
    printf("\n");
}

void contPosicoesVazias(int *vet){
	int i, cont = 0;
	for(i = 0; i < TAM; i++){
        if(vet[i] == 0){
            printf("%d\t", i);
            cont++;
        }
    }
    printf("\nTotal de posicoes vazias = %d\n", cont);
}

void preencher(int *vet){
	int i;
	for(i = 0; i < 10; i++){
		inserirHash(vet, 2+i);
	}
}

void removeHash(int * vet, int indice){
    if(indice > TAM || indice < 0){
        printf("\nEsta posicao nao existe na tabela!\n");
    }
    else{
        if(vet[indice] == 0){
            printf("Esta chave esta vazia!\n");
        }
        else{
            vet[indice] = 0;
        }
    }
}

int main(){
	
	int Hash;
	
    printf("Iniciando a tabela hash.\n");
    iniciarHash(Hash);
    printf("Inserindo elementos na tabela.\n");
    preencher(Hash);
    printf("Imprimindo a tabela:\n");
    imprimirHash(Hash);
    printf("Elementos do indice 0:\n");
    buscar(Hash, 0);
    contPosicoesVazias(Hash);
    printf("Removendo o elemento do indice: 0\n");
    removeHash(Hash, 0);
    printf("Elementos do indice 0:\n");
    buscar(Hash, 0);
    return 0;
}
