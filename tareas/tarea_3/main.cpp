#include "p5.h"

int main() {

    std::tuple<int, string, string, double> t1 = {1321, "Jose", "Perez", 1.68};
    int key;
    string first_name;
    string last_name;
    double height;
    unpack(key, first_name, last_name, height) = t1;
    std::cout << key <<  " "<< first_name << " " << last_name << " "  << height << endl;

    return 0;
}
