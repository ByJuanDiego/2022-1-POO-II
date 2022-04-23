#include <iostream>
#include <numeric>

// Contenedores Asociativos
#include <map>  // std::map, std::multimap
#include <set>  // std::set, std::multiset
#include <unordered_map>
#include <unordered_set>

using namespace std;

void ejemplo_map(){
    cout << __PRETTY_FUNCTION__  << endl << endl;
    std::map<std::string, int> map1 {
        {"c", 2},
        {"a", 1},
        {"b", 1}
    };

    for (const auto &item: map1){
        cout << item.first << ": " << item.second << endl;
    }
    cout << endl;

    map1["z"] = 3;
    for (const auto &[key, value]: map1){
        // A partir de la version de C++17
        cout << key << ": " << value << endl;
    }
    cout << endl;

    auto [it, status] = map1.try_emplace("e", 10);
    cout << it->first << ": " << it->second << " --> " << boolalpha << status << endl << endl;

    for (const auto &[key, value]: map1){
        // A partir de la version de C++17
        cout << key << ": " << value << endl;
    }
    cout << endl;
}

void ejemplo_set(){
    cout << __PRETTY_FUNCTION__  << endl << endl;
    std::set<string> s1 = {"a", "z", "f"};
    s1.insert("b");
    s1.insert("e");

    for (const auto& item: s1){
        cout << item << endl;
    }
    cout << endl;
}

void ejemplo_unordered_map(){

    cout << __PRETTY_FUNCTION__  << endl;
    std::unordered_map<string, int> umap1 {{"z", 1}, {"b", 2}, {"e", 10}};
    umap1["a"] = 0;
    umap1["c"] = 5;

    for (const auto&[key, value]: umap1){
        std::cout << key << ": " << value << endl;
    }

    cout << endl;
}

int main() {
    ejemplo_map();
    ejemplo_set();
    ejemplo_unordered_map();
    return 0;
}
