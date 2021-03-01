//
//  Secuencia.cpp
//  ProyectoED
//
//  Created by Cristóbal Castrillón Balcázar & Nicolás Pérez Fonseca on 14/02/21.
//

#include "Secuencia.hpp"

Secuencia::Secuencia(){
    this->setSecuencia("");
}

Secuencia::Secuencia(std::string seq){
    this->setSecuencia(seq);
}

Secuencia::~Secuencia(){}

std::string Secuencia::getSecuencia(){
    return Secuencia::secuencia;
}

void Secuencia::setSecuencia(std::string secuencia){
    this->secuencia = secuencia;
}

void Secuencia::appendSecuencia(std::string linea){
    std::string a = Secuencia::getSecuencia();
    this->secuencia = a + linea;
}

void Secuencia::conteoBases(std::string secuencia){}
