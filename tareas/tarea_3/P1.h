//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P1_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P1_H

#include <vector>
#include <deque>
#include <iostream>
using namespace std;

template <template<typename ...> class Container, typename T>
Container<Container<T>> split_range(Container<T>& cont, int n){

    auto sz = std::distance(cont.begin(), cont.end());
    auto cant = (sz/n);
    Container<Container<T>> temp(n, Container<T>(cant, T()));

    int i = 0;
    for (typename Container<Container<T>>::iterator it = temp.begin(); it != temp.end(); it++){
        typename Container<T>::iterator it_c = next(cont.begin(), i * cant);
        for (typename Container<T>::iterator it2 = (*it).begin(); it2 != (*it).end(); it2++){
            *it2 = *it_c;
            advance(it_c, 1);
        }
        i++;
    }

    if ((sz % n) != 0){
        auto it = next(temp.begin(), n-1);
        it->resize(distance(it->begin(), it->end()) + (sz % n));
        auto it_c = std::next(cont.begin(), cant * (n-1));
        for (auto it2 = (*it).begin(); it2 != (*it).end(); it2++){
            *it2 = *it_c;
            advance(it_c, 1);
        }
    }

    return temp;
}

#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P1_H
