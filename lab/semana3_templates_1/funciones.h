//
// Created by Juan Diego Castro Padilla on 8/04/22.
//

#ifndef SEMANA3_TEMPLATES_FUNCIONES_H
#define SEMANA3_TEMPLATES_FUNCIONES_H

template<int N> constexpr int factorial(){
    return N * factorial<N-1>();
}

template<> constexpr int factorial<0>(){
    return 1;
};

#endif //SEMANA3_TEMPLATES_FUNCIONES_H
