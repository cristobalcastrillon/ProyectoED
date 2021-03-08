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
    char letraBase;
    for(int i = 0; i < CANTIDAD_BASES; i++){
        bases_seq.push_back(baseTemp);
        switch(i){
            case 0: letraBase = 'A';
            case 1: letraBase = 'C';
            case 2: letraBase = 'G';
            case 3: letraBase = 'T';
            case 4: letraBase = 'U';
            case 5: letraBase = 'R';
            case 6: letraBase = 'Y';
            case 7: letraBase = 'K';
            case 8: letraBase = 'M';
            case 9: letraBase = 'S';
            case 10: letraBase = 'W';
            case 11: letraBase = 'B';
            case 12: letraBase = 'D';
            case 13: letraBase = 'H';
            case 14: letraBase = 'V';
            case 15: letraBase = 'N';
        }
        bases_seq.at(i).setLetraBase(letraBase);
    }
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
