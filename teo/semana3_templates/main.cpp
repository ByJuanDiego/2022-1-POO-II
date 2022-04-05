#include <iostream>
using namespace std;

class A;

class B{
    int y {};
public:
    explicit B(int x):y(x){}
    static void print(A& a);
};

class A {
    int x {};
public:
    explicit A(int x):x(x){}
    friend void B::print(A &a);
};

void B::print(A &a) {
    cout << a.x;
}

int main() {
    A a(1);
    B b(2);
    b.print(a);

    return 0;
}
