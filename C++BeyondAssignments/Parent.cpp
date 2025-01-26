#include <iostream>
#include "Parent.h"

Parent::Parent(std::string name) {
    this->name = name;
    std::string childName = "ChildOf" + name;
    this->child = new Child(childName);
}

Parent::Parent(const Parent& other) {
    std::cout << "Parent cctor" << std::endl;
    this->name = other.name;
    this->child = new Child(*other.child);
}

Parent::~Parent() {
    std::cout << "Parent dtor : " << this->name << std::endl;
    delete this->child;
}

Parent& Parent::operator=(const Parent& other) {
    std::cout << "Parent assignment" << std::endl;

    if (this == &other) return *this;

    this->name = other.name;
    delete this->child;
    this->child = new Child(*other.child);

    return *this;
}

//Move constructor.
Parent::Parent(Parent&& other) noexcept {
    std::cout << "Parent Move constructor" << std::endl;

    //Take over data of right object.
    this->name = std::move(other.name);
    this->child = other.child;

    //Ensure other parent doesn't have the child anymore.
    other.child = nullptr;
}

//Move assignment operator.
Parent& Parent::operator=(Parent&& other) noexcept {
    std::cout << "Parent Move assignment operator" << std::endl;

    //Ensure it doesn't assign itself.
    if (this == &other) return *this;

    //Delete existing data.
    delete this->child;

    //Take over data of right object.
    this->name = std::move(other.name);
    this->child = other.child;

    //Ensure other parent doesn't have the child anymore.
    other.child = nullptr;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Parent& parent) {
    os << "parent name: " << parent.name << "," << *parent.child;
    return os;
}
