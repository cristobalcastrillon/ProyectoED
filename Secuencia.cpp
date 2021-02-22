//
//  Secuencia.cpp
//  ProyectoED
//
//  Created by Cristóbal Castrillón Balcázar & Nicolás Pérez Fonseca on 14/02/21.
//

#include "Secuencia.hpp"

Secuencia::Secuencia(){}

Secuencia::Secuencia(std::string seq){
    setSecuencia(seq);
}

std::string Secuencia::getSecuencia(){
    return Secuencia::secuencia;
}

void Secuencia::setSecuencia(std::string linea){
    std::string a = Secuencia::getSecuencia();
    a.append(linea);
}

void Secuencia::conteoBases(std::string secuencia){}
