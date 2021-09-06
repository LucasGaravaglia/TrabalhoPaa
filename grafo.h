#ifndef GRAFO_H
#define GRAFO_H

#include "vertice.h"
#include "aresta.h"
#include "fila.h"

class Grafo {
private:
  int quantVertices;
  int atualVertice;
  bool orientado;
  Vertice* vertices;

  fila* Fila;
  int* cor;
  int* d;
  int* f;
  int* proc;
  int timestamp;
public:
  Grafo(int quantVertices, bool orientado);
  ~Grafo();
  void auxConstructor();
  void setVertice(Vertice vertice);
  void setQuantVertices(int quantVertices);
  void setOrientado(bool orientado);
  Vertice* getVertice(int pos);
  int getQuantVertices();

  bool getOrientado();
  void buscaProfundidade(int origem);
  void buscaProfundidadeAux(int atual);
  void buscaLargura(int origem);
  int* bellmanFord(int origem);
  void kruskal();
  bool busca(int Vertice1, int Vertice2, Aresta* arestas, int tam);
  bool recur(int Vertice1, int Vertice2, Aresta* arestas, int tam,int flag);
};

#endif