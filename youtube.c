#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>

typedef struct Subscribers{
    char nameSubs[50];
    int age;
    struct Subscribers *next;
}Subs;

typedef struct Channel{
    char nameChannel[50];
    int qtdViews;
    int qtdVideos;
    Subs * subs;
    struct Channel *next;
}Channel;

Subs* readDataSubs(Subs *);

Subs* startSubs(){
	return NULL;
}

Channel* startChannel(){
	return NULL;
}

Subs* insertSubs(Subs subs, Subs *list){
    Subs *novo = (Subs *) malloc(sizeof(Subs));
    strcpy((novo->nameSubs), (subs.nameSubs));
    novo->age = subs.age;
    novo->next = list;
    return novo;
}

Channel* insertChannel(Channel channel, Channel *list){
    Channel *novo = (Channel *) malloc(sizeof(Channel));
    
    strcpy((novo->nameChannel), (channel.nameChannel));
    novo->qtdViews = channel.qtdViews;
    novo->qtdVideos = channel.qtdVideos;
    novo->subs = startSubs();
    
    printf("\nPor favor insira os inscritos do canal!");
    novo->subs = readDataSubs(novo->subs);
    novo->next = list;
    return novo;
}

int isEmptyListSubs(Subs * list){
	return (list == NULL);
}

int isEmptyListChannel(Channel * list){
	return (list == NULL);
}

void printRecursiveSubs(Subs * list){
	Subs * subs = list;
	if(!isEmptyListSubs(subs)){
		printf("\nNome....: %s",subs->nameSubs);
        printf("\nIdade...: %d", subs->age);
		printRecursiveSubs(subs->next);
	}
}


void printRecursiveChannel(Channel * list){
	Channel * ch = list;
	if(!isEmptyListChannel(ch)){
		printf("\nNome do canal............: %s", ch->nameChannel);
		printf("\nTotal de Vizualizações...: %d", ch->qtdViews);
		printf("\nQuantidade de videos.....: %d", ch->qtdVideos);
		printf("\nLista de Inscritos: \n");
		printRecursiveSubs(ch->subs);
		printf("\n------------------------------------------------\n");
		printRecursiveChannel(ch->next);
	}
}

Subs* readDataSubs(Subs *list){
    int condition = 1;
    do{
        Subs subs;
        printf("\n\nInsira os dados do inscrito!");

        printf("\nNome do inscrito: ");
        fflush(stdin);
        gets(subs.nameSubs);

        printf("Idade: ");
        scanf("%d", &subs.age);

        list = insertSubs(subs, list);

        printf("\nInserir mais algum inscrito (1 = S || 0 = N): ");
        scanf("%d", &condition);
    } while(condition == 1);
    return list;
}

Channel * readDataChannel(Channel * list){
    Channel channel;

    printf("\nInsira os dados do canal!\n");

    printf("Nome do canal: ");
    fflush(stdin);
    gets(channel.nameChannel);

    printf("Quantidade de videos: ");
    scanf("%d", &channel.qtdVideos);

    printf("Quantidade total de visualizações: ");
    scanf("%d", &channel.qtdViews);

    return insertChannel(channel, list);
}


int main(){
    setlocale(LC_ALL, "Portuguese");
    Channel * channels = startChannel();
    int option;

    do{

        channels = readDataChannel(channels);


        printf("\nDeseja parar de innserir canais?\n1 = sim e 0 = não");
        scanf("%d", &option);
    }while (option!=1);
    printRecursiveChannel(channels);
    return 0;
}
