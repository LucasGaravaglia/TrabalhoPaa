#ifndef PILHA_H 
#define PILHA_H 

#include "no.h"


class pilha {
private:
  No* top;
public:
  pilha();
  ~pilha();
  bool isEmpty();
  void push(int item);
  int pop();
};

#endif
