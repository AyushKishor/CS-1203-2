#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *next;    
};

typedef struct node * NODEPTR;

int main(){

        NODEPTR p, q, temp;

	p = (NODEPTR) malloc(sizeof(struct node));
	p->info = 5;
	p->next = NULL;

	q = (NODEPTR) malloc(sizeof(struct node));
	q->info = 6;
	q->next = NULL;

	p->next = q;

	q = NULL;
	q = (NODEPTR) malloc(sizeof(struct node));
	q->info = 7;
	q->next = NULL;

	(p->next)->next = q;

	for(temp = p; temp!= NULL; temp = temp->next)
		printf("%d %x %x\n", temp->info, (unsigned int) temp, (unsigned int) temp->next);
}
