#include "HuffmanNode.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

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

            //Creando el árbol (heap)...
            while(histoCopy.size() > 1){
                HuffmanNode * a = histoCopy.top();
                histoCopy.pop();

                HuffmanNode * b = histoCopy.top();
                histoCopy.pop();

                HuffmanNode * pater;
                pater->leftChild = a;
                pater->rightChild = b;
                pater->frecuencia = a->frecuencia + b->frecuencia;
                pater->caracter = '\0';

                histoCopy.push(pater);
            }

            HuffmanNode * root = histoCopy.top();
            std::unordered_map<char, std::string> huffmanCode;
            //TODO: Averiguar por qué no llega a las hojas con 'codificar'
            this->codificar(root, "", huffmanCode);

            for(int i = 0; i < histoCars.size(); i++){
                std::cout << huffmanCode.at(histoCars.at(i).first) << std::endl;
            }
        }

        void codificar(HuffmanNode* root, std::string str, std::unordered_map<char, std::string> &huffmanCode){
            if (!root){
                std::cout << "Retornó en nullptr" << std::endl;
                return;
            }

            if (!root->leftChild && !root->rightChild) {
                std::cout << "Retornó en hoja" << std::endl;
                huffmanCode.at(root->caracter) = str;
            }

            std::cout << "Entró" << std::endl;

            codificar(root->leftChild, str + "0", huffmanCode);
            codificar(root->rightChild, str + "1", huffmanCode);
        }
};