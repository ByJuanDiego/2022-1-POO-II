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
        int x {};
    public:
        A():x(0){
            cout << "c por defecto" << endl;
        }
        A(int x){
            this->x = x;
            cout << "c por parametros" << endl;
        };
        A(const A& other){
            this->x = other.x;
            cout << "c copia " << endl;  
        }
        A& operator=(const A& other){
            this->x = other.x;
            cout << "c asignacion copia" << endl;
            return *this;
        }
        A(A&& other){
            this->x = other.x;
            cout << "c move" << endl;
        }
        A& operator=(A&& other){
            this->x = other.x;
            cout << "c asignacion move" << endl;
            return *this;
        }
        int get_x() const {
            return this->x;
        };
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
    // Es de tamaño invariable
    // Almacenamiento secuancial en el stack
    // Mas ligera que un vector
    // Eficiente para el almacenamiento de una cantidad predeterminada de valores

    cout << __PRETTY_FUNCTION__  << endl;
    array<int, 5> arr = {1, 2, 3, 4};
    arr.at(4) = 5; // at() da un error cuando se accede a un subindice que excede el limite

    print(arr);
    int& x = arr.front();  // returns a reference to the first element in the array container
    int& y = arr.back();   // returns a reference to the last element in the array container
    x++;
    y++;
    print(arr);
    cout << "front: " << arr.front() << " back: " << arr.back() << endl;
    cout << "size: " << arr.size() << endl;
    cout << "is empty: " << boolalpha << arr.empty() << endl; // true if the container is empty, false otherwise
}

void ejemplo_vector(){
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
        cout << *it << endl;
    }
}

void ejemplo_deque(){
    std::deque<int> a;
    
}

void ejemplo_vector_push_back(){
    int n = 10;
    vector<int> vec;
    vec.reserve(n); // afecta al capacity
}

void ejemplo_vector_emplace_back(){

}



int main() {
    // ejemplo_array();
    ejemplo_vector();
    return 0;
}
