#include <iostream>
#include <cstring>
#include <array>
#include <vector>
#include <list>
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

template <typename T, int sz>
auto get_size(const T (&)[sz]){// obtener el tamaño de un array estatico
    return sz;
}

template<typename T, size_t sz>
int get_size(array<T, sz>){// obtener el tamaño de un array
    return sz;
}

template <template<typename...> class Container, typename T>
void push(Container<T>& contenedor, T value){// obtener el tamaño de un array
    contenedor.push_back(value);
}

template<int N>
constexpr int factorial(){
    return N * factorial<N-1>();
}
template<>
constexpr int factorial<0>(){
    return 1;
}

int main() {

    show("Juan");

    cout << "1 + 2 = " << sumar(1, 2) << endl;
    cout << "1.5 + 2.5  = " << sumar<double>(1.5, 2.5) << endl;
    cout << "1 - 1 = " << restar<int>(1, 1) << endl;

    cout << "(int) (1.5 * 2.5) = " << multiplicar<int>(1.5, 2.5) << endl; // retorna un int aunque se deduzcan sus operandos como double
    cout << "1.5 * 2.5 = " << multiplicar(1.5, 2.5) << endl;      // retorna un double por defecto

    int n1 = 2, n2 = 5;
    cout << "n1 + n2 = " << adicionar(n1, n2) << endl;
    cout << "*n1 + *n2 = " << adicionar(&n1, &n2) << endl;
    cout << "str1 + str2 = " <<  adicionar("Hola", " Mundo") << endl;
    cout << "char1* + char2* = " << concatenar("Hola", " Mundo") << endl;

    f(10, 20);
    f<10, 20>();

    /*
    int a = 10, b = 20;
    f(a, b);    // funciona
    f<a, b>();  // no funciona, (a) y (b) no existen en tiempo de compilacion.
    */

    int arr1[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 2> arr2 {0, 1};

    cout << "arr[10] = " << get_size(arr1) << endl;
    cout << "array<int, 2> arr2 = " << get_size(arr2) << endl;

    std::vector<int> vec;
    vec.push_back(1);
    push<vector>(vec, 2);
    push<vector>(vec, 3);
    for (const auto &i: vec){
        cout << i << " ";
    }
    cout << endl;

    std::list<double> lst;
    lst.push_back(1.1);
    push<list>(lst, 2.2);
    push<list>(lst, 3.3);
    for (const auto &i: lst){
        cout << i << " ";
    }
    cout << endl;

    cout << "5! = " << factorial<5>() << endl;

    return 0;
}
