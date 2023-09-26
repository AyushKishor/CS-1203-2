#include <stdio.h>
#include <stdlib.h>

// Node structure for Linked List
typedef struct node {
    int data;
    struct node *next;
} NODE, *NODEPTR;

// Queue structure containing pointers to front and rear
typedef struct queue {
    NODEPTR front, rear;
} QUEUE;

// Function to initialize a new node
NODEPTR newNode(int data) {
    NODEPTR temp = (NODEPTR)malloc(sizeof(NODE));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to insert a node at the rear of the queue
void insert(QUEUE *q, int elm) {
    NODEPTR temp = newNode(elm);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to delete a node from the front of the queue
void delete(QUEUE *q) {
    if (q->front == NULL)
        return;

    NODEPTR temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

// Function to print the queue
void printQueue(QUEUE q) {
    NODEPTR temp = q.front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    QUEUE q = {NULL, NULL};
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insert(&q, data);
                break;
            case 2:
                delete(&q);
                break;
            case 3:
                printQueue(q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
