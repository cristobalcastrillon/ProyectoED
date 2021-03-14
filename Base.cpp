//
//  Base.cpp
//  ProyectoED
//
//  Created by Cristóbal Castrillón Balcázar on 14/02/21.
//

#include "Base.hpp"

Base::Base(){}

Base::Base(char letra, int q){
    setLetraBase(letra);
    setCantidad(q);
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
