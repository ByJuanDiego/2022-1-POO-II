#include "polynomial.h"

int main() {

    auto x = generate_polynomial<1, 2, 3, 3, 2>(2);
    cout << x << endl;
    
    std::cout << generate_polynomial<>(1);

    {
        vector<int> vec{1, 4, 5, 2, 3};
        polynomial<int, 1, 0, 3, 4> p1 = vec;

        cout << p1 << endl;
    }

    {
        polynomial<int, 0, 1> p1 = {1, 2, 3, 4};
        cout << p1 << endl;
    }

    {
        vector<int> vec{1, 4, 5, 2, 3};
        polynomial<int, 1, 0, 3, 4> p1;
        for (const auto &item: vec) {
            p1 += item;
        }
        cout << p1 << endl;
    }

    {
        polynomial<double, 0, 1, 1, 1, 0, 1> p1 = {1.0, 2.0, 6.0, 8.0
        };
        cout << p1 << endl;
        polynomial<double, 0, 1, 1, 1, 0, 1> p2 = {1.0, 2.0, 6.0, 8.0};
        p2 += 3.5;
        cout << p2 << endl;
        cout << p1 << endl;
        return 0;
    }

}
