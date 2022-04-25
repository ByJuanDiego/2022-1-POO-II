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

    pagination& operator = (const pagination<T>& other){
        if (this != &other){
            if (this->data != nullptr){
                delete this->data;
                this->data = nullptr;
            }

            this -> sz = other.sz;
            this -> data = new T[sz];
            for (auto i=0; i < sz; i++){
                this->data[i] = other.data[i];
            }
            this -> current_pg = other.current_pg;
            this -> page_sz = other.page_sz;
        }
        return *this;
    }

    pagination(pagination<T>&& other){
        this -> sz = other.sz;
        this -> data = other.data;
        other.data = nullptr;

        this -> current_pg = 1;
        this -> page_sz = other.page_sz;

    }

    pagination& operator = (pagination<T>&& other){
        if (this == &other){
            return *this;
        }
        else{
            delete this->data;
            this->data = other.data;
            other.data = nullptr;

            this -> sz = other.sz;
            this -> current_pg = other.current_pg;
            this -> page_sz = other.page_sz;
            return *this;
        }
    }

    ~pagination(){
        delete [] data;
    }

    int pages() {
        if (sz%page_sz == 0){
            return sz/page_sz;
        }
        else {
            return sz/page_sz + 1;
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
