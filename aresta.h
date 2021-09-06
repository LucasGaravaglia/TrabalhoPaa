#ifndef ARESTA_H
#define ARESTA_H

/**
 * Classe responsável por armazenar os dados das arestas
 */
class Aresta {
private:
  int peso;//Atributo que armazena o peso de cada vértice.
  int verticeAtual;//Atributo que armazena o nome da vertice a quem pertence.
  int verticeDestino;//Atributo que armazena o nome da vertice de destino
public:
  //Construtor da classe
  Aresta();
  //Construtor da classe sobrecarregado para receber os dados
  Aresta(int peso, int verticeAtual, int verticeDestino);
  //Destrutor da classe
  ~Aresta();
  //Setter do atributo Peso
  void setPeso(int peso);
  //Setter do atributo Vertice atual
  void setVerticeAtual(int atual);
  //Setter do atributo Vertice destino
  void setVerticeDestino(int destino);
  //Getter do atributo Peso
  int getPeso();
  //Getter do atributo Vertice atual
  int getVerticeAtual();
  //Getter do atributo Vertice destino
  int getVerticeDestino();
};

#endif