#ifndef VERTICE_H
#define VERTICE_H

#include "aresta.h"

class Vertice {
private:
  int nomeVertice;
  int quantArestas;
  int atualAresta;
  Aresta* arestas;
public:
  Vertice(int quantArestas, int nomeVertice);
  Vertice();
  ~Vertice();
  void setNomeVertice(int nomeVertice);
  void setQuantArestas(int quantVertices);
  void sortAresta();
  void setArestas();
  int getNomeVertice();
  int getQuantArestas();
  void novaAresta(int peso, int verticeDestino);
  Aresta* getArestas();
};

#endif