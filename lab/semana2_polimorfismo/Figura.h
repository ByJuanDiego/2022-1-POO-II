//
// Created by Juan Diego Castro Padilla on 31/03/22.
//

#ifndef SEMANA2_FIGURA_H
#define SEMANA2_FIGURA_H

#include <string>
#include <iostream>
using namespace std;

class Figura {
protected:
    int x {0};
    int y {0};
public:
    // virtual void dibujar() {} // ocupa memoria de forma innecesaria si se declara de esta forma
    virtual void dibujar() = 0;

    Figura() = default;
    Figura(int x, int y): x(x), y(y) {}

    int get_x() const {return x;}
    int get_y() const {return y;}
    void set_x(int value_x){x = value_x;}
    void set_y(int value_y){y = value_y;}

};


#endif //SEMANA2_FIGURA_H
