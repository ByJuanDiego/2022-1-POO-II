#include "funciones.h"
#include <iostream>
using namespace std;

/*
 Tipos de Template

    - Template de funciones
    - Template de clase
    - Template de variable
    - Template de alias

*/

/*
 Reglas de deduccion de parametros de Templates de funciones

    1. Solo se pueden deducir los tipos de datos en los parametros de la funcion
    2. Los parametros deducibles se escriben de derecha a izquierda

*/

template<typename T>
T f1(){// El tipo no se deduce
    return T();
}

template<typename T1, typename T2>
T2 f2(T1 a, T1 b){// La llamada a la funcion es mas larga porque no se deduce ningun tipo
    return a+b;
}

template<typename T2, typename T1>
T2 f3(T1 a, T1 b){// La llamada a la funcion es mas corta porque los operandos (T1) se deducen
    return a+b;
}

int main(){

    int var1 = f1<int>();
    int var2 = f2<int, int>(10, 20);
    int var3 = f3<int>(10, 20);

    cout << "5^3 = " << Power<5, 3>::val << endl;

    return 0;
}
