//
//  Base.cpp
//  ProyectoED
//
//  Created by Cristóbal Castrillón Balcázar on 14/02/21.
//

#include "Base.hpp"

Base::Base(){
    setCantidad(0);
}

Base::Base(char letra){
    setLetraBase(letra);
}

char Base::getLetraBase(){
    return letraBase;
}

int Base::getCantidad(){
    return cantidad;
}

void Base::setLetraBase(char b){
    letraBase = b;
}

void Base::setCantidad(int q){
    cantidad = q;
}
