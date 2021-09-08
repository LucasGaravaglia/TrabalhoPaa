#include <iostream>
#include "grafo.h"
#include "vertice.h"
#include "aresta.h"
#include "arquivo.h"
#include <new>



int main() {
  Arquivo* arq = new Arquivo();
  Grafo* grafo;
  int entrada, loop = 1,vertice;
  string path = "entrada.txt";
  cout << "Digite o nome do arquivo local para ler\nExemplo 'entrada.txt.'\n";
  fflush(stdin);
  cin >> path;
  try {
    grafo = arq->lerGrafo(path);
  }catch (exception e) {
    cout << "Erro ao ler o arquivo e criar o grafo.\n";
  }
  while (loop) {
    cout << "Selecione uma opção digitando o numero:" << endl;
    cout << "(1) Busca em profundidade" << endl;
    cout << "(2) Busca em Largura" << endl;
    cout << "(3) Bellman-Ford" << endl;
    cout << "(4) Kruskal" << endl;
    cout << "(5) Sair do programa" << endl;
    fflush(stdin);
    cin >> entrada;
    switch (entrada) {
    case 1:
      cout << "Digite a vertice de origem:\n";
      try {
        fflush(stdin);
        cin >> vertice;
        cout << "Busca em Profundidade:\n";
        grafo->buscaProfundidade(vertice);
        cout << "\n";
      }catch (exception e) {
        cout << "Erro ao fazer a busca.\n";
      }
      cout << "Digite continuar para continuar:";
      fflush(stdin);
      cin >> path;
      break;
    case 2:
      cout << "Digite a vertice de origem:\n";
      try {
        fflush(stdin);
        cin >> vertice;
        cout << "Busca em Largura:\n";
        grafo->buscaLargura(vertice);
        cout << "\n";
      }catch (exception e) {
        cout << "Erro ao fazer a busca.\n";
      }
      cout << "Digite continuar para continuar:";
      fflush(stdin);
      cin >> path;
      break;
    case 3:
      cout << "Digite a vertice de origem:\n";
      try {
        fflush(stdin);
        cin >> vertice;
        cout << "Bellman-Ford:\n";
        grafo->bellmanFord(vertice);
        cout << "\n";
      }catch (exception e) {
        cout << "Erro ao calcular menor caminho com bellman-ford.\n";
      }
      cout << "Digite continuar para continuar:";
      fflush(stdin);
      cin >> path;
      break;
    case 4:
      try {
        cout << "Kruskal:\n";
        grafo->kruskal();
        cout << "\n";
      }catch (exception e) {
        cout << "Erro ao gerar arvore geradora.\n";
      }
      cout << "Digite continuar para continuar:";
      fflush(stdin);
      cin >> path;
      break;
    case 5:
      loop = 0;
      break;
    default:
      cout << "Opção invalida, digite continuar e tente novamente:";
      fflush(stdin);
      cin >> path;
      break;
    }
  }


  return 0;
}
