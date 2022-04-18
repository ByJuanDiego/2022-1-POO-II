//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_TEMPLATES_V2022_1_P8_H
#define PROG3_UNIT2_TEMPLATES_V2022_1_P8_H

#include <vector>
using namespace std;

template<typename First>
bool are_same() {
    return true;
}

template<typename First, typename Second, typename  ... ParamPackage>
bool are_same(){
    if (std::is_same_v<First, Second>){
        if (sizeof...(ParamPackage) == 0){
            return true;
        }
        else{
            return are_same<Second, ParamPackage...>();
        }
    }
    else {
        return false;
    }
}

#endif //PROG3_UNIT2_TEMPLATES_V2022_1_P8_H
