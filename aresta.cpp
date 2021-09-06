#include "aresta.h"
#include <new>
#include <iostream>

using namespace std;
  //Construtor da classe sobrecarregado para receber os dados
Aresta::Aresta(int peso, int verticeAtual, int verticeDestino) {
  this->peso = peso;
  this->verticeAtual = verticeAtual;
  this->verticeDestino = verticeDestino;
}
//Construtor da classe
Aresta::Aresta() {
  this->peso = 0;
  this->verticeAtual = 0;
  this->verticeDestino = 0;
}
//Destrutor da classe
Aresta::~Aresta() {
}
//Setter do atributo Peso
void Aresta::setPeso(int peso) {
  this->peso = peso;
}
//Getter do atributo Peso
int Aresta::getPeso() {
  return this->peso;
}
//Setter do atributo Vertice atual
void Aresta::setVerticeAtual(int atual) {
  this->verticeAtual = atual;
}
//Getter do atributo Vertice atual
int Aresta::getVerticeAtual() {
  return this->verticeAtual;
}
//Setter do atributo Vertice destino
void Aresta::setVerticeDestino(int destino) {
  this->verticeDestino = destino;
}
//Getter do atributo Vertice destino
int Aresta::getVerticeDestino() {
  return this->verticeDestino;
}