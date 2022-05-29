#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <algorithm>

std::mutex mtx;

void increase(int& x){
    mtx.lock();     // Inicio de Sección Crítica
    x = x + 1;
    mtx.unlock();   // Fin de sección Crítica
}

void ejemplo1_mutex(){
    int x = 0;
    int nHilos = 100;
    std::vector<std::thread> vHilos(nHilos);

    for (std::thread &h: vHilos)
        h = std::thread(increase, std::ref(x));

    for (std::thread &h: vHilos)
        h.join();

    std::cout << x << std::endl;
}

void ejemplo1_atomic(){// Sólo funciona para el manejo de una operación.

    std::atomic<int> x = 0;
    int nHilos = 100;
    std::vector<std::thread> vHilos(nHilos);

    for (std::thread &h: vHilos)
        h = std::thread([&x]{x++;});

    for (std::thread &h: vHilos)
        h.join();

    std::cout << x << std::endl;
}

class cuentaBancaria{

private:
    std::condition_variable cv;
    std::mutex mtx;
    double saldo = 0;

public:
    void deposito(double importe){
        std::unique_lock ul(cuentaBancaria::mtx); // mtx.lock()
        saldo += importe;
        ul.unlock();
        cv.notify_one();    // Notifica la modificacion del saldo
    } // mtx.unlock()

    void retiro(double importe){
        std::unique_lock ul(cuentaBancaria::mtx);
        cv.wait(ul, [&](){
            return saldo > 0;
            }
        );
        // if (saldo > 0)
        saldo -= importe;
    }

    [[nodiscard]] double getSaldo() const{
        return saldo;
    }
};

void ejemplo3(){
    for (int i=0; i < 10; i++) {
        cuentaBancaria b;
        std::thread t1(&cuentaBancaria::deposito, &b, 100);
        std::thread t2(&cuentaBancaria::retiro, &b, 70);

        t1.join();
        t2.join();

        std::cout << b.getSaldo() << std::endl;
    }
}

void agregarValores(std::vector<int>& vInts, int start, int n_size){
    for (int i=start; i<(n_size+start); i++){
        std::unique_lock ul(mtx);
        vInts.push_back(i);
    }
}

void ejemplo4(){
    int n_size = 100;
    int n_hilos = 10;
    int start = 0;
    std::vector<int> vInt;
    std::vector<std::thread> vHilos(n_hilos);
    auto r = (n_size - start) / n_hilos;
    auto i = start;

    for (auto& hilo: vHilos){
        // hilo = std::thread([&](){ agregarValores(vInt, i, r);});
        hilo = std::thread(agregarValores, std::ref(vInt), i, r);
        i += r;
    }

    for (auto& hilo: vHilos){
        hilo.join();
    }

    for (const auto &value: vInt){
        std::cout << value << std::endl;
    }
}

int main() {
    ejemplo4();
    return 0;
}
