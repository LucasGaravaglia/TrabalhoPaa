#include <iostream>
#include <new>
#include "pilha.h"

using namespace std;

pilha::pilha() {
  this->top = NULL;
}

pilha::~pilha() {
  No* temp;
  while (this->top != NULL) {
    temp = this->top;
    this->top = this->top->next;
    delete temp;
  }
}

bool pilha::isEmpty() {
  return this->top == NULL;
}

void pilha::push(int item) {
  No* newNo = new No;
  newNo->value = item;
  newNo->next = this->top;
  this->top = newNo;
}


int pilha::pop() {
  if (isEmpty()) {
    cout << "A pilha esta vazia!\n";
    cout << "Nao tem elemento a ser removido!\n";
    return -1;
  }
  No* temp = this->top;
  int item = this->top->value;
  this->top = this->top->next;
  delete temp;
  return item;
}
