#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include "sp4.h"

/*
Orden de crecimiento de los algoritmos:
--------------------------------------------------------
C < log(N) < N < N*log(N) < N^2 < N^3 < 2^N


Notación de complejidad algorítmica:
--------------------------------------------------------
Big O: Representa la peor condicion o caso

    Ley de adición:
        O(f(n)) + O(g(n)) = O(f(n) + g(n))

    Ley de multiplicacion:
        O(f(n)) * O(g(n)) = O(f(n) * g(n))
*/

template<typename Container>
void print(const Container& cont){
    for (const auto &i : cont){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void ejemplo_leyes(){
    std::vector<int> v  {1, 2, 3, 4}; // O(1)
    for (const auto &i:v){ // O(1)
        std::cout << i << std::endl;  // O(1)
    }

    int n = 0;
    int m = 0;
    std::cout << "n: ";
    std::cin >> n;
    std::cout << "m: ";
    std::cin >> m;

    for (int i=0; i<n; i++)     // O(n)
        for (int j=0; j<n; j++) // O(n)
            m = m + 1; // O(1)
    // O(n) * O(n) * O(1) = O(n * n * 1) = O(n^2)
}

void ejemplo_1(){
    std::array<int, 5> arr {1, 2, 3, 4, 5}; // O(1)
    std::vector<int> vec (arr.begin(), arr.end()); // O(1)
    print<std::vector<int>>(vec); // O(1)
}

void ejemplo_2(){
    std::ifstream file("datos.txt", std::ios::in);
    std::vector<int> vec;
    std::copy(
            std::istream_iterator<int>(file),
            std::istream_iterator<int>(),
           back_inserter(vec)
    ); // O(n)
    print<std::vector<int>>(vec); // O(n)

    std::ofstream fileResult("result.txt");
    std::copy(
            begin(vec),
            end(vec),
            std::ostream_iterator<int>(fileResult, "\n")
    ); // O(n)
}

void ejemplo_3(){
    int n = 0;
    std::cout << "n: ";
    std::cin >> n;

    for (int i=0; i<n; i++){
        // Do something
    } // O(n)

    for (int i=0; i<100; i++){
        // Do something
    } // O(1)
}

int main() {

    auto x = get_anagrams("amor", "data.txt");

    for (const auto & i :x){
        std::cout << i << std::endl;
    }

    vector<double> v {1, 2, 5, 4, -1, 5, -20, 200};
    auto b = get_par_lejano(v);
    cout << b.first << " " << b.second;

    // Time Complexity
    // Space Complexity

//    ejemplo_leyes();
//    ejemplo_1();
//    ejemplo_2();
//    ejemplo_3();

    return 0;
}
