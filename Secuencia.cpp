//
//  Secuencia.cpp
//  ProyectoED
//
//  Created by Cristóbal Castrillón Balcázar & Nicolás Pérez Fonseca on 14/02/21.
//
#include <iostream>
#include "Secuencia.hpp"

Secuencia::Secuencia(){
    setSecuencia("");
    Base baseTemp;
    char letraBase;
    for(int i = 0; i < CANTIDAD_BASES; i++){
        switch(i){
            case 0: 
            letraBase = 'A';
            break;
            case 1: 
            letraBase = 'C';
            break;
            case 2: 
            letraBase = 'G';
            break;
            case 3: 
            letraBase = 'T';
            break;
            case 4: 
            letraBase = 'U';
            break;
            case 5: 
            letraBase = 'R';
            break;
            case 6: 
            letraBase = 'Y';
            break;
            case 7: 
            letraBase = 'K';
            break;
            case 8: 
            letraBase = 'M';
            break;
            case 9: 
            letraBase = 'S';
            break;
            case 10: 
            letraBase = 'W';
            break;
            case 11: 
            letraBase = 'B';
            break;
            case 12: 
            letraBase = 'D';
            break;
            case 13: 
            letraBase = 'H';
            break;
            case 14: 
            letraBase = 'V';
            break;
            case 15: 
            letraBase = 'N';
            break;
        }
        baseTemp.setLetraBase(letraBase);
        baseTemp.setCantidad(0);
        bases_seq.push_back(baseTemp);
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

void Secuencia::setBases(std::vector<Base> secuenciaBases){
    bases_seq = secuenciaBases;
}

void Secuencia::setIncompleta(bool iC){
    incompleta = iC;
}

bool Secuencia::getIncompleta(){
    return incompleta;
}

void Secuencia::construirGrafo(){
    for (int i = 0; i < this->matrizSecuencia.size(); i++)
    {
        for (int j = 0; j < this->matrizSecuencia.at(i).size(); j++)
        {
            if (i - 1 != 0)
                //superior
                this->grafoSecuencia.insertarArista(this->matrizSecuencia.at(i).at(j), this->matrizSecuencia.at(i - 1).at(j));
            if (i + 1 != this->matrizSecuencia.size())
                //inferior
                this->grafoSecuencia.insertarArista(this->matrizSecuencia.at(i).at(j), this->matrizSecuencia.at(i + 1).at(j));
            if (j != this->matrizSecuencia.at(i).size())
                //izquierdo
                this->grafoSecuencia.insertarArista(this->matrizSecuencia.at(i).at(j), this->matrizSecuencia.at(i).at(j + 1));
            if (j - 1 != 0)
                //derecho
                this->grafoSecuencia.insertarArista(this->matrizSecuencia.at(i).at(j), this->matrizSecuencia.at(i).at(j - 1));
        }
    }
}

void Secuencia::setMatriz(std::vector<std::vector<char> > matriz){
    this->matrizSecuencia = matriz;
}

void Secuencia::conteoBases(){
    std::string secuencia = this->getSecuencia();
    std::vector<Base> secuenciaBases = this->getBases();
    char baseTemp;
    for(int j = 0; j < secuencia.length(); j++){
        baseTemp = secuencia.at(j);
        for(int k = 0; k < CANTIDAD_BASES; k++){
            char base = secuenciaBases.at(k).getLetraBase();
            if(baseTemp == base){
                int cantDeBase = secuenciaBases.at(k).getCantidad();
                secuenciaBases.at(k).setCantidad(cantDeBase+1);
                this->setBases(secuenciaBases);
                break; //Break out of the loop.
            }
            if(baseTemp == '-'){
                setIncompleta(true);
            }
        }
    }
}
