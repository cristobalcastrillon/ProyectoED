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

    //Aparentemente no se está haciendo push correctamente a la lista de secuencias (secLista).
    //TODO: Troubleshoot el error que sale con las siguientes líneas.
    cout << endl;
    cout << "Primera secuencia del archivo: " << archivo1.getSecuencia(0) << endl;
    
    return 0;
}
