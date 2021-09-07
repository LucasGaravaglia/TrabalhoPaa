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
  //Destrutor da classe
  ~Grafo();
  //Construtor da classe.
  Grafo(int quantVertices, bool orientado);
  //Metodo auxiliar para o contrutor que instancia o ponteiro paravertices
  void auxConstructor();
  //Setter do atributo vertice
  void setVertice(Vertice vertice);
  //Setter do atributo quantVertices
  void setQuantVertices(int quantVertices);
  //Setter do atributo orientado
  void setOrientado(bool orientado);
  //Getter do atributo Vertice dado uma posicao do vetor.
  Vertice* getVertice(int pos);
  //Getter do atributo QuantVertices
  int getQuantVertices();
  //Getter do atributo Orientado
  bool getOrientado();

/* Metodo que inicia todas as variaveis para a busca em profundidade.
 * Entrada:      Vertice que comeca a busca.
 * Pré-condição: Grafo estar previamente montado.
 */
  void buscaProfundidade(int origem);
  
/* Metodo recursivo que faz a busca em profundidade "faz a visita em todos os vertices"
 * Entrada:      Vertice atual.
 * Pré-condição: Grafo estar previamente montado.
 */
  void buscaProfundidadeAux(int atual);
/* Metodo responsável por fazer a busca em largura.
 * Entrada:      Vertice que comeca a busca.
 * Pré-condição: Grafo estar previamente montado.
 */
  void buscaLargura(int origem);
/* Metodo responsável por fazer o calculo de menor caminho para os próximos vertices usando bellmanFord.
 * Entrada:      Vertice inicial.
 * Pré-condição: Grafo estar previamente montado, e ser orientado.
 */
  bool bellmanFord(int origem);
  void showBellmanFord(int* vet, int pos, int inicial);
/* Metodo responsável por gerar uma arvore geradora minima.
 * Entrada:      Nenhum.
 * Pré-condição: Grafo estar previamente montado.
 */
  void kruskal();
/* Metodo auxiliar para verificar se a vertice pertence ao menor grafo gerador
 * Entrada:      Nenhum.
 * Pré-condição: Nenhum.
 */  
  bool recur(int Vertice1, int Vertice2, Aresta* arestas, int tam, int flag);
  bool busca(int Vertice1, int Vertice2, Aresta* arestas, int tam);
};

#endif