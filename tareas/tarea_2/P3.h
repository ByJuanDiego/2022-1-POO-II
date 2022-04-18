//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_TEMPLATES_V2022_1_P3_H
#define PROG3_UNIT2_TEMPLATES_V2022_1_P3_H

#include <iostream>
#include <list>
using namespace std;

template<typename Iterator>
typename Iterator::value_type sumarizar(Iterator Begin, Iterator End, typename Iterator::value_type Inicializador){
    typename Iterator::value_type suma = Inicializador;
    for (auto it = Begin; it != End; it++){
        suma += (*it);
    }
    return suma;
}

#endif //PROG3_UNIT2_TEMPLATES_V2022_1_P3_H
