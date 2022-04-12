#include <iostream>
#include <vector>

template<typename T>
void print1(T final){// El caso base se implementa arriba del caso recursivo
    // Especialización de print1(T initial, ParamType... paramType)
    // Caso base
    std::cout <<  final << std::endl;
}
template<typename T, typename ...ParamType>
void print1(T initial, ParamType... paramType){
    // Generalización de print1(T initial, ParamType... paramType)
    // Caso Recursivo
    std::cout << initial << ", ";
    print1(paramType...);
}

template<typename... ParamType>
void print2(ParamType... paramType){
    // Una forma más limitada de implementar print1()
    ((std::cout << paramType << ", "), ...);
    std::cout << std::endl;
}

int main() {
    print1(1, 2, 3);
    print2(1, 2, 3);
    return 0;
}
