#ifndef ENTRIESL_H
#define ENTRIESL_H

#include <string>
#include <QDebug>

struct Entry {
    Entry* next;
    Entry* prev;

    std::string card;
    std::string cipher;
    std::string issueDate;
    std::string returnDate;
};

class EntriesL {
public:
    EntriesL();
    ~EntriesL();

    void add(const std::string& card, const std::string& cipher, const std::string& issueDate, const std::string& returnDate);
    Entry* find(const std::string& card);
    void print() const;
    void clear();
    int size() const;

private:
    Entry* head;
    Entry* tail;
};

#endif // ENTRIESL_H
