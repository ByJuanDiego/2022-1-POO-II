//
// Created by Juan Diego Castro Padilla on 29/03/22.
//

#ifndef SEMANA2_CLASES_H
#define SEMANA2_CLASES_H

#include <iostream>
#include <string>

using namespace std;

/*
  Sobrecarga de Operadores como funcion
  Sobrecarga de Operadores como metodo
*/

class B;

class A {
    friend ostream& operator<<(ostream& os, A& a);
    friend A operator+(A& op1, A& op2);     // sobrecarga como funcion (Clases + Clases)
    friend A operator+(int op1, A& op2);    // sobrecarga como funcion (int + Clases)

private:
    string value;
public:
    A();
    explicit A(string&& str);
    A operator+(int op2);                   // sobrecarga como metodo (Clases + int)
    void print_B(B& b);

};

class B {
private:
    int n {};
public:
    explicit B(int x);
    friend void A::print_B(B& b);           // amistad con un solo metodo de otra clase
};

A operator+(A& op1, A& op2);
A operator+(int op1, A& op2);
ostream& operator<<(ostream& os, A& a);

#endif //SEMANA2_CLASES_H
