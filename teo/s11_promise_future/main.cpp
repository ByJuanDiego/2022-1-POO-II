#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <mutex>
#include <condition_variable>

void producer(std::promise<std::string>& promise){
    promise.set_value("Hola");
}

void consumer(std::future<std::string>& future){
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "El valor del string es: " << future.get() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

void f1() {// Promise y Future
    std::promise<std::string> promise;
    std::future<std::string> future(promise.get_future());

    std::thread t1(producer, std::ref(promise));
    std::thread t2(consumer, std::ref(future));

    t1.join();
    t2.join();
}

std::mutex mtx;
std::condition_variable cv;
void producer2(std::string& value) {
    std::unique_lock ul(mtx);
    // Inicio de seccion critica

    value = "string2";

    ul.unlock();
    // Fin de seccion critica
    cv.notify_one();
}

void consumer2(std::string& value){
    std::unique_lock ul(mtx);
    cv.wait(ul, [&](){return !value.empty();});
    std::cout << "Value: " << value;
}

void f2(){// Condition variable
    std::string value;
    std::thread t1(producer2, std::ref(value));
    std::thread t2(consumer2, std::ref(value));
    t1.join();
    t2.join();
}

int sumar(int x, int y){
    return x+y;
}

void f3(){
    std::future<int> x = std::async<int(int, int)>(sumar, 5, 6);
    std::cout << x.get() << std::endl;
}

int main(){
    f1();
    return 0;
}
