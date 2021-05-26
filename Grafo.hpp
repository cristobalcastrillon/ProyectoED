#include <vector>
#include <map>
#include "NodoGrafo.hpp"

//Grafo NO DIRIGIDO
struct adyacencia
{
    NodoGrafo identificar;
    std::vector<NodoGrafo> *lista;
};


struct Grafo{
    //Cantidad de vértices/nodos
    int V;
    //Lista de Adyacencia
    std::map<std::pair<int,int>,NodoGrafo> listaAdy;

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
    //validar que no este garegado ya
    bool bandera=false;
    for(int i=0; i<listaAdy.size();i++)
    {
        if(listaAdy[i].identificar.key==aNode.key)
        {
            listaAdy[i].lista.push_back(bNode);
            bandera=true;
        }
    }
    if(bandera==false)
    {
        adyacencia nuevoElemento;
        nuevoElemento.identificar=aNode;
        nuevoElemento.lista.push_back(bNode);
        listaAdy.push_back(nuevoElemento);
    }
}