#include <iostream>
#include <new>
#include "fila.h"

using namespace std;

fila::fila() {
  this->first = NULL;
  this->last = NULL;
}

fila::~fila() {
  No* temp;
  while (this->first != NULL) {
    temp = this->first;
    this->first = this->first->next;
    delete temp;
  }
  this->last = NULL;
}

bool fila::isEmpty() {
  return this->first == NULL;
}

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

void fila::show() {
  No* temp = this->first;
  cout << "Fila= [ ";
  while (temp != NULL) {
    cout << temp->value << " ";
    temp = temp->next;
  }
  cout << "]\n";
}