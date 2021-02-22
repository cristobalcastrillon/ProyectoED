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
    
    return 0;
}
