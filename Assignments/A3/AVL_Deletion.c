#include <stdio.h>
#include <stdlib.h>

// Stack Code given by Professor
#define SIZE 4
#define BADVAL -9999

struct stack {
  int sp;
  int arr[SIZE];
};

typedef struct stack STACK;

void init(STACK *s) { s->sp = -1; }

int isEmpty(STACK *s) {
  if (s->sp == -1)
    return 1;
  else
    return 0;
}

int isFull(STACK *s) {
  if (s->sp == SIZE - 1)
    return 1;
  else
    return 0;
}

int top(STACK *s) {

  if (isEmpty(s))
    return BADVAL;
  else
    return (s->arr[s->sp]);
}

int pop(STACK *s) {

  if (isEmpty(s))
    return BADVAL;
  else
    return (s->arr[(s->sp)--]);
}

int push(STACK *s, int elm) {

  if (isFull(s))
    return 0;
  else {
    s->arr[++(s->sp)] = elm;
    return 1;
  }
}
void printStack(STACK *s) {

  int i;
  if (isEmpty(s)) {
    printf("Stack empty\n");
    return;
  }
  for (i = s->sp; i >= 0; i--)
    printf("%d\n", s->arr[i]);
}

// AVL Code given by Professor

struct Node {
  int key;
  struct Node *left;
  struct Node *right;
  int height;
};

int getHeight(struct Node *n) {
  if (n == NULL)
    return 0;
  return n->height;
}

struct Node *createNode(int key) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return node;
}

void displayTree(struct Node *root, int space) {
  int i;

  if (root == NULL)
    return;

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

int max(int a, int b) { return (a > b) ? a : b; }

int getBalanceFactor(struct Node *n) {
  if (n == NULL) {
    return 0;
  }
  return getHeight(n->left) - getHeight(n->right);
}

struct Node *rightRotate(struct Node *y) {
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
  y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

  return x;
}

struct Node *leftRotate(struct Node *x) {
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
  y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

  return y;
}

struct Node *insert(struct Node *node, int key) {
  if (node == NULL)
    return createNode(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);

  node->height = 1 + max(getHeight(node->left), getHeight(node->right));
  int bf = getBalanceFactor(node);

  // Left Left Case
  if (bf > 1 && key < node->left->key) {
    return rightRotate(node);
  }
  // Right Right Case
  if (bf < -1 && key > node->right->key) {
    return leftRotate(node);
  }
  // Left Right Case
  if (bf > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }
  // Right Left Case
  if (bf < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }
  return node;
}

void preOrder(struct Node *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
  }
}

void inOrder(struct Node *root) {
  if (root != NULL) {
    preOrder(root->left);
    printf("%d ", root->key);
    preOrder(root->right);
  }
}

struct Node *deleteNode(struct Node *root, int key) {
  STACK stack;
  init(&stack);
  struct Node *temp = root;
  struct Node *child;
  struct Node *parent = NULL;

  // Step 1: Iteratively find the node to be deleted and push nodes onto stack
  while (temp != NULL && temp->key != key) {
    push(&stack, temp);
    parent = temp;
    if (key < temp->key) {
      temp = temp->left;
    } else {
      temp = temp->right;
    }
  }

  if (temp == NULL) {
    printf("Key not found.\n");
    return root;
  }

  // Node with only one child or no child
  if (temp->left == NULL || temp->right == NULL) {
    if (temp->left == NULL) {
      child = temp->right;
    } else {
      child = temp->left;
    }

    if (parent == NULL) {
      root = child;
    } else if (parent->left == temp) {
      parent->left = child;
    } else {
      parent->right = child;
    }

    free(temp);

  } else {
    // Node with two children
    struct Node *successor = temp->right;
    parent = temp;
    push(&stack, parent);

    while (successor->left != NULL) {
      parent = successor;
      push(&stack, parent);
      successor = successor->left;
    }

    temp->key = successor->key;
    if (parent->left == successor) {
      parent->left = successor->right;
    } else {
      parent->right = successor->right;
    }

    free(successor);
  }

  // Step 2: Retrace the path using the stack and perform rotations if necessary
  while (!isEmpty(&stack)) {
    struct Node *node = pop(&stack);
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    if (bf > 1) {
      if (getBalanceFactor(node->left) < 0) {
        node->left = leftRotate(node->left);
      }
      node = rightRotate(node);
    }

    if (bf < -1) {
      if (getBalanceFactor(node->right) > 0) {
        node->right = rightRotate(node->right);
      }
      node = leftRotate(node);
    }
  }

  return root;
}

int main() {
  struct Node *root = NULL;

  // Inserting nodes
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 70);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 60);
  root = insert(root, 80);

  printf("Original AVL Tree:\n");
  displayTree(root, 10);
  printf("\n");

  // Test 1: Deleting a leaf node (20)
  root = deleteNode(root, 20);
  printf("After deleting leaf node 20:\n");
  displayTree(root, 10);
  printf("\n");

  // Test 2: Deleting a node with one child (70)
  root = deleteNode(root, 70);
  printf("After deleting node 70 with one child:\n");
  displayTree(root, 10);
  printf("\n");

  // Test 3: Deleting a node with two children (50)
  root = deleteNode(root, 50);
  printf("After deleting node 50 with two children:\n");
  displayTree(root, 10);
  printf("\n");

  // Test 4: Deleting a node causing imbalance (40)
  root = deleteNode(root, 40);
  printf("After deleting node 40 causing imbalance:\n");
  displayTree(root, 10);
  printf("\n");

  return 0;
}
