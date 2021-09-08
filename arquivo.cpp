#include "arquivo.h"
#include <fstream>
#include <string.h>
#include "grafo.h"
#include "vertice.h"
#include "aresta.h"


//Construtor da classe Arquivo
Arquivo::Arquivo() {
}

/* Método que le o arquivo e retorna um grafo instanciado.
 * Entrada:      Caminho do arquivo.
 * Pré-condição: Caminho de arquivo válido.
*/
Grafo* Arquivo::lerGrafo(string path) {
  Grafo* grafo;
  try {
    string line;
    string temp;
    int dest, atual;
    ifstream f;
    f.open(path, ios::in);
    if (f.is_open()) {
      getline(f, line);
      temp = line.substr(10);
      getline(f, line);
      cout << (temp[0] == 's');
      grafo = new Grafo(stoi(line.substr(2)), (temp[0] == 's'));
      while (!f.eof()) {
        if (line.length() > 0) {
          getline(f, line);
          line = line.substr(1);
          if (line[1] >= 48 && line[1] < 58) {
            atual = stoi(line.substr(0, 2));
            line = line.substr(3);
          }
          else {
            atual = stoi(line.substr(0, 1));
            line = line.substr(2);
          }
          if (line[1] >= 48 && line[1] < 58) {
            dest = stoi(line.substr(0, 2));
            line = line.substr(4);
          }
          else {
            dest = stoi(line.substr(0, 1));
            line = line.substr(3);
          }
          if (grafo->getOrientado()) {
            grafo->getVertice(atual)->novaAresta(stoi(line), dest, atual);
          }
          else {
            grafo->getVertice(atual)->novaAresta(stoi(line), dest, atual);
            grafo->getVertice(dest)->novaAresta(stoi(line), atual, dest);
          }
        }
      }
      f.close();
    }
    else cout << "Erro ao abrir o arquivo" << endl;

  }  
catch (exception e) {
    cout << "Erro ao ler o arquivo" << endl;
  }
  return grafo;
}


//Destrutor da class Arquivo
Arquivo::~Arquivo() {

}