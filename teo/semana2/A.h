//
// Created by Juan Diego Castro Padilla on 29/03/22.
//

#ifndef SEMANA2_A_H
#define SEMANA2_A_H

#include <iostream>
#include <string>

using namespace std;

/*
  Sobrecarga de Operadores como funcion
  Sobrecarga de Operadores como metodo
*/


class A {
    friend ostream& operator<<(ostream& os, A& a);
    friend A operator+(A& op1, A& op2);
    friend A operator+(int op1, A& op2);
private:
    string value;
public:
    A();
    explicit A(string&& str);
    A operator+(int op2);
};

A operator+(A& op1, A& op2);
A operator+(int op1, A& op2);
ostream& operator<<(ostream& os, A& a);

#endif //SEMANA2_A_H
