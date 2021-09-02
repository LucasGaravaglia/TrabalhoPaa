#ifndef ARESTA_H
#define ARESTA_H

#include "vertice.h"

class Aresta {
private:
  int nomeAresta;
  int quantVertices;
  int atualVertice;
  Vertice* vertices;
public:
  Aresta(int quantArestas, int nomeAresta);
  Aresta();
  ~Aresta();
  void setNomeAresta(int nomeAresta);
  void setQuantVertices(int quantVertices);
  void setVertices();
  int getNomeAresta();
  int getQuantVertices();
  void novaVertice(int peso, int arestaDestino);
  Vertice* getVertices();
};

#endif