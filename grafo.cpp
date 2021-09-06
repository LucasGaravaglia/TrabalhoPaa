#include "grafo.h"
#include "vertice.h"
#include "aresta.h"
#include <new>
#include <iostream>

using namespace std;

#define nil -1
#define inf INT32_MAX
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
void Grafo::buscaProfundidade(int origem) {
  this->cor = new int[this->quantVertices];
  this->d = new int[this->quantVertices];
  this->f = new int[this->quantVertices];
  this->proc = new int[this->quantVertices];
  for (int i = 0;i < this->quantVertices;i++) {
    this->cor[i] = branco;
    this->proc[i] = nil;
  }
  this->timestamp = 0;
  this->buscaProfundidadeAux(origem);
  delete(this->cor);
  delete(this->d);
  delete(this->f);
}

void Grafo::buscaProfundidadeAux(int atual) {
  cout << atual;
  this->cor[atual] = cinza;
  this->timestamp++;
  this->d[atual] = this->timestamp;
  for (int i = 0;i < this->getVertice(atual)->getQuantArestas();i++) {
    if (cor[this->getVertice(atual)->getArestas()[i].getVerticeDestino()] == branco) {
      cout << " - ";
      this->proc[this->getVertice(atual)->getArestas()[i].getVerticeDestino()] = atual;
      this->buscaProfundidadeAux(this->getVertice(atual)->getArestas()[i].getVerticeDestino());
    }
  }
  this->cor[atual] = preto;
  timestamp++;
  this->f[atual] = timestamp;
}

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
      cout << this->getVertice(this->Fila->show())->getQuantArestas() << " ";
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
  int vertices[this->quantVertices];
  int peso = 0;
  int quantArestas = 0;
  int countQuantArestas = 0;
  //Copia todas as vertices para um vetor auxiliar
  for (int i = 0;i < this->quantVertices;i++) {
    vertices[i] = this->getVertice(i)->getNomeVertice();
    quantArestas += this->getVertice(i)->getQuantArestas();
  }
  Aresta* tempArestas = new Aresta[quantArestas];
  Aresta* arestas = new Aresta[quantVertices];
  //Copia todas as arestas para um vetor auxiliar
  for (int i = 0;i < this->quantVertices;i++) {
    for (int j = 0;j < this->getVertice(i)->getQuantArestas();j++, countQuantArestas++) {
      tempArestas[countQuantArestas].setPeso(this->getVertice(i)->getArestas()[j].getPeso());
      tempArestas[countQuantArestas].setVerticeAtual(this->getVertice(i)->getArestas()[j].getVerticeAtual());
      tempArestas[countQuantArestas].setVerticeDestino(this->getVertice(i)->getArestas()[j].getVerticeDestino());
    }
  }
  countQuantArestas = 0;
  for (int i = 0;i < quantArestas;i++) {
    for (int j = i;j < quantArestas;j++) {
      if (tempArestas[i].getPeso() == tempArestas[j].getPeso() && tempArestas[i].getVerticeAtual() == tempArestas[j].getVerticeDestino()) {
        arestas[countQuantArestas].setPeso(tempArestas[i].getPeso());
        arestas[countQuantArestas].setVerticeAtual(tempArestas[i].getVerticeAtual());
        arestas[countQuantArestas].setVerticeDestino(tempArestas[i].getVerticeDestino());
        countQuantArestas++;
      }
    }
  }
  //ordena todas as arestas
  int menor;
  int pesoTemp;
  Aresta* trocaAresta = new Aresta();
  for (int i = 0;i < countQuantArestas;i++) {
    menor = i;
    pesoTemp = arestas[i].getPeso();
    for (int j = i + 1;j < countQuantArestas;j++) {
      if (pesoTemp > arestas[j].getPeso()) {
        pesoTemp = arestas[j].getPeso();
        menor = j;
      }
    }
    tempArestas[i].setPeso(arestas[menor].getPeso());
    tempArestas[i].setVerticeAtual(arestas[menor].getVerticeAtual());
    tempArestas[i].setVerticeDestino(arestas[menor].getVerticeDestino());
    arestas[menor].setPeso(arestas[i].getPeso());
    arestas[menor].setVerticeAtual(arestas[i].getVerticeAtual());
    arestas[menor].setVerticeDestino(arestas[i].getVerticeDestino());
  }
  arestas[0].setPeso(tempArestas[0].getPeso());
  arestas[0].setVerticeAtual(tempArestas[0].getVerticeAtual());
  arestas[0].setVerticeDestino(tempArestas[0].getVerticeDestino());
  int j = 1;
  for (int i = 1;i < countQuantArestas && j < quantVertices;i++) {
    if (!this->busca(tempArestas[i].getVerticeAtual(), tempArestas[i].getVerticeDestino(), arestas, j)) {
      arestas[j].setPeso(tempArestas[i].getPeso());
      arestas[j].setVerticeAtual(tempArestas[i].getVerticeAtual());
      arestas[j].setVerticeDestino(tempArestas[i].getVerticeDestino());
      j++;
    }
  }
  
  for (int k = 0;k < j;k++) {
    peso += arestas[k].getPeso();
  }
  cout << "peso total: "<< peso << endl <<"arestas: ";
  for (int k = 0;k < j;k++) {
    cout << "(" << arestas[k].getVerticeAtual() << "," << arestas[k].getVerticeDestino() << ") ";
  }
}

bool Grafo::busca(int Vertice1, int Vertice2, Aresta* arestas, int tam) {
  int flag1 = 0;
  for (int i = 0;i < tam;i++) 
    if (Vertice1 == arestas[i].getVerticeAtual() || Vertice1 == arestas[i].getVerticeDestino()){
      flag1++;
      break;
    }
  
  for (int i = 0;i < tam;i++) 
  if (Vertice2 == arestas[i].getVerticeAtual() || Vertice2 == arestas[i].getVerticeDestino()){
    flag1++;
    break;
  }
  int dest;
  if (flag1 == 2) {
    return this->recur(Vertice1, Vertice2, arestas, tam,0);
  }
  return (flag1 == 2);
}

bool Grafo::recur(int Vertice1, int Vertice2, Aresta* arestas, int tam,int flag) {
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
      res = recur(Vertice1, Vertice2, arestas, tam,flag+1) || res;
    }
  }
  return res;
}
