#include "tests.h"
#include "simple_list.h"


void test() {
    std::cout << "Virker det?";
    List<int> single_linked_list;
    std::cout << "\n\nTester push_front-funktionen:\n";
    single_linked_list.push_front(1);
    single_linked_list.push_front(2);
    single_linked_list.push_front(3);
    std::cout << single_linked_list.print_list();
    std::cout << "\n---------------------";
    std::cout << "\n";

    std::cout << "\n\nTester push_end-funktionen:\n";
    single_linked_list.push_end(4);
    std::cout << single_linked_list.print_list();
    std::cout << "\n---------------------";

    std::cout << "\n\nTester insert_mid-funktionen:\n";
    single_linked_list.insert_mid(3, 5);
    std::cout << single_linked_list.print_list();
        std::cout << "\n---------------------";

    std::cout << "\n\nTester reverse-funktionen:\n";
    single_linked_list.reverse();
    std::cout << single_linked_list.print_list();
        std::cout << "\n---------------------";

    std::cout << "\n\nTester delete_front()-funktionen:\n";
    single_linked_list.delete_front();
    std::cout << single_linked_list.print_list();
        std::cout << "\n---------------------";

    std::cout << "\n\nTester delete_back-funktionen:\n";
    single_linked_list.delete_back();
    std::cout << single_linked_list.print_list();
        std::cout << "\n---------------------";

    std::cout << "\n\nTester delete_mid-funktionen:\n";
    single_linked_list.delete_middle(1);
    std::cout << single_linked_list.print_list();
    std::cout << "\n---------------------";
}

