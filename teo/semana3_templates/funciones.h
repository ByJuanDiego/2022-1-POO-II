//
// Created by Juan Diego Castro Padilla on 5/04/22.
//

#ifndef SEMANA3_TEMPLATES_FUNCIONES_H
#define SEMANA3_TEMPLATES_FUNCIONES_H

template <int N, int P>
struct Power{
    enum {val = N * Power<N, P-1>::val};
};
template <int N>
struct Power<N, 0>{
    enum {val = 1};
};



#endif //SEMANA3_TEMPLATES_FUNCIONES_H
