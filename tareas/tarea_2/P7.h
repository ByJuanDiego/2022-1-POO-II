//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_TEMPLATES_V2022_1_P7_H
#define PROG3_UNIT2_TEMPLATES_V2022_1_P7_H

#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <list>

using namespace std;

// template<typename T> struct is_not_string: true_type {};
// template<> struct is_not_string<string>: false_type{};

// enable_if<is_not_string<Container<T, X>>::value, bool> = true
// enable_if<is_not_string<Container<T, A>>::value, bool> = true

template<typename T>
ostream& operator<<(ostream& os, std::vector<T>& contenedor){
    os << "{";
    for (auto it = begin(contenedor); it != end(contenedor); it++){
        typename vector<T>::value_type value = *it;
        if (it != prev(end(contenedor))){
            os << value << ", ";
        }
        else{
            os << value;
        }
    }
    os << "}";
    return os;
}

template<typename T>
ostream& operator<<(ostream& os, std::list<T>& contenedor){
    os << "{";
    for (auto it = begin(contenedor); it != end(contenedor); it++){
        typename vector<T>::value_type value = *it;
        if (it != prev(end(contenedor))){
            os << value << ", ";
        }
        else{
            os << value;
        }
    }
    os << "}";
    return os;
}


template<typename T, size_t A>
ostream& operator<<(ostream& os, std::array<T, A>& contenedor){
    os << "{";
    for (auto it = begin(contenedor); it != end(contenedor); it++){
        typename std::array<T, A>::value_type value = *it;
        if (it != prev(end(contenedor))){
            os << value << ", ";
        }
        else{
            os << value;
        }
    }
    os << "}";
    return os;
}

template<typename Key, typename value>
ostream& operator<<(ostream& os, std::map<Key, value>& contenedor){
    os << "{";
    for (auto it = begin(contenedor); it != end(contenedor); it++){
        typename std::map<Key, value>::value_type var = *it;
        os << "{" << var.first << ": " << var.second << "}";
        if (it != prev(end(contenedor))){
            os << ", ";
        }
    }
    os << "}";
    return os;
}

#endif //PROG3_UNIT2_TEMPLATES_V2022_1_P7_H
