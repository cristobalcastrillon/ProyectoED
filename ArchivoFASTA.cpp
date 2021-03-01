#include "ArchivoFASTA.hpp"

//TODO: Implementar los métodos de la clase ArchivoFASTA.

ArchivoFASTA::ArchivoFASTA(){}

std::string ArchivoFASTA::getLineaDescriptiva(int posicionLD){ 
        return this->lineaDescriptiva.at(posicionLD); 
    }

void ArchivoFASTA::setLineaDescriptiva(std::string lineaDescriptiva){}

std::string ArchivoFASTA::getSecuencia(int posicionS){
    return this->secLista.at(posicionS).getSecuencia();
}

void ArchivoFASTA::setSecuencia(std::string cadenaSecuencia){}

bool ArchivoFASTA::cargarArchivo(std::string nombreArchivo){ 
    //'nombreArchivo' debe constar del título del archivo junto a su extensión (e.g. 'ejemplo.txt')
    std::string linea;

    std::ifstream readFASTA(nombreArchivo);

    if(readFASTA.is_open()){
        int contadorSeq = -1; //Contador de secuencias presentes en el archivo. *NO BORRAR*
        Secuencia temp; //Ayuda a gestionar el parsing de secuencias.
        while(getline(readFASTA, linea)){
            if(linea.at(0) == '>'){
                this->lineaDescriptiva.push_back(linea);
                contadorSeq++;
            }
            else{
                secLista.push_back(temp);
                secLista.at(contadorSeq).appendSecuencia(linea);
            }
        }
        return true; //Se ha podido cargar el archivo en «memoria»
    }
    else{
        std::cout << "No se ha podido leer el archivo" << std::endl;
    }

    return false; //No se ha podido cargar el archivo en «memoria»
}
int ArchivoFASTA::conteoSecuencias(){ return 0; }
void ArchivoFASTA::histograma(){}

