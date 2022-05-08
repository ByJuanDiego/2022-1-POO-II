//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P7_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P7_H

#include <iostream>

template<template<class ...> class Container, typename T>
Container<T> rotate_range(Container<T>& container, int n){

    Container<T> temp;
    std::copy(container.begin(), container.end(), std::back_inserter(temp));
    int sz = std::distance(begin(temp), end(temp));

    int i=0;
    if (n > 0){
        for (auto it = std::next(temp.begin(), n); it != temp.end(); it++){
            *it = *std::next(container.begin(), i);
            i++;
        }
        for (auto it = std::begin(temp); it != std::next(temp.begin(), n); it++){
            *it = *std::next(container.begin(), i);
            i++;
        }
    }
    else {
        for (auto it = temp.begin(); it != std::next(temp.begin(), (sz+n)); it++){
            *it = *std::next(container.begin(), i-n);
            i++;
        }
        int j=0;
        for (auto it = std::next(temp.begin(), i); it != temp.end(); it++){
            *it = *std::next(container.begin(), j);
            j++;
        }
    }
    return temp;
}

#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P7_H
