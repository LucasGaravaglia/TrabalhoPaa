#ifndef FILA_H 
#define FILA_H 

#include "no.h"


class fila {

private:
  No* first;
  No* last;
public:
  fila();
  ~fila();
  bool isEmpty();
  void queue(int item);
  int dequeue();
  void show();

};

#endif
