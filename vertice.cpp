#include "vertice.h"
#include <new>
#include <iostream>

using namespace std;
//Construtor sobrecarregado ca classe vertice
Vertice::Vertice(int quantArestas, int nomeVertice) {
  this->nomeVertice = nomeVertice;
  this->quantArestas = quantArestas;
  this->atualAresta = 0;
  this->arestas = (Aresta*)malloc(sizeof(Aresta));
}
//Construtor da classe Vertice
Vertice::Vertice() {
  this->nomeVertice = 0;
  this->quantArestas = 0;
  this->atualAresta = 0;
}
//Destrutor da classe vertice
Vertice::~Vertice() {
}
//Setter da variavel QuantArestas
void Vertice::setQuantArestas(int quantArestas) {
  this->quantArestas = quantArestas;
}
//Método que retorna a quantidade de arestas criadas no vertice
int Vertice::getQuantArestas() {
  return this->atualAresta;
}
//Setter da variavel NomeVertice
void Vertice::setNomeVertice(int nomeVertice) {
  this->nomeVertice = nomeVertice;
}
//Getter da variavel NomeVertice
int Vertice::getNomeVertice() {
  return this->nomeVertice;
}
//Método que cuida da criação de uma aresta nesse vertice
void Vertice::novaAresta(int peso, int verticeDestino, int verticeAtual) {
  this->arestas = (Aresta*)realloc(this->arestas,sizeof(Aresta) * (this->atualAresta + 1));
  this->arestas[this->atualAresta].setVerticeAtual(verticeAtual);
  this->arestas[this->atualAresta].setVerticeDestino(verticeDestino);
  this->arestas[this->atualAresta].setPeso(peso);
  this->atualAresta++;
  this->sortAresta();
}
//Método que ordena o vetor de arestas em ordem crescente.
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
//Getter do vetor de arestas
Aresta* Vertice::getArestas() {
  return this->arestas;
}