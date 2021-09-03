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

  /* Método que escreve o cabeçalho no arquivo binário de árvore
   * Entrada:      Cabeçalho de árvore
   * Retorno:      Nenhum
   * Pré-condição: A variavel nomeSaida deve possuir o nome correto do arquivo de saida
   * Pós-condição: O cabeçalho é escrito no arquivo binário de árvore
  */
  Grafo* lerGrafo(string path);

  //Destrutor da class Arquivo
  ~Arquivo();
};

#endif