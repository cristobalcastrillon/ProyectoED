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
    	std::cout<<"No Hay ecuencias cargadas"<<std::endl;
    	return;
    }
    else{
    	int contApariciones = 0;
    	for(int i=0;secLista.size();i++)
    	{
    		std::string secuencia=secLista.at(i).getSecuencia();
   			for(int j=0;j<secuencia.size();j++){
   			    for(int k=j+1;k<secuencia.length();k++){
   			        std::string t = secuencia.substr(j,k);
   			        if(t==subseq){
   			            contApariciones++;
   			        }
   			    }
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
    	std::cout<<"No Hay ecuencias cargadas"<<std::endl;
    	return;
    }
    else{
    	int contApariciones = 0;
    	std::string mascara;
    	for(int i=0;i<secuencia.length();i++){
    	    mascara=mascara+"X";
    	}
    	for(int i=0;secLista.size();i++)
    	{
    		std::string secuencia=secLista.at(i).getSecuencia();
   			for(int j=0;j<secuencia.size();j++){
   			    for(int k=j+1;k<=secuencia.size();k++){

   			        std::string::size_type pos = secLista.at(i).getSecuencia().find(secuencia,0);
   			        if(pos<std::string::npos){
   			            secLista.at(i).getSecuencia().replace(pos,secuencia.length(),mascara);
   			           contApariciones++;
   			        }
   			    }
   			}
    	}
    	if(contApariciones==0){
    		std::cout<<"La secuencia no existe"<<std::endl;
    		return;
    	}
    	std::cout<<contApariciones<<" secuencias ha sido enmascaradas"<<std::endl;
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
