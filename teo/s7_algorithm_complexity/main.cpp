#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

template <int N>
constexpr long long int factorial(){
    return N * factorial<N - 1>();
}

template<>
constexpr long long int factorial<0>(){
    return 1;
}

int main() {

    constexpr int n = 5;
    auto start = high_resolution_clock::now();
    auto f = factorial<n>();
    auto end = high_resolution_clock::now();

    std::cout  << "factorial de: " << n << " = " << f << std::endl;
    std::cout << "demoró: " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds" << std::endl;

    return 0;
}
