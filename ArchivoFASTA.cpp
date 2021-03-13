#include "ArchivoFASTA.hpp"

//TODO: Implementar los métodos de la clase ArchivoFASTA.

ArchivoFASTA::ArchivoFASTA(){

}

std::string ArchivoFASTA::getLineaDescriptiva(int posicionLD){ 
    return lineasDescriptivas.at(posicionLD);
}

void ArchivoFASTA::setLineaDescriptiva(std::string lineasDescriptivas){}

std::string ArchivoFASTA::getSecuencia(int posicionS){
    return secLista.at(posicionS).getSecuencia();
}

void ArchivoFASTA::setSecuencia(std::string cadenaSecuencia){}

bool ArchivoFASTA::cargarArchivo(std::string nombreArchivo){ 
    //'nombreArchivo' debe constar del título del archivo junto a su extensión (e.g. 'ejemplo.txt')
    std::string linea;

    std::ifstream readFASTA(nombreArchivo);

    if(readFASTA.is_open()){
        contadorSeq = -1; //IMPORTANTE: Tal vez no es necesario para acceder a la posición (int) del último elemento del vector.
        Secuencia temp; //Ayuda a gestionar el parsing de secuencias.
        while(getline(readFASTA, linea)){
            if(linea.at(0) == '>'){
                lineasDescriptivas.push_back(linea);
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
        //OJO: Este método no es fiel a la cantidad de secuencias que existen en realidad en memoria, al no contar el vector, pero sí servirse de la variable 'contadorSeq'.
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

void ArchivoFASTA::histograma(std::string descripcionSecuencia){
    try{
        for(int j = 0; j < lineasDescriptivas.size(); j++){
            if(descripcionSecuencia == lineasDescriptivas.at(j)){
                char itChar = ' ';
                for(int i = 0; i < secLista.at(j).getSecuencia().size(); i++){
                    itChar = secLista.at(j).getSecuencia().at(i);
                    //La siguiente línea es de prueba
                    std::cout << i << " caracter de la secuencia " << itChar << ' ';
                    int tempInt = 0;
                    for(int k = 0; k < CANTIDAD_BASES; k++){
                        if(itChar == secLista.at(j).getBases().at(k).getLetraBase()){
                            //TODO: Aumentar la cantidad del caracter leído en el vector de Bases, propio de la Secuencia.
                            tempInt = secLista.at(j).getBases().at(k).getCantidad()+1;
                            secLista.at(j).getBases().at(k).setCantidad(tempInt);
                            //La siguiente línea es de prueba
                            std::cout << secLista.at(j).getBases().at(k).getCantidad() << std::endl;
                            //FIX: No sé por qué está incrementando en uno para todas las bases, como si 'cantidad' fuera cantidad de caracteres en la secuencia...
                        }
                    }
                }       
            }
        }
    }
    catch(std::exception e){
        std::cout << "Secuencia inválida." << std::endl;
    }
}

void ArchivoFASTA::listarSecuencias(){
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
    try{
        std::ofstream writeFASTA(nombreArchivo);
        std::string contenidoArchivo;
        for(int i = 0; i < contadorSeq+1; i++){
            contenidoArchivo += lineasDescriptivas.at(i) + '\n';
            contenidoArchivo += secLista.at(i).getSecuencia() + '\n';
        }
        writeFASTA << contenidoArchivo;
        writeFASTA.close();
        return true;
    }
    catch(std::exception e){
        std::cout << "Error guardando en " << nombreArchivo << std::endl;
        return false;
    }
}