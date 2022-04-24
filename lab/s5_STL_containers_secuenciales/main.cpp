#include <iostream>
#include <numeric>

// Contenedores Secuenciales
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <list>         // lista doblemente enlazadas
#include <forward_list> // lista simplemente enlazada

using namespace std;

class A{
    private:
        int x = 0;
    public:
        explicit A(int n){
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
        friend ostream& operator << (ostream& os, A& a){
            os << a.x;
            return os;
        }
        int get() const{
            return x;
        }
};

template<typename SecuencialContainer>
void print(SecuencialContainer &container){
    cout << "{";
    for (auto it = begin(container); it != end(container); it++){
        // typename SecuencialContainer::value_type val = *it;
        cout << *it << ((it == prev(end(container))? "":", "));
    }
    cout << "}" << endl;
}

template<typename T>
void print(std::forward_list<T>& fls){
    cout << "{";
    for (auto itr = fls.begin(); itr != fls.end(); itr++){
        cout << *itr << ((next(itr) == end(fls))? "":", ");
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

    print<array<int, 5>>(arr);
    int& x = arr.front();  // returns a reference to the first element in the array container
    int& y = arr.back();   // returns a reference to the last element in the array container
    x++;
    y++;
    print<array<int, 5>>(arr);
    arr.fill(1); // inicializa todos los valores
    print<array<int, 5>>(arr);
    cout << "front(): " << arr.front() << " back(): " << arr.back() << endl;
    cout << "size(): " << arr.size() << endl;
    cout << "is_empty(): " << boolalpha << arr.empty() << endl; // true if the container is empty, false otherwise
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
    // No posee push_front ni emplace_front

    vector<int> v(5);

    // iota rellena un vector con numeros seguidos
    std::iota(v.begin(), v.end(), 1);

    // reverse iterator para iterar un contenedor al revés
    cout << "reverse_iterator: ";
    vector<int>::reverse_iterator it;
    for (it = v.rbegin(); it != v.rend(); it++){
        cout << *it << " ";
    }
    cout << endl << endl;
}

void f(std::vector<A>& v, int&& n, string&& str){
    cout << "------" << endl;
    if (str == "push"){
        v.push_back(A(n));
    }
    else if (str == "emplace"){
        v.emplace_back(n);
    }
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
    print<vector<A>>(v);
}

void ejemplo_vector_push_back(){
    cout << __PRETTY_FUNCTION__ << endl;

    std::size_t n = 6; // n = 8 para mas eficiencia
    // vector<A> vec(n, A(1)); // reserva memoria y crea 6 instancias
    vector<A> vec;
    // Si se conoce el tamaño del vector de antenamo es mejor reservar el espacio
    vec.reserve(n); // reserva memoria para 6 instancias

    f(vec, 10, "push");
    f(vec, 20, "push");
    f(vec, 30, "push");
    f(vec, 40, "push");
    f(vec, 50, "push");
    f(vec, 60, "push");
    //  duplica el capacity, crea un nuevo contenedor y libera el anterior
    f(vec, 70, "push");

    // los vectores no son eficientes para insertar al inicio
    cout << "------" << endl;
    // construye la instancia y despues
    // mueve todos los elementos dentro del mismo contenedor
    // si tiene espacio
    vec.insert(begin(vec), A(5));
    cout << "size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;
    print<vector<A>>(vec);
    cout << endl;

//    auto condition(
//            [](A& a){
//                return a.get() < 50;
//            }
//    );
//
//    vec.erase(remove_if(vec.begin(), vec.end(), condition), vec.end());
//    print(vec);
}

void ejemplo_vector_emplace_back(){
    // El emplace back no requiere construir y mover el objeto, lo crea internamente
    cout << __PRETTY_FUNCTION__ << endl;

    vector<A> vec;
    std::size_t n = 7;
    vec.reserve(n); // reserva memoria para 7 instancias

    f(vec, 10, "emplace");
    f(vec, 20, "emplace");
    f(vec, 30, "emplace");
    f(vec, 40, "emplace");
    f(vec, 50, "emplace");
    f(vec, 60, "emplace");

    cout << "------" << endl;
    vec.emplace(begin(vec), 5);
    cout << "size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;
    print<vector<A>>(vec);
    cout << endl;
}

void ejemplo_deque(){
    cout << __PRETTY_FUNCTION__ << endl;
    // Se comporta de manera similar a un vector
    // Posee push_front y emplace_front

    std::deque<int> dq = {2, 3, 4};
    print<deque<int>>(dq);
    dq.push_front(1);
    print<deque<int>>(dq);
    dq.push_back(5);
    print<deque<int>>(dq);
    cout << endl;
}

void ejemplo_list(){
    cout << __PRETTY_FUNCTION__ << endl;
    // No admite aritmetica de punteros
    // Pueden recorrerse

    list<int> ls = {1, 2, 4};
    print<list<int>>(ls);
    // auto it = (begin(ls)+1)); // Error
    auto it = std::next(begin(ls));
    it++; // Es admisible
    ls.insert(it, 3);

    cout << "rbegin(): ";
    for (auto itr = ls.rbegin(); itr != ls.rend(); itr++){
        // El recorrido inverso es admisible
        cout << *itr << " ";
    }
    cout << endl << endl;
}

void ejemplo_forward_list(){
    cout << __PRETTY_FUNCTION__ << endl;
    // No admite aritmetica de punteros
    // No usar prev() en un forward_list<>
    // Pueden recorrerse solo hacia adelante

    forward_list<int> fls = {2, 3, 4};
    fls.push_front(1);
    print<int>(fls);

    // auto it = (begin(ls)+1)); // Error
    auto it = std::next(begin(fls));
    cout << "next(begin): " << *it << endl;
    it++;
    cout << "it++: " << *it << endl << endl;
}

void ejemplo_lambdas(){
    cout << __PRETTY_FUNCTION__ << endl;

    vector<int> v {1, 2, 3, 2, 5, 2, 6, 2, 4, 8};

    // Imprime el vector completo
    cout << "vector:         ";
    print(v);
    const vector<int>::iterator new_end = remove(begin(v), end(v), 2);

    // Imprime el vector (mismo tamaño)
    cout << "after remove 2: ";
    print(v);

    // Elimina el resto de elementos
    v.erase(new_end, end(v));
    cout << "after erase:    ";
    print(v);

    // Funcion lambda
    const auto odd(
        [] (int n) -> bool {
            return (n % 2 != 0);
        }
    );

    // Remover los elementos sólo si cumplen una condición (odd)
    // Usar los dos metodos juntos evita que trabajemos con el vector con datos adicionales
    v.erase(remove_if(begin(v), end(v), odd), end(v));
    cout << "erase y remove_if:  ";
    print(v);

    cout << "(size: " << v.size() << ", capacity: " << v.capacity() << ")" << endl;
    v.shrink_to_fit();
    cout << "(size: " << v.size() << ", capacity: " << v.capacity() << ")" << endl;
    v.clear();
    cout << "(size: " << v.size() << ", capacity: " << v.capacity() << ")" << endl;
}

int main() {
    ejemplo_array();
    ejemplo_vector();
    ejemplo_vector_push_back();
    ejemplo_vector_emplace_back();
    ejemplo_deque();
    ejemplo_list();
    ejemplo_forward_list();
    ejemplo_lambdas();
    return 0;
}
