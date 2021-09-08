#ifndef LISTAARESTA_H 
#define LISTAARESTA_H 

#include "aresta.h"

struct NoAresta {
  Aresta value;
  NoAresta* next;
};

class listaAresta {
private:
  NoAresta* first;
public:
  //Construtor da fila
  listaAresta();
  //Destrutor da fila
  ~listaAresta();
  //Método que retorna verdadeiro se tem algo no No first ou false caso contrario 
  bool isEmpty();
  //Método que enfileira um item na fila
  void queue(Aresta item);
  //Método que desinfileira um item da fila
  int dequeue();
  //Método que mostra a primeira posição da fila.
  Aresta show();
  NoAresta* auxQueue(NoAresta* newNo,NoAresta* lista);

};

#endif
