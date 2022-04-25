//
// Created by Juan Diego Castro Padilla on 25/04/22.
//

#ifndef TAREA_3_P1_H
#define TAREA_3_P1_H

#include <vector>
#include <deque>
#include <iostream>
using namespace std;

template<template<typename ...> class Return = std::vector, template<typename ...> class Container, typename T>
Return<Container<T>> split_range(Container<T>& container, std::size_t n){
}

//    Return<Container<T>> temp;
//    auto len = container.size()/n;
//
//    if (n * (len) < container.size()){
//        std::size_t i=0;
//        for (; i<n-1; i++){
//            Container<T> cont;
//            for (auto j=0; j < len; j++){
//                cont.push_back(container.at(i*len +j));
//            }
//            temp.push_back(cont);
//        }
//
//        Container<T> last;
//        for (auto j=i*len; j<container.size(); j++){
//            last.push_back(container.at(j));
//        }
//        temp.push_back(last);
//
//    }
//    else{
//        for (std::size_t i=0; i<n; i++){
//            Container<T> cont;
//            for (int j=0; j < len; j++){
//                cont.push_back(container.at(i*len +j));
//            }
//            temp.push_back(cont);
//        }
//    }
//
//    return temp;



#endif //TAREA_3_P1_H
