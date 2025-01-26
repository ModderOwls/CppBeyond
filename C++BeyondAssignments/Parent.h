#pragma once

#include <string>
#include <ostream>
#include "Child.h"

class Parent {
    public:
        Parent(std::string name);
        Parent(const Parent& other);
        virtual ~Parent();
        Parent& operator=(const Parent& other);

        Parent(Parent&& other) noexcept;
        Parent& operator=(Parent&& other) noexcept;

        friend std::ostream& operator<<(std::ostream& os, const Parent& parent);

    private:
        std::string name;
        Child* child;
};

