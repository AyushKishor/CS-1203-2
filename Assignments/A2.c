#include <stdio.h>
#include <stdlib.h>
 
struct node{
    int key;
    struct node *left, *right;
};

//Creating a Stack

struct stack {
    unsigned capacity;
    int top;
    struct node** array;
};

struct stack* createStack(unsigned capacity) {
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (struct node**)malloc(stack->capacity * sizeof(struct node*));
    return stack;
}

struct node * createNode(int k){
    struct node *temp;

    temp = (struct node *) malloc(sizeof(struct node));
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

//Basic Stack Methods that we learnt in class which we need to implement Inorder Traversal without Recursion

int isFull(struct stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct stack* stack) {
    return stack->top == -1;
}

void push(struct stack* stack, struct node* item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

struct node* pop(struct stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}

void displayNode(struct node *temp){

	if (temp == NULL)
		printf("Node does not exist\n");
	else
    		printf("%x %d\n", (unsigned int) temp, temp->key);

}



struct node * search(struct node * anode, int k){

    struct node *temp, *parent;
     
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

// Inorder Implemented with Iteration and using a Stack

void inorderIterative(struct node* root) {
    struct stack* stack = createStack(100);
    struct node* curr = root;

    while (curr != NULL || !isEmpty(stack)) {
        while (curr != NULL) {
            push(stack, curr);
            curr = curr->left;
        }

        curr = pop(stack);
        printf("%d ", curr->key);

        curr = curr->right;
    }

    free(stack->array);
    free(stack);
}

int main()
{
    struct node * root = NULL, *temp;
    int elm, menu;

    while(1){
          printf("0. exit, 1. initialize, 2. search, 3. insert, 4. inorder. Input Choice: ");
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

           case 4: inorderIterative(root); // Calling the function
                printf("\n");
                break;

           default: printf("Wrong choice\n");
         }
        }

    return 0;
}
