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
    
    public:
    ArchivoFASTA();
    std::string getLineaDescriptiva(int posicionLD);
    void setLineaDescriptiva(std::string lineaDescriptiva);
    std::string getSecuencia(int posicionS);
    void setSecuencia(std::string cadenaSecuencia);

    //Comandos requeridos en el enunciado del proyecto:
    bool cargarArchivo(std::string nombreArchivo);
    int conteoSecuencias();
    void histograma();

};

#endif /* ArchivoFASTA_hpp */