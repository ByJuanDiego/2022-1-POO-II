//
// Created by Juan Diego Castro Padilla on 1/04/22.
//

#include "matrix2.h"

namespace utec{

    ostream& operator<<(ostream &os, utec::matrix2 &m) {
        for (int f = 0; f < m.n_row; f++){
            for (int c = 0; c < m.n_col; c++){
                os << *m(f, c) << "\t";
            }
            os << endl;
        }
        os << endl;
        return os;
    }

    SIZE_TYPE matrix2::col_size() const {
        return n_col;
    }

    SIZE_TYPE matrix2::row_size() const {
        return n_row;
    }

    matrix2::matrix2(SIZE_TYPE row, SIZE_TYPE col) {// constructor por parametros
        n_row = row;
        n_col = col;
        data = new integer_t*[n_row*n_col];

        for (int i=0; i<(n_row*n_col); i++) {
            data[i] = new integer_t();
        }
    }

    matrix2::matrix2(const matrix2& other) {// constructor copia
        n_row = other.n_row;
        n_col = other.n_col;

        data = new integer_t*[n_row*n_col];
        for (int i=0; i<(n_row*n_col); i++) {
            data[i] = new integer_t(*other.data[i]);
        }
    }

    matrix2::~matrix2(){// destructor
        for (int i=0; i<(n_row*n_col); i++){
            delete data[i];
        }
        delete [] data;
    }

    integer_t* & matrix2::operator()(int i, int j) {
        return data[i*n_col + j];
    }

}
