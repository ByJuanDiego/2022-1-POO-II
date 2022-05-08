//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P6_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P6_H

#include <vector>
#include <list>

template <
    template <typename ...> class     FirstContainer,
    template <typename ...> class ... ContainerPackage,
          typename T>
auto zip(FirstContainer<T>& firstContainer, ContainerPackage<T>& ... containerPackage){

    FirstContainer<std::vector<T>> temp ((std::distance(firstContainer.begin(), firstContainer.end())), std::vector<T>());

    int i=0;
    for (auto &row: temp){
        row.push_back(*std::next(firstContainer.begin(), i));
        (row.push_back(*std::next(containerPackage.begin(), i)), ...);
        i++;
    }

    return temp;
}

#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P6_H
