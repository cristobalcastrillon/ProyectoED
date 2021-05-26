#include "ArchivoFASTA.hpp"
#include "Grafo.hpp"
#include <sstream>

//-------------------------------------------------------------PRIMERA ENTREGA------------------------------------------------------------------
ArchivoFASTA::ArchivoFASTA()
{
}

std::string ArchivoFASTA::getLineaDescriptiva(int posicionLD)
{
    return lineasDescriptivas.at(posicionLD);
}

void ArchivoFASTA::setLineaDescriptiva(std::string lineasDescriptivas) {}

std::string ArchivoFASTA::getSecuencia(int posicionS)
{
    return secLista.at(posicionS).getSecuencia();
}

void ArchivoFASTA::setSecuencia(std::string cadenaSecuencia)
{
    //Añade una secuencia con el string dado (i.e. la secuencia) a la lista de secuencias
    Secuencia secTemp;
    secTemp.setSecuencia(cadenaSecuencia);
    secLista.push_back(secTemp);
}

bool ArchivoFASTA::cargarArchivo(std::string nombreArchivo)
{
    //'nombreArchivo' debe constar del título del archivo junto a su extensión (e.g. 'ejemplo.txt')
    //si no está en el directorio del proyecto, se debe proporcionar la ruta completa del archivo.
    std::string linea;
    std::ifstream readFASTA(nombreArchivo);
    if (readFASTA.is_open())
    {
        Secuencia temp; //Ayuda a gestionar el parsing de secuencias.
        while (getline(readFASTA, linea))
        {
            if (linea.at(0) == '>')
            {
                lineasDescriptivas.push_back(linea);
                secLista.push_back(temp);
            }
            else
            {
                secLista.at(lineasDescriptivas.size() - 1).appendSecuencia(linea + '\n');
            }
        }
        conteoBasesXSecuencia();
        return true; //Se ha podido cargar el archivo en «memoria»
    }
    else
    {
        std::cout << "No se ha podido leer el archivo" << std::endl;
    }
    return false; //No se ha podido cargar el archivo en «memoria»
}

void ArchivoFASTA::conteoBasesXSecuencia()
{
    for (int i = 0; i < secLista.size(); i++)
    {
        secLista.at(i).conteoBases();
    }
}

int ArchivoFASTA::conteoSecuencias()
{
    try
    {
        if (!(secLista.size()))
        {
            throw std::runtime_error("Error");
        }
        return secLista.size();
    }
    catch (std::exception e)
    {
        std::cout << "No hay secuencias cargadas en memoria: ";
        return 0;
    }
}

void ArchivoFASTA::histograma(std::string descripcionSecuencia)
{
    try
    {
        for (int i = 0; i < lineasDescriptivas.size(); i++)
        {
            if (lineasDescriptivas.at(i) == descripcionSecuencia)
            {
                for (int k = 0; k < CANTIDAD_BASES; k++)
                {
                    int cantDeBase = secLista.at(i).getBases().at(k).getCantidad();
                    std::cout << secLista.at(i).getBases().at(k).getLetraBase() << "\t" << cantDeBase << std::endl;
                }
                break; //Break out of the loop.
            }
        }
    }
    catch (std::exception e)
    {
        std::cout << "Secuencia inválida." << std::endl;
    }
}

void ArchivoFASTA::listarSecuencias()
{
    try
    {
        for (int i = 0; i < secLista.size(); i++)
        {
            int cantBasesSeq = 0;
            for (int k = 0; k < CANTIDAD_BASES; k++)
            {
                if (secLista.at(i).getBases().at(k).getCantidad() > 0)
                {
                    cantBasesSeq++;
                }
            }
            if (secLista.at(i).getIncompleta())
            {
                std::cout << "Secuencia '" << lineasDescriptivas.at(i) << "' contiene al menos " << cantBasesSeq << " bases." << std::endl;
                continue;
            }
            std::cout << "Secuencia '" << lineasDescriptivas.at(i) << "' contiene " << cantBasesSeq << " bases." << std::endl;
        }
    }
    catch (std::exception e)
    {
        std::cout << "No hay secuencias cargadas en memoria.";
    }
}

void ArchivoFASTA::subsecuencia(std::string subseq)
{
    if (secLista.size() == 0)
    {
        std::cout << "No hay secuencias cargadas" << std::endl;
        return;
    }
    else
    {
        int contApariciones = 0;

        for (int i = 0; i < secLista.size(); i++)
        {
            std::string secuencia = secLista.at(i).getSecuencia();
            //Looking for and couting number of occurrences of the given subsequence
            std::size_t found = secuencia.find(subseq);
            secuencia = secuencia.substr(found + subseq.length());
            while (found != std::string::npos)
            {
                contApariciones++;
                found = secuencia.find(subseq);
                secuencia = secuencia.substr(found + subseq.length());
            }
        }
        if (contApariciones == 0)
        {
            std::cout << "La secuencia no existe" << std::endl;
            return;
        }
        std::cout << "La sebsecuencia se repite " << contApariciones << " veces" << std::endl;
        return;
    }
    return;
}

void ArchivoFASTA::enmascarar(std::string secuencia)
{
    if (secLista.size() == 0)
    {
        std::cout << "No hay secuencias cargadas" << std::endl;
        return;
    }
    else
    {
        int contApariciones = 0;
        std::string mascara;
        for (int i = 0; i < secuencia.length(); i++)
        {
            mascara = mascara + "X";
        }
        for (int i = 0; i < secLista.size(); i++)
        {
            std::string secuenciaStr = secLista.at(i).getSecuencia();
            std::string chapuza = secuenciaStr.substr(0, mascara.length());
            //Looking for and replacing all occurrences of the given sequence
            std::size_t found = secuencia.find(secuencia);
            while (found != std::string::npos)
            {
                contApariciones++;
                secuenciaStr.replace(found, secuencia.length(), mascara);
                found = secuenciaStr.find(secuencia, (found + mascara.length()));
            }
            //fixing the error
            secuenciaStr.replace(0, mascara.length(), chapuza);
            //replacing the sequence string with the new one
            secLista.at(i).setSecuencia(secuenciaStr);
        }
        contApariciones -= secLista.size();
        if (contApariciones == 0)
        {
            std::cout << "No se enmascararon subsecuencias" << std::endl;
            return;
        }
        if (contApariciones == 1)
        {
            std::cout << "1 ecuencia ha sido enmascarada" << std::endl;
            return;
        }
        std::cout << contApariciones << " secuencias han sido enmascaradas" << std::endl;
        return;
    }
    return;
}

bool ArchivoFASTA::guardar(std::string nombreArchivo)
{
    try
    {
        std::ofstream writeFASTA(nombreArchivo);
        std::string contenidoArchivo;
        for (int i = 0; i < secLista.size(); i++)
        {
            contenidoArchivo += lineasDescriptivas.at(i) + '\n';
            contenidoArchivo += secLista.at(i).getSecuencia();
        }
        writeFASTA << contenidoArchivo;
        writeFASTA.close();
        return true;
    }
    catch (std::exception e)
    {
        std::cout << "Error guardando en " << nombreArchivo << std::endl;
        return false;
    }
}

void ArchivoFASTA::ayuda()
{
    std::cout << "cargar <archivo.fa>\tCarga un archivo FASTA." << std::endl;
    std::cout << "conteo\tCuenta las secuencias presentes en memoria." << std::endl;
    std::cout << "histograma <descripcion_secuencia>\tImprime la distribución de frecuencias para una secuencia dada." << std::endl;
    std::cout << "listar_secuencias\tLista las secuencias presentes en memoria." << std::endl;
    std::cout << "es_subsecuencia <subsecuencia>\tBusca las ocurrencias presentes en memoria de la subsecuencia dada." << std::endl;
    std::cout << "enmascarar <subsecuencia>\tBusca las ocurrencias presentes en memoria de la subsecuencia dada y las enmascara con el caracter 'X'." << std::endl;
    std::cout << "guardar <archivo.fa>\tGuarda las estructuras manipuladas en un archivo FASTA." << std::endl;
    std::cout << "codificar <nombre_archivo.fabin>\tCodifica las secuencias y sus respectivos identificadores —lineas descriptivas— cargados en memoria, y los guarda en un archivo binario de extensión .fabin." << std::endl;
    std::cout << "decodificar <nombre_archivo.fabin>\tDecodifica el contenido de un archivo binario de extensión .fabin y lo carga en memoria." << std::endl;
}

//-------------------------------------------------------------SEGUNDA ENTREGA------------------------------------------------------------------
bool sortbysec(const std::pair<char, int> &a, const std::pair<char, int> &b)
{
    return (a.second > b.second);
}

HuffmanNode *ArchivoFASTA::codificar(std::string nombreArchivoFABin)
{
    try
    {
        //String binario al que se va a concatenar cada uno de los campos binarios especificados en el formato.
        std::string stringBinario;
        //1. Codificar mediante algoritmo de Huffman
        //  a. Histograma de Bases en el archivo.
        Secuencia secuenciaTemp;                                   //Secuencia (vacía) temporal para efectuar el conteo de bases del archivo COMPLETO.
        std::vector<Base> basesMemoria = secuenciaTemp.getBases(); //Bases cargadas en memoria (archivo COMPLETO).

        for (int i = 0; i < secLista.size(); i++)
        {
            std::vector<Base> basesTemp = secLista.at(i).getBases();
            for (int j = 0; j < basesTemp.size(); j++)
                basesMemoria.at(j).setCantidad(basesMemoria.at(j).getCantidad() + basesTemp.at(j).getCantidad());
        }

        //histogramaCaracteres: vector de pares caracter - frecuencia.
        std::vector<std::pair<char, int>> histogramaCaracteres;

        for (int i = 0; i < CANTIDAD_BASES; i++)
        {
            if (basesMemoria.at(i).getCantidad() > 0)
                histogramaCaracteres.push_back(std::pair<char, int>(basesMemoria.at(i).getLetraBase(), basesMemoria.at(i).getCantidad()));
        }

        //  b. Ordenar histograma.
        std::sort(histogramaCaracteres.begin(), histogramaCaracteres.end(), sortbysec);

        //  c. Crear árbol de Huffman.
        HuffmanTree *arbol = new HuffmanTree(histogramaCaracteres);

        //  d. Crear string binario con el formato especificado en el enunciado del proyecto (que se guarda en el archivo .fabin)
        // 'n': número entero de 2 bytes que representa la cantidad de bases diferentes presentes en las secuencias cargadas en ese momento en memoria.
        int n = 0;
        //ci y fi son dos números entero de 1 y 8 bytes, respectivamente, que representan un código de la base de genoma y su frecuencia asociada
        std::string c_f = "";
        for (int i = 0; i < CANTIDAD_BASES; i++)
        {
            if (basesMemoria.at(i).getCantidad() > 0)
            {
                n++;
                //valEntero : código ASCII para el caracter
                int valEntero = int(basesMemoria.at(i).getLetraBase());
                c_f += std::bitset<8>(valEntero).to_string() + std::bitset<64>(basesMemoria.at(i).getCantidad()).to_string();
            }
        }

        std::string n_binary = std::bitset<16>(n).to_string();
        stringBinario = n_binary + c_f;

        //ns (secLista.size()) es un número entero de 4 bytes que representa la cantidad de secuencias que hay en el archivo.
        stringBinario += std::bitset<32>(secLista.size()).to_string();

        for (int i = 0; i < lineasDescriptivas.size(); i++)
        {
            //li es un número entero de 2 bytes que representa el tamaño del nombre de la i-ésima secuencia.
            stringBinario += std::bitset<16>(lineasDescriptivas.at(i).size()).to_string();
            for (int j = 0; j < lineasDescriptivas.at(i).size(); j++)
            {
                //sij es el caracter que se encuentra en la j-ésima posición del nombre de la i-ésima secuencia.
                //valEntero : código ASCII para el caracter
                int valEntero = int(lineasDescriptivas.at(i).at(j));
                stringBinario += std::bitset<8>(valEntero).to_string();
            }
        }

        for (int i = 0; i < secLista.size(); i++)
        {
            //wi un número entero de 8 bytes que representa la longitud de la i-ésima secuencia.
            stringBinario += std::bitset<64>(secLista.at(i).getSecuencia().size()).to_string();

            //xi un número entero de 2 bytes que representa la indentación de la i-ésima secuencia.
            std::string xi = std::bitset<16>(0).to_string();
            //binary_codei es la secuencia binaria que representa la i-ésima secuencia. Note que si la secuencia no es múltiplo de 8, se debe completar con los “0” necesarios.
            std::string binary_code = "";
            for (int j = 0; j < secLista.at(i).getSecuencia().size(); j++)
                binary_code += arbol->huffmanCode[secLista.at(i).getSecuencia().at(j)];

            while (binary_code.size() % 8 != 0)
                binary_code += '0';

            stringBinario += xi + binary_code;
        }

        //EL SIGUIENTE CICLO ES DE PRUEBA...
        // for(int i = 0; i < histogramaCaracteres.size(); i++){
        //     std::cout << histogramaCaracteres.at(i).first << '\t' << histogramaCaracteres.at(i).second << std::endl;
        // }

        //LA SIGUIENTE LÍNEA ES DE PRUEBA...
        //std::cout << stringBinario << std::endl;

        //2. Guardar en archivo .fabin
        nombreArchivoFABin += ".fabin";
        std::fstream writeFABin(nombreArchivoFABin, std::fstream::binary | std::fstream::out | std::fstream::trunc);

        if (writeFABin.is_open())
        {
            for (int i = 0; i < stringBinario.size(); i += 8)
            {
                std::string subString = stringBinario.substr(i, 8);
                int entero = stoi(subString, 0, 2);
                writeFABin.put(entero);
            }
            writeFABin.close();
        }

        return arbol->histoCopy.top();
    }
    catch (std::exception e)
    {
        std::cout << "No se puede guardar las secuencias cargadas en " << nombreArchivoFABin << ".fabin" << std::endl;
        return NULL;
    }
}

// Function to convert binary to decimal
int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int temp = num;
    while (temp)
    {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
}

void decode(HuffmanNode *root, int &index, std::string str, std::string &a)
{
    std::string retorno;
    if (root == nullptr)
    {
        return;
    }

    //Encontró una hoja
    if (root->leftChild == NULL && root->rightChild == NULL)
    {
        a += root->caracter;
        return;
    }

    index++;

    if (str[index] == '0')
        decode(root->leftChild, index, str, a);
    else
        decode(root->rightChild, index, str, a);
}

bool ArchivoFASTA::decodificar(std::string nombreArchivoFABin)
{
    try
    {
        //Extrayendo los datos del archivo binario...
        std::ifstream readFABin;
        readFABin.open(nombreArchivoFABin, std::ios::binary | std::ios::in);
        std::string stringBinario = "";
        std::bitset<8> buffer;
        while (readFABin.read((char *)&buffer, 1))
        {
            stringBinario = stringBinario + buffer.to_string();
        }
        readFABin.close();

        //Guardando cada campo del formato...
        //leyendo n
        int n = binaryToDecimal(stoi(stringBinario.substr(0, 16)));
        int index = 17;
        std::cout << "n = " << n << std::endl;
        //leyendo ci y fi
        std::vector<std::pair<char, int>> histogramaCaracteres;
        char ci;
        int fi;
        //ESTE FOR ESTÁ MAL: LO QUE SE TIENE QUE HACER ES BUSCAR LA CANTIDAD DE REPETICIONES PARA CADA UNA DE LAS BASES (A,C,G,T,U...) SON 16 EN TOTAL
        for (int i = 0; i < n; i++)
        {
            //Sacando ci
            ci = (char)binaryToDecimal(stoi(stringBinario.substr(index, 8)));
            index += 9;
            //Sacando fi
            fi = binaryToDecimal(stoi(stringBinario.substr(index, 64)));
            index += 65;
            histogramaCaracteres.push_back(std::pair<char, int>(ci, fi));
        }

        //LOOP DE PRUEBA...
        for (int i = 0; i < histogramaCaracteres.size(); i++)
        {
            std::cout << "Character: " << histogramaCaracteres.at(i).first << "\tFrequency: " << histogramaCaracteres.at(i).second << std::endl;
        }

        std::sort(histogramaCaracteres.begin(), histogramaCaracteres.end(), sortbysec);
        //Creando el árbol de Huffman
        HuffmanTree *arbol = new HuffmanTree(histogramaCaracteres);
        //Leyendo ns
        int ns = binaryToDecimal(stoi(stringBinario.substr(index, 32)));
        index++;

        //Siguientes dos líneas: versión de Nicolás
        std::string decoded;
        decode(arbol->histoCopy.top(), index, stringBinario, decoded);

        //Siguiente línea: versión usando el 'decodificar' que tenemos en HuffmanTree
        // std::string decoded2 = arbol->decodificar(arbol->histoCopy.top(), index, stringBinario);

        std::cout << "Secuencias decodificadas desde " << nombreArchivoFABin << " y cargadas en memoria" << std::endl;
        return true;
    }

    catch (std::exception e)
    {
        std::cout << "No se puede cargar las secuencias en  " << nombreArchivoFABin << std::endl;
        return false;
    }
}

//-------------------------------------------------------------TERCERA ENTREGA------------------------------------------------------------------
void ArchivoFASTA::armarMatrizSecuencia(std::vector<std::vector<char>> &matriz, std::string descripcion_secuencia)
{
    //Método para armar una matriz que contiene la secuencia, a partir de la descripción de la misma.
    //La matriz que se arma, se guarda en la Secuencia correspondiente, de esta manera se garantiza que cada Secuencia puede tener una matriz en la misma instancia del programa
    for (int i = 0; i < lineasDescriptivas.size(); i++)
    {
        if (lineasDescriptivas.at(i) == descripcion_secuencia)
        {
            std::string secuencia = secLista.at(i).getSecuencia();
            std::istringstream ss(secuencia);
            std::string linea;
            while (std::getline(ss, linea, '\n'))
            {
                std::vector<char> lineaMat;
                std::copy(linea.begin(), linea.end(), std::back_inserter(lineaMat));
                matriz.push_back(lineaMat);

                //Impresión de prueba...
                // for(int it = 0; it < lineaMat.size(); it++)
                //     std::cout << lineaMat.at(it);
                // std::cout << '\n';
                //std::cout << linea << std::endl;
            }
            //Se crea la matriz para (dentro de) la estructura Secuencia:
            secLista.at(i).setMatriz(matriz);
        }
    }

    int maxSize = 0;
    for (int i = 0; i < matriz.size(); i++)
    {
        if (matriz.at(i).size() > maxSize)
            maxSize = matriz.at(i).size();
    }

    for (int i = 0; i < matriz.size(); i++)
    {
        while (matriz.at(i).size() < maxSize)
            matriz.at(i).push_back(NULL);
    }

    //El siguiente ciclo es de prueba...
    // for(int i = 0; i < matriz.size(); i++){
    //     for(int j = 0; j < maxSize; j++)
    //         std::cout << matriz.at(i).at(j);
    //     std::cout << '\n';
    // }
}

void ArchivoFASTA::ruta_mas_corta(std::string descripcion_secuencia, int i, int j, int x, int y)
{
    try
    {
        std::vector<std::vector<char>> matrizSecuencia;
        armarMatrizSecuencia(matrizSecuencia, descripcion_secuencia);
    }
    catch (std::exception e)
    {
    }
}

void ArchivoFASTA::base_remota(std::string descripcion_secuencia, int i, int j)
{
    try
    {
        std::vector<std::vector<char>> matrizSecuencia;
        armarMatrizSecuencia(matrizSecuencia, descripcion_secuencia);

        // El siguiente ciclo es de prueba...
        for (int i = 0; i < matrizSecuencia.size(); i++)
        {
            for (int j = 0; j < matrizSecuencia.at(i).size(); j++)
                std::cout << matrizSecuencia.at(i).at(j);
            std::cout << '\n';
        }
    }
    catch (std::exception e)
    {
    }
}