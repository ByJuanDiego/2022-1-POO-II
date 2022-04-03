//
// Created by Juan Diego Castro Padilla on 1/04/22.
//

#include "matrix.h"

namespace utec{

    void matrix_t::_destroy_() {
        for (int i=0; i<(n_row*n_col); i++){
            delete data[i];
        }
        delete [] data;
    }

    ostream& operator<<(ostream &os, const matrix_t &m){
        for (int f = 0; f < m.n_row; f++){
            for (int c = 0; c < m.n_col; c++){
                os << *m(f, c) << "\t";
            }
            os << endl;
        }
        os << endl;
        return os;
    }

    SIZE_TYPE matrix_t::col_size() const {
        return n_col;
    }

    SIZE_TYPE matrix_t::row_size() const {
        return n_row;
    }

    matrix_t::matrix_t(SIZE_TYPE row, SIZE_TYPE col): n_row(row), n_col(col) {// constructor por parametros
        data = new number_t*[n_row*n_col];
        for (int i=0; i<(n_row*n_col); i++) {
            data[i] = new number_t();
        }
    }

    matrix_t::matrix_t(const matrix_t& other): n_row(other.n_row), n_col(other.n_col) {// constructor copia
        data = new number_t*[n_row*n_col];
        for (int i=0; i<(n_row*n_col); i++) {
            data[i] = new number_t(*other.data[i]);
        }
    }

    matrix_t& matrix_t::operator=(const matrix_t &other){
        if (&other == this){
            return *this;
        }

        _destroy_();
        n_col = other.n_col;
        n_row = other.n_row;

        data = new number_t*[n_row*n_col];
        for (int i=0; i<(n_row*n_col); i++) {
            data[i] = new number_t(*other.data[i]);
        }
        return *this;
    }

    matrix_t::~matrix_t(){// destructor
        _destroy_();
    }

    number_t* & matrix_t::operator()(SIZE_TYPE i, SIZE_TYPE j) {
        return data[i * n_col + j];
    }

    number_t* matrix_t::operator()(SIZE_TYPE i, SIZE_TYPE j) const {
        return data[i * n_col + j];
    }

}
