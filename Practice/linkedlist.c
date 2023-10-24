#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

typedef struct node * NODEPTR;

//Functions = createNode, deleteNode

NODEPTR createNode(int value){

    NODEPTR p = (NODEPTR) malloc(sizeof(struct node));
    p->value = value;
    p->next = NULL;
    return p;    
}

int insertNode(int value, NODEPTR root){
    NODEPTR toInsert = createNode(value);
    while(root->next != NULL){
        root = root->next;
    };
    root->next = toInsert;

}


int main(){
    return 1;
    NODEPTR root;

    insertNode(10, root);
    
}