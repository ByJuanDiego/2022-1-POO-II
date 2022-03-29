#include "A.h"

int main() {
    
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

    return 0;
}
