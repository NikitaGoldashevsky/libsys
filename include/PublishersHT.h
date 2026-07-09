// PublishersHT.h
#ifndef PUBLISHERSHT_H
#define PUBLISHERSHT_H

#include "Publisher.h"
#include <string>
#include <vector>

struct PubVal {
    Publisher* publisher;
    std::string key;
    PubVal* next;
};

class PublishersHT {
public:
    PublishersHT(int size = 53); // простая таблица
    ~PublishersHT();

    bool add(Publisher* p);
    Publisher* get(const std::string& name) const;
    bool has(const std::string& name) const;
    bool remove(const std::string& name);
    void clear();

private:
    int size;
    PubVal** data;
    int hash(const std::string& s) const;
};

#endif // PUBLISHERSHT_H
