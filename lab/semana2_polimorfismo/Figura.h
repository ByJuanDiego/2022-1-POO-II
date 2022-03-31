//
// Created by Juan Diego Castro Padilla on 31/03/22.
//

#ifndef SEMANA2_FIGURA_H
#define SEMANA2_FIGURA_H

#include <string>
#include <iostream>
using namespace std;

class Figura {
public:
    // virtual void dibujar() {} // ocupa memoria de forma innecesaria si se declara de esta forma
    virtual void dibujar() = 0;
};


#endif //SEMANA2_FIGURA_H
