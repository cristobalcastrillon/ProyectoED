#include <vector>
#include "NodoGrafo.hpp"

//Grafo NO DIRIGIDO
struct Grafo{

    //Cantidad de vértices/nodos
    int V;

    //Lista de nodos/vértices
    std::vector<NodoGrafo> * listaNodos;

    Grafo();
    Grafo(int nV);
};

Grafo::Grafo(){
    V = 0;
    listaNodos = NULL;
}

Grafo::Grafo(int nV){
    V = nV;
    listaNodos = new std::vector<NodoGrafo>[V];
}