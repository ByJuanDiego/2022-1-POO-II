//
// Created by Juan Diego Castro Padilla on 1/04/22.
//

#ifndef TAREA_1_MATRIX2_H
#define TAREA_1_MATRIX2_H


#include <iostream>
using namespace std;
typedef int SIZE_TYPE;
typedef int integer_t;

namespace utec{

    class matrix2 {// una mejora de matrix_t pero con un solo array de punteros

        friend ostream& operator<<(ostream& os, utec::matrix2& m);

    private:

        SIZE_TYPE n_row;
        SIZE_TYPE n_col;
        integer_t** data = nullptr;

    public:

        matrix2(SIZE_TYPE row, SIZE_TYPE col);  // constructor por parametros
        matrix2(const matrix2& other);          // constructor copia
        ~matrix2();                             // destructor

        integer_t* & operator()(int x, int y); // sobrecarga ()
        SIZE_TYPE row_size() const;
        SIZE_TYPE col_size() const;
    };
}




#endif //TAREA_1_MATRIX2_H
