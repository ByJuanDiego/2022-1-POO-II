#include <memory>
#include <iostream>
using namespace std;

int main() {

    /* Punteros no compartidos
        Están diseñados para asignar memoria a un único puntero
    */

    unique_ptr<int> ptr1 = make_unique<int>(10);
    // ptr1 -----> (10)
    cout << "*ptr: " << *ptr1 << endl;

    unique_ptr<int> ptr2 = std::move(ptr1);
    // ptr1 -----> nullptr
    // ptr2 -----> (10)
    cout << "*ptr2: " << *ptr2 << endl;


    /* Punteros compartidos
        Están diseñados para escenarios complejos donde se requiere compartir la propiedad de la memoria.
        Cuenta adicionalmente con una referencia a un contador que registra el número de propietarios.

        use_count(): retorna el número de shared_ptr que comparten la propiedad de un objeto manejado.
        reset()    : libera la referencia al objeto manejado, equivalente a asignar a un puntero tradicional el valor nullptr.
        get()      : retorna el puntero original.
        operator bool(): retorna false si esta vacío, equivalente a la verificar si un puntero tradicional apunta a nullptr.

     */

    shared_ptr<int> ptr3 = make_shared<int>(5);
    cout << "*ptr3: " << *ptr3 << endl;

    shared_ptr<int> ptr4 = ptr3;
    cout << "Count: " << ptr4.use_count() << endl;

    ptr4.reset();   // nullptr
    if (!(ptr4.operator bool())){
        cout << "ptr4 es un puntero nulo" << endl;
    }
    cout << "Count: " << ptr3.use_count() << endl;

    return 0;
}
