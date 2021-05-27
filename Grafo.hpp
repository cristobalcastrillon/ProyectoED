#include <vector>
#include <map>
#include "NodoGrafo.hpp"

//Grafo NO DIRIGIDO

struct Grafo{
    //Cantidad de vértices/nodos
    int V;
    //Lista de Adyacencia
    std::map<std::pair<int,int>,std::vector<NodoGrafo>> listaAdy;

    Grafo();
    Grafo(int nV);
    void insertarArista(std::pair<int,int> u , char a,std::pair<int,int> v, char b);
};

Grafo::Grafo(){
    V = 0;
}

Grafo::Grafo(int nV){
    V = nV;
}

void Grafo::insertarArista(std::pair<int,int> u , char a,std::pair<int,int> v, char b){
    //Método para añadir una arista entre el caracter 'a' y el caracter 'b'.
    NodoGrafo aNode(u,a);
    NodoGrafo bNode(v,b);
    listaAdy[aNode.key].push_back(bNode);
}