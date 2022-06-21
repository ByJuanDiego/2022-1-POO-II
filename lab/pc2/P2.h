//
// Created by Juan Diego Castro Padilla on 7/06/22.
//

#ifndef PC2_P2_H
#define PC2_P2_H

#include <cmath>
#include <thread>
#include <iostream>
#include <vector>
#include <list>

int get_number_of_threads(int sz, int rng) {
    int max_threads = (sz + rng - 1) / rng;
    int k_threads = static_cast<int>(std::thread::hardware_concurrency());
    return std::min(k_threads != 0? k_threads: 2, max_threads);
}

template <typename Iterator, typename T>
void aux_maximo(Iterator start, Iterator stop, T& product){
    product *= *std::max_element(start, stop);
}

const int expected_range = 25;
template<typename T, template<typename ...> class Container>
T find_max_product(Container<T>& cont){

    int size = std::distance(cont.begin(), cont.end());
    auto n_hilos = get_number_of_threads(size, expected_range);
    int range = (size / n_hilos);
    std::vector<std::thread> v_hilos(n_hilos);
    std::cout << n_hilos << std::endl;
    T product = 1;

    auto current = cont.begin();
    std::for_each( v_hilos.begin(), std::prev(v_hilos.end()), [&](std::thread& hilo){
        hilo = std::thread(aux_maximo<decltype(cont.begin()), T>, current, std::next(current, range), std::ref(product));
        std::advance(current, range);
    });

    range = std::distance(current, cont.end());
    auto thread_it = std::prev(v_hilos.end());
    *thread_it = std::thread(aux_maximo<decltype(cont.begin()), T>, current, std::next(current, range), std::ref(product));

    for (std::thread& hilo : v_hilos){
        hilo.join();
    }

    return product;
}


#endif //PC2_P2_H
