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
        std::priority_queue<HuffmanNode*, std::vector<HuffmanNode *>, comp> histoCopy;

        HuffmanTree(std::vector<std::pair <char, int> > histoCars){
            //Copiando los pares caracter - frecuencia del histograma...
            for(int i = 0; i < histoCars.size(); i++){
                HuffmanNode * huffPtr = new HuffmanNode(histoCars.at(i).first, histoCars.at(i).second);
                histoCopy.push(huffPtr);
            }
 
            while(histoCopy.size() > 1){
                std::cout << "Entró al while" << std::endl;
                HuffmanNode * a = histoCopy.top();
                histoCopy.pop();
                //La siguiente línea es de prueba...
                std::cout << a->caracter << '\t' << a->frecuencia << std::endl;

                HuffmanNode * b = histoCopy.top();
                histoCopy.pop();
                //La siguiente línea es de prueba...
                std::cout << b->caracter << '\t' << b->frecuencia << std::endl;

                HuffmanNode * pater;
                pater->leftChild = a;
                pater->rightChild = b;
                pater->frecuencia = a->frecuencia + b->frecuencia;
                pater->caracter = '\0';

                histoCopy.push(pater);
            }

            HuffmanNode * root = histoCopy.top();
        }


};