//
// Created by Juan Diego Castro Padilla on 1/04/22.
//

#ifndef TAREA_1_MATRIX_H
#define TAREA_1_MATRIX_H

#include <iostream>
#include <iomanip>
#include "number.h"
using namespace std;
typedef int SIZE_TYPE;

namespace utec{

    class matrix_t {

        friend ostream& operator<<(ostream& os, const matrix_t& m);

    private:

        SIZE_TYPE nrow;
        SIZE_TYPE ncol;
        number_t** data = nullptr;
        void _destroy_();
        void _copy_(number_t** other_data);
        void _assign_(SIZE_TYPE row, SIZE_TYPE col);

    public:

        matrix_t(SIZE_TYPE row, SIZE_TYPE col);     // constructor por parametros
        matrix_t(const matrix_t& other);            // constructor copia
        matrix_t& operator=(const matrix_t& other); //  constructor asignacion-copia

        ~matrix_t();                                // destructor

        SIZE_TYPE row_size() const;
        SIZE_TYPE col_size() const;

        number_t* & operator()(int i, int j);       // sobrecarga (i, j) como set
        number_t* operator()(SIZE_TYPE i, SIZE_TYPE j) const; // sobrecarga (i, j) como get

    };

    ostream& operator<<(ostream &os, const utec::matrix_t &m);
}


#endif //TAREA_1_MATRIX_H
