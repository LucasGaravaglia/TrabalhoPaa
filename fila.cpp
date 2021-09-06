#include <iostream>
#include <new>
#include "fila.h"

using namespace std;
//Construtor da fila
fila::fila() {
  this->first = NULL;
  this->last = NULL;
}
//Destrutor da fila
fila::~fila() {
  No* temp;
  while (this->first != NULL) {
    temp = this->first;
    this->first = this->first->next;
    delete temp;
  }
  this->last = NULL;
}
//Método que retorna verdadeiro se tem algo no No first ou false caso contrario
bool fila::isEmpty() {
  return this->first == NULL;
}
//Método que enfileira um item na fila
void fila::queue(int item) {
  No* newNo = new No;
  newNo->value = item;
  newNo->next = NULL;
  if (this->first == NULL) {
    this->first = newNo;
  }
  else {
    this->last->next = newNo;
  }
  this->last = newNo;
}
//Método que desinfileira um item da fila
int fila::dequeue() {
  if (isEmpty()) {
    cout << "A fila esta vazia!\n";
    cout << "Nao tem elemento a ser removido!\n";
    return -1;
  }
  else {
    No* temp = this->first;
    int item = this->first->value;
    this->first = this->first->next;
    if (this->first == NULL) {
      this->last = NULL;
    }
    delete temp;
    return item;
  }
}
//Método que mostra a primeira posição da fila.
int fila::show() {
  return this->first->value;
}