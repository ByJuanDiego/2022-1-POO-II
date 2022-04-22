#include <iostream>
#include <numeric>

// Contenedores Secuenciales
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <list>         // lista doblemente enlazadas
#include <forward_list> // lista simplemente enlazada

// Contenedores Asociativos
#include <map>
#include <set>

using namespace std;

class A{
    private:
        int x = 0;
    public:
        A(int n){
            this->x = n;
            cout << x << " constructor por parametros" << endl;
        };
        A(const A& other){
            this->x = other.x;
            cout << x << " constructor copia " << endl;
        }
        A& operator=(const A& other){
            this->x = other.x;
            cout << x << " constructor asignacion copia" << endl;
            return *this;
        }
        A(A&& other){
            this->x = other.x;
            cout << x << " constructor move" << endl;
        }
        A& operator=(A&& other){
            this->x = other.x;
            cout << x << " constructor asignacion move" << endl;
            return *this;
        }
};

template<typename SecuencialContainer>
void print(SecuencialContainer &arr){
    cout << "{";
    for (auto it = begin(arr); it != end(arr); it++){
        typename SecuencialContainer::value_type val = *it;
        cout << val << ((it == prev(end(arr))? "":", "));
    }
    cout << "}" << endl;
}

void ejemplo_array(){
    cout << __PRETTY_FUNCTION__  << endl;
    // Es de tamaño invariable
    // Almacenamiento secuancial en el stack
    // Mas ligera que un vector
    // Eficiente para el almacenamiento de una cantidad predeterminada de valores

    array<int, 5> arr = {1, 2, 3, 4};
    arr.at(4) = 5; // at() da un error cuando se accede a un subindice que excede el limite

    print(arr);
    int& x = arr.front();  // returns a reference to the first element in the array container
    int& y = arr.back();   // returns a reference to the last element in the array container
    x++;
    y++;
    print(arr);
    arr.fill(1); // inicializa todos los valores
    print(arr);
    cout << "front: " << arr.front() << " back: " << arr.back() << endl;
    cout << "size: " << arr.size() << endl;
    cout << "is empty: " << boolalpha << arr.empty() << endl; // true if the container is empty, false otherwise
    cout << endl;
}

void ejemplo_vector(){
    cout << __PRETTY_FUNCTION__ << endl;
    // Los valores se guardan en la memoria dinamica de forma continua
    // Complejiddad de acceso aleatorio a los datos de O(1)
    // Complejidad de inserción y borrado al final de O(1)
    // Complejidad de inserción y borrado al comienzo e interior de O(n)
    // Mayor uso de memoria a comparacion del std::array
    // Es ineficiente para la inserción y borrado al inicio

    vector<int> v(5);

    // iota rellena un vector con numeros seguidos
    std::iota(v.begin(), v.end(), 1);

    // reverse iterator para iterar un contenedor al revés
    vector<int>::reverse_iterator it;
    for (it = v.rbegin(); it != v.rend(); it++){
        cout << *it << " ";
    }
    cout << endl << endl;
}

void ejemplo_deque(){
    cout << __PRETTY_FUNCTION__ << endl;
    std::deque<int> a;
    cout << endl;
}

void f(std::vector<A>& v, int&& n){
    cout << "------" << endl;
    v.push_back(A(n));
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
}

void ejemplo_vector_push_back(){
    cout << __PRETTY_FUNCTION__ << endl;

    // vector<A> vec(6, A(1)); // crea 6 instancias
    int n = 6;
    vector<A> vec;
    vec.reserve(n); // reserva memoria para 6 instancias (capacity)
    
    f(vec, 10);
    f(vec, 20);
    f(vec, 30);
    f(vec, 40);
    f(vec, 50);
    f(vec, 60);
    f(vec, 70); //  duplica el capacity

    // los vectores no son eficientes para insertar al inicio
    cout << "------" << endl;
    vec.insert(begin(vec), A(5));
    cout << "size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;
    cout << "------" << endl;
}

void ejemplo_vector_emplace_back(){
    cout << __PRETTY_FUNCTION__ << endl;
    cout << endl;
}


int main() {
    ejemplo_array();
    ejemplo_vector();
    ejemplo_vector_push_back();
    return 0;
}
