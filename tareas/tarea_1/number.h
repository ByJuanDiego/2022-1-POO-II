//
// Created by Juan Diego Castro Padilla on 2/04/22.
//

#ifndef TAREA_1_NUMBER_H
#define TAREA_1_NUMBER_H

#include <iostream>
#include <iomanip>
using namespace std;

class number_t {
public:
    number_t() = default;
    virtual ~number_t() = default;
    virtual void print(ostream& os) = 0;
};


class integer_t: public number_t{
private:
    int integer;
public:
    integer_t();
    explicit integer_t(int integer);
    void print(ostream& os) override;
};


class real_t: public number_t{
private:
    double real;
public:
    real_t();
    explicit real_t(double real);
    void print(ostream& os) override;
};


class complex_t: public number_t{
private:
    double real, imaginario;
public:
    complex_t();
    complex_t(double real, double imaginario);
    void print(ostream& os) override;
};


#endif //TAREA_1_NUMBER_H
