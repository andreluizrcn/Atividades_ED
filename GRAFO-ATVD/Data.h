#ifndef DATA_H
#define DATA_H
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
  int info;
  struct Node *next;
} Node;

typedef struct adjMatrix {
  int **matrix;
  int num_vertices;
} adjMatrix;

typedef struct Queue {
  Node *front;
  Node *rear;
} Queue;

typedef struct graph {
  int num_vertices;
  Node **array;
  adjMatrix *matrix;
} graph;

inline Node *getNode() { return (Node *)malloc(sizeof(Node)); };
void freeNode(Node *node);

graph *createGraph(int vertix);
void addEdgeList(Node *ptr, int info);
void addEdgeMatrix();

void enqueue(Queue *ptrQ, int value);
bool isEmptyQueue(Queue *ptrQ);
int dequeue(Queue *printQ);

bool isEmptyStack(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
void initStack(Stack *stack);
void freeStack(Stack *stack);

graph *readInstance(const char *filename);
Node *ifExistsList(Node *list, int dest);
int ifExistsMatrix(adjMatrix *matrix, int srcX, int destY);

void print();

#endif
