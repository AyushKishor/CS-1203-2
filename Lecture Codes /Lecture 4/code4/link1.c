#include <stdio.h>
#include <stdlib.h>

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

int main(){

        NODEPTR p, q, temp;

        p = createNode(5); 
        q = createNode(6); 
        p->next = q;

        q = NULL;
        q = createNode(7); 

        (p->next)->next = q;

        for(temp = p; temp!= NULL; temp = temp->next)
                printf("%d %x %x\n", temp->info, (unsigned int) temp, (unsigned int) temp->next);
}

