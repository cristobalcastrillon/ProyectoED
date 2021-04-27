#include "HuffmanNode.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

struct comp{
    bool operator()(const HuffmanNode * a, const HuffmanNode * b){
        return (a->frecuencia >= b->frecuencia);
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

            //Creando el árbol (min heap)...
            while(histoCopy.size() > 1){
                imprimirQueue(histoCopy);

                HuffmanNode * pater;
                pater->leftChild = histoCopy.top();
                histoCopy.pop();
                pater->rightChild = histoCopy.top();
                histoCopy.pop();
                pater->frecuencia = (pater->leftChild->frecuencia + pater->rightChild->frecuencia);
                pater->caracter = '\0';

                // std::cout << "Left: " << pater->leftChild->caracter << ' ' << pater->leftChild->frecuencia << '\t';
                // std::cout << "Right: " << pater->rightChild->caracter << ' ' << pater->rightChild->frecuencia << '\t';
                // std::cout << "Pater: " << pater->caracter << ' ' << pater->frecuencia << std::endl;

                histoCopy.push(pater);
            }

            HuffmanNode * root = histoCopy.top();
            //La siguiente línea es de prueba...
            //preorder(root);

            std::unordered_map<char, std::string> huffmanCode;
            //TODO: Averiguar por qué no llega a las hojas con 'codificar'
            //this->codificar(root, "", huffmanCode);

            // for(int i = 0; i < histoCars.size(); i++){
            //     std::cout << huffmanCode.at(histoCars.at(i).first) << std::endl;
            // }
        }

        void imprimirQueue(std::priority_queue<HuffmanNode*, std::vector<HuffmanNode *>, comp> histoCopy){
            while(histoCopy.size()>0){
                std::cout << histoCopy.top()->frecuencia << ' ';
                histoCopy.pop();
            }
            std::cout << '\n';
        }

        void codificar(HuffmanNode* root, std::string str, std::unordered_map<char, std::string> &huffmanCode){
            if (!root){
                std::cout << "Retornó en nullptr" << std::endl;
                return;
            }

            if (root->leftChild == NULL && root->rightChild == NULL){
                std::cout << "Retornó en hoja" << std::endl;
                huffmanCode.at(root->caracter) = str;
            }

            std::cout << "Entró" << std::endl;

            codificar(root->leftChild, str + "0", huffmanCode);
            codificar(root->rightChild, str + "1", huffmanCode);
        }

        void preorder(HuffmanNode * nodo){
            if(nodo == NULL)
                return;
            std::cout << nodo->caracter << '\t' << nodo->frecuencia << std::endl;
            preorder(nodo->leftChild);
            preorder(nodo->rightChild);
        }
};