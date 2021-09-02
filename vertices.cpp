#include "vertice.h"
#include <new>
#include <iostream>

using namespace std;

Vertice::Vertice(int peso, int arestaAtual, int arestaDestino) {
  this->peso = peso;
  this->arestaAtual = arestaAtual;
  this->arestaDestino = arestaDestino;
}
Vertice::Vertice() {
  this->peso = 0;
  this->arestaAtual = 0;
  this->arestaDestino = 0;
}

Vertice::~Vertice() {
  cout << "Vertice Destruída." << endl;
}
void Vertice::setPeso(int peso) {
  this->peso = peso;
}
int Vertice::getPeso() {
  return this->peso;
}
void Vertice::setArestaAtual(int atual) {
  this->arestaAtual = arestaAtual;
}
int Vertice::getArestaAtual() {
  return this->arestaAtual;
}
void Vertice::setArestaDestino(int destino) {
  this->arestaDestino = arestaDestino;
}
int Vertice::getArestaDestino() {
  return this->arestaDestino;
}