//
// Created by Juan Diego Castro Padilla on 24/04/22.
//

#ifndef PC1_SIMULACRO_PAGINATION_H
#define PC1_SIMULACRO_PAGINATION_H

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class pagination;

template<typename U>
vector<U> generate_vector(pagination<U>& pag){
    vector<U> temp;
    temp.reserve(pag.page_sz);
    for (int i=0; i<pag.page_sz; i++){
        auto idx = pag.page_sz*(pag.current_pg-1) + i;
        if (idx >= pag.sz){
            break;
        } else{
            temp.push_back(pag.data[idx]);
        }
    }
    return temp;
}

template<typename T>
class pagination {

    template<typename U>
    friend vector<U> generate_vector(pagination<U>& pag);

private:

    T* data = nullptr;
    std::size_t sz = 0;
    int page_sz = 0;
    int current_pg = 0;

public:

    pagination(std::initializer_list<T> l){
        this -> sz = l.size();
        this -> data = new T[sz];
        this -> current_pg = 1;
        this -> page_sz = 10;
        int i = 0;
        for (auto itr = l.begin(); itr != l.end(); itr++){
            data[i] = *itr;
            i++;
        }
    }

    pagination(const pagination<T>& other){
        this -> sz = other.sz;
        this -> data = new T[sz];
        this -> current_pg = 1;
        this -> page_sz = other.page_sz;
        for  (int i=0; i<sz; i++){
            data[i] = other.data[i];
        }
    }

    ~pagination(){
        delete [] data;
    }

    int pages() const {
        if (sz%page_sz == 0){
            return sz/page_sz;
        }
        else if (page_sz * (sz/page_sz) < sz){
            return sz/page_sz + 1;
        }
        else{
            return sz/page_sz - 1;
        }
    }

    int current_page(){
        return this->current_pg;
    }

    void page_size(int value){
        this->page_sz = value;
    }

    void front(){
        this->current_pg = 1;
    }

    void back(){
        this->current_pg = pages();
    }

    void operator++(int){
        if (current_pg+1 <= pages()){
            current_pg++;
        }
    }

    void operator--(int){
        if (current_pg-1 > 0){
            current_pg--;
        }
    }

    friend ostream& operator << (ostream& os, const pagination& pag){
        for (int i=0; i<pag.page_sz; i++){
            auto idx = pag.page_sz*(pag.current_pg-1) + i;
            if (idx >= pag.sz){
                break;
            }
            else{
                os << pag.data[idx] << " ";
            }
        }
        return os;
    }

};



#endif //PC1_SIMULACRO_PAGINATION_H
