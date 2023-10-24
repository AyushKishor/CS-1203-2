#include <stdio.h>
#include <stdlib.h>


// Node Structure for Binary Search Tree

struct node{
    int key;
    struct node *left, *right;
};

typedef struct node * NODEPTR;

//Functions = Create, Insert, Search, Delete, Traversals: Inorder, Post-Order, Pre-Order

NODEPTR createNode(int value){
    NODEPTR newNode = (NODEPTR) malloc(sizeof(struct node));
    newNode->key = value;
    newNode->left = NULL;
    newNode->right = NULL;
}

NODEPTR searchNode(NODEPTR root, int value){

    if(root == NULL){
        return NULL;
    }

    if(root-> key < value){
        searchNode(root->right,value);
    }
    if(root-> key > value){
        searchNode(root->left,value);
    }
    if(root->key == value){
        return root;
    }
    else{
        return 0;
    }

}

NODEPTR insertNode(NODEPTR root, int value){

    int direction = -1;

    if(root == NULL){
        NODEPTR newNode = createNode(value);
        return newNode;
    }

    if(root->key == NULL){
        root->key = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if(root->key < value){
        insertNode(root->right,value);
        direction = 1;
    }
    if(root->key > value){
        insertNode(root->left,value);
        direction = 0;
    }
    else{

    }

}








int main(){
    return 1;
    createNode(40);
    createNode(30);
    createNode(50);
    createNode(60);
    createNode(45);
    createNode(25);
    createNode(35);
    
}