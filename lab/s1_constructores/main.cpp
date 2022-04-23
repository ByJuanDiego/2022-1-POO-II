//
// Created by Juan Diego Castro Padilla on 24/03/22.
//

#include "A.h"

void mostrar1(int& n){// lvalue
    cout << n << endl;
}

void mostrar2(int&& n){// rvalue
    n++;
    cout << n << endl;
}

utec::A fabrica_objeto_A(){
    utec::A temp(0);
    return temp;
}

int main() {

    utec::A a;
    utec::A b;
    utec::A c(a);
    b = c;
    a = fabrica_objeto_A();
    utec::A d = std::move(a);

    // cout << a.get_value() << endl; // --> error porque la variable a ha sido movida

    utec::A e(10);
    // utec::A f = 10;

    cout << b.get_value() << endl;
    cout << c.get_value() << endl;
    cout << d.get_value() << endl;
    cout << e.get_value() << endl;
    // cout << f.get_value() << endl;

    // mostrar1(1); // --> error porque la variable no existe
    // mostrar2(1);

    return 0;

}
