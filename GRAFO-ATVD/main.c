#include "Data.h"
#include <stdio.h>

int main() {
  const char *filename = "../instncias_grafo/pcv10.txt"; // Arquivo de entrada
  graph *g = readInstance(filename);
  if (g == NULL) {
    fprintf(stderr, "Falha ao ler o grafo do arquivo.\n");
    return EXIT_FAILURE;
  }

  // Exemplo de BFS
  printf("BFS do vértice 0 ao vértice 4:\n");
  BFS(g, 0, 4);

  // Exemplo de DFS
  printf("DFS começando pelo vértice 0:\n");
  DFS(g, 0);

  // Libera memória após uso
  freeGraph(g);

  return EXIT_SUCCESS;
}
