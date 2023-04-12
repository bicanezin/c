#include <stdio.h>
#include <stdlib.h>


typedef struct informacao{ //
   int valor;
}informacao;

typedef struct no{
   informacao dado;
   struct no *sub_arvore_esquerda;
   struct no *sub_arvore_direita;
}no;


no * planta_arvore(no *arvore){
   arvore = NULL;
   return(arvore);
}

no * insere(informacao info, no *arvore){
   if(arvore == NULL){
      arvore = (no *)malloc(sizeof(no));
      arvore->dado = info;
      arvore->sub_arvore_esquerda = NULL;
      arvore->sub_arvore_direita= NULL;
      return(arvore);
   }
   if(info.valor < arvore->dado.valor){
//       printf("%d inserido na esquerda",arvore->dado.valor);
      arvore->sub_arvore_esquerda=insere(info,arvore->sub_arvore_esquerda);
      return(arvore);
   }
   if(info.valor > arvore->dado.valor){
//       printf("%d inserido na direita", arvore->dado.valor);
      arvore->sub_arvore_direita=insere(info,arvore->sub_arvore_direita);
      return(arvore);
   }
   else
      return NULL;
}

int imprime_pre_ordem(no *arvore){/// a função ultilizada foi a pre-ordem pois imprime primeiro a raiz, depois segue pela esquerda e depois pela direita 
   int a=1,b=1;
   if(arvore != NULL){
      printf("(");
      printf("%d",arvore->dado.valor);
      a=imprime_pre_ordem(arvore->sub_arvore_esquerda);///a==0 caso sub_arvore_esquerda==NULL
      b=imprime_pre_ordem(arvore->sub_arvore_direita);///a==0 caso sub_arvore_direita==NULL
      if(b==0 && a==0)printf("()");///imprime  () se e somente se encontrar um nó folha
      else if(b==0 && a!=0);///isso acontece se encontrar um nó com a perna direita null
      else if(b!=0 && a==0);///isso acontece se encontrar um nó com a perna esquerda null
      /**         Observações:
      Existem tambem mais dois casos:
         1°- Para imprimir quando a perna direita ou esquerda for null ou seja quando as raizes da arvore não estiverem completas basta retirar a condição da linha 50 (obs:só imprimira as "pernas" vazias)e atualizar o resto assim:
         if(b==0 && a!=0)printf("()");
         if(b!=0 && a==0)printf("()");
         
         2°- Para imprimir quando a perna direita ou esquerda for null ou as duas basta retirar a condição da linha 50,51,52 e fazer uma condição para cada assim:
         if(b==0)printf("()");
         if(a==0)printf("()");
      
      That's All Folks! (É só isso pessoal!) 
      **/
      printf(")");///fecha a representação de uma raiz
   }else return 0;//retorna 0 caso arvore == NULL 
}
//         testes realizados:
//  caso ativado: (15(13(9(6()))(14()))(25(17())(28(27())(31()))))
//  1° caso: (15(13(9(6()())())(14()()))(25(17()())(28(27()())())))
//  2° caso: (15(13(9(6)())(14))(25(17)(28(27)())))

main(){
   no *arvore,
   *arv,
   *arv2;
   informacao dado;
   int ret,i;
   printf("quantos nos tem a arvore? ");
   scanf("%d",&ret);
   printf("\n");arvore = planta_arvore(arvore);
   for(i=0;i<ret;i++){
      scanf("%d",&dado.valor);
      arvore = insere(dado,arvore);
      if(arvore == NULL);
   }
//     printf("\nEm ordem :");
   imprime_pre_ordem(arvore);
   printf("\n");
}
