#include <stdio.h>
#include <stdlib.h>

typedef struct ArvoreBinaria{
	int valor;
	struct ArvoreBinaria * esq;
	struct ArvoreBinaria * dir;
}ArvoreBinaria;

ArvoreBinaria* criar(){
	return NULL;
}

ArvoreBinaria* inserir(int valor, ArvoreBinaria* esq, ArvoreBinaria* dir){
	ArvoreBinaria *new = (ArvoreBinaria*) malloc(sizeof(ArvoreBinaria));
	new->valor = valor;
	new->esq = esq;
	new->dir = dir;
	return new;
}

int arvoreVazia(ArvoreBinaria* arvore){
	return (arvore == NULL);
}

int buscar(ArvoreBinaria* arv, int valor){
	if(arvoreVazia(arv))
		return 0;
	
	else{
		if(arv->valor == valor)
			return 1;
		else{
			buscar(arv->esq, valor);
			buscar(arv->dir, valor);
		}
	}
}

ArvoreBinaria* liberarArvore(ArvoreBinaria* arv){
	if(!arvoreVazia(arv)){
		liberarArvore(arv->esq);
		liberarArvore(arv->dir);
		free(arv);
	}
	return NULL;
}

void imprimirArvorePreOrdem(ArvoreBinaria* arv){
	if(!arvoreVazia(arv)){
		printf("%d\n", arv->valor);
		imprimirArvorePreOrdem(arv->esq);
		imprimirArvorePreOrdem(arv->dir);
	}
}

void imprimirArvoreInOrdem(ArvoreBinaria* arv){
	if(!arvoreVazia(arv)){
		imprimirArvoreInOrdem(arv->esq);
		printf("%d\n", arv->valor);		
		imprimirArvoreInOrdem(arv->dir);
	}
}

void imprimirArvorePosOrdem(ArvoreBinaria* arv){
	if(!arvoreVazia(arv)){
		imprimirArvorePosOrdem(arv->esq);
		imprimirArvorePosOrdem(arv->dir);
		printf("%d\n", arv->valor);
	}
}

int main(){
	ArvoreBinaria* arv;
	
	arv = criar();
	arv = inserir(10, 
        inserir(15, 
            inserir(20, criar(), criar()),
            inserir(35, criar(), criar())
        ),
        inserir(12, 
            inserir(25, criar(), criar()),
            inserir(12, 
                inserir(3, criar(), criar()),
                inserir(1, criar(), criar())
            )
        )
    );
	
	printf("\nPre Ordem\n");
	imprimirArvorePreOrdem(arv);
	printf("\n\nIn Ordem\n");
	imprimirArvoreInOrdem(arv);
	printf("\n\nPos Ordem\n");
	imprimirArvorePosOrdem(arv);
	
	printf("\nO elemento 10 existe? (1,0) : %d\n", buscar(arv, 10));
	
	liberarArvore(arv);
	
	return 0;
}
