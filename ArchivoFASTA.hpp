#ifndef ArchivoFASTA_hpp
#define ArchivoFASTA_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>

class ArchivoFASTA {
    private:
    //Clase que guarda las subcadenas que componen el archivo (líneas descriptivas; secuencias).
    vector<string> lineaDescriptiva;
    vector<Secuencia> secLista;
    
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