// LibrariansHT.h
#ifndef LIBRARIANSHT_H
#define LIBRARIANSHT_H

#include "Librarian.h"
#include <string>
#include <QDebug>

struct LibVal {
    Librarian* librarian;
    std::string key;
    LibVal* next;
};

class LibrariansHT {
public:
    LibrariansHT(int size = 31);
    ~LibrariansHT();

    bool add(Librarian* l);
    Librarian* get(const std::string& id) const;
    bool has(const std::string& id) const;
    bool remove(const std::string& id);
    void clear();
    void log() const;

private:
    int size;
    LibVal** data;
    int hash(const std::string& s) const;
};

#endif // LIBRARIANSHT_H
