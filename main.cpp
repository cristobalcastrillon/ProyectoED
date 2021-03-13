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

    // ArchivoFASTA archivo1;
    // archivo1.cargarArchivo("ejemplo.txt");

    // cout << "Primera línea de referencia del archivo 1: " << archivo1.getLineaDescriptiva(0) << endl;
    // cout << "Primera secuencia del archivo 1: " << archivo1.getSecuencia(0) << endl;
    // cout << "Segunda línea de referencia del archivo 1: " << archivo1.getLineaDescriptiva(1) << endl;
    // cout << "Segunda secuencia del archivo 1: " << archivo1.getSecuencia(1) << endl;

    // cout << "Cantidad de secuencias en el archivo 1: " << archivo1.conteoSecuencias() << endl;
    // cout << "Histograma de la secuencia en la posición 0 del vector:" << endl;
    // archivo1.histograma(archivo1.getLineaDescriptiva(0));

    // ArchivoFASTA archivo2;
    // archivo2.cargarArchivo("ejemplo2.txt");

    // cout << "Cantidad de secuencias en el archivo 2: " << archivo2.conteoSecuencias() << endl;

    string comando;

    while(1)
    {
        getline(cin,comando);

        if(comando.find("cargar") != string::npos)
        {
            //Nombre del archivo: 'nombre_archivo'
            string nombre_archivo = comando.substr(6);
            cout << nombre_archivo << endl;
            ArchivoFASTA archivoNuevo;
            archivoNuevo.cargarArchivo(nombre_archivo);
        }
        if(comando.find("conteo") != string::npos)
        {
            //Ejecuta conteo
            //TODO: Agregar el llamado a función.
        }
        if(comando.find("listar_secuencias")!= string::npos)
        {
            //Ejecuta listar_secuencias
            //TODO: Agregar el llamado a función.
        }
        if(comando.find("histograma") != string::npos)
        {
            //Descripcion_secuencia
            string descripcion_secuencia = comando.substr(11);
            cout << descripcion_secuencia << endl;
            //TODO: Agregar el llamado a función.
        }
        if(comando.find("es_subsecuencia") != string::npos)
        {
            //Secuencia
            string secuencia = comando.substr(16);
            cout << secuencia << endl;
            //TODO: Agregar el llamado a función.
        }
        if(comando.find("enmascarar") != string::npos)
        {
            //Secuencia
            string secuencia = comando.substr(11);
            cout << secuencia << endl;
            //TODO: Agregar el llamado a función.
        }
        if(comando.find("guardar") != string::npos)
        {
            //Nombre_archivo
            string nombre_archivo = comando.substr(8);
            cout << nombre_archivo << endl;
            //TODO: Agregar el llamado a función.
        }
        if(comando.find("salir") != string::npos)
        {
            //Salir
            exit(0);
        }
    }

    return 0;
}
