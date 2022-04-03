//
// Created by Juan Diego Castro Padilla on 1/04/22.
//

#include "matrix.h"

namespace utec{

    void matrix_t::_assign_(SIZE_TYPE row, SIZE_TYPE col){
        nrow = row;
        ncol = col;
        data = new number_t*[nrow * ncol];
    }

    void matrix_t::_copy_(number_t** other_data) {
        for (int i=0; i<(nrow*ncol); i++) {
            *data[i] = *other_data[i];
        }
    }

    void matrix_t::_destroy_() {
        for (int i=0; i<(nrow*ncol); i++){
            delete data[i];
        }
        delete [] data;
    }
    
    ostream& operator<<(ostream &os, const matrix_t &m){
        for (int f = 0; f < m.nrow; f++){
            for (int c = 0; c < m.ncol; c++){
                os << setw(6);
                m(f, c)->print(os);
            }
            os << endl;
        }
        os << endl;
        return os;
    }

    SIZE_TYPE matrix_t::col_size() const {
        return ncol;
    }

    SIZE_TYPE matrix_t::row_size() const {
        return nrow;
    }

    matrix_t::matrix_t(SIZE_TYPE row, SIZE_TYPE col){// constructor por parametros
        _assign_(row, col);
        for (int i=0; i<(nrow*ncol); i++)
            data[i] = new integer_t();
    }

    matrix_t::matrix_t(const matrix_t& other) {// constructor copia
        _assign_(other.nrow, other.ncol);
        _copy_(other.data);
    }

    matrix_t& matrix_t::operator=(const matrix_t &other){// sobrecarga asignacion copia
        if (&other == this){
            return *this;
        }

        _destroy_();
        _assign_(other.nrow, other.ncol);
        _copy_(other.data);
        return *this;
    }

    matrix_t::~matrix_t(){// destructor
        _destroy_();
    }

    number_t* & matrix_t::operator()(SIZE_TYPE i, SIZE_TYPE j) {
        return data[i * ncol + j];
    }

    number_t* matrix_t::operator()(SIZE_TYPE i, SIZE_TYPE j) const {
        return data[i * ncol + j];
    }

}
