#ifndef VERTICE_H
#define VERTICE_H

class Vertice {
private:
  int peso;
  int arestaAtual;
  int arestaDestino;
public:
  Vertice(int peso, int arestaAtual, int arestaDestino);
  Vertice();
  ~Vertice();
  void setPeso(int peso);
  int getPeso();
  void setArestaAtual(int atual);
  int getArestaAtual();
  void setArestaDestino(int destino);
  int getArestaDestino();
};

#endif