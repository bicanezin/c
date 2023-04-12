#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "Opec.h"

int main()
{
	setlocale(LC_ALL,"portuguese");
	
	canalYT* listaCanais;
	inscritos* listaInscritos;
	
	canalYT cadCanal;
	inscritos cadInscrito;
		
	listaCanais = iniciar();
	listaInscritos = iniciarInscritos();	
	
	while(1)
	{
		switch(menu())
		{
			case 1:
				fflush(stdin);
				printf("\nDigite o nome do canal: ");
				scanf(" %s", &cadCanal.nome);
				fflush(stdin);				
				printf("Digite o total de visualizações: ");
				scanf("%d", &cadCanal.total_visualizacoes);
				fflush(stdin);
				printf("Digite a quantidade de videos ");
				scanf("%d", &cadCanal.qtd_videos);
				printf("\n");
				fflush(stdin);
				printf("Digite o nome do inscrito: ");
				scanf(" %s", &cadInscrito.nome_insc);
				printf("Digite a idade do inscrito: ");
				scanf("%d", &cadInscrito.idade);
				listaCanais = inserirCanais(listaCanais, cadCanal.nome, cadCanal.total_visualizacoes, cadCanal.qtd_videos);	
				listaInscritos = inserirInscritos(listaInscritos, cadInscrito.nome_insc, cadInscrito.idade);
			break;
			
			case 2:
				listarCanais(listaCanais);
			break;
			
			case 3:
				maiorQtd(listaCanais);
			break;
			
			case 4:
				menorQtd(listaCanais);
			break;
			
			case 5:
				removerFim(listaCanais);
			break;
			
			case 6:
				removerInicio(listaCanais);
			break;
			
			case 8:
				liberarLista(listaCanais);
			break;
		}
	}
}
