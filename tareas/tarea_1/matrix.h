//
// Created by Juan Diego Castro Padilla on 1/04/22.
//

#ifndef TAREA_1_MATRIX_H
#define TAREA_1_MATRIX_H

#include <iostream>
#include <iomanip>
#include "number.h"
using namespace std;
typedef unsigned long int SIZE_TYPE;

namespace utec{

    class matrix_t {

        // Amistad
        friend ostream& operator<<(ostream& os, const matrix_t& m);

    private:

        // Atributos
        SIZE_TYPE nrow;
        SIZE_TYPE ncol;
        number_t** data = nullptr;

        // Métodos privados
        void _assign_(SIZE_TYPE row, SIZE_TYPE col);
        void _copy_(number_t** other_data);
        void _destroy_();

    public:

        // Constructor por Parámetros
        matrix_t(SIZE_TYPE row, SIZE_TYPE col);     // constructor por parametros

        // Constructor Copia
        matrix_t(const matrix_t& other);            //  Copia
        matrix_t& operator=(const matrix_t& other); //  Asignacion-Copia Sobrecarga =

        // Destructor
        ~matrix_t();

        // Getters
        SIZE_TYPE row_size() const;
        SIZE_TYPE col_size() const;

        // Sobrecarga ()
        number_t* & operator()(SIZE_TYPE i, SIZE_TYPE j);       // Como Set
        number_t* operator()(SIZE_TYPE i, SIZE_TYPE j) const;   // Como Get

    };

    // Sobrecarga <<
    ostream& operator<<(ostream &os, const matrix_t &m);

}


#endif //TAREA_1_MATRIX_H
