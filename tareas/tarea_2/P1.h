//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_TEMPLATES_V2022_1_P1_H
#define PROG3_UNIT2_TEMPLATES_V2022_1_P1_H

#include <iostream>
#include <string>
using namespace std;

template<typename T = string>
T input(string message = "") {
    T temp;
    cout << message;
    cin >> temp;
    return temp;
}

#endif //PROG3_UNIT2_TEMPLATES_V2022_1_P1_H
