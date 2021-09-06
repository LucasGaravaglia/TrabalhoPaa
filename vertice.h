#ifndef VERTICE_H
#define VERTICE_H

#include "aresta.h"

class Vertice {
private:
  int nomeVertice;
  //Atributo que armazena a quantidade maxima de arestas do vertice
  int quantArestas;
  //Atributo que armazena a quantidade atual de arestas
  int atualAresta;
  Aresta* arestas;
public:
  //Construtor da classe Vertice
  Vertice();
  //Construtor sobrecarregado ca classe vertice
  Vertice(int quantArestas, int nomeVertice);
  //Destrutor da classe vertice
  ~Vertice();
  //Setter da variavel NomeVertice
  void setNomeVertice(int nomeVertice);
  //Setter da variavel QuantArestas
  void setQuantArestas(int quantVertices);
  //Método que ordena o vetor de arestas em ordem crescente.
  void sortAresta();
  //Getter da variavel NomeVertice
  int getNomeVertice();
  //Método que retorna a quantidade de arestas criadas no vertice
  int getQuantArestas();
  //Método que cuida da criação de uma aresta nesse vertice
  void novaAresta(int peso, int verticeDestino, int verticeAtual);
  //Getter do vetor de arestas
  Aresta* getArestas();
};

#endif