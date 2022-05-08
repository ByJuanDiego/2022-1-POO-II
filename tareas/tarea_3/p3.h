//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P3_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P3_H

#include <initializer_list>


template<template<typename ...> typename Container, typename T>
Container<T> delete_range(const Container<T>& cont, T value){
    Container<T> temp;

    for (const auto &i: cont){
        if (i != value){
            temp.push_back(i);
        }
    }

    return temp;
}

template<template<typename ...> typename Container, typename T>
Container<T> delete_range(const Container<T>& cont, const std::initializer_list<T> initializerList){
    Container<T> temp = cont;

    for (const auto &i: initializerList){
        if (std::find(temp.begin(), temp.end(), i) != std::end(cont)){
            temp.erase(
                std::remove(temp.begin(), temp.end(), i),
                temp.end()
            );
        }
    }

    return temp;
}

#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P3_H
