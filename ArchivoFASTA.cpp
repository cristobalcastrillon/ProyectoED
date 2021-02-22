#include "ArchivoFASTA.hpp"

//TODO: Implementar los métodos de la clase ArchivoFASTA.

ArchivoFASTA::ArchivoFASTA(){}

std::string ArchivoFASTA::getLineaDescriptiva(int posicionLD){ return "cadenaEjemplo"; }

void ArchivoFASTA::setLineaDescriptiva(std::string lineaDescriptiva){}

std::string ArchivoFASTA::getSecuencia(int posicionS){ return "cadenaEjemplo"; }

void ArchivoFASTA::setSecuencia(std::string cadenaSecuencia){}

bool ArchivoFASTA::cargarArchivo(std::string nombreArchivo){ 
    //'nombreArchivo' debe constar del título del archivo junto a su extensión (e.g. 'ejemplo.txt')
    std::string linea;

    std::ifstream readFASTA(nombreArchivo);

    if(readFASTA.is_open()){
        int contadorSeq = 0; //Contador de secuencias presentes en el archivo.
        Secuencia temp; //Ayuda a gestionar el parsing de secuencias.
        while(getline(readFASTA, linea, '\0')){
            if(linea.at(0) == '>'){
                this->lineaDescriptiva.push_back(linea);
                //La siguiente línea es de prueba:
                std::cout << this->lineaDescriptiva.at(0);
            }
            else{
                this->secLista.push_back(temp);
                this->secLista.at(contadorSeq) = this->secLista.at(contadorSeq).getSecuencia() + linea;
                //La siguiente línea es de prueba:
                std::cout << this->secLista.at(contadorSeq).getSecuencia() << std::endl;
                contadorSeq++;
            }
        }
    }
    else{
        std::cout << "No se ha podido leer el archivo" << std::endl;
    }

    return false; 
}
int ArchivoFASTA::conteoSecuencias(){ return 0; }
void ArchivoFASTA::histograma(){}

