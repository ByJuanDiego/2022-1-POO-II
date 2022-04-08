#include <iostream>
using namespace std;

/*
 1. Programacion generica
    - Se lleva a cabo en tiempo de compilacion
    - Templates
 5. Tipos de parametro de template
    - Parametros tipo       : <typename T>
    - Parametros no tipo    : <int a, int b> (util para arreglos estaticos, muy limitado para otros usos)
    - Parametros de tamplate: <>
*/


void show(string&& nombre, string&& apellido = "Castro"){
    /*
    void show2(string&& nombre = "Juan", string&& apellido);
    no funciona porque los parametros por defecto se quitan de izquierda a derecha
    */
    cout << nombre << " " << apellido << endl;
}

template <typename T>
T sumar(T o1, T o2){
    return o1 + o2;
}

template<typename T>
T restar(int a, int b){
    return a+b;
}

template<typename T1 = double, typename T2, typename T3>
T1 multiplicar(T2 a, T3 b){
    // T1 por defecto es double
    return a*b;
}

template<typename T>
auto adicionar(T var1, T var2){
    return var1 + var2;
}

template<typename T>
auto adicionar(T* ptr1, T* ptr2){ // Especializacion de "adicionar(T var1, T var2);"
    return (*ptr1) + (*ptr2);
}

auto adicionar(const char* str1, const char* str2){
    return string(str1) + string(str2);
}

void f1(int a, int b){
    cout << "a: " << a << " b: " << b << endl;
}

template<int a, int b>
void f2(){
    cout << "a: " << a << " b: " << b << endl;
}

int main() {

    show("Juan");

    cout << sumar(1, 2) << endl;
    cout << sumar<double>(static_cast<int>(1.4), 2.3) << endl;

    cout << restar<int>(1, 1) << endl;

    cout << multiplicar<int>(1, 3) << endl;

    auto x = multiplicar(3, 2.3);
    cout << x << endl;

    int n1 = 1, n2 = 3;
    cout << adicionar(n1, n2) << endl;
    cout << adicionar(&n1, &n2) << endl;
    cout << adicionar("Hola", " Mundo") << endl;

    f1(10, 20);
    f2<10, 20>();

    /*
    int a=10, b=20;
    f1(a, b);    // funciona
    f2<a, b>();  // no funciona, (a) y (b) no existen en tiempo de compilacion.
    */

    return 0;
}
