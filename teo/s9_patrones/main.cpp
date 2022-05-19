#include "Singleton.h"


int main() {

    auto obj1 = Singleton::get_instance("Instancia 1");
    std::cout << obj1->get_text() << std::endl;
    obj1->set_text("Texto");
    std::cout << obj1->get_text() << std::endl;

    auto obj2 = obj1->get_instance("Instancia 2");
    std::cout << obj1->get_text() << std::endl;
    std::cout << obj2->get_text() << std::endl;

    return 0;
}
