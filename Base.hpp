//
//  Base.hpp
//  ProyectoED
//
//  Created by Cristóbal Castrillón Balcázar on 14/02/21.
//

#ifndef Base_hpp
#define Base_hpp

#include <string>
#include <vector>
#include <stdio.h>

struct Base {
//Clase utilizada para crear el vector de pares Base - Cantidad, útil para imprimir un _histograma_.
private:
    char letraBase;
    int cantidad; //Por defecto es igual a 0.
public:
    Base();
    Base(char letra, int q);
    char getLetraBase();
    int getCantidad();
    void setLetraBase(char b);
    void setCantidad(int q);
};

#endif /* Base_hpp */
