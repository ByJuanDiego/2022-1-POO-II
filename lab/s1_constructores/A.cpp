//
// Created by Juan Diego Castro Padilla on 25/03/22.
//

#include "A.h"

namespace utec {

    A::A() {// por defecto
        this->ptrValue = new int(); // -> lo inicializa con 0 por defecto

        cout << "defecto" << endl;
    }

    A::A(const A &another) {// copia
        this->ptrValue = new int(*(another.ptrValue));

        cout << "copia" << endl;
    }

    A& A::operator=(const A &another) {// asignacion - copia
        if (&another == this){
            return *this;
        }

        delete ptrValue;
        ptrValue = new int(*(another.ptrValue));

        cout << "asignacion - copia " << endl;
        return *this;
    }

    A::A(A &&another) {// move
        ptrValue = another.ptrValue;
        another.ptrValue = nullptr;

        cout << "move" << endl;
    }

    A &A::operator=(A &&another) {// asignacion - move
        delete ptrValue;
        ptrValue = another.ptrValue;
        another.ptrValue = nullptr;

        cout << "asignacion - move" << endl;
        return *this;
    }

    int A::get_value() {
        return *ptrValue;
    }

    A::A(int value) {// por parametro
        this->ptrValue = new int(value);

        cout << "por parametro" << endl;
    }

    A::~A() {// destructor
        delete ptrValue;

        cout << "destructor" << endl;
    }

}