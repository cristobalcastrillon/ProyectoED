#ifndef ArchivoFASTA_hpp
#define ArchivoFASTA_hpp

#include <iostream>
#include <fstream>
#include <string.h>
#include <bitset>
#include <algorithm>
#include "HuffmanTree.hpp"
#include "Secuencia.hpp"

struct ArchivoFASTA {
    private:
    //Clase que guarda las subcadenas que componen el archivo (líneas descriptivas; secuencias).
    std::vector<std::string> lineasDescriptivas;
    std::vector<Secuencia> secLista;
    
    public:
    ArchivoFASTA();
    std::string getLineaDescriptiva(int posicionLD);
    void setLineaDescriptiva(std::string lineasDescriptivas);
    std::string getSecuencia(int posicionS);
    void setSecuencia(std::string cadenaSecuencia);

    //Comandos requeridos en el enunciado del proyecto:
    //Primera entrega:
    bool cargarArchivo(std::string nombreArchivo);
    void conteoBasesXSecuencia();
    int conteoSecuencias();
    void histograma(std::string descripcionSecuencia);
    void listarSecuencias();
    void subsecuencia(std::string subseq);
    void enmascarar(std::string secuencia);
    bool guardar(std::string nombreArchivo);
    void ayuda();

    //Segunda entrega:
    bool codificar(std::string nombreArchivoFABin); //Codificación de Huffman
    bool decodificar(std::string nombreArchivoFABin); //Decodificación de Huffman

};

#endif /* ArchivoFASTA_hpp */