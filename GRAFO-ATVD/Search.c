#include "Data.h"
#include <stdio.h>
#include <stdlib.h>

void printPath(int *predecessor, int s, int t) {
  if (t == s) {
    printf("%d ", s);
  } else if (predecessor[t] == -1) {
    printf("Não há caminho entre %d e %d\n", s, t);
  } else {
    printPath(predecessor, s, predecessor[t]);
    printf("%d ", t);
  }
}

void BFS(graph *g, int s, int t) {
  int num_vertices = g->num_vertices;
  int *color = (int *)malloc(num_vertices * sizeof(int));
  int *predecessor = (int *)malloc(num_vertices * sizeof(int));
  int *distance = (int *)malloc(num_vertices * sizeof(int));

  for (int i = 0; i < num_vertices; i++) {
    color[i] = 0;
    predecessor[i] = -1;
    distance[i] = -1;
  }

  Queue q;
  q.front = q.rear = NULL;

  color[s] = 1;
  distance[s] = 0;
  enqueue(&q, s);

  while (!isEmptyQueue(&q)) {
    int u = dequeue(&q);
    Node *v = g->adjList[u];

    while (v != NULL) {
      if (color[v->info] == 0) {
        color[v->info] = 1;
        distance[v->info] = distance[u] + 1;
        predecessor[v->info] = u;
        enqueue(&q, v->info);
      }
      v = v->next;
    }
    color[u] = 2;
  }

  printPath(predecessor, s, t);

  free(color);
  free(predecessor);
  free(distance);
}

void DFS(graph *g, int s) {
  int num_vertices = g->num_vertices;
  int *color = (int *)malloc(num_vertices * sizeof(int));
  int *predecessor = (int *)malloc(num_vertices * sizeof(int));

  for (int i = 0; i < num_vertices; i++) {
    color[i] = 0;
    predecessor[i] = -1;
  }

  Stack stack;
  stack.top = NULL;

  push(&stack, s);
  color[s] = 1;
  while (!isEmptyStack(&stack)) {
    int u = pop(&stack);
    Node *v = g->adjList[u];

    while (v != NULL) {
      if (color[v->info] == 0) {
        push(&stack, v->info);
        color[v->info] = 1;
        predecessor[v->info] = u;
      }
      v = v->next;
    }
    color[u] = 2;
  }

  free(color);
  free(predecessor);
}
