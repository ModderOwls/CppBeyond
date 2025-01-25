#pragma once

#include <iostream>
#include <vector>
#include <ctime> // For std::tm

#include "Transactie.h"

class Bankrekening {
public:
    Bankrekening(double startSaldo = 0.0);

    Bankrekening& operator+(double bedrag);
    Bankrekening& operator-(double bedrag);

    friend std::ostream& operator<<(std::ostream& os, const Bankrekening& rekening);

private:
    double saldo;
    std::vector<Transactie> transactieHistorie;
    std::tm get_time() const;
};
