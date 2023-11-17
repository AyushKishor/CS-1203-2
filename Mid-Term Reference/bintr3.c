#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node *left, *right;
};

// Time Complexity: O(1)
// Space Complexity: O(1)
struct node * createNode(int k){
    struct node *temp;
    temp = (struct node *) malloc(sizeof(struct node));
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

// Time Complexity: O(1)
// Space Complexity: O(1)
void displayNode(struct node *temp){
    if (temp == NULL)
        printf("Node does not exist\n");
    else
        printf("%x %d\n", (unsigned int) temp, temp->key);
}

// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree (due to recursive call stack)
void displayTree(struct node* root, int space){
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

// Time Complexity: O(h) where h is the height of the tree
// Space Complexity: O(1)
struct node * search(struct node * anode, int k){
    struct node *temp;
    if (anode == NULL) return NULL;
    temp = anode;
    while (temp != NULL){
        if (temp->key == k){
            return temp;
        }
        if (k < temp->key){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return NULL;
}

// Time Complexity: O(h) where h is the height of the tree
// Space Complexity: O(1)
struct node * insert(struct node * anode, int k){
    struct node *temp, *parent;
    int direction;
    if (anode == NULL){
        anode = createNode(k);
        return anode;
    }
    temp = anode;
    while (temp != NULL){
        if (temp->key == k){
            printf("node with value %d exists\n", k);
            return temp;
        }
        if (k < temp->key){
            parent = temp;
            temp = temp->left;
            direction = 0;
        }
        else{
            parent = temp;
            temp = temp->right;
            direction = 1;
        }
    }
    temp = createNode(k);
    if (direction == 0)
        parent->left = temp;
    else
        parent->right = temp;
    return temp; 
}

// Time Complexity: O(h) where h is the height of the tree
// Space Complexity: O(1)
struct node * delete (struct node * anode, int k){
    struct node *temp, *parent, *intemp, *inparent;
    int direction, flag = 0, val;
    if (anode == NULL){ 
        printf("Tree empty\n");
        return NULL;
    }
    parent = NULL; 
    temp = anode;
    while (temp != NULL){
        if (temp->key == k){
            flag = 1;
            break;
        }
        if (k < temp->key){
            parent = temp;
            temp = temp->left;
            direction = 0;
        }
        else{
            parent = temp;
            temp = temp->right;
            direction = 1;
        }
    }
    // ... [rest of the function]
    return NULL;
}

// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree (due to recursive call stack)
void inorder(struct node * anode){
    if (anode != NULL) {
        inorder(anode->left);
        printf("%d ", anode->key);
        inorder(anode->right);
    }
}

// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree (due to recursive call stack)
void preorder(struct node * anode){
    if (anode != NULL) {
        printf("%d ", anode->key);
        preorder(anode->left);
        preorder(anode->right);
    }
}

// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree (due to recursive call stack)
void postorder(struct node * anode){
    if (anode != NULL) {
        postorder(anode->left);
        postorder(anode->right);
        printf("%d ", anode->key);
    }
}

// Time Complexity: O(n)
// Space Complexity: O(h) where h is the height of the tree (due to recursive call stack)
void freeTree(struct node * anode){
    if (anode != NULL) {
        freeTree(anode->left);
        freeTree(anode->right);
        free(anode);
    }
}

int main()
{
    struct node * root = NULL, *temp;
    int elm, menu;

    while(1){
      printf("\n0. exit, 1. initialize, 2. search, 3. insert, 4. delete,\n ");
      printf("5. inorder, 6. preorder, 7. postorder, 8. free tree, 9. display. Input Choice: ");
          scanf("%d", &menu);

          switch(menu){
           case 0: exit(0);

           case 1: root = NULL;
                   break;

           case 2: printf("Give element to search: ");
                   scanf("%d", &elm);
		   temp = search(root, elm);
		   displayNode(temp);
                   break;

           case 3: printf("Give element to insert: ");
                   scanf("%d", &elm);
		   if (root == NULL)
		   	temp = root = insert(root, elm);
		   else
		   	temp = insert(root, elm);
		   displayNode(temp);
                   break;

           case 4: printf("Give element to delete: ");
                   scanf("%d", &elm);
		   if (root == NULL)
                      printf("Tree empty\n");
		   else if ((root->key == elm) && (root->left == NULL) && (root->right == NULL)){
		      temp = root;
                      root = NULL;
		   }
		   else if ((root->key == elm) && (root->left != NULL) && (root->right == NULL)){
			temp = root;
			root = root->left;
		   }
		   else if ((root->key == elm) && (root->left == NULL) && (root->right != NULL)){
			temp = root;
			root = root->right;
		   }
		   else
		   	temp = delete(root, elm);

		   displayNode(temp);
                   break;

           case 5: inorder(root);
		   printf("\n");
                   break;

           case 6: preorder(root);
                   printf("\n");
                   break;

           case 7: postorder(root);
                   printf("\n");
                   break;

           case 8: freeTree(root);
                   root = NULL;
                   break;

           case 9: if (root == NULL) printf("Tree empty\n");
		   displayTree(root, 0);
                   break;

           default: printf("Wrong choice\n");
         }
        }

    return 0;
}