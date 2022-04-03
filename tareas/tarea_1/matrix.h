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

        // atributos
        SIZE_TYPE nrow;
        SIZE_TYPE ncol;
        number_t** data = nullptr;

        // metodos privados
        void _assign_(SIZE_TYPE row, SIZE_TYPE col);
        void _copy_(number_t** other_data);
        void _destroy_();

    public:

        matrix_t(SIZE_TYPE row, SIZE_TYPE col);     // constructor por parametros
        matrix_t(const matrix_t& other);            // constructor copia
        matrix_t& operator=(const matrix_t& other); //  constructor asignacion-copia

        ~matrix_t();                                // destructor

        SIZE_TYPE row_size() const;
        SIZE_TYPE col_size() const;

        number_t* & operator()(int i, int j);                   // sobrecarga () como set
        number_t* operator()(SIZE_TYPE i, SIZE_TYPE j) const;   // sobrecarga () como get

    };

    ostream& operator<<(ostream &os, const utec::matrix_t &m);
}


#endif //TAREA_1_MATRIX_H
