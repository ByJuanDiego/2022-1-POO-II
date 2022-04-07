//
// Created by Juan Diego Castro Padilla on 5/04/22.
//

#ifndef SEMANA3_TEMPLATES_FUNCIONES_H
#define SEMANA3_TEMPLATES_FUNCIONES_H

#include <cstring>

auto concatenar(const char* a, const char* b){
    char* result = new char[strlen(a) + strlen(b) + 1];
    strcpy(result, a);
    strcat(result, b);
    return result;
}

template <int N, int P>
struct Power{
    enum {val = N * Power<N, P-1>::val};
};
template <int N>
struct Power<N, 0>{
    enum {val = 1};
};

template <typename T, int sz>
auto get_size(const T (&arr)[sz]){// obtener el tamaño de un array
    return sz;
}

#endif //SEMANA3_TEMPLATES_FUNCIONES_H
