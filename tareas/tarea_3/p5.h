//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P5_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P5_H

#include <tuple>
#include <iostream>

template <typename ... ParamPackage>
std::tuple<ParamPackage& ...> unpack(ParamPackage& ... paramPackage){
    return std::tie(paramPackage...);
}

#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P5_H
