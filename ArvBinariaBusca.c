#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct BinarySearchTree{
    int value;
    struct BinarySearchTree * left;
    struct BinarySearchTree * right;
} BinarySearchTree;

BinarySearchTree* create(){
    return NULL;
}

int isEmptyTree(BinarySearchTree * bst){
    return (bst == NULL);
}

BinarySearchTree* insert(BinarySearchTree * bst, int value){
    if(isEmptyTree(bst)){
        bst = (BinarySearchTree*) malloc(sizeof(BinarySearchTree));
        bst->value = value;
        bst->left = NULL;
        bst->right = NULL;
    }
    else if(value < bst->value){
        bst->left = insert(bst->left, value);
    }
    else{
        bst->right = insert(bst->right, value);
    }
    return bst;
}

void printTreeInOrdem(BinarySearchTree * bst){
    if(!isEmptyTree(bst)){
        printTreeInOrdem(bst->left);
        printf("%d  ", bst->value);
        printTreeInOrdem(bst->right);
    }
}


BinarySearchTree* search(BinarySearchTree * bst, int value){
    if(isEmptyTree(bst))
        return NULL;
    else if(bst->value > value)
        return search(bst->left, value);
    else if(bst->value < value)
        return search(bst->right, value);
    else
        return bst;
}

BinarySearchTree* freeTree(BinarySearchTree * bst){
    if(!isEmptyTree(bst)){
        freeTree(bst->left);
        freeTree(bst->right);
        free(bst);
    }
    return NULL;
}

BinarySearchTree* removeNode(BinarySearchTree * bst, int value){
    if(bst == NULL) return NULL;
    else if(bst->value > value)
        bst->left = removeNode(bst->left, value);
    else if(bst->value < value)
        bst->right = removeNode(bst->right, value);
    else{
        if(bst->left == NULL && bst->right == NULL){
            free(bst);
            bst = NULL;
        }
        else if(bst->left == NULL){
            BinarySearchTree * aux = bst;
            bst = bst->right;
            free(aux);
        }
        else if(bst->right == NULL){
            BinarySearchTree * aux = bst;
            bst = bst->left;
            free(aux);
        }
        else{
            BinarySearchTree * aux = bst->right;
            while(aux->left != NULL)
                aux = aux->left;
            bst->value = aux->value;
            aux->value = value;
            bst->right = removeNode(bst->right, value);
        }
    }
    return bst;
}


int main(){
    BinarySearchTree * bst;
    bst = create();
    
    setlocale(LC_ALL, "portuguese");
    
    bst = insert(bst, 10);
    bst = insert(bst, 5);
    bst = insert(bst, 15);
    bst = insert(bst, 4);
    bst = insert(bst, 7);
    bst = insert(bst, 6);
    bst = insert(bst, 8);
    bst = insert(bst, 12);
    bst = insert(bst, 20);
    bst = insert(bst, 11);
    
    printf("Imprimindo a árvore binária In-Ordem:\n");
    printTreeInOrdem(bst);
    
    //printf("\n\nRetornando o valor do elemento 1 -> %d:\n", search(bst, 1)->value);
    
    printf("\n\nRemovendo o nó raiz 10\n");
    removeNode(bst, 10);
    
    printf("\nImprimindo a árvore binária In-Ordem:\n");
    printTreeInOrdem(bst);
    
    printf("\n\nRemovendo o nó 8\n");
    removeNode(bst, 8);
    
    printf("\nImprimindo a árvore binária In-Ordem:\n");
    printTreeInOrdem(bst);
    
    
    printf("\n\nLiberando a árvore binária.\n");
    freeTree(bst);
    
    return 0;
}

