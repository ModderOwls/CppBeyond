
#include "Transactie.h"

Transactie::Transactie(std::string schrijving, double hoeveelheid, const std::tm& datum) 
{
    this->schrijving = schrijving;
    this->hoeveelheid = hoeveelheid;
    this->datum = datum;
}

std::ostream& operator<<(std::ostream& os, const Transactie& transactie)
{
    os << transactie.schrijving
        << " van " << transactie.hoeveelheid
        << ", datum: " << transactie.datum.tm_mday << " - " << transactie.datum.tm_mon + 1; //Date: Day - Month

    return os;
}