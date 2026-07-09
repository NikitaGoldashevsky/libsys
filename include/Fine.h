// Fine.h
#ifndef FINE_H
#define FINE_H

#include <string>

struct Fine {
    std::string id;          // уникальный идентификатор штрафа (например F001)
    std::string card;        // номер билета читателя
    std::string cipher;      // шифр книги, за которую назначен штраф
    double amount;           // сумма штрафа
    std::string reason;      // причина штрафа
    bool paid;               // оплачен ли штраф
};

#endif // FINE_H
