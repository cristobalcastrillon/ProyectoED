#include <vector>
#include <set>
#include "NodoGrafo.hpp"

//Grafo NO DIRIGIDO
struct Grafo{

    //Cantidad de vértices/nodos
    int V;

    //Lista de nodos/vértices
    std::vector<NodoGrafo> * listaNodos;

    Grafo(){
        V = 0;
        listaNodos = NULL;
    }

    Grafo(int nV){
        V = nV;
        listaNodos = new std::vector<NodoGrafo>[V];
    }

    //Dijkstra's algorithm for finding the shortest path to every other vertex given a source node (s) in a graph
    // void dijsktra(int s){
    //     //Shortest path will be inserted in the following set:
    //     set<pair<int, int> > extracted;

    //     //Vector of distances
    //     vector<int> distances(V, INF);

    //     //Distance from source vector to itself = 0
    //     extracted.insert(make_pair(s, 0));
    //     distances[s] = 0;


    //     while(!extracted.empty()){
    //         pair<int, int> temp = *(extracted.begin());
    //         extracted.erase(extracted.begin());

    //         //Vertex key
    //         int u = temp.second;

    //         for(auto it = listaNodos[u].begin(); it != listaNodos[u].end(); it++){
    //             //v: adjacent vertex 'key'
    //             int v = it->first;
    //             int weight = it->second;

    //             if(distances[v] > distances[u] + weight){

    //                 if(distances[v] != INF){
    //                     extracted.erase(extracted.find(make_pair(distances[v], v)));
    //                 }

    //                 distances[v] = distances[u] + weight;
    //                 extracted.insert(make_pair(distances[v], v));
    //             }
    //         }
    //     }

    //     cout << "Distancias mínimas desde el vértice " << s << ':' << endl;
    //     for(int i = 0; i < V; i++){
    //         cout << "Vértice " << i << "\tDistancia " << distances[i] << endl;
    //     }

    // }
};

