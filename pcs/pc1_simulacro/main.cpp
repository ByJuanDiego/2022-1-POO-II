#include "pagination.h"

int main() {
    pagination<int> pg1 = {1, 2, 3, 4, 5, 6, 5, 10, 11, 12};
    pg1.page_size(3);
    pg1++; pg1++; pg1++; pg1++;
    cout << pg1 << endl;
    pg1++;
    cout << pg1 << endl;
    pg1.front();
    pg1--;
    cout << pg1 << endl;
    pg1.back();
    cout << pg1 << endl;
    pg1--; pg1--;
    cout << pg1.current_page() << endl;
    auto pg2 = pg1;
    pg2.page_size(4);
    pg1++;
    cout << pg2 << endl;
    cout << pg1 << endl;

    cout << pg2.current_page() << " | " << pg1.current_page() << endl;
    cout << pg2.pages() << " | " << pg1.pages() << endl;


    pagination<double> pg3 = {1, 2, 3, 4, 5, 6, 5, 10, 11, 12, 3, 4, 10};
    pg3.page_size(5);
    pg3++;

    auto vec1 = generate_vector(pg3);
    for (const auto& item: vec1){
        cout << item << " ";
    }
    cout << endl;

    return 0;
}
