#include "p9.h"

int main() {

    fixed_stack<int, 100> fs1;
    std::vector<float> vc1 = {1, 2, 3, 4, 5, 6, 7, 8};
    copy(begin(vc1), end(vc1), fixed_stack_pusher(fs1));
    while (!fs1.empty()){
        cout << fs1.top() << " ";
        fs1.pop();
    }
    // 8 7 6 5 4 3 2 1

    return 0;
}
