//
// Created by Juan Diego Castro Padilla on 25/03/22.
//

#ifndef SEMANA1_A_H
#define SEMANA1_A_H

#include <iostream>
using namespace std;

namespace utec {
    class A {

    private:
        int *ptrValue = nullptr;

    public:

        // Convertible
        A();                                // constructor por defecto
        explicit A(int value);                       // constructor por parametros - convertible

        // Copia
        A(const A &another);                // constructor copia
        A& operator=(const A &another);    // constructor asignacion - copia

        // Move
        A(A &&another);                     // constructor move
        A &operator=(A &&another);          // constructor asignacion - move


        // Destructor
        ~A();

        int get_value();

    };
}

#endif //SEMANA1_A_H
