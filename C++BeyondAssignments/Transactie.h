#pragma once

#include <iostream>

class Transactie 
{
    public:
        Transactie(std::string schrijving, double hoeveelheid, const std::tm& datum);

        friend std::ostream& operator<<(std::ostream& os, const Transactie& transactie);

    private:
        std::string schrijving;
        double hoeveelheid;
        std::tm datum;
};