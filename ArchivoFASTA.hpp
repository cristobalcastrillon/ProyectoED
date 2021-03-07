#ifndef ArchivoFASTA_hpp
#define ArchivoFASTA_hpp

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Secuencia.hpp"

class ArchivoFASTA {
    private:
    //Clase que guarda las subcadenas que componen el archivo (líneas descriptivas; secuencias).
    std::vector<std::string> lineaDescriptiva;
    std::vector<Secuencia> secLista;
    int contadorSeq; //Su valor es igual al índice de la última posición en el vector 'secLista'.
    
    public:
    ArchivoFASTA();
    std::string getLineaDescriptiva(int posicionLD);
    void setLineaDescriptiva(std::string lineaDescriptiva);
    std::string getSecuencia(int posicionS);
    void setSecuencia(std::string cadenaSecuencia);

    //Comandos requeridos en el enunciado del proyecto:
    bool cargarArchivo(std::string nombreArchivo);
    int conteoSecuencias();
    void histograma(std::string descripcionSecuencia);
    void listarSecuencias();
    void subsecuencia(std::string subseq);
    void enmascarar(std::string secuencia);
    bool guardar(std::string nombreArchivo);

};

#endif /* ArchivoFASTA_hpp */