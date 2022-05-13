//
// Created by Juan Diego Castro Padilla on 12/05/22.
//

#include "sp4.h"
#include <iostream>
#include <vector>
#include <random>
#include <queue>
#include <fstream>
using namespace std;

// n = numero de filas
// m = numero de columnos
// n == m el caso mas desfavorable

using row_t = vector<int>;
using matrix_t = vector<row_t>;

bool ejercicio_1(const matrix_t& matrix) {

    auto nrow = size(matrix);         // Cantidad de filas            // O(1)
    auto ncol = size(matrix.front()); // Cantidad de columnas         // O(1)
    auto tab = vector<bool>(nrow * ncol, false);                      // O(n*m) // O(n^2)

    for (const auto& row: matrix)                   // O(n)
        for (const auto& value: row)                  // O(m)
            tab[value - 1] = true;

    for (const auto& i: tab)                        // O(n*m)
        if(!tab[i])
            return false;

    return true;                                    // O(1)
}
// O(1) + O(n^2) + O(n)*O(n) + O(n^2) + O(1)
// = O(1) + O(n^2) + O(n^2) + O(n^2) + O(1)
// = O(1 + n^2 + n^2 + n^2 + 1) = O(2 + 3n^2)
// = O(n^2) considerando una matriz cuadrada

// O(1) + O(n*m) + O(n)O(m) + O(n*m) + O(1)
// O(1) + O(nm) + O(nm) + O(nm) + O(1)
// O(2) + O(3nm)
// O(2 + 3mn)
// O(3nm)
// = O(nm) para un C = 4 y n0 = 1 tal que n >= n0 m >= n0

void ejercicio_2(int n) {
    for( int i = n;  i > 0;  i /= 2 ) {
        for( int j = 1;  j < n;  j *= 2 ) {
            for( int k = 0;  k < n;  k += 2 ) {
                // ... constant number of operations
            }
        }
    }
}

void ejercicio_3(int n) {
    auto sum = 0;
    for ( int i = 1; i < n; i *= 2 ) {
        for ( int j = n; j > 0; j /= 2 ) {
            for ( int k = j; k < n; k += 2 ) {
                sum += (i + j * k );
            }
        }
    }
}

void ejercicio_4(int n) {
    for( int i = n;  i > 0;  i-- ) {
        for( int j = 1;  j < n;  j *= 2 ) {
            for( int k = 0;  k < j;  k++ ) {
                // ... constant number C of operations
            }
        }
    }
}

void ejercicio_5(int n) {
    for( int bound = 1; bound <= n; bound *= 2 ) {
        for( int i = 0; i < bound; i++ ) {
            for( int j = 0; j < n; j += 2 ) {
                // ... constant number of operations
            }
            for( int j = 1; j < n; j *= 2 ) {
                // ... constant number of operations
            }
        }
    }
}

int randint(int first, int last) {
    random_device rd;
    uniform_int_distribution<int> dis(first, last);
    return dis(rd);
}

int ejercicio_6(int n) {
    if ( n <= 0 ) return 0;
    int i = randint( 0, n - 1 );
    return ejercicio_6( i ) + ejercicio_6( n - 1 - i );
    // i + n - 1 - i // i + n - 1 - i
    //  ejercicio_6(n - 1)
}

void ejercicio_7(int n) {
    int k = 1;
    while (k <= n)
        k = 3 * k;
}

void ejercicio_8(int n) {
    int j = 0;
    for (int i = 0; i < n; ++i) {
        j = i;
        while (j < i * i) {
            j = j + 1;
            if (j % i == 0)
                for (int k = 0; k < j; ++k)
                    cout << "utec";
        }
    }
}

void ejercicio_9(int n) {
    int count = 0;
    for (int i = n/2; i < n; ++i) {
        int j = 1;
        while (j + n/2 <= n) {
            int k = 1;
            while (k <= n) {
                ++count;
                k *= 2;
            } // end while
            ++j;
        } // end while
    } // end for
    std::cout << count;
}

void ejercicio_10(int n) {
    int sum = 0;
    for (int i = 0; i < sqrt(n)/2; ++i)
        sum++;
    int j = 0;
    for (; j < sqrt(n)/4; ++j)
        sum++;
    for (int k = 0; k < 8 + j; ++k)
        sum++;
}


int ejercicio_11 (int n, int x) {
    if (n <= 1) return 1;
    else
        for (int i = 1; i <= n; ++i)
            x = x + 1;
    return ejercicio_11 (n-1, x);
}

int ejercicio_12 (vector<int> v) {
    auto n = size(v);

    if (n == 0) return 0;
    if (n == 1) {
        int value = v.back();
        v.pop_back();
        return value;
    }

    vector<int> v1;
    vector<int> v2;
    auto left = begin(v);
    auto middle = next(left, n/2);
    auto right = end(v);

    copy(left, middle, back_inserter(v1));
    copy(middle, right, back_inserter(v2));

    return ejercicio_12(v1) + ejercicio_12 (v2);
}

/*
Ejercicio #14
Elaborar una función "get_anagrams" que cuente con 2 parámetros,
el primero para recibir una palabra y el segundo el nombre de un archivo,
el programa debe devolver un vector con todas las palabras dentro del archivo
que sean anagrama del primer parametro, cada palabra estará escrita en una línea del archivo.

vector<string> get_anagrams(string word, string filename);

Determinar el bigO del algoritmo que halla desarrollado.
*/

vector<string> get_anagrams(string word, string filename) {
    std::vector<string> result;                   // O(1)
    ifstream InputFile(filename, ios::in); // O(1)

    const auto is_anagram(
        [=] (auto palabra) {
            if (palabra.size() != word.size()){ // O(1)
                return false;                   // O(1)
            }
            auto sz = size(word); // O(1)
            std::vector<int> vec(256, 0); // O(1), 256 elementos siempre constantes
            for (int i=0; i<sz; i++){           // O(m) itera tantas veces como caracteres tenga la palabra
                vec[toascii(word[i])]--;     // O(1)
                vec[toascii(palabra[i])]++;  // O(1)
            }
            for (int i=0; i<256; i++){          // O(1)
                if (vec[i] != 0)                // O(1)
                    return false;               // O(1)
            }
            return true;                        // O(1)
        }
    ); // BigO = m

    std::copy_if(// O(n)
        std::istream_iterator<std::string>(InputFile), // O(1)
        std::istream_iterator<string>(), // O(1)
        std::back_inserter(result), // O(1)
        is_anagram// O(m)
        );

    return result; // O(1)
} // BigO = O(n * m)


/*
Ejercicio #15
Elaborar una función "get_par_lejano" que lea un vector con valores
aleatorios de doubles y que retorne un pair con los 2 valores que
tengan la mayor diferencia entre 2 valores del vector
(en valor absoluto), el programa debía ser lineal en el peor de los casos.

pair <double, double> get_par_lejano(const vector<double>& data);
*/

pair<double, double> get_par_lejano(const vector<double>& data) {
    std::pair<double, double> pares = {0, 0}; // O(1)
    auto minIt = std::min_element(data.begin(), data.end()); // O(n)
    auto maxIt = std::max_element(data.begin(), data.end()); // O(n)
    pares.first = *minIt;   // O(1)
    pares.second = *maxIt; // O(1)
    return pares;          // O(1)
} // BigO = O(C + 2*n) = O(n)
