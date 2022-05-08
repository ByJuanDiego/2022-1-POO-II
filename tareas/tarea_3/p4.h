//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P4_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P4_H

#include <iostream>

template<template<typename ...> class Container, typename T>
Container<T> delete_duplicated(const Container<T>& cont){
    Container<T> temp;

    for (const auto &i: cont){
        if (std::find(temp.begin(), temp.end(), i) == temp.end()){
            temp.push_back(i);
        }
    }

    return temp;
}

#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P4_H
