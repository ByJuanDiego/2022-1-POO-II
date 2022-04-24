//
// Created by Juan Diego Castro Padilla on 24/04/22.
//

#ifndef S5_STL_CONTENEDORES_FUNCTIONS_H
#define S5_STL_CONTENEDORES_FUNCTIONS_H

#include <vector>
#include <iostream>
using namespace std;

template<typename T>
void quick_remove_at(std::vector<T>& vec, std::size_t idx){
    try {
        vec.at(idx) = std::move(vec.back()); // at() da un error cuando se accede a un subindice que excede el limite
        vec.pop_back();
    } catch (const std::out_of_range &e){
        cout << "Out of range access detected: " << e.what() << endl;
    }
}
template<typename T>
void quick_remove_at(std::vector<T>& vec, typename std::vector<T>::iterator itr){
    if (itr != vec.end()) {
        *itr = std::move(vec.back()); // at() da un error cuando se accede a un subindice que excede el limite
        vec.pop_back();
    }
}

template<typename T>
void insert_sorted(vector<T>& vec, T value){
    auto itr = lower_bound(begin(vec), end(vec), value);
    vec.insert(itr, value);
}

#endif //S5_STL_CONTENEDORES_FUNCTIONS_H
