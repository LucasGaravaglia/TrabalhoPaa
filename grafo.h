#ifndef GRAFO_H
#define GRAFO_H

#include "vertice.h"
#include "aresta.h"

class Grafo {
private:
  int quantArestas;
  int atualAresta;
  bool orientado;
  Aresta* arestas;
public:
  Grafo(int quantArestas, bool orientado, Aresta* arestas);
  ~Grafo();

  void setAresta(Aresta aresta);
  void setQuantArestas(int quantArestas);
  void setOrientado(bool orientado);
  Aresta getAresta(int pos);
  int getQuantArestas();

  bool getOrientado();
  void buscaLargura(int origem);
  void buscaProfundidade(int origem);
  void bellmanFord(int origem);
  void kruskal();
};

#endif