//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_TEMPLATES_V2022_1_P5_H
#define PROG3_UNIT2_TEMPLATES_V2022_1_P5_H

using namespace std;

template <typename T>
T suma_producto(T last){
    return last;
}

template <typename T1, typename T2>
auto suma_producto(T1 last1, T2 last2){
    return last1*last2;
}

template <typename T1, typename T2, typename... ParamPackage>
auto suma_producto(T1 first, T2 second, ParamPackage... paramPackage){
    return first*second + suma_producto(paramPackage...);
}

#endif //PROG3_UNIT2_TEMPLATES_V2022_1_P5_H
