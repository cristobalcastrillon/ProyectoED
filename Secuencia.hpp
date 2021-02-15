//
//  Secuencia.hpp
//  ProyectoED
//
//  Created by Cristóbal Castrillón Balcázar on 14/02/21.
//

#ifndef Secuencia_hpp
#define Secuencia_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Base.hpp"

class Secuencia {
//Clase que define a una secuencia.
private:
    std::string secuencia;
    std::vector<Base> bases_seq;
public:
    //Cada uno de los constructores debe garantizar que se cree una lista de las bases existentes (A,G,C,T,U).
    Secuencia();
    Secuencia(std::string seq);
    std::string getSecuencia();
    //setSecuencia recibe una sección de la secuencia, correspondiente a la línea que se está leyendo del archivo FASTA.
    void setSecuencia(std::string linea);
    
    //Método que cuenta la frecuencia (cantidad de veces que aparece en la secuencia) de cada base.
    void conteoBases(std::string secuencia);
};

#endif /* Secuencia_hpp */
