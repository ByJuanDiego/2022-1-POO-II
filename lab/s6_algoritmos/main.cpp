#include <iostream>
#include <vector>
#include <cmath>
#include <functional>

//#define PATRONES
#define EJEMPLOS
using namespace std;
using namespace std::placeholders;

template<typename Container>
void print(Container& vec){
    typename Container::iterator it;
    for (it = vec.begin(); it != vec.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void patron_1(){
    cout << __PRETTY_FUNCTION__  << endl;
    // function(FirstItr, LastItr);

    std::vector<int> v = {10, 1, 4, 7, 8};
    std::sort(begin(v), end(v));    // {1 4 7 8 10}
    print(v);
}

void patron_2(){
    cout << __PRETTY_FUNCTION__  << endl;
    // function(FirstItr, LastItr, Value);

    std::vector<int> v = {10, 2, 4, 7, 8};
    auto iter = std::find(std::begin(v), std::end(v), 7);

    if (iter != std::end(v)){
        std::cout << *iter << std::endl;
    }
}

void patron_3(){
    cout << __PRETTY_FUNCTION__  << endl;
    // function(FirstItr1, LastItr1, FirstItr2);

    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {4, 5, 6};
    std::copy(v1.begin(), v1.end(), v2.begin());

    std::vector<int> v3;
    std::copy(std::begin(v1), std::end(v1), std::back_inserter<std::vector<int>>(v3));

    print(v3);
}

void patron_4(){
    cout << __PRETTY_FUNCTION__ << endl;
    // function(FirstItr1, LastItr1, FirstItr2, LastItr2, FirstItr3);

    std::vector<int> v1 = {1, 5, 0};
    std::vector<int> v2 = {100, 11, 5, 6, 9};
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    std::vector<int> v3;

    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v3));

    print(v3);
}

// Funciones
bool is_par_function(int n){
    return n%2==0;
}

// Funcion Lambda
const auto is_par_lambda(
    [] (auto n) {
        return (n % 2 == 0);
    }
);

// Funcion Objeto
struct is_par_functor{
    bool operator() (int n){
        return n%2==0;
    }
};

// Metodo de clase
class is_par_class{
public:
    bool method(int n){
        return n%2==0;
    }
};

void patron_5(){
    cout << __PRETTY_FUNCTION__  << endl;
    // function(FirstItr, LastItr, Predicate);

    std::vector<int> v1 = {10, 2, 3, 4, 1};
    print(v1);
    auto it = remove(v1.begin(), v1.end(), 2);
    print(v1);
    v1.erase(it, end(v1));
    print(v1);

    v1.erase(
            // Funcion Lambda
            remove_if(v1.begin(), v1.end(), is_par_lambda),
            v1.end());
    print(v1);

    std::vector<int> v2 = {10, 2, 3, 4, 1};
    is_par_functor functor;

    v2.erase(
            // Funcion objeto
            remove_if(v2.begin(), v2.end(), functor),
            v2.end());
    print(v2);
}

void ejemplo_puntero_funcion(){
    cout << __PRETTY_FUNCTION__ << endl;

    // Puntero a funcion
    bool (*ptr_funcion)(int) = &is_par_function;
    cout << std::boolalpha << ptr_funcion(3) << endl;

    is_par_class instance;
    // Puntero a metodo
    bool (is_par_class::*ptr_method1)(int) = &is_par_class::method;
    cout << boolalpha << (instance.*ptr_method1)(4) << endl;

    // Puntero a metodo (std::placeholders)
    auto ptr_method_2 = std::bind(&is_par_class::method, &instance, placeholders::_1);
    cout << boolalpha << ptr_method_2(2) << endl;
}

void ejemplo_lambda(){
    cout << __PRETTY_FUNCTION__  << endl;
    // [=] acceso a todos como lectura (no modificacion)
    // [&] acceso a todos como escrituta (modificacion)

    auto sumar = [](auto a, auto b) {
        return a+b;
    };

    auto exponente_raiz = 1/3.0;
    auto raiz_cubica = [=] (auto base) {
        return pow(base, exponente_raiz);
    };

    cout << sumar(10, 20) << endl;
    cout << raiz_cubica(8) << endl;
}



int main() {

#if defined(PATRONES) // Directiva de pre procesamiento

    patron_1();
    patron_2();
    patron_3();
    patron_4();
    patron_5();

#endif

#if defined(EJEMPLOS)

    ejemplo_puntero_funcion();
    //ejemplo_lambda();

#endif

    return 0;
}
