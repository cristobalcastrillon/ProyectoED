//
//  main.cpp
//  ProyectoED
//
//  Created by Cristóbal Castrillón Balcázar & Nicolás Pérez Fonseca on 14/02/21.
//

#include <iostream>
#include <string>
#include "ArchivoFASTA.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    ArchivoFASTA archivo1;
    archivo1.cargarArchivo("ejemplo.txt");

    cout << "Primera línea de referencia del archivo 1: " << archivo1.getLineaDescriptiva(0) << endl;
    cout << "Primera secuencia del archivo 1: " << archivo1.getSecuencia(0) << endl;
    cout << "Segunda línea de referencia del archivo 1: " << archivo1.getLineaDescriptiva(1) << endl;
    cout << "Segunda secuencia del archivo 1: " << archivo1.getSecuencia(1) << endl;

    cout << "Cantidad de secuencias en el archivo 1: " << archivo1.conteoSecuencias() << endl;
    cout << "Histograma de la secuencia en la posición 0 del vector:" << endl;
    archivo1.histograma(archivo1.getLineaDescriptiva(0));

    ArchivoFASTA archivo2;
    archivo2.cargarArchivo("ejemplo2.txt");

    cout << "Cantidad de secuencias en el archivo 2: " << archivo2.conteoSecuencias() << endl;

    return 0;
}
