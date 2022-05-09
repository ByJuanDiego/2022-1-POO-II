//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P9_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P9_H

#include <iostream>
#include <vector>
#include <initializer_list>
#include <iterator>
#include <array>
#include <stack>
#include <memory>
using namespace std;

template<typename T, size_t sz>
class fixed_stack;

template<typename T, std::size_t sz>
class fixed_stack_pusher{

public:

    using iterator_category = std::forward_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = T;
    using pointer           = T*;
    using reference         = T&;

    explicit fixed_stack_pusher(fixed_stack<T, sz>& stack){
        stack1 = &stack;
        iterador = stack.pila.begin();
    }

    fixed_stack_pusher<T, sz>& operator++(){
        ++iterador;
        return *this;
    }

    fixed_stack_pusher<T, sz>& operator=(T value){
        stack1->push(value);
        return *this;
    }

    fixed_stack_pusher<T, sz>& operator*(){
        return *this;
    }

private:

    typename std::iterator<iterator_category , T> iterador;
    fixed_stack<T, sz>* stack1 = nullptr;

};


template<typename T, std::size_t sz>
class fixed_stack{

    friend class fixed_stack_pusher<T, sz>;

private:

    long int tope = -1;
    std::vector<T> pila;

public:

    fixed_stack() = default;

    fixed_stack(std::initializer_list<T> lst): pila(sz, T()){
        long int idx = 0;
        for (auto it = lst.begin(); it != lst.end(); it++){
            if (idx == sz){
                break;
            } else{
                *std::next(pila.begin(), idx) = *it;
                idx++;
            }
        }
        tope = idx-1;
        if (size() < sz){
            pila.erase(std::next(std::begin(pila), size()), std::end(pila));
        }
    }

    T& top() {
        return *std::next(pila.begin(), tope);
    }

    void pop(){
        if (size() > 0){
            pila.erase(std::next(pila.begin(), tope));
            tope--;
        }
    }

    bool push(T Value){
        if (size() == sz){
            return false;
        } else {
            pila.push_back(std::move(Value));
            tope++;
            return true;
        }
    }

    bool empty(){
        return (size() == 0);
    }

    int size(){
        return (tope+1);
    }

};


#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P9_H
