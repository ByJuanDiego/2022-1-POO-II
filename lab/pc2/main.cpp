#include "P1.h"
#include "P2.h"
#include <vector>
#include <iostream>
#include "P1.h"

#include <vector>


using namespace std;

int main() {
//    vector<long long int> vec;
//    int n;
//    while (cin >> n){
//        vec.push_back(n);
//    }
//    remove_duplicates(vec);
//    for (const auto &value : vec){
//        std::cout << value << std::endl;
//    }

    vector<long> vec;
    int n;
    while (cin >> n){
        vec.emplace_back(n);
    }

    auto result = find_max_product(vec);
    std::cout << result << endl;

    return 0;
}
