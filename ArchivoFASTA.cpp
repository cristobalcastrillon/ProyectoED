#include "ArchivoFASTA.hpp"
#include <string.h>

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

void ArchivoFASTA::setSecuencia(std::string cadenaSecuencia){
    //Añade una secuencia con el string dado (i.e. la secuencia) a la lista de secuencias
    Secuencia secTemp;
    secTemp.setSecuencia(cadenaSecuencia);
    secLista.push_back(secTemp);
}

bool ArchivoFASTA::cargarArchivo(std::string nombreArchivo){ 
    //'nombreArchivo' debe constar del título del archivo junto a su extensión (e.g. 'ejemplo.txt')
    //si no está en el directorio del proyecto, se debe proporcionar la ruta completa del archivo.
    std::string linea;
    std::ifstream readFASTA(nombreArchivo);
    if(readFASTA.is_open()){
        Secuencia temp; //Ayuda a gestionar el parsing de secuencias.
        while(getline(readFASTA, linea)){
            if(linea.at(0) == '>'){
                lineasDescriptivas.push_back(linea);
                secLista.push_back(temp);
            }
            else{
                secLista.at(lineasDescriptivas.size()-1).appendSecuencia(linea);
            }
        }
        conteoBasesXSecuencia();
        return true; //Se ha podido cargar el archivo en «memoria»
    }
    else{
        std::cout << "No se ha podido leer el archivo" << std::endl;
    }
    return false; //No se ha podido cargar el archivo en «memoria»
}

void ArchivoFASTA::conteoBasesXSecuencia(){
    for(int i = 0; i < secLista.size(); i++){
        secLista.at(i).conteoBases();
    }
}

int ArchivoFASTA::conteoSecuencias(){
    try{
        if(!(secLista.size())){
            throw std::runtime_error("Error");
        }
        return secLista.size();
    }
    catch(std::exception e ){
        std::cout << "No hay secuencias cargadas en memoria: ";
        return 0;
    }
}

void ArchivoFASTA::histograma(std::string descripcionSecuencia){
    try{
        for(int i = 0; i < lineasDescriptivas.size(); i++){
            if(lineasDescriptivas.at(i) == descripcionSecuencia){
                for(int k = 0; k < CANTIDAD_BASES; k++){
                    int cantDeBase = secLista.at(i).getBases().at(k).getCantidad();
                    std::cout << secLista.at(i).getBases().at(k).getLetraBase() << "\t" << cantDeBase << std::endl;
                }
                break; //Break out of the loop.
            }
        }

    }
    catch(std::exception e){
        std::cout << "Secuencia inválida." << std::endl;
    }
}

void ArchivoFASTA::listarSecuencias(){
    try{
        for(int i = 0; i < secLista.size(); i++){
            int cantBasesSeq = 0;
            //bool incompleta = false;
            for(int k = 0; k < CANTIDAD_BASES; k++){
                if(secLista.at(i).getBases().at(k).getCantidad() > 0){
                    cantBasesSeq++;
                }
            }
            if(secLista.at(i).getIncompleta()){
                std::cout << "Secuencia '" << lineasDescriptivas.at(i) << "' contiene al menos " << cantBasesSeq << " bases." << std::endl;    
                continue;
            }
            std::cout << "Secuencia '" << lineasDescriptivas.at(i) << "' contiene " << cantBasesSeq << " bases." << std::endl;
        }
    }
    catch(std::exception e){
        std::cout << "No hay secuencias cargadas en memoria.";
    }
}

void ArchivoFASTA::subsecuencia(std::string subseq){
    if(secLista.size() == 0){
    	std::cout<<"No hay secuencias cargadas"<<std::endl;
    	return;
    }
    else{
    	int contApariciones = 0;

    	for(int i=0;i<secLista.size();i++)
    	{
    		std::string secuencia=secLista.at(i).getSecuencia();
    	    //Looking for and couting number of occurrences of the given subsequence
    	    std::size_t found = secuencia.find(subseq);
    	    secuencia = secuencia.substr(found+subseq.length());
    	    while(found != std::string::npos){
    	        contApariciones++;
    	        found = secuencia.find(subseq);
    	        secuencia = secuencia.substr(found+subseq.length());
    	    }
    	}
    	if(contApariciones==0){
    		std::cout<<"La secuencia no existe"<<std::endl;
    		return;
    	}
    	std::cout<<"La sebsecuencia se repite "<<contApariciones<<" veces"<<std::endl;
    	return;
    }
    return;
}

void ArchivoFASTA::enmascarar(std::string secuencia){
    if(secLista.size() == 0){
    	std::cout<<"No hay secuencias cargadas"<<std::endl;
    	return;
    }
    else{
    	int contApariciones = 0;
        std::string mascara;
    	for(int i=0;i<secuencia.length();i++){
    	    mascara=mascara+"X";
    	}
    	for(int i=0;i<secLista.size();i++)
    	{
    		std::string secuenciaStr=secLista.at(i).getSecuencia();
    		std::string chapuza = secuenciaStr.substr(0,mascara.length());
    	    //Looking for and replacing all occurrences of the given sequence
    	    std::size_t found = secuencia.find(secuencia);
    	    while(found != std::string::npos){
    	        contApariciones++;
                secuenciaStr.replace(found,secuencia.length(),mascara);
                found=secuenciaStr.find(secuencia,(found+mascara.length()));
    	    }
    	    //fixing the error
    	    secuenciaStr.replace(0,mascara.length(),chapuza);
    	    //replacing the sequence string with the new one
    	    secLista.at(i).setSecuencia(secuenciaStr);
    	}
    	contApariciones-=secLista.size();
    	if(contApariciones==0){
    		std::cout<<"No se enmascararon subsecuencias"<<std::endl;
    		return;
    	}
    	if(contApariciones==1){
    		std::cout<<"1 ecuencia ha sido enmascarada"<<std::endl;
    		return;
    	}
    	std::cout<<contApariciones<<" secuencias han sido enmascaradas"<<std::endl;
    	return;
    }
    return;
}

bool ArchivoFASTA::guardar(std::string nombreArchivo){
    try{
        std::ofstream writeFASTA(nombreArchivo);
        std::string contenidoArchivo;
        for(int i = 0; i < secLista.size(); i++){
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

void ArchivoFASTA::ayuda(){
    std::cout << "cargar <archivo.fa>\tCarga un archivo FASTA." << std::endl;
    std::cout << "conteo\tCuenta las secuencias presentes en memoria." << std::endl;
    std::cout << "histograma <descripcion_secuencia>\tImprime la distribución de frecuencias para una secuencia dada." << std::endl;
    std::cout << "listar_secuencias\tLista las secuencias presentes en memoria." << std::endl;
    std::cout << "es_subsecuencia <subsecuencia>\tBusca las ocurrencias presentes en memoria de la subsecuencia dada." << std::endl;
    std::cout << "enmascarar <subsecuencia>\tBusca las ocurrencias presentes en memoria de la subsecuencia dada y las enmascara con el caracter 'X'." << std::endl;
    std::cout << "guardar <archivo.fa>\tGuarda las estructuras manipuladas en un archivo FASTA." << std::endl;
}
