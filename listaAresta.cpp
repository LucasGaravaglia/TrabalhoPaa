#include <iostream>
#include <new>
#include "listaAresta.h"

using namespace std;
//Construtor da fila
listaAresta::listaAresta() {
  this->first = NULL;
}
//Destrutor da fila
listaAresta::~listaAresta() {
  NoAresta* temp;
  while (this->first != NULL) {
    temp = this->first;
    this->first = this->first->next;
    delete temp;
  }
}
//Método que retorna verdadeiro se tem algo no No first ou false caso contrario
bool listaAresta::isEmpty() {
  return this->first == NULL;
}
//Método que enfileira um item na fila
void listaAresta::queue(Aresta item) {
  NoAresta* newNo = new NoAresta();
  newNo->value.setPeso(item.getPeso());
  newNo->value.setVerticeAtual(item.getVerticeAtual());
  newNo->value.setVerticeDestino(item.getVerticeDestino());
  newNo->next = NULL;
  
  if (this->first == NULL) {
    this->first = newNo;
  }
  else {
    this->first = this->auxQueue(newNo,this->first);
  }
}
NoAresta* listaAresta::auxQueue(NoAresta* newNo, NoAresta* lista) {
  if (lista == NULL) {
    return newNo;
  }
  if (newNo->value.getPeso() < lista->value.getPeso()) {
    newNo->next = lista;
    return newNo;
  }
  lista->next = this->auxQueue(newNo, lista->next);
  return lista;

}
//Método que desinfileira um item da fila
int listaAresta::dequeue() {
  if (isEmpty()) {
    cout << "A fila esta vazia!\n";
    cout << "Nao tem elemento a ser removido!\n";
    return -1;
  }
  else {
    NoAresta* temp = this->first;
    int item = this->first->value.getPeso();
    this->first = this->first->next;
    delete temp;
    return item;
  }
}
//Método que mostra a primeira posição da fila.
Aresta listaAresta::show() {
  return this->first->value;
}