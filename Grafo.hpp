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
    void shortestPath(NodoGrafo s, NodoGrafo e){
        // Create set to store vertices
        // Use this to extract the shortest path
        set<pair<int, int>> extract_set;

        // Vector for distances
        // All paths are initialized to a large value
        vector<int> distances(V, INF);

        // Insert the entry point into the set
        // Initialize distance to 0
        extract_set.insert(make_pair(0, s));
        distances[s] = 0;

        // Continue until all shortest distances are finalized
        while(!extract_set.empty()){
            // Extract the minimum distances
            pair<int, int> tmp = *(extract_set.begin());
            extract_set.erase(extract_set.begin());

            // Get the vertex number
            int u = tmp.second;

            // Go over the adjacency list
            for(auto i = adj[u].begin(); i != adj[u].end(); i++){
                // Get the vertex and weight
                int v = (*i).first;
                int weight = (*i).second;

                // Check if we have found a shorter path to v
                if(distances[v] > distances[u] + weight){

                    // Remove the current distance if it is in the set
                    if(distances[v] != INF){
                        extract_set.erase(extract_set.find(make_pair(distances[v], v)));
                    }
                
                    // Update the distance
                    distances[v] = distances[u] + weight;
                    extract_set.insert(make_pair(distances[v], v));
                }
            }
        }

        std::cout << "Minimum distances from vertex: " << s << std::endl;
        for(int i = 0; i < V; i++){
            std::cout << "Vertex: " << i << "\tDistance: " << distances[i] << std::endl;
        }

    }
};

