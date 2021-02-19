//
//  main.cpp
//  ProyectoED
//
//  Created by Cristóbal Castrillón Balcázar on 14/02/21.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Secuencia.hpp"
#include "ArchivoFASTA.hpp"

using namespace std;

struct archivo {
//Estructura que guarda las subcadenas que componen el archivo (líneas descriptivas; secuencias).
    vector<string> lineaDescriptiva;
    vector<Secuencia> secLista;
};

int main(int argc, const char * argv[]) {
    
    string linea; //String utilizado para extraer cada línea del archivo FASTA.
    archivo archivoFASTA;
    
    ifstream readFasta("ejemplo.txt");
    if(readFasta.is_open()){
        int contadorSeq = 0; //Contador de secuencias presentes en el archivo.
        Secuencia temp; //Ayuda a gestionar el parsing de secuencias.
        while(getline(readFasta, linea, '\0')){
            if(linea.at(0) == '>'){
                archivoFASTA.lineaDescriptiva.push_back(linea);
                //La siguiente línea es de prueba:
                cout << archivoFASTA.lineaDescriptiva.at(0);
            }
            else{
                archivoFASTA.secLista.push_back(temp);
                archivoFASTA.secLista.at(contadorSeq) = archivoFASTA.secLista.at(contadorSeq).getSecuencia() + linea;
                //La siguiente línea es de prueba:
                cout << archivoFASTA.secLista.at(contadorSeq).getSecuencia() << endl;
                contadorSeq++;
            }
        }
    }
    else{
        cout << "No se ha podido leer el archivo" << endl;
    }
    
    return 0;
}
