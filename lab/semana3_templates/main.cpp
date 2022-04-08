#include <iostream>
#include <cstring>
using namespace std;

/*
 1. Programacion generica
    - Se lleva a cabo en tiempo de compilacion
    - Templates

 2. Templates
    - Funciones
    - Clase
    - Variables
        T a = valor;
    - Alias
        using TYPE = int
        typedef int TYPE;

 3. Templates de funciones
    - Los tipos de parametros de Template se pueden deducir

 4.
    - Las variables se clasifican en tipos (int, double, string)
    - Los tipos se clasifican en conceptos

      +---------------------------+-----------------------------+
      |     template generico     |     template especifico     |
      ----------------------------+------------------------------
      | adicionar(T var1, T var2) | adicionar(T* ptr1, T* ptr2) |
      +---------------------------+-----------------------------+

 5. Tipos de parametro de template
    - Parametros TIPO       : <typename T>
    - Parametros NO-TIPO    : <int a, int b> (util para arreglos estaticos, muy limitado para otros usos)
    - Parametros TEMPLATE   : <>
*/

/*
 Reglas de deduccion de parametros de Templates de funciones

    1. Solo se pueden deducir los tipos de datos en los parametros de la funcion
    2. Los parametros deducibles se escriben de derecha a izquierda
    3. La deduccion se detiene al momento de encontrar un parametro no deducible

*/

void show(string&& nombre, string&& apellido = "Castro"){
    /*
    void show(string&& nombre = "Juan", string&& apellido);
    no funciona porque los parametros por defecto se quitan de izquierda a derecha
    */
    cout << nombre << " " << apellido << endl;
}

template <typename T>
T sumar(T o1, T o2){
    return o1+o2;
}

template<typename T>
T restar(int a, int b){
    return a-b;
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
auto adicionar(T* ptr1, T* ptr2){
    // Especializacion de "adicionar(T var1, T var2);"
    return (*ptr1) + (*ptr2);
}

auto adicionar(const char* str1, const char* str2){
    return (string(str1) + string(str2));
}

auto concatenar(const char* src1, const char* src2){
    char* result = new char[strlen(src1) + strlen(src2) + 1];
    strcpy(result, src1);
    return strcat(result, src2);
}

void f(int a, int b){
    cout << "a: " << a << " b: " << b << endl;
}

template<int a, int b>
void f(){
    cout << "a: " << a << " b: " << b << endl;
}

int main() {

    show("Juan");

    cout << sumar(1, 2) << endl;
    cout << sumar<double>(1.5, 2.5) << endl;
    cout << restar<int>(1, 1) << endl;

    cout << multiplicar<int>(1.5, 2.5) << endl; // retorna un int aunque se deduzcan sus operandos como double
    cout << multiplicar(1.5, 2.5) << endl;      // retorna un double por defecto

    int n1 = 1, n2 = 3;
    cout << adicionar(n1, n2) << endl;
    cout << adicionar(&n1, &n2) << endl;
    cout << adicionar("Hola", " Mundo") << endl;
    cout << concatenar("Hola", " Mundo") << endl;

    f(10, 20);
    f<10, 20>();

    /*
    int a = 10, b = 20;
    f1(a, b);    // funciona
    f2<a, b>();  // no funciona, (a) y (b) no existen en tiempo de compilacion.
    */

    return 0;
}
