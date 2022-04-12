#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <list>

template<typename T1 = double, typename T2>
T1 f1(T2 param){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return param;
}

template<typename Param, int value = 10>
void f2(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<
        int value,
        template<typename...> class Container>
void f3(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<typename...ParamTypePackage>
void f4(ParamTypePackage...paramPackage){
    // "..." puede almacenar: (int, double, string)
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<int...ParamNoTypePackage>
void f5(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<template<typename...> class...ParamTemplatePackage>
void f6(){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

template<typename T>
void f7(T last){
    std::cout << __PRETTY_FUNCTION__ << "  ";
    // El caso base se implementa arriba del caso recursivo
    // Especialización de print1(T initial, ParamType... paramType)
    // Caso base
    std::cout << last << std::endl;
} template<typename T, typename... ParamType>
void f7(T first, ParamType... otherParams){
    std::cout << __PRETTY_FUNCTION__ << "  ";
    // Generalización de print1(T initial, ParamType... paramType)
    // Caso Recursivo
    std::cout << first << ", " << std::endl;
    f7(otherParams...);
}

template<typename... ParamNoTypePackage>
void f8(ParamNoTypePackage... ParamPackage){
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    // Una forma más limitada y compacta de implementar f7()
    // "fold expression"
    ((std::cout << ParamPackage << ", "), ...);
    std::cout << std::endl;
}

int main() {

    f1(10);
    f2<int, 1>();
    f3<1, std::vector>();
    f4(1, -3, 4.3, 4.5, std::string("Hola"));
    f5<1, 2, 3, 4, 5>();
    f6<std::vector, std::map, std::list, std::basic_string>();

    std::cout << std::endl;
    f7(1, 2, 4.5, std::string("A"));

    std::cout << std::endl;
    f8(0, -1, 3.14, std::string("B"));

    return 0;
}
