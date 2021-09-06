#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <iostream>
#include <string.h>
#include"grafo.h"
#include <new>

using namespace std;

class Arquivo {
private:
  FILE* entrada;
public:
  //Construtor da classe Arquivo
  Arquivo();

  /* Método que le o arquivo e retorna um grafo instanciado.
   * Entrada:      Caminho do arquivo.
   * Pré-condição: Caminho de arquivo válido.
  */
  Grafo* lerGrafo(string path);

  //Destrutor da class Arquivo
  ~Arquivo();
};

#endif