#include "vertice.h"
#include <new>
#include <iostream>

using namespace std;

Vertice::Vertice(int quantArestas, int nomeVertice) {
  this->nomeVertice = nomeVertice;
  this->quantArestas = quantArestas;
  this->atualAresta = 0;
  this->arestas = (Aresta*)malloc(sizeof(Aresta));
}
Vertice::Vertice() {
  this->nomeVertice = 0;
  this->quantArestas = 0;
  this->atualAresta = 0;
}
Vertice::~Vertice() {
}

void Vertice::setQuantArestas(int quantArestas) {
  this->quantArestas = quantArestas;
}
int Vertice::getQuantArestas() {
  return this->atualAresta;
}
void Vertice::setNomeVertice(int nomeVertice) {
  this->nomeVertice = nomeVertice;
}
int Vertice::getNomeVertice() {
  return this->nomeVertice;
}

void Vertice::novaAresta(int peso, int verticeDestino, int verticeAtual) {
  this->arestas = (Aresta*)realloc(this->arestas,sizeof(Aresta) * (this->atualAresta + 1));
  this->arestas[this->atualAresta].setVerticeAtual(verticeAtual);
  this->arestas[this->atualAresta].setVerticeDestino(verticeDestino);
  this->arestas[this->atualAresta].setPeso(peso);
  this->atualAresta++;
  this->sortAresta();
}

void Vertice::sortAresta() {
  Aresta* tempAresta = new Aresta[this->quantArestas];
  Aresta temp;
  int index = 0, destino = 0;
  for (int i = 0;i < this->atualAresta;i++) {
    destino = this->arestas[i].getVerticeDestino();
    index = i;
    for (int j = i;j < this->atualAresta;j++) {
      if (this->arestas[j].getVerticeDestino() < destino) {
        destino = this->arestas[j].getVerticeDestino();
        index = j;
      }
    }
    temp.setPeso(this->arestas[i].getPeso());
    temp.setVerticeDestino(this->arestas[i].getVerticeDestino());
    temp.setVerticeAtual(this->arestas[i].getVerticeAtual());
    this->arestas[i].setPeso(this->arestas[index].getPeso());
    this->arestas[i].setVerticeAtual(this->arestas[index].getVerticeAtual());
    this->arestas[i].setVerticeDestino(this->arestas[index].getVerticeDestino());
    this->arestas[index].setPeso(temp.getPeso());
    this->arestas[index].setVerticeAtual(temp.getVerticeAtual());
    this->arestas[index].setVerticeDestino(temp.getVerticeDestino());
  }
}

Aresta* Vertice::getArestas() {
  return this->arestas;
}