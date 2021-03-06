//
//  Secuencia.hpp
//  ProyectoED
//
//  Created by Cristóbal Castrillón Balcázar & Nicolás Pérez Fonseca on 14/02/21.
//

#ifndef Secuencia_hpp
#define Secuencia_hpp

#define CANTIDAD_BASES 16

#include "Base.hpp"
#include "Grafo.hpp"

struct Secuencia {
//Clase que define a una secuencia.
private:
    std::string secuencia;
    std::vector<Base> bases_seq;
    bool incompleta;
    std::vector<std::vector<char> > matrizSecuencia;
    Grafo grafoSecuencia;

public:
    //Cada uno de los constructores debe garantizar que se cree una lista de las bases existentes (A,G,C,T,U).
    Secuencia();
    Secuencia(std::string seq);
    ~Secuencia();
    std::string getSecuencia();
    void setSecuencia(std::string secuencia);
    //appendSecuencia recibe una sección de la secuencia, correspondiente a la línea que se está leyendo del archivo FASTA.
    void appendSecuencia(std::string linea);
    std::vector<Base> getBases();
    void setBases(std::vector<Base> secuenciaBases);
    void setIncompleta(bool iC);
    bool getIncompleta();
    void construirGrafo();
    void setMatriz(std::vector<std::vector<char> > matriz);
    
    //Método que cuenta la frecuencia (cantidad de veces que aparece en la secuencia) de cada base.
    void conteoBases();    
};

#endif /* Secuencia_hpp */
