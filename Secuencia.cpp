//
//  Secuencia.cpp
//  ProyectoED
//
//  Created by Cristóbal Castrillón Balcázar & Nicolás Pérez Fonseca on 14/02/21.
//

#include "Secuencia.hpp"

Secuencia::Secuencia(){
    this->setSecuencia("");
    Base baseTemp;
    for(int i = 0; i < 16; i++){
        bases_seq.push_back(baseTemp);
    }
    bases_seq.at(0).setLetraBase('A');
    bases_seq.at(1).setLetraBase('C');
    bases_seq.at(2).setLetraBase('G');
    bases_seq.at(3).setLetraBase('T');
    bases_seq.at(4).setLetraBase('U');
    bases_seq.at(5).setLetraBase('R');
    bases_seq.at(6).setLetraBase('Y');
    bases_seq.at(7).setLetraBase('K');
    bases_seq.at(8).setLetraBase('M');
    bases_seq.at(9).setLetraBase('S');
    bases_seq.at(10).setLetraBase('W');
    bases_seq.at(11).setLetraBase('B');
    bases_seq.at(12).setLetraBase('D');
    bases_seq.at(13).setLetraBase('H');
    bases_seq.at(14).setLetraBase('V');
    bases_seq.at(15).setLetraBase('N');
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

std::vector<Base> Secuencia::getBases(){
    return bases_seq;
}

void Secuencia::conteoBases(std::string secuencia){}
