#include <iostream>
#include <string>
#include <fstream>

#include <stack>
#include <queue> // Tanto queue como priority queue

#include <deque>
#include <vector>

#include <functional>
#include <type_traits>

using namespace std;

template< typename T, template<typename ...> class Adapter, typename Function, typename ... Params>
void for_adapter(Adapter<T, Params...>& adapter, const Function& fn){
    while (!adapter.empty()){
        if constexpr (is_same_v<queue<T>, Adapter<T, Params...>>){
            fn(adapter.front());
        }
        else{
            fn(adapter.top());
        }
        adapter.pop();
    }
}

template<typename T>
void print(const T& val){
    std::cout << val << " ";
}

// Stack

void ejemplo1(){
    std::deque<int> q = {1, 2, 3, 4};
    std::stack<int, deque<int>> s(q);

    for_adapter<int, std::stack, std::function<void(const int&)>, std::deque<int>> (s, print<int>);
    std::cout << std::endl;
}

void ejemplo2(){
    std::vector<int> q = {1, 2, 3, 4};
    std::stack<int, vector<int>> s(q);

    for_adapter<int, std::stack, std::function<void(const int&)>, std::vector<int>> (s, print<int>);
    std::cout << std::endl;
}

// Qeque

void ejemplo3(){
    ifstream file("../in.txt", ios::in);
    std::deque<int> dq {std::istream_iterator<int>(file), std::istream_iterator<int>()};
    std::stack<int, deque<int>> s(dq);

    for_adapter(s, print<int>);
    std::cout << std::endl;
}

void ejemplo4(){
    ifstream file("../in.txt", ios::in);
    std::deque<int> dq {std::istream_iterator<int>(file), std::istream_iterator<int>()};
    std::queue<int, deque<int>> q(dq);

    for_adapter(q, print<int>);
    std::cout << std::endl;
}

// Priority Queue

void ejemplo5(){
    ifstream file("../in.txt", ios::in);
    std::priority_queue<int> pq {std::istream_iterator<int>(file), std::istream_iterator<int>()};
    for_adapter(pq, print<int>);
    std::cout << std::endl;
}

void ejemplo6(){
    std::deque<int> dq {1, 2, 3, 4};
    std::priority_queue<int> pq {dq.begin(), dq.end()};
    for_adapter(pq, print<int>);
    std::cout << std::endl;
}

void ejemplo7(){
    less<string> ls {};
    std::cout << std::boolalpha << ls(std::string("Hola"), std::string("Chau")) << std::endl; // Hola < Chau
    greater<int> gt {};
    std::cout << std::boolalpha << gt(20, 10) << std::endl; // 20 > 10
}

// Priority Queue con clases definidas

class person_t {
private:
    string nombre;
    int edad;
public:
    person_t(std::string name, int age) : nombre(move(name)), edad(age) {};

    [[nodiscard]] bool operator < (const person_t& other) const {return edad < other.edad;}
    [[nodiscard]] bool operator == (const person_t& other) const {return edad == other.edad;}
    [[nodiscard]] bool operator > (const person_t& other) const {return edad > other.edad;}
    [[nodiscard]] int get_age() const {return this->edad;}
    [[nodiscard]] std::string get_nombre() const {return this->nombre;}

    friend ostream& operator << (ostream& os, const person_t& person){
        os << person.nombre << ", " << person.edad << ".";
        return os;
    }
};

void ejemplo8(){
    // Hace uso de las sobrecargas <, > y ==
    priority_queue<person_t, vector<person_t>, less<>> pq;
    pq.emplace("Juan", 10);
    pq.emplace("Miriam", 5);
    pq.emplace("Jose", 30);
    pq.emplace("Yair", 50);
    pq.emplace("Pedro", 34);
    pq.emplace("Ruben", 25);
    for_adapter(pq, print<person_t>);

    std::cout << endl;
}

void ejemplo9(){
    // Hace uso de las sobrecargas <, > y ==
    priority_queue<person_t, vector<person_t>, greater<>> pq;
    pq.emplace("Juan", 10);
    pq.emplace("Miriam", 5);
    pq.emplace("Jose", 30);
    pq.emplace("Yair", 50);
    pq.emplace("Pedro", 34);
    pq.emplace("Ruben", 25);
    for_adapter(pq, print<person_t>);

    std::cout << endl;
}

void ejemplo10(){
    // Hace uso de las sobrecargas <, > y ==
    priority_queue<person_t, vector<person_t>, function<bool(person_t, person_t)>> pq {greater<person_t> {}};
    pq.emplace("Juan", 10);
    pq.emplace("Miriam", 5);
    pq.emplace("Jose", 30);
    pq.emplace("Yair", 50);
    pq.emplace("Pedro", 34);
    pq.emplace("Ruben", 25);
    for_adapter(pq, print<person_t>);

    std::cout << endl;
}

void ejemplo11(){
    // Comparador definido fuera de la clase
    std::function<bool(person_t, person_t)> compare_by_name = [&](const person_t& p1, const person_t& p2) -> bool{
        return p1.get_nombre() > p2.get_nombre();
    };

    priority_queue<person_t, vector<person_t>, function<bool(const person_t&, const person_t&)>> pq {compare_by_name};
    // priority_queue<person_t, vector<person_t>, decltype(compare_by_name)> pq {compare_by_name};

    pq.emplace("Juan", 10);
    pq.emplace("Miriam", 5);
    pq.emplace("Jose", 30);
    pq.emplace("Yair", 50);
    pq.emplace("Pedro", 34);
    pq.emplace("Ruben", 25);
    for_adapter(pq, print<person_t>);

    std::cout << endl;
}

int main() {

    // Stack
    ejemplo1();
    std::cout << "-------------------------" << std::endl;
    ejemplo2();
    std::cout << "-------------------------" << std::endl;

    // Queue
    ejemplo3();
    std::cout << "-------------------------" << std::endl;
    ejemplo4();
    std::cout << "-------------------------" << std::endl;

    // Priority Queue

    ejemplo5();
    std::cout << "-------------------------" << std::endl;
    ejemplo6();
    std::cout << "-------------------------" << std::endl;
    ejemplo7();
    std::cout << "-------------------------" << std::endl;
    ejemplo8();
    std::cout << "-------------------------" << std::endl;
    ejemplo9();
    std::cout << "-------------------------" << std::endl;
    ejemplo10();
    std::cout << "-------------------------" << std::endl;
    ejemplo11();
    return 0;
}
