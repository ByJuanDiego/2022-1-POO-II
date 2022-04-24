#include <memory>
#include <iostream>
#include <vector>

using namespace std;

class B{
public:
    B() {
        cout << "constructor default" << endl;
    }
    ~B(){
        cout << "destructor" << endl;
    }
};

void f1(){
    // construye y libera automaticamente
    unique_ptr<B> temp = make_unique<B>();
    // llama al destructor al salir del scope
}

unique_ptr<B> f2(){
    unique_ptr<B> temp = make_unique<B>();
    return std::move(temp);
    // extiende la existencia del unique_ptr<> fuera de este scope
}

void ejemplo_unique(){
    /* Punteros no compartidos
    Están diseñados para asignar memoria a un único puntero
    */
    cout << __PRETTY_FUNCTION__ << endl;
    unique_ptr<int> uniquePtr1 = make_unique<int>(10);
    // uniquePtr1 -----> (10)
    cout << "*uniquePtr1: " << *uniquePtr1 << endl;

    unique_ptr<int> uniquePtr2 = std::move(uniquePtr1);
    // uniquePtr1 -----> nullptr
    // uniquePtr2 -----> (10)
    cout << "*uniquePtr2: " << *uniquePtr2 << endl;

}

void ejemplo_shared(){
    /* Punteros compartidos
    Están diseñados para escenarios complejos donde se requiere compartir la propiedad de la memoria.
    Cuenta adicionalmente con una referencia a un contador que registra el número de propietarios.

    use_count(): retorna el número de shared_ptr que comparten la propiedad de un objeto manejado.
    reset()    : libera la referencia al objeto manejado, equivalente a asignar a un puntero tradicional el valor nullptr.
    get()      : retorna el puntero original.
    operator bool(): retorna false si esta vacío, equivalente a la verificar si un puntero tradicional apunta a nullptr.

    */

    cout << endl << endl << __PRETTY_FUNCTION__ << endl;
    shared_ptr<int> sharedPtr1 = make_shared<int>(5);
    cout << "*sharedPtr1: " << *sharedPtr1 << endl;

    shared_ptr<int> sharedPtr2 = sharedPtr1;

    cout << "Count: " << sharedPtr2.use_count() << endl;
    {
        shared_ptr<int> sharedPtr3 = sharedPtr1;
        cout << "Count: " << sharedPtr1.use_count() << endl;
        sharedPtr3.reset();
    }
    cout << "Count: " << sharedPtr1.use_count() << endl;

    sharedPtr2.reset();   // nullptr
    if (!(sharedPtr2.operator bool())){
        cout << "sharedPtr2 es un puntero nulo" << endl;
    }
    cout << "Count: " << sharedPtr1.use_count() << endl;
}

void ejemplo_vector(){
    cout << endl << __PRETTY_FUNCTION__  << endl;
    vector<unique_ptr<int>> vec;
    vec.reserve(10);

    for (int i=0; i<10; i++){
        vec.push_back(make_unique<int>(i));
    }

    for (const auto& ptr: vec){
        cout << *ptr << " ";
    }
    cout << endl;

    vec.clear(); // Para poder reutilizar el vector
}

struct W; // Forward declaration

struct S{
    weak_ptr<W> atr_w;
    ~S()  { cout << "destructor S" << endl;}
};

struct W{
    weak_ptr<S> atr_s;
    ~W() { cout << "destructor W" << endl;}
};

void ejemplo_weak(){
    /* Punteros compartidos
        No puede reservar memoria, se usa como complemento del shared_ptr<>
     */
    cout << endl << endl << __PRETTY_FUNCTION__ << endl;

    shared_ptr<S> s1 = make_shared<S>();
    {
        shared_ptr<W> w1 = make_shared<W>();
        s1->atr_w = w1;
        w1->atr_s = s1;
        cout << s1.use_count() << endl;
        cout << w1.use_count() << endl;
    }
    cout << s1.use_count() << endl;
}

int main() {

    ejemplo_unique();
    ejemplo_shared();
    ejemplo_weak();

    f1();
    auto ptr = f2();

    ejemplo_vector();
    cout << "Fin del main" << endl;

    return 0;
}
