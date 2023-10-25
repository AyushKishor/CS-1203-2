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
    return newNode;
}


void displayTree(struct node* root, int space)
{
    int i;
    if (root == NULL) return;
    space += 10;
    // Process right child first
    displayTree(root->right, space);
    // Print current node after space count
    printf("\n");
    for (i = 10; i < space; i++)
    printf(" ");
    printf("%d\n", root->key);
    // Process left child
    displayTree(root->left, space);
}

NODEPTR searchNode(NODEPTR root, int value){

    if(root == NULL){
        return NULL;
    }

    if(root-> key < value){
        return searchNode(root->right,value);
    }
    if(root-> key > value){
        return searchNode(root->left,value);
    }
    if(root->key == value){
        return root;
    }
    else{
        return NULL;
    }

}

NODEPTR insertNode(NODEPTR root, int value){


    if(root == NULL){
        NODEPTR newNode = createNode(value);
        return newNode;
    }

    if(!(root->key)){
        root->key = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    if(root->key < value){
        root->right = insertNode(root->right,value);
    }
    if(root->key > value){
        root->left = insertNode(root->left,value);
    }

    return root;
    
}

int deleteNode(NODEPTR root, int value){
    if(!(searchNode(root, value))){
        return 0;
    }
    else{
        NODEPTR foundNode = searchNode(root,value);

        if(foundNode->left == NULL && foundNode->right == NULL){
            
        }
    }
};








int main(){

    NODEPTR root;

    root = insertNode(root, 40);
    root = insertNode(root, 30);
    root = insertNode(root, 50);
    root = insertNode(root, 60);
    root = insertNode(root, 45);
    root = insertNode(root, 25);
    root = insertNode(root, 35);
    root = insertNode(root, 42);
    displayTree(root, 0);
    // deleteNode();
    NODEPTR k = searchNode(root, 35);
    printf("%d", k -> key);

    return 0;
}