//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_TEMPLATES_V2022_1_P10_H
#define PROG3_UNIT2_TEMPLATES_V2022_1_P10_H
#include <vector>
#include <array>
using namespace std;

template<typename Container>
class searcher{
private:
    Container* container;
    void bubbleSort(){
        for (int i = 0; i < container->size() - 1; i++) {
            for (int j = 0; j < container->size() - i - 1; j++) {
                if ((*container)[j] > (*container)[j + 1]) {
                    typename Container::value_type temp = (*container)[j];
                    (*container)[j] = (*container)[j+1];
                    (*container)[j+1] = temp;
                }
            }
        }
    }
    int linearSearch(int value){
        for (int i=0; i<container->size(); i++){
            if ((*container)[i] == value){
                return i;
            }
        }
        return -1;
    }

public:
    searcher(Container& other){
        container = &other;
        bubbleSort();
    }
    int operator << (int x){
        return linearSearch(x);
    }
};

template<typename T, size_t sz>
class searcher<array<T, sz>>{
private:
    array<T, sz>* container;
    void bubbleSort(){
        for (int i = 0; i < sz - 1; i++) {
            for (int j = 0; j < sz - i - 1; j++) {
                if ((*container)[j] > (*container)[j + 1]) {
                    T temp = (*container)[j];
                    (*container)[j] = (*container)[j+1];
                    (*container)[j+1] = temp;
                }
            }
        }
    }
    int linearSearch(int value){
        for (int i=0; i<container->size(); i++){
            if ((*container)[i] == value){
                return i;
            }
        }
        return -1;
    }
public:
    searcher(array<T, sz>& other){
        container = &other;
        bubbleSort();
    }
    int operator << (int x){
        return linearSearch(x);
    }
};















#endif //PROG3_UNIT2_TEMPLATES_V2022_1_P10_H
