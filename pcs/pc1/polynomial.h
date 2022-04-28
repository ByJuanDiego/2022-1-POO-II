//
// Created by Juan Diego Castro Padilla on 26/04/22.
//

#ifndef PC1_POLYNOMIAL_H
#define PC1_POLYNOMIAL_H


#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <cmath>

using namespace std;

template<int ... Coefficients, typename T>
T generate_polynomial(T x){
    int grado = 0;
    return ((pow(x, grado++)*Coefficients)+...+0);
}

template<typename T, int... Coefficients>
class polynomial {
private:

    pair<T, T>* pares_ordenados;
    std::size_t sz;
    void bubbleSort(){
        if (pares_ordenados != nullptr) {
            for (int i = 0; i < sz - 1; i++)
                for (int j = 0; j < sz - i - 1; j++)
                    if (pares_ordenados[j].first > pares_ordenados[j + 1].first)
                        swap(pares_ordenados[j], pares_ordenados[j + 1]);
        }
    }

public:

    polynomial(){
        this->pares_ordenados = nullptr;
        this->sz = 0;
    }

    polynomial(std::initializer_list<T> x_values){
        this -> sz = x_values.size();
        this -> pares_ordenados = new pair<T, T>[this->sz];

        int idx = 0;
        for (auto itr = x_values.begin(); itr != x_values.end(); itr++){
            pares_ordenados[idx] = {*itr, generate_polynomial<Coefficients...>(*itr)};
            idx++;
        }
    }
    
    polynomial(std::vector<T>& x_vec){
        this -> sz = x_vec.size();
        this -> pares_ordenados = new pair<T, T>[this->sz];

        for (int i = 0; i < sz; i++){
            pares_ordenados[i] = {x_vec[i], generate_polynomial<Coefficients...>(x_vec[i])};
        }
    }

    polynomial(const polynomial& otherPoly){
        this -> sz = otherPoly.sz;
        this -> pares_ordenados = new pair<T, T>[this->sz];
        for (int i = 0; i< sz; i++){
            T x = otherPoly.pares_ordenados[i].first;
            pares_ordenados[i] = pair<T, T>(x, generate_polynomial<Coefficients...>(x));
        }
    }

    polynomial& operator = (const polynomial& otherPoly){
        if (this != &otherPoly){

            if (this->pares_ordenados != nullptr){
                delete [] pares_ordenados;
                pares_ordenados = nullptr;
            }

            this -> sz = otherPoly.sz;
            this -> pares_ordenados = new pair<T, T>[this->sz];
            for (int i = 0; i < sz; i++){
                T x = otherPoly.pares_ordenados[i].first;
                pares_ordenados[i] = pair<T, T>(x, generate_polynomial<Coefficients...>(x));
            }
        }
        return *this;
    }

    ~polynomial(){
        delete [] pares_ordenados;
    }

    void operator += (T x){
        auto* temp = new pair<T, T>[sz+1];

        for (int i=0; i<sz; i++){
            temp[i] = pair<T, T>(pares_ordenados[i].first, pares_ordenados[i].second);
        }
        sz++;

        temp[sz-1] = pair<T, T>(x, generate_polynomial<Coefficients...>(x));
        delete [] pares_ordenados;
        pares_ordenados = temp;
    }

    friend ostream& operator << (ostream& os, polynomial& poly){
        poly.bubbleSort();
        for (int i=0; i<poly.sz; i++){
            os << "{" << poly.pares_ordenados[i].first << ", " << poly.pares_ordenados[i].second << "} ";
        }
        return os;
    }

    void clear(){
        delete [] pares_ordenados;
        this -> sz = 0;
        pares_ordenados = nullptr;
    }

};

#endif //PC1_POLYNOMIAL_H
