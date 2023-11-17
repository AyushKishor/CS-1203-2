#include <stdio.h>  
#include <stdlib.h>  

struct Node  
{  
    int key;  
    struct Node *left;  
    struct Node *right;  
    int height;  
};  

// Time Complexity: O(1)
// Space Complexity: O(1)
int getHeight(struct Node *n){  
    if(n==NULL)  
        return 0;  
    return n->height;  
}  

// Time Complexity: O(1)
// Space Complexity: O(1)
struct Node *createNode(int key){  
    struct Node* node = (struct Node *) malloc(sizeof(struct Node));  
    node->key = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1;  
    return node;  
}

// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree (due to recursion stack)
void displayTree(struct Node* root, int space)
{
    int i;

    if (root == NULL) return;

    space += 10;

    displayTree(root->right, space);

    printf("\n");
    for (i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    displayTree(root->left, space);
}

// Time Complexity: O(1)
// Space Complexity: O(1)
int max (int a, int b){  
    return (a>b)?a:b;  
}  

// Time Complexity: O(1)
// Space Complexity: O(1)
int getBalanceFactor(struct Node * n){  
    if(n==NULL){  
        return 0;  
    }  
    return getHeight(n->left) - getHeight(n->right);  
}  

// Time Complexity: O(1)
// Space Complexity: O(1)
struct Node* rightRotate(struct Node* y){  
    struct Node* x = y->left;  
    struct Node* T2 = x->right;  
   
    x->right = y;  
    y->left = T2;  
   
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;  
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;  
   
    return x;  
}  

// Time Complexity: O(1)
// Space Complexity: O(1)
struct Node* leftRotate(struct Node* x){  
    struct Node* y = x->right;  
    struct Node* T2 = y->left;  
   
    y->left = x;  
    x->right = T2;  
   
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;  
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;  
   
    return y;  
}  

// Time Complexity: O(log n) for balanced AVL trees, but can degrade to O(n) in worst case scenarios
// Space Complexity: O(log n) for balanced AVL trees due to recursion stack
struct Node *insert(struct Node* node, int key){  
    if (node == NULL)  
        return  createNode(key);  
   
    if (key < node->key)  
        node->left  = insert(node->left, key);  
    else if (key > node->key)  
        node->right = insert(node->right, key);  
   
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));  
    int bf = getBalanceFactor(node);  
   
    // Left Left Case  
        if(bf>1 && key < node->left->key){  
            return rightRotate(node);  
        }  
    // Right Right Case  
        if(bf<-1 && key > node->right->key){  
            return leftRotate(node);  
        }  
    // Left Right Case  
    if(bf>1 && key > node->left->key){  
            node->left = leftRotate(node->left);  
            return rightRotate(node);  
        }  
    // Right Left Case  
    if(bf<-1 && key < node->right->key){  
            node->right = rightRotate(node->right);  
            return leftRotate(node);  
        }  
    return node;  
}  

// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree (due to recursion stack)
void preOrder(struct Node *root)  
{  
    if(root != NULL)  
    {  
        printf("%d ", root->key);  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  

// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree (due to recursion stack)
void inOrder(struct Node *root)  
{  
    if(root != NULL)  
    {  
        inOrder(root->left);  
        printf("%d ", root->key);  
        inOrder(root->right);  
    }  
}  