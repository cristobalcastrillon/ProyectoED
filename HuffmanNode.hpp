#include <iostream>

struct HuffmanNode{
        char caracter;
        int frecuencia;
        HuffmanNode * leftChild;
        HuffmanNode * rightChild;

        HuffmanNode(){
            caracter = NULL;
            frecuencia = NULL;
            leftChild = rightChild = NULL;
        }
        
        HuffmanNode(char c, int f){
            caracter = c;
            frecuencia = f;
            leftChild = rightChild = NULL;
        }

        HuffmanNode(int f){
            caracter = NULL;
            frecuencia = f;
            leftChild = rightChild = NULL;
        }
};