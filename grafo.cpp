#include "grafo.h"
#include "vertice.h"
#include "aresta.h"
#include <new>

Grafo::Grafo(int quantArestas, bool orientado, Aresta* arestas) {
  this->quantArestas = quantArestas;
  this->orientado = orientado;
  this->arestas = new Aresta[quantArestas];
  this->atualAresta = 0;
}
Grafo::~Grafo() {
  this->quantArestas = 0;
  this->orientado = false;
}
void Grafo::setAresta(Aresta aresta) {
  this->arestas[this->atualAresta] = aresta;
}
Aresta Grafo::getAresta(int pos) {
  if (pos < quantArestas)
    return this->arestas[pos];
  return;
}
void Grafo::setQuantArestas(int quantArestas) {
  this->quantArestas = quantArestas;
}
int Grafo::getQuantArestas() {
  return this->quantArestas;
}
void Grafo::setOrientado(bool orientado) {
  this->orientado = orientado;
}
bool Grafo::getOrientado() {
  return this->orientado;
}
void Grafo::buscaLargura(int origem) {

}
void Grafo::buscaProfundidade(int origem) {

}
void Grafo::bellmanFord(int origem) {

}
void Grafo::kruskal() {

}