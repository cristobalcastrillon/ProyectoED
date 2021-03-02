#include "ArchivoFASTA.hpp"

//TODO: Implementar los métodos de la clase ArchivoFASTA.

ArchivoFASTA::ArchivoFASTA(){}

std::string ArchivoFASTA::getLineaDescriptiva(int posicionLD){ 
    return lineaDescriptiva.at(posicionLD);
}

void ArchivoFASTA::setLineaDescriptiva(std::string lineaDescriptiva){}

std::string ArchivoFASTA::getSecuencia(int posicionS){
    return secLista.at(posicionS).getSecuencia();
}

void ArchivoFASTA::setSecuencia(std::string cadenaSecuencia){}

bool ArchivoFASTA::cargarArchivo(std::string nombreArchivo){ 
    //'nombreArchivo' debe constar del título del archivo junto a su extensión (e.g. 'ejemplo.txt')
    std::string linea;

    std::ifstream readFASTA(nombreArchivo);

    if(readFASTA.is_open()){
        contadorSeq = -1;
        Secuencia temp; //Ayuda a gestionar el parsing de secuencias.
        while(getline(readFASTA, linea)){
            if(linea.at(0) == '>'){
                lineaDescriptiva.push_back(linea);
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

int ArchivoFASTA::conteoSecuencias(){
    try{
        if(!(contadorSeq+1)){
            throw std::runtime_error("Error");
        }
        return contadorSeq+1;
    }
    catch(std::exception e ){
        std::cout << "No hay secuencias cargadas en memoria: ";
        return 0;
    }
}

void ArchivoFASTA::histograma(){

}

void ArchivoFASTA::listarSecuencias(std::string descripcionSecuencia){
    try{

    }
    catch(std::exception e){
        std::cout << "No hay secuencias cargadas en memoria.";
    }
}

void ArchivoFASTA::subsecuencia(std::string subseq){
    
}

void ArchivoFASTA::enmascarar(std::string secuencia){

}

bool ArchivoFASTA::guardar(std::string nombreArchivo){

}