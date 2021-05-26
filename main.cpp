//
//  main.cpp
//  ProyectoED
//
//  Created by Cristóbal Castrillón Balcázar & Nicolás Pérez Fonseca on 14/02/21.
//

#include "ArchivoFASTA.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    string comando;
    ArchivoFASTA archivoNuevo;
    HuffmanNode * arbol; //la raíz del arbol
    int cont = 0; //Contador de secuencias

    while(1)
    {
        std::cout << "$ ";
        getline(cin, comando);
        if(comando.find("cargar") != string::npos)
        {
            //DESCRIPCIÓN: Carga en memoria los datos contenidos en el archivo identificado por nombre_archivo.
            //PARÁMETROS: 
            //  Nombre del archivo: 'nombre_archivo'
            string nombre_archivo = comando.substr(7);
            if(archivoNuevo.cargarArchivo(nombre_archivo)){
                switch(cont = archivoNuevo.conteoSecuencias() - cont){
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
            cout << archivoNuevo.conteoSecuencias() << " en memoria" << endl;
        }
        if(comando.find("listar_secuencias")!= string::npos)
        {
            //DESCRIPCIÓN:  Imprime en n líneas (una para secuencia) la información básica (cantidad de bases) de cada secuencia. Si la secuencia es completa (i.e. no tiene el código ’-’) imprime el segundo mensaje, si no, el tercero.
            //PARÁMETROS: 
            //  N/A
            //TODO: Implementar el método 'listarSecuencias()' 
            archivoNuevo.listarSecuencias();
        }
        if(comando.find("histograma") != string::npos)
        {
            //DESCRIPCIÓN:  Imprime el histograma de una secuencia, en caso de que exista. El histograma se define como el conteo (frecuencia) de cada código en la secuencia. Por cada línea (’\n’ es el caracter de salto de línea) se escribe el código y la cantidad de veces que aparece en la secuencia.
            //PARÁMETROS: 
            //  Descripción de la secuencia: 'descripcion_secuencia'
            string descripcion_secuencia = comando.substr(11);
            archivoNuevo.histograma(descripcion_secuencia);
        }
        if(comando.find("es_subsecuencia") != string::npos)
        {
            //DESCRIPCIÓN:   Determina si una secuencia, dada por el usuario, existe dentro de las secuencias cargadas. Si es así, determina la cantidad de veces en las que esta secuencia dada se repite.
            //PARÁMETROS: 
            //  Secuencia: 'secuencia'
            string secuencia = comando.substr(16);
            archivoNuevo.subsecuencia(secuencia);
        }
        if(comando.find("enmascarar") != string::npos)
        {
            //DESCRIPCIÓN:   Enmascara una secuencia dada por el usuario, si existe. Los elementos que pertenecen a la subsecuencia se enmascaran, cambiando cada código por el código ’X’.
            //PARÁMETROS: 
            //  Secuencia: 'secuencia'
            string secuencia = comando.substr(11);
            archivoNuevo.enmascarar(secuencia);
        }
        if(comando.find("guardar") != string::npos)
        {
            //DESCRIPCIÓN:   Guarda en el archivo nombre_archivo las secuencias cargadas en memoria. Se debe tener en cuenta la justificación (de líneas) del archivo inicial.
            //PARÁMETROS: 
            //  Nombre del archivo: 'nombre_archivo'
            string nombre_archivo = comando.substr(8);
            archivoNuevo.guardar(nombre_archivo);
        }
        if(comando.find("ayuda") != string::npos)
        {
            //DESCRIPCIÓN:   Guarda en el archivo nombre_archivo las secuencias cargadas en memoria. Se debe tener en cuenta la justificación (de líneas) del archivo inicial.
            //PARÁMETROS: 
            //  Nombre del archivo: 'nombre_archivo'
            archivoNuevo.ayuda();
        }
        if(comando.find("codificar") != string::npos)
        {
            //DESCRIPCIÓN:   Codifica las secuencias y sus respectivos identificadores —lineas descriptivas— cargados en memoria, y los guarda en un archivo binario de extensión .fabin.
            //PARÁMETROS: 
            //  Nombre del archivo binario a guardar: 'nombre_archivoFABin'
            string nombre_archivoFABin = comando.substr(10);
            arbol = archivoNuevo.codificar(nombre_archivoFABin);
        }
        if(comando.find("decodificar") != string::npos)
        {
            //DESCRIPCIÓN:   Decodifica el contenido de un archivo binario de extensión .fabin y lo carga en memoria.
            //PARÁMETROS: 
            //  Nombre del archivo binario a leer: 'nombre_archivoFABin'
            string nombre_archivoFABin = comando.substr(12);   
            archivoNuevo.decodificar(nombre_archivoFABin);
        }
        if(comando.find("salir") != string::npos)
        {
            //DESCRIPCIÓN:   Termina la ejecución de la aplicación.
            //PARÁMETROS: 
            //  N/A
            exit(0);
        }
        if(comando.find("ruta_mas_corta") != string::npos)
        {
            //DESCRIPCIÓN:  El comando debe imprimir en pantalla la secuencia de vértices del grafo que describen la ruta más corta entre la base ubicada en la posición [i ,j ] de la matriz de la secuencia descripcion_secuencia y la base ubicada en la posición [x ,y ] de la misma matriz. Así mismo,
            //debe imprimir el costo total de la ruta, teniendo en cuenta el peso que tiene cada conexión entre bases.
            //PARÁMETROS:
            //  descripcion_secuencia
            //  i
            //  j
            //  x
            //  y

            string restante = comando.substr(15);
            std::size_t index = restante.find(' ');

            string descripcion_secuencia = restante.substr(0, index);
            index++;
            restante = restante.substr(index);
            index = restante.find(' ');
            
            string i = restante.substr(0, index);
            index++;
            restante = restante.substr(index);
            index = restante.find(' ');

            string j = restante.substr(0, index);
            index++;
            restante = restante.substr(index);
            index = restante.find(' ');

            string x = restante.substr(0, index);
            index++;
            restante = restante.substr(index);
            index = restante.find(' ');

            string y = restante.substr(0);

            archivoNuevo.ruta_mas_corta(descripcion_secuencia, stoi(i), stoi(j), stoi(x), stoi(y));            
        }
        if(comando.find("base_remota") != string::npos)
        {
            //DESCRIPCIÓN:   Para la base ubicada en la posición [i ,j ] de la matriz de la secuencia descripcion_secuencia , el comando busca la ubicación de la misma base (misma letra) más lejana dentro de la matriz. Para esta base remota, el comando debe imprimir en pantalla su ubicación, la secuencia de vértices que describen la ruta entre la base origen y la base remota, y el costo total de la ruta.
            //PARÁMETROS:
            //  descripcion_secuencia
            //  i
            //  j

            string restante = comando.substr(12);
            std::size_t index = restante.find(' ');

            string descripcion_secuencia = restante.substr(0, index);
            index++;
            restante = restante.substr(index);
            index = restante.find(' ');
            
            string i = restante.substr(0, index);
            index++;
            restante = restante.substr(index);
            index = restante.find(' ');

            string j = restante.substr(0);

            archivoNuevo.base_remota(descripcion_secuencia, stoi(i), stoi(j));
        }
    }

    return 0;
}
