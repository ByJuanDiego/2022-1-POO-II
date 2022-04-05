#include "Clases.h"
#include "Persona.h"

int main() {// La sobrecarga de operadores es un tipo de polimorfismo [ad-hoc]

    // Tipos de operadores: según número de operadores
    // - unarios
    // - binarios
    // - terciarios

    A a1("juan");
    A a2 = (a1 + 10), a3 = (20 + a1);
    A a4("Hola"), a5(" Mundo");
    A a6(a4 + a5);
    cout << a1;
    cout << a2;
    cout << a3;
    cout << a4;
    cout << a5;
    cout << a6;

    Persona p1;
    p1.set_nombre("Juan");
    p1.set_dni("12345");
    cout << p1.get_nombre() << " " << p1.get_dni() << endl;

    const Persona p2 ("Maria", "23456");
    cout << p2.get_nombre() << " " << p2.get_dni() << endl;

    cout << Persona::get_clase() << endl;
    cout << Persona::sumar(10, 20) << endl;

    B b(1);
    a1.print_B(b);

    return 0;
}
