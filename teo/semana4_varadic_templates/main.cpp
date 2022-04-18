#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <list>
using namespace std;

/*
 __PRETTY_FUNCTION__ is a gcc extension.
 contains the "pretty" name of the function, including the signature of the function.
*/

template<typename T1 = double, typename T2>
T1 f1(T2 param){
    // Template con parámetros no tipo (T1 por defecto)
    cout << __PRETTY_FUNCTION__ << endl;
    //
    return param;
}

template<typename Param, int value = 10>
void f2(){
    // Template con parámetro TIPO y NO TIPO con valor por defecto
    cout << __PRETTY_FUNCTION__ << endl;
}

template<
        int value,
        template<typename...> class Container = vector>
void f3(){
    // Template con parámetro NO TIPO y template TIPO con valor por defecto
    cout << __PRETTY_FUNCTION__ << endl;
}

// "..." puede almacenar: (int, double, string)
template<typename...ParamTypePackage>
void f4(ParamTypePackage...paramPackage){
    // Package de TIPO
    cout << __PRETTY_FUNCTION__ << endl;
}

template<int...ParamNoTypePackage>
void f5(){
    // Package de NO TIPO
    cout << __PRETTY_FUNCTION__ << endl;
}

template<template<typename...> class...ParamTemplatePackage>
void f6(){
    // Package de Templates TIPO
    cout << __PRETTY_FUNCTION__ << endl;
}

template<typename T>
void print1(T last){
    // El caso base se implementa arriba del caso recursivo
    // Especialización de print1(T first, ParamType... otherParams);
    // Condición Base (Una sobrecarga del template)
    cout << last << endl;
}
template<typename T, typename... ParamType>
void print1(T first, ParamType... otherParams){
    // Generalización de print1(T first, ParamType... otherParams);
    // Condición Recursiva (Un template genérico)
    cout << first << ", ";
    print1(otherParams...);
}

template<typename... ParamNoTypePackage>
void print2(ParamNoTypePackage... ParamPackage){// Fold Expressions
    // Una forma más limitada y compacta de implementar print1()
    // ((os << param1 << ", "), (os << param2 << ", "), ...)
    ((cout << ParamPackage << ", "), ...);
    cout << std::endl;
}

template<typename ... Params>
auto suma1(Params... params){
    // (param1+(param2+(param3+...)))
    return (params+...);
}

template<typename ... Params>
auto suma2(Params... params){
    // ((((param1)+param2)+param1)+...)
    return (...+params);
}

template<typename T>
constexpr bool is_int(T param){
    return false;
}
template<>
constexpr bool is_int<int>(int param){
    return true;
}

template<template<typename...> class T>
constexpr bool is_vector(){
    return false;
}
template<>
constexpr bool is_vector<vector>(){
    return true;
}

template<
        template <typename...> class First,
        template <typename...> class... ParamTemplatePackage>
constexpr void f7() {
    // Verifica si los params son del template vector
    cout << "is_vector()?: ";
    cout << boolalpha << is_vector<First>() << endl;
    if constexpr (sizeof...(ParamTemplatePackage) > 0)
        f7<ParamTemplatePackage...>();
}

template <typename... ParamPackage>
auto size(ParamPackage... params){
    return sizeof...(params);
}

template<typename T>
T menor(T arg){
    return arg;
}
template<typename T, typename... ParamPackage>
T menor(T first, ParamPackage... args){
    T recMin = menor(args...);
    return (first < recMin)? first:recMin;
}

template<typename T>
T mayor(T arg){
    return arg;
}
template<typename T, typename... Params>
T mayor(T first, Params... args){
    T recMax = mayor(args...);
    return (first > recMax)? first:recMax;
}

template <typename... ParamPackage>
float media(ParamPackage... args){
    return suma1(args...)/(double)size(args...);
}

int main() {

    f1(10);
    f2<int, 1>();
    f3<1, list>();
    f4(1, -3, 4.3, 4.5, string("Hola"));
    f5<1, 2, 3, 4, 5>();
    f6<vector, map, list, basic_string>();
    f7<vector, map, vector, list>();

    print1(1, 2, 4.5, string("A"));
    print2(0, -1, 3.14, string("B"));

    cout << "is_int(10): " << boolalpha << (is_int(10)) << endl;
    cout << "is_int(1.0): " << boolalpha << (is_int(1.0)) << endl;
    cout << "is_int('A'): " << boolalpha << (is_int("A")) << endl;
    
    cout << "len(1,2,3) = " << size(1, 2, 3) << endl;
    cout << "min(9,1,2) = " << menor(9, 1, 2) << endl;
    cout << "max(7,9,3) = " << mayor(7, 9, 3) << endl;
    cout << "sum1(1+2+3) = " << suma1(1, 2, 3) << endl;
    cout << "sum2(4+5+6) = " << suma2(4, 5, 6) << endl;
    cout << "mean(1,9,3) = " << media(1, 9, 3) << endl;
    
    return 0;
}
