#include <iostream>
#include <vector>
using namespace std;

/*
    Sobrecarga de funciones:
        
        void print(int x, int y);

        template<typename T1, typename T2>
        void print(T1 x, T2, y);

    La sobrecarga de clases no es admisible... pero:

        Especialización  de clases:

            template<typename T>
            class A{
                T t {};
            };

            template<>
            class A<int>{
                int i {};
            };
*/

template<typename T>
class Vector{
    T* data;
    int capacity;
    int size;
public:
    Vector() {cout << "Type T: " << __PRETTY_FUNCTION__  << endl;}

};

// Especialización Total
template<>
class Vector<int>{
    int* data;
    int capacity;
    int size;
public:
    Vector() {cout << "Type int: " << __PRETTY_FUNCTION__  << endl;}

};

// Clase generica
template<typename T1, typename T2>
class A{
public:
    A(){
        cout << "Generic <T1, T2>: " << __PRETTY_FUNCTION__  << endl;
    }
};

// Especializacion parcial por derecha
template<typename T>
class A<char, T>{
public:
    A(){
        cout << "Parcial <char, T>: " << __PRETTY_FUNCTION__  << endl;
    }
};


// Especializacion parcial por izquierda
template<typename T>
class A<T, char>{
public:
    A(){
        cout << "Parcial <T, char>: " << __PRETTY_FUNCTION__  << endl;
    }
};

// Especializacion total
template<>
class A<int, int>{
public:
    A(){
        cout << "Total <int, int>: " << __PRETTY_FUNCTION__  << endl;
    }
};

// Caso Recursivo
template <int N>
struct factorial{
    inline static constexpr int value = N * factorial<N-1>::value;
};

// Caso Base
template<>
struct factorial<0>{
    inline static constexpr int value = 1;
};

int main() {

    Vector<int> v1;
    Vector<double> v2;
    Vector<string> v3;
    cout << endl;

    A<double, double> a1;
    A<int, double> a2;
    A<char, int> a3;
    A<int, char> a4;
    A<int, int> a5;
    cout << endl;

    cout << factorial<5>::value << endl;

}
