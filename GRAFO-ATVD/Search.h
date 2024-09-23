#ifndef SEARCH_H
#define SEARCH_H
#include "Data.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GREY 1
#define BLACK 2

typedef struct Stack {
  int top;
  int *items;
} Stack;

void BFS(graph *g, int srcX, int endY);
void DFS(graph *g, int srcX, int endY);

#endif
