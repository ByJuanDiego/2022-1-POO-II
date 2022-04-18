//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_TEMPLATES_V2022_1_P2_H
#define PROG3_UNIT2_TEMPLATES_V2022_1_P2_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

template<typename Iterator, typename Stream>
void print(Iterator Begin, Iterator End, Stream& os, string delimiter = " "){
    for (auto it = Begin; it != End; it++){
        os << *it  << ((it != prev(End))? delimiter:"");
    }
    os << endl;
}

#endif //PROG3_UNIT2_TEMPLATES_V2022_1_P2_H
