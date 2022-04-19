//
// Created by Juan Diego Castro Padilla on 31/03/22.
//

#ifndef SEMANA2_RECTANGULO_H
#define SEMANA2_RECTANGULO_H

#include "Figura.h"

class Rectangulo: public Figura{
public:
    Rectangulo(int x, int y): Figura(x, y) {}
    Rectangulo(): Rectangulo(0, 0) {}
    void dibujar() override {cout << "Dibujando Rectangulo" << endl;}
};

#endif //SEMANA2_RECTANGULO_H
