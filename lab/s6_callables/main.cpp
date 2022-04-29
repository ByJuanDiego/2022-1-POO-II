#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <map>
#include <tuple>
using namespace std;

#define FORWARD
#define BIDIRECTIONAL
#define RANDOM_ACCESS

#define PRINT(EX) cout << #EX << " = " << (EX) << endl;
#define SUMA(a, b) ((a)+(b))

void ejemplo_macro(){
    cout << __PRETTY_FUNCTION__  << endl;

    PRINT(10+10)
    auto x = SUMA(10, 20);
    cout << x << endl;
}

void ejemplo_forward_iterator(){
    cout << __PRETTY_FUNCTION__  << endl;
    std::forward_list<int> fl = {1, 2, 3, 4, 5};
    std::forward_list<int>::iterator it1 = begin(fl);

    cout << (*it1) << endl;
    cout << *(++it1) << endl;
    cout << (*it1)++ << endl;
    cout << (*it1) << endl;
    cout << ++(*it1) << endl;
    /*
    * cout << --it1 << endl;
    * cout << it1 + 1 << endl;
    * it1 += 1;
    */
    for (const auto &i: fl){
        cout << i << " ";
    }
    cout << endl;

    cout << "it1: " << *it1 << endl;
    cout << "it1 + 1: " << *next(it1, 1) << endl;
    advance(it1, 1); // no retorna valor, a diferencia de next
    cout << "it1: " << *it1 << endl;
    cout << "size del forward list: " << distance(begin(fl), end(fl)) << endl;

    auto it2 = prev(it1, -1);
    cout << "it2: " << *it2 << endl;
}

void ejemplo_bidirectional_iterator(){
    cout << __PRETTY_FUNCTION__  << endl;
    std::list<int> ls = {10, 20, 30, 40};
    std::list<int>::iterator it1 = end(ls);

    cout << *(--it1) << endl;
}

void ejemplo_random_access_iterator(){
    cout << __PRETTY_FUNCTION__ << endl;
    std::vector<int> v = {10, 20, 30, 40};
    std::vector<int>::iterator it1 = begin(v);

    cout << *(it1 + 2) << endl;
    cout << it1[3] << endl;

    for (const auto &i: v){
        cout << i << " ";
    }
    cout << endl;
}

void ejemplo_begin_end(){
    cout << __PRETTY_FUNCTION__ << endl;
    int arr[] = {10, 20, 30, 40, 50};
    for (auto it = begin(arr); it != end(arr); it++){
        cout << *it << " ";
    }
    cout << endl;
}

template<typename C>
struct is_forward_iterator {
    constexpr inline static bool value = is_same_v<typename C::iterator::iterator_category, std::forward_iterator_tag>;
};

template<typename C>
constexpr bool is_forward_iterator_v = is_forward_iterator<C>::value;

template<typename C>
enable_if_t<is_forward_iterator_v<C>, void>
f1(){
    cout << "es un forward_iterator" << endl;
}

template<typename C>
typename enable_if<is_same<typename C::iterator::iterator_category, std::bidirectional_iterator_tag>::value, void>::type
f2(){
    cout << "es un bidirectional_iterator" << endl;
}

int main() {

#if defined(FORWARD)
    ejemplo_forward_iterator();
#endif

#if defined(BIDIRECTIONAL)
    ejemplo_bidirectional_iterator();
#endif

#if defined(RANDOM_ACCESS)
    ejemplo_random_access_iterator();
#endif

    ejemplo_begin_end();

    f1<forward_list<int>>();
    f2<list<int>>();

    cout << endl << "Ejecución Exitosa" << endl;
    return 0;
}
