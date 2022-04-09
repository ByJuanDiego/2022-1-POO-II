#include <iostream>
#include <array>
#include <vector>
#include <list>
using namespace std;

template <typename T, int sz>
auto get_size(const T (&)[sz]){// obtener el tamaño de un array estatico
    return sz;
}

template<typename T, size_t sz>
int get_size(std::array<T, sz>&){// obtener el tamaño de un std::array
    return sz;
}

template <template<typename...> class Container, typename T>
void push(Container<T>& contenedor, T value){// push_back para un contenedor generico
    contenedor.push_back(value);
}

template<typename Iterator>
void display(Iterator begin, Iterator end){
    for (auto it=begin; it!=end; it++){
        typename Iterator::value_type value = *it;
        cout << value << " ";
    }
    cout << endl;
}

template<int N>
constexpr int factorial(){
    return N * factorial<N-1>();
}
template<>
constexpr int factorial<0>(){
    return 1;
}

int main() {

    int arr1[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 2> arr2 {0, 1};

    cout << "arr[10] = " << get_size(arr1) << endl;
    cout << "array<int, 2> arr2 = " << get_size(arr2) << endl;

    std::vector<int> vec;
    vec.push_back(1);
    push<vector>(vec, 2);
    push<vector>(vec, 3);
    display(begin(vec), end(vec));

    std::list<double> lst;
    lst.push_back(1.1);
    push<list>(lst, 2.2);
    push<list>(lst, 3.3);
    display(begin(lst), end(lst));

    cout << "5! = " << factorial<5>() << endl;

    return 0;
}
