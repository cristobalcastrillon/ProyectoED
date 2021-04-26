#include "HuffmanNode.hpp"
#include <iostream>
#include <vector>
#include <queue>

bool sortbysec(const std::pair<char, int> &a, const std::pair<char, int> &b){
    return (a.second > b.second);
}

struct comp{
    bool operator()(const HuffmanNode * a, const HuffmanNode * b){
        return (a->frecuencia > b->frecuencia);
    }
};

struct HuffmanTree{
        HuffmanNode * root;
        std::priority_queue<HuffmanNode*, std::vector<HuffmanNode *>, comp> histoCopy;

        HuffmanTree(std::vector<std::pair <char, int> > histoCars){
            //Copiando los pares caracter - frecuencia del histograma...
            for(int i = 0; i < histoCars.size(); i++){
                HuffmanNode * huffPtr = new HuffmanNode(histoCars.at(i).first, histoCars.at(i).second);
                histoCopy.push(huffPtr);
                //La siguiente línea es de prueba...
                std::cout << histoCopy.top()->caracter << '\t' << histoCopy.top()->frecuencia;
            }
 
            while(histoCopy.size() > 1){
                HuffmanNode * a = histoCopy.top();
                histoCopy.pop();
                //La siguiente línea es de prueba...
                // std::cout << a->caracter << ':\t' << a->frecuencia << std::endl;

                HuffmanNode * b = histoCopy.top();
                histoCopy.pop();
                //La siguiente línea es de prueba...
                // std::cout << b->caracter << ':\t' << b->frecuencia << std::endl;

                HuffmanNode * nuevo = insertarParNodos(a, b);
                //La siguiente línea es de prueba...
                std::cout << "Insertó a y b." << std::endl;

                histoCopy.push(nuevo);
            }
        }

        HuffmanNode * insertarParNodos(HuffmanNode * a, HuffmanNode * b){
            HuffmanNode * temp;
            temp->leftChild  = a;
            temp->rightChild = b;
            temp->frecuencia = a->frecuencia + b->frecuencia;
            temp->caracter = NULL;
            return temp;
        }

        void inorder(HuffmanNode * nodo){
            if(nodo == NULL)
                return;
            inorder(nodo->leftChild);
            std::cout << nodo->frecuencia << '\t';
            inorder(nodo->rightChild);
        }
};