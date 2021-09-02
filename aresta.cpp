#include "aresta.h"
#include <new>
#include <iostream>

using namespace std;

Aresta::Aresta(int quantVertices, int nomeAresta) {
  this->nomeAresta = nomeAresta;
  this->quantVertices = quantVertices;
  this->vertices = new Vertice[quantVertices];
  this->atualVertice = 0;
}
Aresta::Aresta() {
  this->nomeAresta = 0;
  this->quantVertices = 0;
  this->atualVertice = 0;
}
Aresta::~Aresta() {
  delete this->vertices;
}
void Aresta::setQuantVertices(int quantVertices) {
  this->quantVertices = quantVertices;
}
int Aresta::getQuantVertices() {
  return this->quantVertices;
}
void Aresta::setNomeAresta(int nomeAresta) {
  this->nomeAresta = nomeAresta;
}
int Aresta::getNomeAresta() {
  return this->nomeAresta;
}
void Aresta::setVertices() {
  delete(this->vertices);
  this->vertices = new Vertice[this->quantVertices];
}
void Aresta::novaVertice(int peso, int arestaDestino) {
  this->vertices[this->atualVertice].setArestaAtual(this->nomeAresta);
  this->vertices[this->atualVertice].setArestaDestino(arestaDestino);
  this->vertices[this->atualVertice].setPeso(peso);
  this->atualVertice++;
}
Vertice* Aresta::getVertices() {
  return this->vertices;
}