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

template<typename T>
T* make_smart_ptr(T inicializador){
    return new T(inicializador);
}

template<typename T>
T* make_smart_ptr(int x, int y){
    return new T(x, y);
}

template<typename T>
class smart_ptr{
private:
    T* ptr;
public:
    smart_ptr() {
        ptr = make_smart_ptr(T());
    }
    smart_ptr(T* param){
        ptr = make_smart_ptr(*param);
    }
    virtual ~smart_ptr(){
        delete ptr;
    }
    T operator * (){
        return *ptr;
    }
    smart_ptr& operator = (T* param){
        ptr = make_smart_ptr(*param);
        return *this;
    }
};

template<>
class smart_ptr<point>{
private:
    point* punto;
public:
    smart_ptr(){
        punto = make_smart_ptr<point>(0, 0);
    }
    smart_ptr(point* Other){
        punto = make_smart_ptr<point>(Other->get_x(), Other->get_y());
    }
    smart_ptr& operator = (point* Other){
        punto = make_smart_ptr<point>(Other->get_x(), Other->get_y());
        return *this;
    }
    virtual ~smart_ptr(){
        delete punto;
    }
    point& operator * (){
        return *punto;
    }
    point* operator->(){
        return punto;
    }
};

#endif //PROG3_UNIT2_TEMPLATES_V2022_1_P4_H
