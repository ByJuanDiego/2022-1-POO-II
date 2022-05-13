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
    for( int i = n;  i > 0;  i /= 2 ) {                 // O(log(n))
        for( int j = 1;  j < n;  j *= 2 ) {             // O(log(n))
            for( int k = 0;  k < n;  k += 2 ) {         // O(n)
                // ... constant number of operations    // O(1)
            }
        }
    }
} // BigO = O(C1 * n * log(n) * log(n)) = O(n * log(n)²)

void ejercicio_3(int n) {
    auto sum = 0;                               // O(1)
    for ( int i = 1; i < n; i *= 2 ) {          // O(log(n))
        for ( int j = n; j > 0; j /= 2 ) {      // O(log(n))
            for ( int k = j; k < n; k += 2 ) {  // O(n)
                sum += (i + j * k );            // O(1)
            }
        }
    }
} // BigO = O(C2 * n * log(n) * log(n) + C1) = O(n * log(n)²)

void ejercicio_4(int n) {
    for( int i = n;  i > 0;  i-- ) {                    // O(n)
        for( int j = 1;  j < n;  j *= 2 ) {             // O(log(n))
            for( int k = 0;  k < j;  k++ ) {            // O(n), en el peor de los casos j=n-1
                // ... constant number C of operations  // O(1)
            }
        }
    }
} // BigO = O(C1 *n * log(n) * n) = O(n²*log(n))

void ejercicio_5(int n) {
    for( int bound = 1; bound <= n; bound *= 2 ) {      // O(log(n))
        for( int i = 0; i < bound; i++ ) {              // O(n)
            for( int j = 0; j < n; j += 2 ) {           // O(n)
                // ... constant number of operations    // O(1)
            }
            for( int j = 1; j < n; j *= 2 ) {           // O(log(n))
                // ... constant number of operations    // O(1)
            }

        }
    }
} // BigO = O( (C1*log(n) + C2*n) * n * log(n) ) = O( (log(n) + n) * n * log(n) )
  //                                             = O(log(n)*n*log(n) + n*n*log(n))
  //                                             = O(n*log(n)² + n²*log(n))
  //                                             = O(n²*log(n))

int randint(int first, int last) {
    random_device rd;                                   // O(1) = C1
    uniform_int_distribution<int> dis(first, last);  // O(1) = C2
    return dis(rd);                                   // O(1) = C3
} // BigO = O(1)

int ejercicio_6(int n) {// T(n)
    if ( n <= 0 ) return 0;                 // O(1) = C1
    int i = randint( 0, n - 1 );    // O(1) = C2
    return (ejercicio_6(i) +  // En el peor caso i=(n-1)
    ejercicio_6( n - 1 - i)); // En el peor caso i=0
    // Pero i no puede valer (n-1) y 0 a la vez, asi que el peor caso seria n/2
} // BigO = C + T(n/2) + T(n/2)
  //      = C + 2*T(n/2)
  // a = 2, b = 2, d = 0
  // a > b^d -> 2 > 1
  // BigO = O(n^(logb(a)))
  // BigO = O(n^(log2(2)))
  //      = O(n)

void ejercicio_7(int n) {
    int k = 1;
    while (k <= n)  {
        k = 3 * k;
    }
    // Es el equivalente a: for (int k=1; k<=n; k *= 3);
    // El numero de instrucciones se reduce a una fraccion del numero anterior (1/3)
} // BigO = (log3(n))

void ejercicio_8(int n) {
    int j = 0;                              // O(1)
    for (int i = 0; i < n; ++i) {           // O(n), en el peor caso i=n-1
        j = i;                              // O(1)
        while (j < i * i) {                 // O(n²), en el peor caso j=i²-1
            j = j + 1;                      // O(1)
            if (j % i == 0)                 // O(1)
                for (int k = 0; k < j; ++k) // O(n²), en el peor caso k=j-1
                    cout << "utec";         // O(1)
        }
    }
} // BigO = O( ((C1*n² + C2 + C3) * n² + C4) * n + C5)
  //      = O(n²*n²*n)
  //      = O(n^5)

void ejercicio_9(int n) {
    int count = 0;                  // O(1) = C1
    for (int i = n/2; i < n; ++i) { // O(n)
        int j = 1;                  // O(1) = C2
        while (j + n/2 <= n) {      // O(n)
            int k = 1;              // O(1) = C3
            while (k <= n) {        // log2(n) (el while completo)
                ++count;
                k *= 2;
            } // end while
            ++j;                    // O(1) = C4
        } // end while
    } // end for
    std::cout << count;             // O(1) = C5
} // BigO = O(((log2(n) + C3 + C4)* n + C2)* n + C1 + C5)
  //      = O(log2(n) * n * n)
  //      = O(n² * log2(n))

void ejercicio_10(int n) {
    int sum = 0;                                // O(1) = C1
    for (int i = 0; i < sqrt(n)/2; ++i)  // O(√n), En el peor caso i=(√n/2)-1
        sum++;                                  // O(1) = C2
    int j = 0;                                  // O(1) = C3
    for (; j < sqrt(n)/4; ++j)           // O(√n), En el peor caso j=(√n/4)-1
        sum++;                                  // O(1) = C4
    for (int k = 0; k < 8 + j; ++k)             // O(√n), En el peor caso k = j+7
        sum++;                                  // O(1) = C5
} // BigO = O(C1 + (C2*n^(1/2)) + C3 + (C4*n^(1/2)) + (C5*n^(1/2)))
  //      = O(C6 + (C2+C4+C5)*n^(1/2))
  //      = O(n^(1/2))

int ejercicio_11 (int n, int x) {
    if (n <= 1) return 1;            // O(1) = C1
    else
        for (int i = 1; i <= n; ++i) // O(n)
            x = x + 1;               // O(1) = C2
    return ejercicio_11 (n-1, x);  // T(n-1)

} // BigO = T(n) = (C1+C2*n) + T(n-1)
  //                  ...    + (C1+C2*n) + T(n-2)
  //                  ...    +    ...    + (C1+C2*n) + T(1)
  //                  ...    +    ...    +    ...    + C1
  //                -------------- n veces -----------------
  // BigO = O((C1+C2)*n * n + C1)
  //      = O(n²)

int ejercicio_12 (vector<int> v) {
    auto n = size(v);   // O(1) = C1

    if (n == 0) return 0;               // O(1) = C2
    if (n == 1) {                       // O(1) = C3
        int value = v.back();           // O(1) = C4
        v.pop_back();                   // O(1) = C5
        return value;                   // O(1) = C6
    }

    vector<int> v1; // O(1) = C7
    vector<int> v2; // O(1) = C8
    auto left = begin(v);            // O(1) = C9
    auto middle = next(left, n/2); // O(1) = C10
    auto right = end(v);             // O(1) = C11

    copy(left, middle, back_inserter(v1));  // O(n)
    copy(middle, right, back_inserter(v2)); // O(n)

    return ejercicio_12(v1) + ejercicio_12 (v2);
} // BigO = f(n) = C + n + n + f(n/2) + f(n/2)
  //             = C + 2*n^1 + 2*f(n/2)
  //    a = 2, b = 2, d = 1
  //    a = b^d:
  // BigO = O(n^1 * log(n))
  //      = O(n * log(n))

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
