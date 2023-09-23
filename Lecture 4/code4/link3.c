#include <stdio.h>
#include <stdlib.h>
#define BADVAL -9999

struct node{
    int info;
    struct node *next;    
};

typedef struct node * NODEPTR;

NODEPTR createNode(int val){
	NODEPTR p;
	p = (NODEPTR) malloc(sizeof(struct node));
	p->info = val;
	p->next = NULL;
	return p;
}

int delete(NODEPTR *afront, NODEPTR *arear){
	NODEPTR temp;
	int val;

	if (*afront == NULL) return BADVAL;
	else{
		temp = *afront;
		(*afront) = (*afront)->next;
		val = temp->info;
		free(temp); 
		if (*afront == NULL)
			*arear = NULL;
		return val;
	}
}

void insert(NODEPTR *afront, NODEPTR *arear, int elm){
	NODEPTR temp;
	temp = createNode(elm);
	if (*afront == NULL){
		*afront = temp;
		*arear = temp;
	}
	else{
		(*arear)->next = temp;
		*arear = temp;
	}
}

void printQueue(NODEPTR front){

	NODEPTR temp;

	if (front == NULL){ 
		printf("Queue empty\n");
		return;
	}

	printf("<- F ");
	for (temp = front; temp!= NULL; temp = temp->next)
		printf("%d ", temp->info);
        printf("<- R\n");
}

int main(){

        NODEPTR front, rear;
	int elm, menu;

	while(1){
          printf("0. exit, 1. initialize, 2. delete, 3. insert, 4. print. Input Choice: ");
	  scanf("%d", &menu);

	  switch(menu){
	   case 0: exit(0);
           case 1: front = rear = NULL; 
                   break;
           case 2: printf("Popped Value %d\n", delete(&front, &rear)); 
                   break;
           case 3: printf("Give element: "); 
                   scanf("%d", &elm); 
                   insert(&front, &rear, elm); 
                   break;
           case 4: printQueue(front); 
                   break;
	   default: printf("Wrong choice\n");
         }
        }
}
