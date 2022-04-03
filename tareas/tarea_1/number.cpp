//
// Created by Juan Diego Castro Padilla on 2/04/22.
//

#include "number.h"

integer_t::integer_t(): integer(0){}

integer_t::integer_t(int integer): integer(integer){}

void integer_t::print(ostream& os) {
    os << integer;
}


real_t::real_t(): real(0){}

real_t::real_t(double real): real(real){}

void real_t::print(ostream& os) {
    os << fixed << setprecision(2) << real;
}


complex_t::complex_t(): real(0), imaginario(0) {}

complex_t::complex_t(double real, double imaginario): real(real), imaginario(imaginario) {}

void complex_t::print(ostream& os) {
    os << fixed << setprecision(2) << real << ((imaginario < 0)? "-": "+" ) << abs(imaginario) << "i";
}
