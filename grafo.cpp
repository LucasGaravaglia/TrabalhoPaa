#include "grafo.h"
#include "vertice.h"
#include "aresta.h"
#include <new>

#define nil -1
#define inf (unsigned)(-1)
#define branco 0
#define cinza 1
#define preto 2

Grafo::Grafo(int quantVertices, bool orientado) {
  this->quantVertices = quantVertices;
  this->orientado = orientado;
  this->atualVertice = 0;
  this->vertices = new Vertice[quantVertices];
  this->auxConstructor();
}
void Grafo::auxConstructor() {
  for (int i = 0;i < quantVertices;i++) {
    this->vertices[i].setQuantArestas(quantVertices + 1);
    this->vertices[i].setNomeVertice(i);
    this->vertices[i].setArestas();
  }
}
Grafo::~Grafo() {
  this->quantVertices = 0;
  this->orientado = false;
}
void Grafo::setVertice(Vertice vertice) {
  this->vertices[this->atualVertice] = vertice;
}
Vertice* Grafo::getVertice(int pos) {
  return &this->vertices[pos];
}
void Grafo::setQuantVertices(int quantVertices) {
  this->quantVertices = quantVertices;
}
int Grafo::getQuantVertices() {
  return this->quantVertices;
}
void Grafo::setOrientado(bool orientado) {
  this->orientado = orientado;
}
bool Grafo::getOrientado() {
  return this->orientado;
}
void Grafo::buscaLargura(int origem) {
  this->cor = new int[this->quantVertices];
  this->d = new int[this->quantVertices];
  this->f = new int[this->quantVertices];
  this->proc = new int[this->quantVertices];
  for (int i = 0;i < this->quantVertices;i++) {
    this->cor[i] = branco;
    this->proc[i] = nil;
  }
  this->Pilha = new pilha();
  this->timestamp = 0;
  this->buscaLarguraAux(origem);
  delete(this->cor);
  delete(this->d);
  delete(this->f);
  delete(this->Pilha);
}

void Grafo::buscaLarguraAux(int atual) {
  cout << atual << endl;
  this->cor[atual] = cinza;
  this->timestamp++;
  this->d[atual] = this->timestamp;
  for (int i = 0;i < this->getVertice(atual)->getQuantArestas();i++) {
    if (cor[this->getVertice(atual)->getArestas()[i].getVerticeDestino()] == branco) {
      this->proc[this->getVertice(atual)->getArestas()[i].getVerticeDestino()] = atual;
      this->buscaLarguraAux(this->getVertice(atual)->getArestas()[i].getVerticeDestino());
    }
  }
  this->cor[atual] = preto;
  timestamp++;
  this->f[atual] = timestamp;
}

void Grafo::buscaProfundidade(int origem) {
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
    cout << atual;
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
  }

}

int* Grafo::bellmanFord(int origem) {
  if (!this->orientado) {
    cout << "Grafo nao orientado." << endl;
    return 0;
  }
  else {
    int pesoTemp;
    this->Fila = new fila();
    this->Fila->queue(origem);
    this->proc = new int[this->quantVertices];
    this->d = new int[this->quantVertices];
    for (int i = 0;i < this->quantVertices;i++) {
      this->proc[i] = nil;
      this->d[i] = inf;
    }
    this->d[origem] = 0;
    while (!this->Fila->isEmpty()) {
      cout << this->getVertice(this->Fila->show())->getQuantArestas();
      // cout << this->Fila->show()
      for (int i = 0;i < this->getVertice(this->Fila->show())->getQuantArestas();i++) {
        pesoTemp = this->d[this->getVertice(this->Fila->show())->getArestas()[i].getVerticeAtual()] + this->getVertice(this->Fila->show())->getArestas()[i].getPeso();
        this->Fila->queue(this->getVertice(this->Fila->show())->getArestas()->getVerticeDestino());
        if (pesoTemp < d[this->getVertice(this->Fila->show())->getArestas()->getVerticeDestino()]) {
          this->d[this->getVertice(this->Fila->show())->getArestas()->getVerticeDestino()] = pesoTemp;
        }
      }
      this->Fila->dequeue();
    }
    return this->d;
  }
}
void Grafo::kruskal() {

}