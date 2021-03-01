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

    cout << "Primera línea de referencia del archivo: " << archivo1.getLineaDescriptiva(0) << endl;
    cout << "Primera secuencia del archivo: " << archivo1.getSecuencia(0) << endl;
    cout << "Segunda línea de referencia del archivo: " << archivo1.getLineaDescriptiva(1) << endl;
    cout << "Segunda secuencia del archivo: " << archivo1.getSecuencia(1) << endl;

    return 0;
}
