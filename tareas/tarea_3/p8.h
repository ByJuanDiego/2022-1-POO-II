//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P8_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P8_H

#include <string>
#include <fstream>
#include <iterator>
#include <vector>
#include <forward_list>
#include <deque>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

template<template<class ...> class Container = std::vector>
Container<std::string> filter_codes(const std::string& ruta, char caracter){
    std::ifstream InputFile(ruta);
    Container<std::string> temp;

    auto starts_with (
        [=](std::string str){
            return str[0] == caracter;
        }
    );

    copy_if(
            std::istream_iterator<std::string>(InputFile),
            std::istream_iterator<std::string>(),
            std::back_inserter(temp),
            starts_with);

    sort(temp.begin(), temp.end(), less<>());
    return temp;
}

#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P8_H
