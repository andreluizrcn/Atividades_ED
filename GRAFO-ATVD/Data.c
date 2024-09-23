#include "Data.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int num_vertices;
fscanf(file, "%d", &num_vertices);

graph *g = createGraph(num_vertices);

g->matrix = (adjMatrix *)malloc(sizeof(adjMatrix));
g->matrix->num_vertices = num_vertices;
g->matrix->matrix = (int **)malloc(num_vertices * sizeof(int *));
for (int i = 0; i < num_vertices; i++) {
  g->matrix->matrix[i] = (int *)malloc(num_vertices * sizeof(int));
  for (int j = 0; j < num_vertices; j++) {
    fscanf(file, "%d", &g->matrix->matrix[i][j]);
  }
}

g->array = (Node **)malloc(num_vertices * sizeof(Node *));
for (int i = 0; i < num_vertices; i++) {
  g->array[i] = NULL;
}

fclose(file);
return g;
}

Node *ifExistsList(Node *list, int dest) {
  Node *p;
  for (p = list; p != NULL; p = p->next) {
    if (p->info == dest)
      return p;
  }
  return NULL;
}

int ifExistsMatrix(adjMatrix *matrix, int srcX, int destY) {
  if (srcX < 0 || srcX >= matrix->num_vertices || destY < 0 ||
      destY >= matrix->num_vertices) {
    return 0;
  }

  return matrix->matrix[srcX][destY] != 0;
}

graph *createGraph(int vertix) {
  graph *g = (graph *)malloc(sizeof(graph));
  g->num_vertices = vertix;

  g->matrix = NULL;
  g->array = (Node **)malloc(vertix * sizeof(Node *));
  for (int i = 0; i < vertix; i++) {
    g->array[i] = NULL;
  }

  return g;
}

void freeNode(Node *node) { free(node); }

void addEdgeList(Node *ptr, int dado) {
  Node *q = getNode();
  q->info = dado;
  q->next = ptr;
  ptr = q;
}

void enqueue(Queue *ptrQ, int value) {
  Node *p = getNode();
  p->info = value;
  p->next = NULL;

  if (ptrQ->rear == NULL) {
    ptrQ->front = ptrQ->rear = p;
  } else {
    (ptrQ->rear)->next = p;
    ptrQ->rear = p;
  }
}

bool isEmptyQueue(Queue *ptrQ) { return ptrQ->front == NULL; }

int dequeue(Queue *ptrQ) {
  if (isEmptyQueue(ptrQ)) {
    return -1;
  }

  Node *p = ptrQ->front;
  int value = p->info;
  ptrQ->front = ptrQ->front->next;

  if (ptrQ->front == NULL) {
    ptrQ->rear = NULL;
  }

  freeNode(p);
  return value;
}

void initStack(Stack *stack) {
  stack->top = -1;
  stack->items = (int *)malloc(MAX * sizeof(int));
}

bool isEmptyStack(Stack *stack) { return stack->top == -1; }

void push(Stack *stack, int value) {
  if (stack->top == MAX - 1) {
    printf("Stack overflow\n");
    return;
  }
  stack->items[++(stack->top)] = value;
}

int pop(Stack *stack) {
  if (isEmptyStack(stack)) {
    printf("Stack underflow\n");
    return -1;
  }
  return stack->items[(stack->top)--];
}

void freeStack(Stack *stack) { free(stack->items); }
