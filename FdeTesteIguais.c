#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Node{
	int value;
	struct Node *next;
	struct Node *prev;
} Node;

typedef struct Queue{
	Node *start;
	Node *end;
} Queue;

Queue* create(){
	Queue *q = (Queue*) malloc(sizeof(Queue));
	
	q->start = NULL;
	q->end = NULL;
	
	return q;
}

Queue* create2(){
	Queue *q2 = (Queue*) malloc(sizeof(Queue));
	
	q2->start = NULL;
	q2->end = NULL;
	
	return q2;
}

void insertEnd(Queue *q, int value){
	Node *new = (Node*) malloc(sizeof(Node));
	
	new->value = value;
	new->next = NULL;
	
	if(q->end != NULL){
		q->end->next = new;
		new->prev = q->end;
	
	}else{
		q->start = new;
		new->prev = NULL;
	}
	q->end = new;
}

void insertStart(Queue *q, int value){
	Node *new = (Node*) malloc(sizeof(Node));
	
	new->value = value;
	new->prev = NULL;
	
	if(q->end != NULL){
		q->start->prev = new;
		new->next = q->start;
	}
	else{
		q->end = new;
		new->next = NULL;
	}
	q->start = new;
}

void insertEnd2(Queue *q2, int value){
	Node *new = (Node*) malloc(sizeof(Node));
	
	new->value = value;
	new->next = NULL;
	
	if(q2->end != NULL){
		q2->end->next = new;
		new->prev = q2->end;
	
	}else{
		q2->start = new;
		new->prev = NULL;
	}
	q2->end = new;
}

void insertStart2(Queue *q2, int value){
	Node *new = (Node*) malloc(sizeof(Node));
	
	new->value = value;
	new->prev = NULL;
	
	if(q2->end != NULL){
		q2->start->prev = new;
		new->next = q2->start;
	}
	else{
		q2->end = new;
		new->next = NULL;
	}
	q2->start = new;
}


int isEmptyQueue(Queue *q){
	return (q->start == NULL);
}

int isEmptyQueue2(Queue *q2){
	return (q2->start == NULL);
}

void printQueue(Queue *q){
	Node *p = q->start;

	if(isEmptyQueue(q)){
		printf("Essa fila está vazia!\n");
	
	} else{
		while(p != NULL){
			printf("%d  ", p->value);
			p = p->next;
		}
	}
	
	printf ("\n");
}

void printQueue2(Queue *q2){
	Node *p = q2->start;

	if(isEmptyQueue2(q2)){
		printf("Essa fila está vazia!\n");
	
	} else{
		while(p != NULL){
			printf("%d  ", p->value);
			p = p->next;
		}
	}
	
	printf ("\n");
}

Node* searchStart(Queue *q){
	Node *p;
	
	for(p=q->start; p != NULL; p=p->next){
		if(p->value % 2 == 0){
			return p;
		}
	}
	return NULL;
}

Node* searchEnd(Queue *q){
	Node *p;
	
	for(p=q->end; p != NULL; p=p->prev){
		if(p->value % 2 == 0){
			return p;
		}
	}
	return NULL;
}

void freeQueue(Queue * q){
	Node *p = q->start;
	while(p != NULL){
		Node * t = p->next;
		free(p);
		p = t;
	}
	free(q);
}

int order(Queue *q) {
	Node *p = q->start;
	int cont = 0;
	
	while (p->next != NULL) {
		if (p->value > p->next->value) {
			cont++;
		}
		p = p->next;
	}
	
	if(cont == 5) {
		return (1);
	
	} else {
		return (0);
	}
}

int compare(Queue *q, Queue *q2) {
	Node *aux1 = q->start;
	Node *aux2 = q2->start;
	
	while (aux1 != NULL && aux2 != NULL) {
		if (aux1->value != aux2->value)
			break;
		
		aux1 = aux1->next;
		aux2 = aux2->next;
	}
	
	if (aux1 == NULL && aux2 == NULL)
		return (1);
	else
		return (0);
}

int compareRecursive(Queue *q, Queue *q2) {
	Node *aux1 = q->start;
	Node *aux2 = q2->start;
	
	if (q == NULL || q2 == NULL) {
		return (1);
	
	} else if (q->start->value != q2->start->value) {
		
	}
}

int main(){
	setlocale(LC_ALL, "portuguese");
	
	Queue *q, *q2;
	Node *searched = NULL;
	Node *searchedE = NULL;
	Node *comp;
	Node *ord;
	q = create();
	q2 = create2();

	insertStart(q, 4);
	insertStart(q, 5);
	insertStart(q, 6);
	
	insertEnd(q, 3);
	insertEnd(q, 2);
	insertEnd(q, 1);
	
	insertStart2(q2, 8);
	insertStart2(q2, 7);
	insertStart2(q2, 6);
	
	insertEnd2(q2, 9);
	insertEnd2(q2, 10);
	insertEnd2(q2, 11);
	
	printf("Fila 1: \n");
	printQueue(q);
	
	searched = searchStart(q);
	if(searched != NULL){
		printf("\nPrimeiro elemento mais proximo do inicio que é par: %d\n", searched->value);
	}
	
	searchedE = searchEnd(q);
	if(searchedE != NULL){
		printf("Primeiro elemento mais proximo do fim que é par: %d\n", searchedE->value);
	}
	
	ord = order(q);
	if (ord == 1) {
		printf("\nA fila está ordenada de forma decrescente\n");
	} else {
		printf ("\nA fila não está ordenada de forma decrescente\n");
	}
	
	printf("\nVerifica se os caracteres são iguais: \n");
	printf("Fila 1: \n");
	printQueue(q);
	printf("Fila 2: \n");
	printQueue(q2);
	
	comp = compare(q, q2);
	if (comp == 1) {
		printf ("\nA fila 1 e a fila 2 são iguais\n");
	} else if (comp == 0) {
		printf ("A fila 1 e a fila 2 são diferentes\n");
	} else {
		printf ("Erro ao verificar as filas\n");
	}
	

	freeQueue(q);
	printf("\nFila liberada...");
	return 0;
}

