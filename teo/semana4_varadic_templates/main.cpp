#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <list>
using namespace std;

template<typename T1 = double, typename T2>
T1 f1(T2 param){
    cout << __PRETTY_FUNCTION__ << endl;
    return param;
}

template<typename Param, int value = 10>
void f2(){
    cout << __PRETTY_FUNCTION__ << endl;
}

template<
        int value,
        template<typename...> class Container>
void f3(){
    cout << __PRETTY_FUNCTION__ << endl;
}

template<typename...ParamTypePackage>
void f4(ParamTypePackage...paramPackage){
    // "..." puede almacenar: (int, double, string)
    cout << __PRETTY_FUNCTION__ << endl;
}

template<int...ParamNoTypePackage>
void f5(){
    cout << __PRETTY_FUNCTION__ << endl;
}

template<template<typename...> class...ParamTemplatePackage>
void f6(){
    cout << __PRETTY_FUNCTION__ << endl;
}

template<typename T>
void f7(T last){
    cout << __PRETTY_FUNCTION__ << "  ";
    // El caso base se implementa arriba del caso recursivo
    // Especialización de f7(T first, ParamType... otherParams);
    // Caso base
    cout << last << endl;
} template<typename T, typename... ParamType>
void f7(T first, ParamType... otherParams){
    cout << __PRETTY_FUNCTION__ << "  ";
    // Generalización de f7(T first, ParamType... otherParams);
    // Caso Recursivo
    cout << first << ", " << endl;
    f7(otherParams...);
}

template<typename... ParamNoTypePackage>
void f8(ParamNoTypePackage... ParamPackage){// Fold Expressions
    cout << __PRETTY_FUNCTION__ << "  ";
    // Una forma más limitada y compacta de implementar f7()
    // ((os << param1 << ", "), (os << param2 << ", "), ...)
    ((cout << ParamPackage << ", "), ...);
    cout << std::endl;
}

template<typename ... Params>
auto f9(Params... params){
    // (param1+(param2+(param3+...)))
    return (params+...);
}

template<typename ... Params>
auto f10(Params... params){
    // (((...+param3)+param2)+param1)
    return (...+params);
}

template<typename T>
constexpr bool is_int(){
    return false;
} template<> constexpr bool is_int<int>(){
    return true;
}

template<template<typename...> class T>
constexpr bool is_vector(){
    return false;
} template<> constexpr bool is_vector<vector>(){
    return true;
}

template<
        template <typename...> class First,
        template <typename...> class... ParamTemplatePackage>
constexpr void f11() {
    // Verifica si los params son del template vector
    cout << __PRETTY_FUNCTION__ << "  ";
    cout << boolalpha << is_vector<First>() << endl;
    if constexpr (sizeof...(ParamTemplatePackage) > 0)
        f11<ParamTemplatePackage...>();
    else
        cout << endl;
}


int main() {

    f1(10);
    f2<int, 1>();
    f3<1, vector>();
    f4(1, -3, 4.3, 4.5, string("Hola"));
    f5<1, 2, 3, 4, 5>();
    f6<vector, map, list, basic_string>();

    cout << endl;
    f7(1, 2, 4.5, string("A"));
    cout << endl;
    f8(0, -1, 3.14, string("B"));
    cout << endl;

    auto suma1 = f9(1, 2, 3, 4);
    auto suma2 = f10(5, 6, 7, 8);
    cout << "1+2+3+4 = " << suma1 << endl;
    cout << "5+6+7+8 = " << suma2 << endl;

    cout << "is_int(int): " << boolalpha << (is_int<int>()) << endl;
    cout << "is_int(bool): " << boolalpha << (is_int<bool>()) << endl;

    cout << endl;
    f11<vector, map, vector, list>();
    return 0;
}
