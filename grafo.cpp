#include "grafo.h"
#include "vertice.h"
#include "aresta.h"
#include <new>
#include <iostream>
#include "listaAresta.h"

using namespace std;

#define nil -1
#define inf INT16_MAX
#define branco 0
#define cinza 1
#define preto 2
//Construtor da classe.
Grafo::Grafo(int quantVertices, bool orientado) {
  this->quantVertices = quantVertices;
  this->orientado = orientado;
  this->atualVertice = 0;
  this->vertices = new Vertice[quantVertices];
  this->auxConstructor();
}
//Metodo auxiliar para o construtor que instancia o ponteiro paravertices
void Grafo::auxConstructor() {
  for (int i = 0;i < quantVertices;i++) {
    this->vertices[i].setQuantArestas(quantVertices + 1);
    this->vertices[i].setNomeVertice(i);
  }
}
//Destrutor da classe
Grafo::~Grafo() {
  this->quantVertices = 0;
  this->orientado = false;
}
//Setter do atributo vertice
void Grafo::setVertice(Vertice vertice) {
  this->vertices[this->atualVertice] = vertice;
}
//Getter do atributo Vertice dado uma posicao do vetor.
Vertice* Grafo::getVertice(int pos) {
  return &this->vertices[pos];
}
//Setter do atributo quantVertices
void Grafo::setQuantVertices(int quantVertices) {
  this->quantVertices = quantVertices;
}
//Getter do atributo QuantVertices
int Grafo::getQuantVertices() {
  return this->quantVertices;
}
//Setter do atributo quantVertices
void Grafo::setOrientado(bool orientado) {
  this->orientado = orientado;
}
//Getter do atributo Orientado
bool Grafo::getOrientado() {
  return this->orientado;
}
/* Metodo que inicia todas as variaveis para a busca em profundidade.
 * Entrada:      Vertice que comeca a busca.
 * Pré-condição: Grafo estar previamente montado.
 */
void Grafo::buscaProfundidade(int origem) {
  this->cor = new int[this->quantVertices];
  this->proc = new int[this->quantVertices];
  for (int i = 0;i < this->quantVertices;i++) {
    this->cor[i] = branco;
    this->proc[i] = nil;
  }
  this->buscaProfundidadeAux(origem);
  delete(this->cor);
}
/* Metodo recursivo que faz a busca em profundidade "faz a visita em todos os vertices"
 * Entrada:      Vertice atual.
 * Pré-condição: Grafo estar previamente montado.
 */
void Grafo::buscaProfundidadeAux(int atual) {
  cout << atual;
  this->cor[atual] = cinza;
  this->timestamp++;
  for (int i = 0;i < this->getVertice(atual)->getQuantArestas();i++) {
    if (cor[this->getVertice(atual)->getArestas()[i].getVerticeDestino()] == branco) {
      cout << " - ";
      this->proc[this->getVertice(atual)->getArestas()[i].getVerticeDestino()] = atual;
      this->buscaProfundidadeAux(this->getVertice(atual)->getArestas()[i].getVerticeDestino());
    }
  }
  this->cor[atual] = preto;
}
/* Metodo responsável por fazer a busca em largura.
 * Entrada:      Vertice que comeca a busca.
 * Pré-condição: Grafo estar previamente montado.
 */
void Grafo::buscaLargura(int origem) {
  this->cor = new int[this->quantVertices];
  this->d = new int[this->quantVertices];
  this->proc = new int[this->quantVertices];
  this->Fila = new fila();
  int atual = origem;
  int dest;
  for (int i = 0;i < this->quantVertices;i++) {
    this->cor[i] = branco;
    this->d[i] = inf;
    this->proc[i] = nil;
  }
  this->cor[origem] = cinza;
  this->d[origem] = 0;
  this->proc[origem] = nil;
  this->Fila->queue(origem);
  while (!this->Fila->isEmpty()) {
    atual = this->Fila->show();
    cout << atual << " ";
    for (int i = 0;i < this->getVertice(atual)->getQuantArestas();i++) {
      dest = this->getVertice(atual)->getArestas()[i].getVerticeDestino();
      if (cor[dest] == branco) {
        this->cor[dest] = cinza;
        this->d[dest] = this->d[atual] + 1;
        this->proc[dest] = atual;
        this->Fila->queue(dest);
      }
    }
    this->Fila->dequeue();
    this->cor[atual] = preto;
    if (!this->Fila->isEmpty())
      cout << "- ";
  }

}
/* Metodo responsável por fazer o calculo de menor caminho para os próximos vertices usando bellmanFord.
 * Entrada:      Vertice inicial.
 * Pré-condição: Grafo estar previamente montado, e ser orientado.
 */
bool Grafo::bellmanFord(int origem) {
  if (!this->orientado) {
    cout << "Grafo nao orientado." << endl;
    return 1;
  }else {
    int pai[this->quantVertices] = {};
    this->d = new int[this->quantVertices];
    for (int i = 0;i < this->quantVertices;i++) {
      this->d[i] = inf;
      pai[i] = i;
    }
    this->d[origem] = 0;
    for (int k = 0;k < this->quantVertices-1;k++){
      for (int i = 0;i < this->quantVertices;i++) {
        for (int j = 0;j < this->vertices[i].getQuantArestas();j++) {
          if (this->d[this->vertices[i].getArestas()[j].getVerticeDestino()] > this->vertices[i].getArestas()[j].getPeso() + this->d[i]) {
            this->d[this->vertices[i].getArestas()[j].getVerticeDestino()] = this->vertices[i].getArestas()[j].getPeso() + this->d[i];
            pai[this->vertices[i].getArestas()[j].getVerticeDestino()] = i;
          }
        }
      }
    }
    bool check[this->quantVertices];
    cout << "origem: " << origem << endl;
    for (int i = 0;i < this->quantVertices;i++) {
      for (int posCheck = 0;posCheck < this->quantVertices;posCheck++) {
        check[posCheck] = false;
      }
      if(this->d[i] >= inf){
        cout << "destino: " << i << " dist.: Infinito caminho: ";
      }else{
        cout << "destino: " << i << " dist.: " << this->d[i] << " caminho: ";
      }
      this->showBellmanFord(pai, i, origem, check);
      if (i != pai[i]) 
        cout <<  " - " << i;
      cout << endl;
    }
    for (int i = 0;i < this->quantVertices - 1;i++) {
      for (int j = 0;j < this->vertices[i].getQuantArestas();j++) {
        if (d[this->vertices[i].getArestas()[j].getVerticeDestino()] < 0) {
          return false;
        }
      }
    }
    return true;
  }
}
/* Metodo responsável por exibir o menor caminho.
 * Entrada:      vetor de pai, posicao e atual.
 * Pré-condição: Nenhum.
 */
void Grafo::showBellmanFord(int* vet, int pos, int origem, bool* check) {
  if(!check[vet[pos]]){
    if (vet[pos] == origem) {
      cout << vet[pos];
    }else {
      check[pos] = true;
      showBellmanFord(vet, vet[pos], origem, check);
      cout << " - " << vet[pos];
    }
  }else {
    cout << vet[pos];
  }
}
/* Metodo responsável por gerar uma arvore geradora minima.
 * Entrada:      Nenhum.
 * Pré-condição: Grafo estar previamente montado.
 */
void Grafo::kruskal() {
  if (this->orientado) {
    cout << "Grafo orientado." << endl;
  }else{
    int countQuantArestas = 0;
    listaAresta *listaARESTA = new listaAresta();
    //Copia todas as arestas para uma lista encadeada.
    for (int i = 0;i < this->quantVertices;i++) {
      for (int j = 0;j < this->getVertice(i)->getQuantArestas();j++, countQuantArestas++) {
        listaARESTA->queue(this->getVertice(i)->getArestas()[j]);
      }
    }
    Aresta arestas[countQuantArestas + 1];
    arestas[0].setPeso(listaARESTA->show().getPeso());
    arestas[0].setVerticeAtual(listaARESTA->show().getVerticeAtual());
    arestas[0].setVerticeDestino(listaARESTA->show().getVerticeDestino());
    listaARESTA->dequeue();
    int j = 1;
    for (int i = 1;i < countQuantArestas && j < quantVertices;i++) {
      if (!this->busca(listaARESTA->show().getVerticeAtual(), listaARESTA->show().getVerticeDestino(), arestas, j,0)) {
        arestas[j].setPeso(listaARESTA->show().getPeso());
        arestas[j].setVerticeAtual(listaARESTA->show().getVerticeAtual());
        arestas[j].setVerticeDestino(listaARESTA->show().getVerticeDestino());
        j++;
      }
      listaARESTA->dequeue();
    }
    int peso = 0;
    for (int k = 0;k < j;k++) {
      peso += arestas[k].getPeso();
    }
    cout << "peso total: "<< peso << endl << "arestas: ";
    for (int k = 0;k < j;k++) {
      cout << "(" << arestas[k].getVerticeAtual() << "," << arestas[k].getVerticeDestino() << ") ";
    }
  }
}
/* Metodo auxiliar para verificar se a vertice pertence ao menor grafo gerador
 * Entrada:      Nenhum.
 * Pré-condição: Nenhum.
 */  
bool Grafo::busca(int Vertice1, int Vertice2, Aresta* arestas, int tam,int flag) {
  bool res = false;
  if (Vertice1 == Vertice2) return true;
  if (flag == tam) return false;
  for (int i = 0;i < tam;i++) {
    if (arestas[i].getVerticeAtual() == Vertice1 || Vertice1 == arestas[i].getVerticeDestino()) {
      if (arestas[i].getVerticeAtual() == Vertice1) {
        Vertice1 = arestas[i].getVerticeDestino();
      }else {
        Vertice1 = arestas[i].getVerticeAtual();
      }
      res = busca(Vertice1, Vertice2, arestas, tam,flag+1) || res;
    }
  }
  return res;
}
