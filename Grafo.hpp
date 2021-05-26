#include <vector>
#include "NodoGrafo.hpp"

//Grafo NO DIRIGIDO
struct Grafo{
    //Cantidad de vértices/nodos
    int V;
    //Lista de Adyacencia
    std::vector<NodoGrafo> * listaAdy;

    Grafo();
    Grafo(int nV);
    void insertarArista(char a, char b);
};

Grafo::Grafo(){
    V = 0;
    listaAdy = NULL;
}

Grafo::Grafo(int nV){
    V = nV;
    listaAdy = new std::vector<NodoGrafo>[V];
}

void Grafo::insertarArista(char a, char b){
    //Método para añadir una arista entre el caracter 'a' y el caracter 'b'.
    NodoGrafo aNode(a);
    NodoGrafo bNode(b);
    listaAdy[a].push_back(bNode);
    listaAdy[b].push_back(aNode);
}