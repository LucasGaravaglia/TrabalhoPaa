#include <iostream>
#include "grafo.h"
#include "vertice.h"
#include "aresta.h"
#include "arquivo.h"
#include <new>



int main() {
  Arquivo* arq = new Arquivo();
  Grafo* grafo = arq->lerGrafo("entrada.txt");
  grafo->buscaProfundidade(3);

  return 0;
}
