//
// Created by Juan Diego Castro Padilla on 25/04/22.
//

#ifndef TAREA_3_P2_H
#define TAREA_3_P2_H

#include <vector>
#include <deque>
#include <iostream>
#include <list>
using namespace std;

template<template<typename ...> class Container, typename T>
Container<T> sum_range(Container<T>& c1, Container<T>& c2){
    Container<T> result;

    if (c1.size() == c2.size()){
        auto itr2 = c2.begin();
        for (auto itr1 = c1.begin(); itr1 != c1.end(); itr1++){
            result.push_back(*itr1 + *itr2);
            itr2++;
        }
    } else if (c1.size() > c2.size()){
        for (int i=0; i<c1.size(); i++){
            result.push_back(c1[i] + c2[i%c2.size()]);
        }
    } else{
        for (int i=0; i<c2.size(); i++){
            result.push_back(c2[i] + c1[i%c1.size()]);
        }
    }
    return result;
}


#endif //TAREA_3_P2_H
