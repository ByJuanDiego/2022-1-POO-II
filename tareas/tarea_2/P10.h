//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_TEMPLATES_V2022_1_P10_H
#define PROG3_UNIT2_TEMPLATES_V2022_1_P10_H
#include <vector>
#include <array>
using namespace std;

template<typename cont>
int binarySearch(int value, cont*& container){

    int min_idx {0};
    int max_idx = container->size()-1;
    int mid;

    while (true){
        if (max_idx < min_idx){
            return -1;
        }
        else{
            mid = (min_idx + max_idx)/2;
            if ((*container)[mid] < value){
                min_idx = mid + 1;
            }
            else if ((*container)[mid] > value){
                max_idx = mid - 1;
            }
            else{
                return mid;
            }
        }
    }
}

template<typename cont>
void bubbleSort(cont*& container){
    for (int i = 0; i < container->size() - 1; i++) {
        for (int j = 0; j < container->size() - i - 1; j++) {
            if ((*container)[j] > (*container)[j + 1]) {
                typename cont::value_type temp = (*container)[j];
                (*container)[j] = (*container)[j+1];
                (*container)[j+1] = temp;
            }
        }
    }
}

template<typename Container>
class searcher{
private:
    Container* container;
public:
    searcher(Container& other){
        container = &other;
        bubbleSort(container);
    }
    int operator << (int x){
        return binarySearch(x, container);
    }
};


template<typename T, size_t sz>
class searcher<array<T, sz>>{
private:
    array<T, sz>* container;
public:
    searcher(array<T, sz>& other){
        container = &other;
        bubbleSort(container);
    }
    int operator << (int x){
        return binarySearch(x, container);
    }
};


#endif //PROG3_UNIT2_TEMPLATES_V2022_1_P10_H
