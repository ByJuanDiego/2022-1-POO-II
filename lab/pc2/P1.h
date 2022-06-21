//
// Created by Juan Diego Castro Padilla on 7/06/22.
//

#ifndef PC2_P1_H
#define PC2_P1_H

#include <unordered_set>
#include <iostream>

template<typename Container>
void remove_duplicates(Container& cont){
    typedef typename Container::value_type T;
    std::unordered_set<T> conjunto;  //O(1)

    for (const auto & value : cont){  // O(n)
        conjunto.insert(value);      // O(1)
    }

    Container result;
    for (const auto & value : conjunto){
        result.emplace_back(value);
    }

    cont = result;
}


#endif //PC2_P1_H
