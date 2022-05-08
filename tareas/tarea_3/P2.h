//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P2_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P2_H

#include <vector>
#include <list>
using namespace std;

template<template<typename ...> class Container, typename T>
Container<T> sum_range(Container<T>& cont1, Container<T>& cont2){
    auto n = std::max(distance(cont1.begin(), cont1.end()), distance(cont2.begin(), cont2.end()));
    Container<T> temp(n);

    auto it1 = cont1.cbegin();
    auto it2 = cont2.cbegin();

    for (typename Container<T>::iterator it = temp.begin(); it != temp.end(); it++){
        *it = ((*it1) + (*it2));
        it1++;
        it2++;
        if (it1 == cont1.end()){
            it1 = cont1.cbegin();
        } else if(it2 == cont2.end()){
            it2 = cont2.cbegin();
        }
    }

    return temp;
}

#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P2_H
