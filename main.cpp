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
    ArchivoFASTA archivoNuevo;
    while(1)
    {
        getline(cin, comando);
        if(comando.find("cargar") != string::npos)
        {
            //DESCRIPCIÓN: Carga en memoria los datos contenidos en el archivo identificado por nombre_archivo.
            //PARÁMETROS: 
            //  Nombre del archivo: 'nombre_archivo'
            string nombre_archivo = comando.substr(7);
            if(archivoNuevo.cargarArchivo(nombre_archivo)){
                switch(int cont = archivoNuevo.conteoSecuencias()){
                    case 1:
                        cout << "1 secuencia cargada correctamente desde " << nombre_archivo << endl;
                        break;
                    default: 
                        cout << cont << " secuencias cargadas correctamente desde " << nombre_archivo << endl;
                }
            }
        }
        if(comando.find("conteo") != string::npos)
        {
            //DESCRIPCIÓN: Imprime por pantalla la cantidad de secuencias cargadas en memoria.
            //PARÁMETROS: 
            //  N/A
            archivoNuevo.conteoSecuencias();
        }
        if(comando.find("listar_secuencias")!= string::npos)
        {
            //DESCRIPCIÓN:  Imprime en n líneas (una para secuencia) la información básica (cantidad de bases) de cada secuencia. Si la secuencia es completa (i.e. no tiene el código ’-’) imprime el segundo mensaje, si no, el tercero.
            //PARÁMETROS: 
            //  Descripción de la secuencia: 'descripcion_secuencia'
            string descripcion_secuencia = comando.substr(12);
            cout << descripcion_secuencia << endl;
            //TODO: Implementar el método 'listarSecuencias()' OJO: No olvidar incluir parámetro 'descripcion_secuencia'.
            archivoNuevo.listarSecuencias();
        }
        if(comando.find("histograma") != string::npos)
        {
            //DESCRIPCIÓN:  Imprime el histograma de una secuencia, en caso de que exista. El histograma se define como el conteo (frecuencia) de cada código en la secuencia. Por cada línea (’\n’ es el caracter de salto de línea) se escribe el código y la cantidad de veces que aparece en la secuencia.
            //PARÁMETROS: 
            //  Descripción de la secuencia: 'descripcion_secuencia'
            string descripcion_secuencia = comando.substr(12);
            cout << descripcion_secuencia << endl;
            archivoNuevo.histograma(descripcion_secuencia);
        }
        if(comando.find("es_subsecuencia") != string::npos)
        {
            //DESCRIPCIÓN:   Determina si una secuencia, dada por el usuario, existe dentro de las secuencias cargadas. Si es así, determina la cantidad de veces en las que esta secuencia dada se repite.
            //PARÁMETROS: 
            //  Secuencia: 'secuencia'
            string secuencia = comando.substr(17);
            cout << secuencia << endl;
            archivoNuevo.subsecuencia(secuencia);
        }
        if(comando.find("enmascarar") != string::npos)
        {
            //DESCRIPCIÓN:   Enmascara una secuencia dada por el usuario, si existe. Los elementos que pertenecen a la subsecuencia se enmascaran, cambiando cada código por el código ’X’.
            //PARÁMETROS: 
            //  Secuencia: 'secuencia'
            string secuencia = comando.substr(12);
            cout << secuencia << endl;
            archivoNuevo.enmascarar(secuencia);
        }
        if(comando.find("guardar") != string::npos)
        {
            //DESCRIPCIÓN:   Guarda en el archivo nombre_archivo las secuencias cargadas en memoria. Se debe tener en cuenta la justificación (de líneas) del archivo inicial.
            //PARÁMETROS: 
            //  Nombre del archivo: 'nombre_archivo'
            string nombre_archivo = comando.substr(9);
            cout << nombre_archivo << endl;
            archivoNuevo.guardar(nombre_archivo);
        }
        if(comando.find("salir") != string::npos)
        {
            //DESCRIPCIÓN:   Termina la ejecución de la aplicación.
            //PARÁMETROS: 
            //  N/A
            exit(0);
        }
    }

    return 0;
}
