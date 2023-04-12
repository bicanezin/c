#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_ListaEncadeada.h"
#include "TAD_ListaDuplamenteEncadeada.h"

int main() {
	setlocale(LC_ALL,"portuguese");
	
	AlunosED* listaEncadeada;
	Pesos* listaDuplamenteEncadeada;
	
	printf("---------------------------------------------- LISTA ENCADEADA ----------------------------------------------\n");
	listaEncadeada = LE_iniciar();
	
	listaEncadeada = LE_inserirNoFim(listaEncadeada, "Diogo", 26); //fim da lista
	listaEncadeada = LE_inserirNoFim(listaEncadeada, "Eduardo", 18);
	listaEncadeada = LE_inserirNoFim(listaEncadeada, "Matheus", 19); //inicio da lista
	
	listaEncadeada = LE_inserirOrdenado(listaEncadeada, "Bianca", 17);
	listaEncadeada = LE_inserirOrdenado(listaEncadeada, "Judite", 20);
	
	LE_listarAlunos(listaEncadeada);
	
	LE_maiorElemento(listaEncadeada);
	LE_menorElemento(listaEncadeada);
	
	LE_removerInicio(listaEncadeada);
	LE_removerFim(listaEncadeada);
	
	LE_listarAlunos(listaEncadeada);
	
	LE_liberarLista(listaEncadeada);
	
	printf("\n---------------------------------------------- LISTA DUPLAMENTE ENCADEADA ----------------------------------------------");
	listaDuplamenteEncadeada = LDE_iniciar();
	
	listaDuplamenteEncadeada = LDE_inserirNoFim(listaDuplamenteEncadeada, 86);
	listaDuplamenteEncadeada = LDE_inserirNoFim(listaDuplamenteEncadeada, 35);
	listaDuplamenteEncadeada = LDE_inserirNoFim(listaDuplamenteEncadeada, 100); 
	
	listaDuplamenteEncadeada = LDE_inserirOrdenado(listaDuplamenteEncadeada, 89);
	listaDuplamenteEncadeada = LDE_inserirOrdenado(listaDuplamenteEncadeada, 75);
	listaDuplamenteEncadeada = LDE_inserirOrdenado(listaDuplamenteEncadeada, 113);
	
	LDE_listar(listaDuplamenteEncadeada);
	
	LDE_maiorElemento(listaDuplamenteEncadeada);
	LDE_menorElemento(listaDuplamenteEncadeada);
	
	//LE_removerInicio(listaDuplamenteEncadeada);
	//LE_removerFim(listaDuplamenteEncadeada);
	
	//LE_listarAlunos(listaDuplamenteEncadeada);
	
	LDE_liberarLista(listaDuplamenteEncadeada);
	return 0;
}
