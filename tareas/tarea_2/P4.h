//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_TEMPLATES_V2022_1_P4_H
#define PROG3_UNIT2_TEMPLATES_V2022_1_P4_H

#include <iostream>
using namespace std;

class point {
    int x;
    int y;
public:
    point(int x, int y): x{x}, y{y} {}
    point() = default;

    friend ostream& operator<< (ostream& os, const point& p) {
        os << "{" << p.x <<", " << p.y << "}" << endl;
        return os;
    }

    int get_x() { return x; }
    int get_y() { return y; }
};

template<typename T, typename... Package>
T* make_smart_ptr(Package... params){
    return new T(params...);
}

template<typename T>
class smart_ptr{
private:
    T* ptr;
public:
    smart_ptr() {
        ptr = make_smart_ptr<T>(T());
    }
    smart_ptr(T* param){
        ptr = make_smart_ptr<T>(*param);
    }
    virtual ~smart_ptr(){
        delete ptr;
    }
    T operator * (){
        return *ptr;
    }
    T* operator -> (){
        return ptr;
    }
    smart_ptr& operator = (T* param){
        ptr = make_smart_ptr<T>(*param);
        return *this;
    }
};


#endif //PROG3_UNIT2_TEMPLATES_V2022_1_P4_H
