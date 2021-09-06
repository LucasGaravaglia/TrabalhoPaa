#include <iostream>
#include "grafo.h"
#include "vertice.h"
#include "aresta.h"
#include "arquivo.h"
#include <stdlib.h>
#include <new>



int main() {
  Arquivo* arq = new Arquivo();
  Grafo* grafo;
  int entrada, loop = 1,vertice;
  string path = "entrada.txt";
  while (loop) {
    system("clear");
    cout << "Selecione uma opção digitando o numero:" << endl;
    cout << "(0) Ler arquivo" << endl;
    cout << "(1) Busca em profundidade" << endl;
    cout << "(2) Busca em Largura" << endl;
    cout << "(3) Bellman-Ford" << endl;
    cout << "(4) Kruskal" << endl;
    cout << "(5) Sair do programa" << endl;
    cin >> entrada;
    switch (entrada) {
    case 0:
      system("clear");
      cout << "Digite o nome do arquivo local para ler\nExemplo 'entrada.txt.'\n";
      cin >> path;
      try {
        grafo = arq->lerGrafo(path);
      }catch (exception e) {
        cout << "Erro ao ler o arquivo e criar o grafo.\n";
      }
      break;
    case 1:
      system("clear");
      cout << "Digite a vertice de origem:\n";
      try {
        cin >> vertice;
        system("clear");
        cout << "Busca em Profundidade:\n";
        grafo->buscaProfundidade(vertice);
        cout << "\n";
      }catch (exception e) {
        cout << "Erro ao fazer a busca.\n";
      }
      cout << "Digite continuar para continuar:";
      cin >> path;
      break;
    case 2:
      system("clear");
      cout << "Digite a vertice de origem:\n";
      try {
        cin >> vertice;
        system("clear");
        cout << "Busca em Largura:\n";
        grafo->buscaLargura(vertice);
        cout << "\n";
      }catch (exception e) {
        cout << "Erro ao fazer a busca.\n";
      }
      cout << "Digite continuar para continuar:";
      cin >> path;
      break;
    case 3:
      system("clear");
      cout << "Digite a vertice de origem:\n";
      try {
        cin >> vertice;
        system("clear");
        cout << "Bellman-Ford:\n";
        grafo->bellmanFord(vertice);
        cout << "\n";
      }catch (exception e) {
        cout << "Erro ao calcular menor caminho com bellman-ford.\n";
      }
      cout << "Digite continuar para continuar:";
      cin >> path;
      break;
    case 4:
      system("clear");
      try {
        cout << "Kruskal:\n";
        grafo->kruskal();
        cout << "\n";
      }catch (exception e) {
        cout << "Erro ao gerar arvore geradora.\n";
      }
      cout << "Digite continuar para continuar:";
      cin >> path;
      break;
    case 5:
      loop = 0;
      break;
    default:
      system("clear");
      cout << "Opção invalida, digite continuar e tente novamente:";
      cin >> path;
      break;
    }
  }


  return 0;
}
