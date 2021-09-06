#ifndef FILA_H 
#define FILA_H 


//Struct para os nós da fila
struct No {
  int value;
  No* next;
};

class fila {
private:
  No* first;
  No* last;
public:
  //Construtor da fila
  fila();
  //Destrutor da fila
  ~fila();
  //Método que retorna verdadeiro se tem algo no No first ou false caso contrario 
  bool isEmpty();
  //Método que enfileira um item na fila
  void queue(int item);
  //Método que desinfileira um item da fila
  int dequeue();
  //Método que mostra a primeira posição da fila.
  int show();

};

#endif
