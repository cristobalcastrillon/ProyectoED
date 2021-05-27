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
    Grafo grafoSecuencia(secuencia.size());
    for (int i = 0; i < this->matrizSecuencia.size(); i++)
    {
        for (int j = 0; j < this->matrizSecuencia.at(i).size(); j++)
        {
            bool limSup, limIzq, limDer, limInf;
            NodoGrafo temp(matrizSecuencia.at(i).at(j), i, j);
            //Límite superior de la matriz
            if(i == 0){
                limSup = true;
                temp.inf = new NodoGrafo(matrizSecuencia.at(i+1).at(j), i+1, j);
                temp.wInf = calcularPeso(i, j, i+1, j);
            }

            //Límite izquierdo de la matriz
            if(j == 0){
                limIzq = true;
                temp.der = new NodoGrafo(matrizSecuencia.at(i).at(j+1), i, j+1);
                temp.wDer = calcularPeso(i, j, i, j+1);
            }

            //Límite derecho de la matriz
            if(j == matrizSecuencia.at(i).size() - 1){
                limDer = true;
                temp.izq = new NodoGrafo(matrizSecuencia.at(i).at(j-1), i, j-1);
                temp.wIzq = calcularPeso(i, j, i, j-1);
            }

            //Límite inferior de la matriz
            if(i == matrizSecuencia.size() - 1){
                limInf = true;
                temp.sup = new NodoGrafo(matrizSecuencia.at(i-1).at(j), i-1, j);
                temp.wSup = calcularPeso(i, j, i-1, j);
            }

            if(!(limSup && limIzq && limDer && limInf)){
                temp.inf = new NodoGrafo(matrizSecuencia.at(i+1).at(j), i+1, j);
                temp.der = new NodoGrafo(matrizSecuencia.at(i).at(j+1), i, j+1);
                temp.izq = new NodoGrafo(matrizSecuencia.at(i).at(j-1), i, j-1);
                temp.sup = new NodoGrafo(matrizSecuencia.at(i-1).at(j), i-1, j);

                temp.wInf = calcularPeso(i, j, i+1, j);
                temp.wDer = calcularPeso(i, j, i, j+1);
                temp.wIzq = calcularPeso(i, j, i, j-1);
                temp.wSup = calcularPeso(i, j, i-1, j);
            }

            grafoSecuencia.listaNodos->push_back(temp);
        }
    }
}

void Secuencia::setMatriz(std::vector<std::vector<char> > matriz){
    this->matrizSecuencia = matriz;
}

std::vector<std::vector<char> >  Secuencia::getMatriz()
{
    return matrizSecuencia;
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

float Secuencia::calcularPeso(int i, int j, int x, int y){
    char a = matrizSecuencia.at(i).at(j);
    char b = matrizSecuencia.at(x).at(y);
    unsigned int r= a-b;
    return 1/1+r;
} 

void Secuencia::rutaMasCorta(int i, int j, int x, int y){
    std::cout<<"entra a ruta mas corta"<<std::endl;
    NodoGrafo ij, xy;
    for(int k = 0; k < grafoSecuencia.V; k++){
        for(int l = 0; l < grafoSecuencia.listaNodos[k].size(); l++){
            if(grafoSecuencia.listaNodos[k].at(l).posicionMatriz[0] == i && grafoSecuencia.listaNodos[k].at(l).posicionMatriz[1] == j){
                ij = grafoSecuencia.listaNodos[k].at(l);
            }
        }
    }
    for(int k = 0; k < grafoSecuencia.V; k++){
        for(int l = 0; l < grafoSecuencia.listaNodos[k].size(); l++){
            if(grafoSecuencia.listaNodos[k].at(l).posicionMatriz[0] == x && grafoSecuencia.listaNodos[k].at(l).posicionMatriz[1] == y){
                xy = grafoSecuencia.listaNodos[k].at(l);
            }
        }
    }
    std::cout<<"Llama a shortestPath"<<std::endl;
    grafoSecuencia.shortestPath(ij, xy);
}
