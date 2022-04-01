//
// Created by Juan Diego Castro Padilla on 1/04/22.
//

#ifndef TAREA_1_MATRIX_H
#define TAREA_1_MATRIX_H


#include <iostream>
using namespace std;
typedef int SIZE_TYPE;
typedef int integer_t;

namespace utec{

    class matrix_t {

        friend ostream& operator<<(ostream& os, utec::matrix_t& m);

    private:

        SIZE_TYPE n_row;
        SIZE_TYPE n_col;
        integer_t*** data = nullptr;

    public:

        matrix_t(SIZE_TYPE row, SIZE_TYPE col);             // constructor por parametros
        matrix_t(const matrix_t& other);        // constructor copia
        ~matrix_t();                            // destructor

        integer_t* & operator()(int x, int y);    // sobrecarga ()
        SIZE_TYPE row_size() const;
        SIZE_TYPE col_size() const;
    };
}


#endif //TAREA_1_MATRIX_H
