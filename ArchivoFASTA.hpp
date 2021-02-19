#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class ArchivoFASTA {
    private:
    //Clase que guarda las subcadenas que componen el archivo (líneas descriptivas; secuencias).
    vector<string> lineaDescriptiva;
    vector<Secuencia> secLista;
    
    public:
    ArchivoFASTA();
    string getLineaDescriptiva(int posicionLD);
    void setLineaDescriptiva(string lineaDescriptiva);
    string getSecuencia(int posicionS);
    void setSecuencia(string cadenaSecuencia);

    bool cargarArchivo();
    void histograma();

};