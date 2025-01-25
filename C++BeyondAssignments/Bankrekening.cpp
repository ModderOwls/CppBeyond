#include "Bankrekening.h"

Bankrekening::Bankrekening(double startSaldo) 
{
    this->saldo = startSaldo;
}

std::tm Bankrekening::get_time() const {
    std::time_t t = std::time(nullptr);

    //localtime_s to be safe, but also because compiler was complaining.
    tm ltm;
    localtime_s(&ltm, &t);

    return ltm;
}

Bankrekening& Bankrekening::operator+(double bedrag) 
{
    //Dont allow negative numbers when adding/removing.
    if (bedrag < 0) {
        throw std::invalid_argument("Bedragen bij bij- of afschrijving kunnen niet negatief zijn.");
    }

    saldo += bedrag;
    transactieHistorie.emplace_back("Bijschrijving", bedrag, get_time());

    return *this;
}

Bankrekening& Bankrekening::operator-(double bedrag) 
{
    //Dont allow negative numbers when adding/removing.
    if (bedrag < 0) {
        throw std::invalid_argument("Bedragen bij bij- of afschrijving kunnen niet negatief zijn.");
    }

    saldo -= bedrag;
    transactieHistorie.emplace_back("Afschrijving", bedrag, get_time());

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Bankrekening& rekening) {
    os << "Saldo: " << rekening.saldo << "\nTransactie-historie:" << std::endl;

    for (int i = 0; i < rekening.transactieHistorie.size(); ++i) {
        os << "-" << rekening.transactieHistorie[i] << std::endl;
    }

    return os;
}