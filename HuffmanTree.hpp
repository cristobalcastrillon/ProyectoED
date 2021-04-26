#include "HuffmanNode.hpp"
#include <iostream>
#include <vector>

bool sortbysec(const std::pair<char, int> &a, const std::pair<char, int> &b){
    return (a.second > b.second);
}

struct HuffmanTree{
        HuffmanNode * root;
        std::vector<std::pair<char, int> > histogramaCaracteres;

        HuffmanTree(std::vector<std::pair <char, int> > histoCars){
            std::vector<std::pair<char, int> > histoCopy = histoCars;
            while(histoCopy.size() > 1){
                HuffmanNode * a = new HuffmanNode(histoCopy.at(histoCopy.size()-1).first, histoCopy.at(histoCopy.size()-1).second);
                //La siguiente línea es de prueba...
                std::cout << a->caracter << '\t' << a->frecuencia << std::endl;

                HuffmanNode * b = new HuffmanNode(histoCopy.at(histoCopy.size()-2).first, histoCopy.at(histoCopy.size()-2).second);
                //La siguiente línea es de prueba...
                std::cout << b->caracter << '\t' << b->frecuencia << std::endl;

                HuffmanNode * nuevo;
                insertarParNodos(a, b, nuevo);
                //TODO: Arreglar función insertar (NO inserta en el árbol hasta el momento)
                //La siguiente línea es de prueba...
                std::cout << "Insertó a y b." << std::endl;

                std::pair<char, int> nuevoNodoHistograma;
                nuevoNodoHistograma.first = NULL;
                nuevoNodoHistograma.second = histoCopy.at(histoCopy.size()-1).second + histoCopy.at(histoCopy.size()-2).second;
                for(int i = 0 ; i < 2; i++)
                    histoCopy.pop_back();
                histoCopy.push_back(nuevoNodoHistograma);
                std::sort(histoCopy.begin(), histoCopy.end(), sortbysec);
            }
        }

        HuffmanNode * insertarParNodos(HuffmanNode * a, HuffmanNode * b, HuffmanNode * root){
            root->leftChild  = a;
            root->rightChild = b;
            root->frecuencia = a->frecuencia + b->frecuencia;
            root->caracter = NULL;
            return root;
        }

        void inorder(HuffmanNode * nodo){
        if(nodo == NULL)
            return;
        inorder(nodo->leftChild);
        std::cout << nodo->frecuencia << '\t';
        inorder(nodo->rightChild);
    }
};