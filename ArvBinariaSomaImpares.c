#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct BinaryTree{
	int value;
	struct BinaryTree * left;
struct BinaryTree * right;
} BinaryTree;

BinaryTree *create(){
	return NULL;
}

BinaryTree * insert(int value, BinaryTree * left, BinaryTree * right){
	BinaryTree * new = (BinaryTree*) malloc(sizeof(BinaryTree));
	new->value = value;
	new->left = left;
	new->right = right;
	return new;
}

int isEmptyTree(BinaryTree *tree){
	return (tree == NULL);
}
/*
void printTree(BinaryTree * bt){
	
	if(!isEmptyTree(bt)){
		printf("%d  ", bt->value);
		printTree(bt->left);
		printTree(bt->right);
    }
}
*/

void printTree(BinaryTree * bt){
	printf("(");
	
	if(bt == NULL)
		printf("-1");
	else {
		printf("%d", bt->value);
		printTree(bt->left);
		printTree(bt->right);
	}
}

int sumOddLeafs(BinaryTree * bt){
    if(isEmptyTree(bt)){
        return 0;
    }
    else{
        if(bt-> left == NULL && bt->right == NULL && (bt->value % 2 != 0)){
            return bt->value;
        }
        else{
            return (sumOddLeafs(bt->left) + sumOddLeafs(bt->right));
        }
    }
}
 

BinaryTree * freeTree(BinaryTree * bt){
	if(!isEmptyTree(bt)){
		freeTree(bt->left);
		freeTree(bt->right);
		free(bt);
    }
    return NULL;
}

int main(){
    BinaryTree * bt;
    int b = 9;
    
    setlocale(LC_ALL, "portuguese");
    
	bt = create();
	
    bt = insert(10, 
        insert(15, 
            insert(20, create(), create()),
            insert(35, create(), create())
        ),
        insert(12, 
            insert(25, create(), create()),
            insert(12, 
                insert(3, create(), create()),
                insert(1, create(), create())
            )
        )
    );
    
    printTree(bt);
    
    mostraArvore(bt, b);
    
    printf("\nA soma dos números ímpares da folha é : %d\n", sumOddLeafs(bt));
    freeTree(bt);
    return 0;
}
