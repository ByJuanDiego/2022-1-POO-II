//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_TEMPLATES_V2022_1_P9_H
#define PROG3_UNIT2_TEMPLATES_V2022_1_P9_H

#include <iostream>
using namespace std;

template<typename T, size_t sz>
void init_array(T (&arr)[sz], int initial_value = 0, int paso = 1){
    for (auto i=0; i<sz; i++){
        arr[i] = initial_value + i*paso;
    }
}

template<typename T, size_t sz>
void init_array(T (&arr)[sz], int initial_value, int sgte_al_final, int paso){
    for (auto i=0; i<sz; i++){
        arr[i] = initial_value + i*paso;
        if ((arr[i] + paso) >= sgte_al_final) {
            return;
        }
    }
}

#endif //PROG3_UNIT2_TEMPLATES_V2022_1_P9_H
