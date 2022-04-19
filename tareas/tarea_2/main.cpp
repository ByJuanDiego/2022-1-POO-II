#include "P1.h"
#include "P2.h"
#include "P3.h"
#include "P4.h"
#include "P5.h"
#include "P6.h"
#include "P7.h"
#include "P8.h"
#include "P9.h"
#include "P10.h"

void ejercicio_1(){
    // Por default el template retorna un std::string
    auto text = input();
    auto entero = input<int>("Ingrese un numero: ");
    auto real = input<double>("Ingrese un numero: ");
    std::cout << "El texto es: " << text << endl;
    std::cout << "El entero es: " << entero << endl;
    std::cout << "El real es: " << real << endl;
}

void ejercicio_2(){
    // Vector
    std::vector<int> vec = {10, 20, 30, 40, 50, 60};
    // Imprimir en consola
    print(begin(vec), end(vec), std::cout, "-");
    // Grabarlos en un archivo
    std::ofstream file("out.txt");
    print(begin(vec), end(vec), file, "|");
    // Imprimir la mitad de valores
    auto last_it = next(begin(vec), vec.size() / 2);
    print(begin(vec), last_it, std::cout, "-");
}

void ejercicio_3(){
    // Contenedor
    std::list<double> lst = {10.5, 20.4, 30.2, 40.5, 50.9, 60.5};
    cout << "Total: " << sumarizar(begin(lst), end(lst), 0) << endl;
    // Calcular la mitad de valores inferior
    auto last_it = next(begin(lst), lst.size() / 2);
    cout << "Sumatoria de la mitad: " << sumarizar(begin(lst), last_it, 0) << endl;
}

void ejercicio_4(){

    smart_ptr<int> sp1; // puntero inteligente no inicializado
    sp1 = make_smart_ptr<int>(10);
    cout << *sp1 << endl;   // Imprimiendo el contenido
    smart_ptr<string> sp2 = make_smart_ptr<string>("Hola");
    cout << *sp2 << endl;

    smart_ptr<point> sp3; // puntero inteligente no inicializado
    sp3 = make_smart_ptr<point>(20, 30);

    cout << *sp3 << endl;   // Imprimiendo el contenido

    smart_ptr<point> sp4 = make_smart_ptr<point>(10, 40); // puntero inteligente no inicializado
    cout << sp4->get_x() << endl;
    cout << sp4->get_y() << endl;
}

void ejercicio_5(){
    std::cout << suma_producto(1, 10, 3, 5) << endl; // El resultado seria: 25
    std::cout << suma_producto(1) << endl; // El resultado seria: 1
    std::cout << suma_producto(2, 10.5, 14.0, 1, 11.0) << endl; // El resultado seria: 46
    std::cout << suma_producto(-2, 0, 1, 0, 0) << endl; // El resultado seria: 0
}

void ejercicio_6(){
    char var1{};
    std::cout << index_of<int, char>(var1) << endl; // El resultado seria: 1
    string var2;
    std::cout << index_of<int, char, double, float, string>(var2) << endl; // El resultado seria: 4
    vector<int> var3;
    std::cout << index_of<int, char, vector<int>, list<double>>(var3) << endl; // El resultado seria: 2
    vector<double> var4;
    std::cout << index_of<int, char, vector<int>, list<double>>(var4) << endl; // El resultado seria: -1
}

void ejercicio_7(){
    std::array<int, 3> arr = {10, 20, 30};
    std::cout << "Los valores de arr son: " << arr << std::endl; // Los valores de lst son: {10, 20, 30}
    std::vector<int> vec = {10, 20, 30};
    std::cout << "Los valores de vec son: " << vec << std::endl; // Los valores de lst son: {10, 20, 30}
    std::list<int> lst = {10, 20, 30};
    std::cout << "Los valores de lst son: " << lst << std::endl; // Los valores de lst son: {10, 20, 30}
    std::map<char, int> mp = {{'a', 10}, {'b', 20}, {'c', 30}};
    std::cout << "Los valores de mp son: " << mp << std::endl; // Los valores de mp son: {{a: 10}, {b: 20}, {c: 30}}
}

void ejercicio_8(){
    cout << boolalpha << are_same<int>() << endl; // true
    cout << boolalpha << are_same<int, int , char>() << endl; // false
    cout << boolalpha << are_same<vector<int>, vector<int> , vector<int>>() << endl; // true
    cout << boolalpha << are_same<int, const int, int&, int &&>() << endl; // false
}

void ejercicio_9(){
    double arreglo[] {0, 0, 0, 4, 5, 6};
    init_array(arreglo, 2, 8, 2);   // Se puede configurar el valor inicial (2)
    // valor siguiente al final (8) y
    // el paso (2)
    for (const auto& i: arreglo)
        std::cout << i << " ";
    std::cout << std::endl;
    // output: 2 4 6 4 5 6
}

void ejercicio_10(){

    array<int, 4> arr = { 40, 10, 25, 20 };
    searcher<array<int, 4>> s1 = arr;
    for (const auto& i: arr)
        cout << i << " ";
    cout << endl;                // 10 20 25 40
    auto index = (s1 << 10);
    cout << index << endl;      // 0

    vector<int> vec = {5, 1, 2, 3, 5, 7, 7};
    searcher<vector<int>> s2 = vec;
    for (const auto& i: vec)
        cout << i << " ";
    cout << endl;                // 1 2 3 5 5 7 7
    cout << (s2 << 10) << endl;  // -1


}

int main() {

//    ejercicio_1();
//    ejercicio_2();
//    ejercicio_3();
//    ejercicio_4();
//    ejercicio_5();
//    ejercicio_6();
//    ejercicio_7();
//    ejercicio_8();
//    ejercicio_9();
    ejercicio_10();

    return 0;
}
