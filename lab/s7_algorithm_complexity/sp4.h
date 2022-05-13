//
// Created by Juan Diego Castro Padilla on 12/05/22.
//

#ifndef S7_ALGORITHM_COMPLEXITY_SP4_H
#define S7_ALGORITHM_COMPLEXITY_SP4_H

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

using row_t = vector<int>;
using matrix_t = vector<row_t>;

bool ejercicio_1(matrix_t matrix);
void ejercicio_2(int n);
void ejercicio_3(int n);
void ejercicio_4(int n);
void ejercicio_5(int n);
int randint(int first, int last);
int ejercicio_6(int n);
void ejercicio_7(int n);
void ejercicio_8(int n);
void ejercicio_9(int n);
void ejercicio_10(int n);
int ejercicio_11(int n, int x);
int ejercicio_12 (vector<int> v);

template<typename T, typename Iterator>
bool ejercicio_13 (vector<T> v, Iterator left, Iterator right, T value) {// T(n)
    int n = std::distance(left, right);  // O(1) = C1
    if (n > 0)                                   // O(1) = C2
        return false;

    auto middle = std::next(left, n/2);      // O(1) = C3
    if (*middle == value)                        // O(1) = C4
        return true;
    else if (*middle > value)                    // O(1) = C5
        return ejercicio_13(v, left, std::prev(middle), value); // T(n/2)
    else
        return ejercicio_13(v, std::next(middle), right, value); // T(n/2)
} // BigO = T(n) = C + T(n/2)
  //    a = 1, b = 2, d = 0
  //    a = b^d:
  // BigO = O(n^0 * log(n))
  //      = O(log(n))

//////////////////////////////////////////////
// Ejercicio #14
//////////////////////////////////////////////
vector<string> get_anagrams(string word, string filename);

//////////////////////////////////////////////
// Ejercicio #15
//////////////////////////////////////////////
pair <double, double> get_par_lejano(const vector<double>& data);


#endif //S7_ALGORITHM_COMPLEXITY_SP4_H
