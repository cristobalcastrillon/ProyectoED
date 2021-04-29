#include "HuffmanNode.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

struct comp
{
    bool operator()(const HuffmanNode *a, const HuffmanNode *b)
    {
        return (a->frecuencia >= b->frecuencia);
    }
};

struct HuffmanTree
{
    std::priority_queue<HuffmanNode *, std::vector<HuffmanNode *>, comp> histoCopy;
    std::unordered_map<char, std::string> huffmanCode;

    HuffmanTree() {}

    HuffmanTree(std::vector<std::pair<char, int>> histoCars)
    {
        //Copiando los pares caracter - frecuencia del histograma...
        for (int i = 0; i < histoCars.size(); i++)
        {
            HuffmanNode *huffPtr = new HuffmanNode(histoCars.at(i).first, histoCars.at(i).second);
            histoCopy.push(huffPtr);
        }

        //Creando el árbol (min heap)...
        while (histoCopy.size() != 1)
        {
            HuffmanNode *left = histoCopy.top();
            histoCopy.pop();
            HuffmanNode *right = histoCopy.top();
            histoCopy.pop();
            int sum = left->frecuencia + right->frecuencia;

            histoCopy.push(getNode('\0', sum, left, right));
        }

        HuffmanNode *root = histoCopy.top();

        codificar(root, "", this->huffmanCode);
    }

    HuffmanNode *getNode(char ch, int freq, HuffmanNode *left, HuffmanNode *right)
    {
        HuffmanNode *node = new HuffmanNode();

        node->caracter = ch;
        node->frecuencia = freq;
        node->leftChild = left;
        node->rightChild = right;

        return node;
    }

    void codificar(HuffmanNode *root, std::string str, std::unordered_map<char, std::string> &huffmanCode)
    {
        if (!root)
        {
            return;
        }

        if (root->leftChild == NULL && root->rightChild == NULL)
        {
            huffmanCode[root->caracter] = str;
            //La siguiente línea es de prueba...
            //std::cout << root->caracter << '\t' << str << std::endl;
        }

        codificar(root->leftChild, str + "0", huffmanCode);
        codificar(root->rightChild, str + "1", huffmanCode);
    }
/*
    std::string decode(HuffmanNode *root, int &index, std::string str)
    {
        std::string retorno;
        if (root == nullptr)
        {
            return;
        }

        // found a leaf node
        if (!root->leftChild && !root->rightChild)
        {
            retorno= retorno + root->caracter;
            return;
        }

        index++;

        if (str[index] == '0')
            decode(root->leftChild, index, str);
        else
            decode(root->rightChild, index, str);
    }*/
};