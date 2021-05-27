#include <vector>
#include <set>
#include "NodoGrafo.hpp"
#include <list>

//Grafo NO DIRIGIDO
struct Grafo
{

    //Cantidad de vértices/nodos
    int V;

    //Lista de nodos/vértices
    std::vector<NodoGrafo> *listaNodos;

    Grafo()
    {
        V = 0;
        listaNodos = NULL;
    }

    Grafo(int nV)
    {
        V = nV;
        listaNodos = new std::vector<NodoGrafo>[V];
    }

    //Dijkstra's algorithm for finding the shortest path to every other vertex given a source node (s) in a graph
    void shortestPath(NodoGrafo s, NodoGrafo e)
    {
        std::cout<<"Entra a shortest path"<<std::endl;
        //Marcando todos los nodos como no visitados
        std::vector<NodoGrafo> path;


        for (int i = 0; i < V; i++)
        {
            for (int j = 0; listaNodos[i].size(); j++)
            {
                listaNodos[i].at(j).visited = false;
            }
        }

        std::cout<<"Marca no visitados"<<std::endl;
        //cola para los visitados
        std::list<NodoGrafo> visitados;
        //marcando como visitado el nodo de partida
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; listaNodos[i].size(); j++)
            {
                if (listaNodos[i].at(j).posicionMatriz[0] == s.posicionMatriz[0] && listaNodos[i].at(j).posicionMatriz[1] == s.posicionMatriz[1])
                {
                    listaNodos[i].at(j).visited == true;
                }
            }
        }
        //agregamos le nodo de partida como visitado
        visitados.push_back(s);
        //ciclo que no se sabe que hace o para que sirve
        while (!visitados.empty())
        {
            //sacar las cosas
            NodoGrafo temp = visitados.front();
            
            //verificar que el destino no sea igual al comienzo
            if (!(temp.posicionMatriz[0] == e.posicionMatriz[0] && temp.posicionMatriz[1] == e.posicionMatriz[1]))
            {
                std::cout << "La ruta mas corta entre la base [" << s.posicionMatriz[0] << "," << s.posicionMatriz[1] << "] y la base en [" << e.posicionMatriz[0] << "," << e.posicionMatriz[1] << "] es: ";
                float costoFinal = 0;
                for(int i = 0; i < path.size(); i++)
                {
                    //calculo del costo 
                    //Costo por derecha
                    if(path.at(i).der->posicionMatriz[0] == path.at(i+1).posicionMatriz[1] && path.at(i).der->posicionMatriz[1] == path.at(i+1).posicionMatriz[1] && path.at(i).der->posicionMatriz[1] == path.at(i+1).posicionMatriz[1] && i+1 != path.size())
                    {
                        costoFinal += path.at(i+1).wDer;
                    }
                    //Costo por izquierda
                    if(path.at(i).izq->posicionMatriz[0] == path.at(i+1).posicionMatriz[1] && path.at(i).izq->posicionMatriz[1] == path.at(i+1).posicionMatriz[1] && path.at(i).izq->posicionMatriz[1] == path.at(i+1).posicionMatriz[1] && i+1 != path.size())
                    {
                        costoFinal += path.at(i+1).wIzq;
                    }
                    //Costo por ariba
                    if(path.at(i).sup->posicionMatriz[0] == path.at(i+1).posicionMatriz[1] && path.at(i).sup->posicionMatriz[1] == path.at(i+1).posicionMatriz[1] && path.at(i).sup->posicionMatriz[1] == path.at(i+1).posicionMatriz[1] && i+1 != path.size())
                    {
                        costoFinal += path.at(i+1).wSup;
                    }
                    //Costo por abajo
                    if(path.at(i).inf->posicionMatriz[0] == path.at(i+1).posicionMatriz[1] && path.at(i).inf->posicionMatriz[1] == path.at(i+1).posicionMatriz[1] && path.at(i).inf->posicionMatriz[1] == path.at(i+1).posicionMatriz[1] && i+1 != path.size())
                    {
                        costoFinal += path.at(i+1).wInf;
                    }
                    std::cout << path.at(i).carBase;
                }

                std::cout << "El costo total de la ruta es: " << costoFinal << std::endl;
                
                return;
            }
            //Se saca de los Visitados
            std::cout << "hace pop front de visitados" << std::endl;
            visitados.pop_front();
            
            //Tomar todos los vertices adyacentes
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; listaNodos[i].size(); j++)
                {
                    if(listaNodos[i].at(j).visited == false)
                    {
                        listaNodos[i].at(j).visited = true;
                        visitados.push_back(listaNodos[i].at(j));
                        path.push_back(e);
                    }
                }
            }
        }
    }
};
