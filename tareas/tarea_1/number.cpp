//
// Created by Juan Diego Castro Padilla on 2/04/22.
//

#include "number.h"

integer_t::integer_t(): number_t(), integer(0){}

integer_t::integer_t(int integer): number_t(), integer(integer){}

void integer_t::print(ostream& os) {
    os << integer;
}


real_t::real_t(): number_t(), real(0){}

real_t::real_t(double real): number_t(), real(real){}

void real_t::print(ostream& os) {
    os << fixed << setprecision(1) << real;
}


complex_t::complex_t(): number_t(), real(0), imaginario(0) {}

complex_t::complex_t(double real, double imaginario): number_t(), real(real), imaginario(imaginario) {}

void complex_t::print(ostream& os) {
    os << fixed << setprecision(1) << real << ((imaginario < 0)? "-": "+" ) << abs(imaginario) << "i";
}
