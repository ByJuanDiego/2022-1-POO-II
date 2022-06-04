#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <numeric>
#include <thread>
using namespace std;

void generate_file(std::string& name, int size, int _min, int _max){
    std::ofstream file(name, std::ios::out);

    if (file.fail())
        std::cout << "Error al crear el archivo: " << name << std::endl;

    std::random_device rd;
    std::uniform_int_distribution<int> dis(_min, _max);

    for (int i=0; i<size; i++){
        file << dis(rd) << std::endl;
    }
}

std::vector<int> generate_vector(std::string& name){
    std::ifstream file(name, std::ios::in);

    if (file.fail())
        std::cout << "Error al leer el archivo: " << name << std::endl;

    std::vector<int> result;
    std::copy(std::istream_iterator<int>(file), std::istream_iterator<int>(), std::back_inserter(result));

    return result;
}

void print_vector(std::vector<int>& vec){
    std::copy(std::begin(vec), std::end(vec), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

void ejemplo1(std::string file_name){
    // suma de los elementos de un vector haciendo uso de std::accumulate en un solo hilo
    std::vector<int> vec = generate_vector(file_name);
    print_vector(vec);
    std::cout << "ej1 Σ: " << std::accumulate(std::begin(vec), std::end(vec), 0) << std::endl;
}

template<typename Iterator>
void summarize(Iterator first, Iterator last, Iterator suma){
    *suma = std::accumulate(first, last, 0);
}

void ejemplo2(std::string file_name){
    vector<int> vec = generate_vector(file_name);
    int n_hilos = 4;
    auto size = vec.size();
    auto range = size / n_hilos;

    vector<thread> v_thread(n_hilos);
    vector<int> sumas(n_hilos, 0);

    auto it = vec.begin();
    auto it_sum = sumas.begin();

    for (thread& hilo : v_thread){
        if (it_sum == prev(sumas.end()))
            range = (size - range*(sumas.size()-1));
        hilo = thread(summarize<decltype(it)>, it, next(it, (int)range), it_sum);
        it_sum++;
        advance(it, range);
    }

    for (thread& hilo: v_thread){
        hilo.join();
    }

    cout << "ej2 Σ: " << accumulate(begin(sumas), end(sumas), 0) << endl;
}

int main() {

    // generate_file("../datos_20.txt", 20, 0,100 );
    // generate_file("../datos_9.txt", 9, 0, 20);
    std::string file = "../datos_9.txt";
    ejemplo1(file);
    ejemplo2(file);

    return 0;
}
