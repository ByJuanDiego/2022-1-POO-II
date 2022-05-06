#include <iostream>
#include <vector>
#include <array>

/*
Orden de crecimiento de los algoritmos:
--------------------------------------------------------
C < log(N) < N < N*log(N) < N^2 < N^3 < 2^N


Notación de complejidad algorítmica:
--------------------------------------------------------
Big O: Representa la peor condicion o caso

    Ley de adición: O(f(n)) + O(g(n)) = O(f(n) + g(n))

*/

int main() {

    // Time Complexity
    // Space Complexity

    // O(1) + O(n) + O(n) = O(1 + n + n) = O(2*n + 1) = O(n)

    std::vector<int> v  {1, 2, 3, 4};
    for (const auto &i: v) // O(n)
        std::cout << i << std::endl;  // O(1)
    // O(n) * O(1) = O(n * 1) = O(n)

    int n = 5;
    int m = 1;
    for (int i=0; i<n; i++)     // O(n)
        for (int j=0; j<n; j++) // O(n)
            m = m + 1; // O(1)
    // O(n) * O(n) * O(1) = O(n * n * 1) = O(n^2)

    return 0;
}
