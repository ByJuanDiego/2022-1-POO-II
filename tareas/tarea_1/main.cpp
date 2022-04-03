#include "matrix.h"
#include "number.h"
#include <random>

int main() {

    random_device rd;
    uniform_int_distribution<int> dis1(0, 9);
    uniform_real_distribution<double> dis2(-9, 9);

    utec::matrix_t m1(4, 5);
    for (int i = 0; i < m1.row_size(); ++i) {
        for (int j = 0; j < m1.col_size(); ++j) {
            m1(i, j) = new integer_t(dis1(rd));
        }
    }
    std::cout << m1;
    utec::matrix_t m2 = m1;

    for (int i = 0; i < m2.row_size(); ++i) {
        for (int j = 0; j < m2.col_size(); ++j) {
            m2(i, j) = new complex_t(dis2(rd), dis2(rd));
        }
    }
    std::cout << m1;
    std::cout << m2;

    utec::matrix_t m3(5, 5);
    for (int i = 0; i < m3.row_size(); ++i) {
        for (int j = 0; j < m3.col_size(); ++j) {
            m3(i, j) = new real_t(dis2(rd));
        }
    }
    m3(0,0) = new integer_t(1);
    cout << m3;

    return  0;
}
