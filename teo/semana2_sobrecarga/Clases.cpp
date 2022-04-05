//
// Created by Juan Diego Castro Padilla on 29/03/22.
//

#include "Clases.h"

A::A(): value(" "){
}

A::A(string&& str): value(str){
}

A A::operator+(int op2){
    return A(value + to_string(op2));
}

ostream& operator<<(ostream& os, A& a){
    os << a.value << endl;
    return os;
}

A operator+(A& op1, A& op2){
    return A(op1.value + op2.value);
}

A operator+(int op1, A& op2){
    return A(to_string(op1) + op2.value);
}

void A::print_B(B &b) {
    cout << "B.n: " << b.n << " Clases.value: " << value;
}

B::B(int x): n(x) {
}
