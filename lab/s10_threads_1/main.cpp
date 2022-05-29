#include <iostream>
#include <thread>
#include <cmath>
using namespace std;

#define EX1
//#define EX2

class point_t{
private:
    int x, y;
public:
    point_t(int x, int y): x(x), y(y) {};
    void show () const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
    void calcular_distancia(int x2, int y2, double& distance) const {
        distance = sqrt(pow((x2-x), 2) + pow((y2-y), 2));
    }
};

void sumar(int a, int b, int* ptr){
    std::cout << __PRETTY_FUNCTION__  << ": " << this_thread::get_id() << std::endl;
    *ptr = a + b;
}
void sumar(int a, int b, int& num){
    std::cout << __PRETTY_FUNCTION__  << ": " << this_thread::get_id() << std::endl;
    num = a+b;
}

void ejemplo1(){
    void (*f1)(int, int, int&) = &sumar;
    void (*f2)(int, int, int*) = &sumar;

    int suma = 0;

    std::cout << "-------------------------" << std::endl;
    thread t1(f1, 10, 40, ref(suma));
    t1.join();
    std::cout << suma << std::endl;

    std::cout << "-------------------------" << std::endl;
    thread t2 (f2, 20, 20, &suma);
    t2.join();
    std::cout << suma << std::endl;
}

void ejemplo1_lambda(){
    int suma = 0;
    std::cout << "-------------------------" << std::endl;

    thread t1([&](){ sumar(10, 60, suma);});
    t1.join();
    std::cout << suma << std::endl;

    std::cout << "-------------------------" << std::endl;
    thread t2 ([&](){ sumar(10, 20, &suma);});
    t2.join();
    std::cout << suma << std::endl;
}

void ejemplo2(){
    point_t point(10, 20);
    std::cout << "-------------------------" << std::endl;
    thread t1(&point_t::show, &point);
    t1.join();

    double distance = 0;
    thread t2(&point_t::calcular_distancia, &point, 20, 40, ref(distance));
    t2.join();
    cout << "Distancia: " << distance << endl;
}

void ejemplo2_lambda(){
    point_t point(10, 20);
    std::cout << "-------------------------" << std::endl;
    thread t1([&](){point.show();});
    t1.join();

    double distance = 0;
    thread t2([&]() {point.calcular_distancia(20, 40, distance);});
    t2.join();
    cout << "Distancia: " << distance << endl;

}

int main() {
    std::cout << __PRETTY_FUNCTION__  << ": "  << this_thread::get_id() << std::endl;

#if defined(EX1)

    ejemplo1();
    ejemplo1_lambda();

#elif defined(EX2)

    ejemplo2();
    ejemplo2_lambda();

#endif

    return 0;
}
