#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Node{
	int value;
	struct Node *next;
}Node;

typedef struct Queue{
	Node *start;
	Node *end;
}Queue;

Queue* create() {
	Queue *q = (Queue*) malloc(sizeof(Queue));
	
	q->start = NULL;
	q->end = NULL;
	
	return q;	
}

int isEmpty(Queue *q) {
	if (q == NULL)
		return 1;
	
	if (q->start == NULL)
		return 1;
		
	return 0;
}

void enQueue(Queue *q, int value) {
	Node *new = (Node*) malloc (sizeof(Node));
	
	new->value = value;
	new->next = NULL;
	
	if (q->end == NULL) {
		q->start = new;
	
	} else {
		q->end->next = new;	
	}
	
	q->end = new;
}

void deQueue(Queue *q) {
	if (isEmpty(q)) {
		printf("A fila está vazia\n");
	
	} else {
		Node *p;
		p = q->start;
		q->start = q->start->next;
		
		if (q->start == NULL) {
			q->start = NULL;
		}
		
		free(p);
	}
}

void print(Queue *q){
	if (isEmpty(q)) {
		printf("A fila está vazia\n");
	} 
	
	Node *p;
	p = q->start;
	
	while (p != NULL) {
		printf ("%d ", p->value);
		p = p->next;
	}
	
	printf ("\n");
}

Node* search(Queue *q, int value){
	Node *p;
	
	for(p = q->start; p != NULL; p = p->next){
		if(p->value == value){
			return p;
		}
	}
	return NULL;
}

int main() {
	setlocale (LC_ALL, "portuguese");
	
	Queue *q;
	Node *s;
	
	q = create();
	
	enQueue(q, 3);
	enQueue(q, 4);
	enQueue(q, 5);
	enQueue(q, 6);
	
	print(q);
	
	deQueue(q);
	
	print(q);
	
	s = search(q, 1);
	if(s != NULL){
		printf("Encontrou o elemento: %d\n", s->value);
	} else {
		printf("\nElemento não encontrado\n")
	}
}

