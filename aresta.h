#ifndef ARESTA_H
#define ARESTA_H

class Aresta {
private:
  int peso;
  int verticeAtual;
  int verticeDestino;
public:
  Aresta(int peso, int verticeAtual, int verticeDestino);
  Aresta();
  ~Aresta();
  void setAresta(Aresta other);
  void setPeso(int peso);
  int getPeso();
  void setVerticeAtual(int atual);
  int getVerticeAtual();
  void setVerticeDestino(int destino);
  int getVerticeDestino();
};

#endif