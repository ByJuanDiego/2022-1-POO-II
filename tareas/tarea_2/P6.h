//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_TEMPLATES_V2022_1_P6_H
#define PROG3_UNIT2_TEMPLATES_V2022_1_P6_H

#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename First, typename ... ParamPackage, typename T>
int index_of(T value, int index = 0){
    if (std::is_same_v<First, T>){
        return index;
    }
    else {
        if constexpr((sizeof ... (ParamPackage)) == 0) {
            return -1;
        } else {
            return index_of<ParamPackage...>(value, ++index);
        }
    }
}

#endif //PROG3_UNIT2_TEMPLATES_V2022_1_P6_H
