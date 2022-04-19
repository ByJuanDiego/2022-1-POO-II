//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_TEMPLATES_V2022_1_P10_H
#define PROG3_UNIT2_TEMPLATES_V2022_1_P10_H
#include <vector>
#include <array>
using namespace std;

template<typename cont>
int linearSearch(int value, cont*& container){
    for (int i=0; i<container->size(); i++){
        if ((*container)[i] == value){
            return i;
        }
    }
    return -1;
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

    template<typename cont>
    friend int linearSearch(int value, cont*& container);

    template<typename cont>
    friend void bubbleSort(cont*& container);

private:
    Container* container;
public:
    searcher(Container& other){
        container = &other;
        bubbleSort(container);
    }
    int operator << (int x){
        return linearSearch(x, container);
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
        return linearSearch(x, container);
    }
};


#endif //PROG3_UNIT2_TEMPLATES_V2022_1_P10_H
