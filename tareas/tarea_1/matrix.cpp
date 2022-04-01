//
// Created by Juan Diego Castro Padilla on 1/04/22.
//

#include "matrix.h"

namespace utec{

    ostream& operator<<(ostream &os, utec::matrix_t &m) {
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

    matrix_t::matrix_t(SIZE_TYPE row, SIZE_TYPE col) {// constructor por parametros
        n_row = row;
        n_col = col;
        data = new integer_t**[n_row];

        for (int i=0; i<n_row; i++) {
            data[i] = new integer_t*[n_col];
            for (int j=0; j<n_col; j++){
                data[i][j] = new integer_t(0);
            }
        }
    }

    matrix_t::matrix_t(const matrix_t& other) {// constructor copia
        n_row = other.n_row;
        n_col = other.n_col;

        data = new integer_t**[n_row];
        for (int i=0; i<n_row; i++) {
            data[i] = new integer_t *[n_col];
            for (int j=0; j<n_col; j++){
                data[i][j] = new integer_t(*other.data[i][j]);
            }
        }
    }

    matrix_t::~matrix_t(){// destructor
        for (int i=0; i<n_row; i++){
            for (int j=0; j<n_col; j++){
                delete data[i][j];
            }
            delete [] data[i];
        }
        delete [] data;
    }

    integer_t* & matrix_t::operator()(int x, int y) {
        return data[x][y];
    }

}
