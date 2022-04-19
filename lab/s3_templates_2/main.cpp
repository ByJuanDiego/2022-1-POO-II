#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <cmath>
using namespace std;

template <typename T, int sz>
auto get_size(const T (&)[sz]){
    // Obtener el tamaño de un array estatico
    return sz;
}

template<typename T, size_t sz>
int get_size(std::array<T, sz>&){
    // Obtener el tamaño de un std::array
    return sz;
}

template<int N>
constexpr
// constexpr: To be evaluated at compile time
// const    : I promise not to change the value
long long int factorial(){
    return N * factorial<N-1>();
}
template<>
constexpr long long int factorial<0>(){
    return 1;
}

template <typename Container>
void push(Container& contenedor, typename Container::value_type valueType
          // La deducción se hace en tiempo de compilación, por eso es necesario
          // especificar que el operador de ámbito hace referencia a un tipo de dato
          // y no a un atributo de clase.
          ){
    contenedor.push_back(valueType);
}

template <template<typename...> class Container, typename T>
void push(Container<T>& contenedor_, T valueType_){
    // Forma alternativa
    contenedor_.push_back(valueType_);
}

template<typename Iterator>
void display(Iterator start, Iterator stop){
    for (auto it= start; it != stop; it++){
        typename Iterator::value_type value = *it;
        cout << value << " ";
    }
    cout << endl;
}

template<typename Iterator>
auto suma_elementos(Iterator start, Iterator stop, typename Iterator::value_type initial){
    typename Iterator::value_type suma = initial;
    for (auto it = start; it != stop; it++){
        suma += (*it);
    }
    return suma;
}

struct A{
    int atributo_de_objeto = 0;                 // Atributo de objeto (requiere instanciación)
    inline static int atributo_de_clase = 10;   // Atributo de clase  (no requiere instanciación)
    typedef int value_type;                     // Alias
};

int main() {

    int arr1[5] {0, 1, 2, 3, 4};
    std::array<int, 2> arr2 {0, 1};

    cout << "size(int[]) = " << get_size(arr1) << endl;
    cout << "size(array<>) = " << get_size(arr2) << endl;

    cout << "5! = " << factorial<5>() << endl;


    std::vector<int> vec;
    vec.push_back(1);
    push<vector<int>>(vec, 2);
    push<vector, int>(vec, 3);
    display<vector<int>::iterator>(begin(vec), end(vec));
    cout << "Suma de elementos: " << suma_elementos(begin(vec), end(vec), 0) << endl;

    std::list<double> lst;
    lst.push_back(1.1);
    push<list<double>>(lst, 2.2);
    push<list, double>(lst, 3.3);
    display<list<double>::iterator>(begin(lst), end(lst));
    cout << "Suma de elementos: " << suma_elementos(begin(lst), end(lst), 0) << endl;


    int a1 = A::atributo_de_clase;  // Operador de ámbito para acceder a la variable
    typename A::value_type a2 = 0;  // Operador de ámbito para acceder al alias
    /*
        Para evitar que el compilador se confunda se usa el typename para decir explícitamente que
        A::value_type hace referencia al tipo de dato y no a un atributo de clase
    */
    cout << "a1: " << a1 << " a2: " << a2 << endl;

    return 0;
}
