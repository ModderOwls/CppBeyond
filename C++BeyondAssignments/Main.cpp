#include <iostream>
#include "Parent.h"

int main() {
    auto p1 = new Parent("Parent1");
    std::cout << "p1:" << *p1 << std::endl;

    auto p2 = new Parent(*p1); // Roept de copy constructor aan
    std::cout << "p2:" << *p2 << std::endl;

    auto p3 = new Parent("Parent3");
    std::cout << "p3:" << *p3 << std::endl;

    *p3 = *p1; // Roept de assignment operator aan
    std::cout << "p1:" << *p3 << std::endl;

    //Test the move constructor.
    auto p4 = new Parent(std::move(*p1));
    std::cout << "p4:" << *p4 << std::endl;

    //Test the move assignment operator.
    *p3 = std::move(*p4);
    std::cout << "p3 (na move):" << *p3 << std::endl;

    std::cout << std::endl;

    //Looks a bit confusing in console, so an explanation:
    delete p1; //None because move constructor took data for p4.
    delete p2; //Parent 1 because it copies p1, and others aren't harmed as it doesn't delete p1's data.
    delete p3; //Parent 1 because move assignment operator moved data from p4 to here.
    delete p4; //None because despite moving data from p1 to it, p3 took p4's data afterwards.

    return 0;
}