#include "aresta.h"
#include <new>
#include <iostream>

using namespace std;

Aresta::Aresta(int peso, int verticeAtual, int verticeDestino) {
  this->peso = peso;
  this->verticeAtual = verticeAtual;
  this->verticeDestino = verticeDestino;
}
Aresta::Aresta() {
  this->peso = 0;
  this->verticeAtual = 0;
  this->verticeDestino = 0;
}
Aresta::~Aresta() {
}
void Aresta::setPeso(int peso) {
  this->peso = peso;
}
void Aresta::setAresta(Aresta other) {
  this->peso = other.getPeso();
  this->verticeAtual = other.getVerticeAtual();
  this->verticeDestino = other.getVerticeDestino();
}
int Aresta::getPeso() {
  return this->peso;
}
void Aresta::setVerticeAtual(int atual) {
  this->verticeAtual = atual;
}
int Aresta::getVerticeAtual() {
  return this->verticeAtual;
}
void Aresta::setVerticeDestino(int destino) {
  this->verticeDestino = destino;
}
int Aresta::getVerticeDestino() {
  return this->verticeDestino;
}