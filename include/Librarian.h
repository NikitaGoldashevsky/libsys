// Librarian.h
#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include <string>

struct Librarian {
    std::string id;        // уникальный ID (например L001)
    std::string fio;       // ФИО библиотекаря
    std::string position;  // должность
    std::string workShift; // смена (например "утренняя", "вечерняя")
};

#endif // LIBRARIAN_H
