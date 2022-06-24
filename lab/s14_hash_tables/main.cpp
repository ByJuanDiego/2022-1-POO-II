#include <iostream>
#include <functional>
#include <string>
#include "chash.h"

void ejemplo_hash(){
    std::hash<int> hi;
    std::hash<bool> hb;
    std::hash<std::string> hs;

    std::cout << hi(123) << std::endl;
    std::cout << hi(234) << std::endl;

    std::cout << hs("Hola Mundo") << std::endl;
    std::cout << hs("Hola Mundi") << std::endl;

    std::cout << hb(true) << std::endl;
    std::cout << hb(false) << std::endl;
}

void ejemplo_chash(){
    close_hash_table<std::string , int> ht(10);
    auto [item, found] = ht.insert({"A", 1});
    if (found){
        std::cout << "Valor insertado: " << item->first << ", " << item->second << std::endl;
    }
    else{
        std::cout << "No inserto" << std::endl;
    }

    auto [item1, found1] = ht.insert({"A", 1});
    if (found1){
        std::cout << "Valor insertado: " << item1->first << ", " << item1->second << std::endl;
    }
    else{
        std::cout << "No inserto" << std::endl;
    }

    ht.insert({"B", 2});
    ht.insert({"C", 3});
    auto [item2, found2] = ht.find("B");
    if (found2){
        std::cout << "Valor insertado: " << item2->first << ", " << item2->second << std::endl;
    }
    else{
        std::cout << "No inserto" << std::endl;
    }

    bool removed = ht.remove("Z");
    if (removed){
        std::cout << "removido" << std::endl;
    }
    else{
        std::cout << "no removido" << std::endl;
    }

}

int main() {
    ejemplo_chash();
    return 0;
}
