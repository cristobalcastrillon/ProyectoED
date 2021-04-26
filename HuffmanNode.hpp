#include <iostream>

struct HuffmanNode{
        char caracter;
        int frecuencia;
        HuffmanNode * leftChild;
        HuffmanNode * rightChild;

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