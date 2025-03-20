#ifndef ENTRIESL_H
#define ENTRIESL_H

#include <string>
#include <QDebug>
#include <QTableWidget>

const static std::string NOT_RETURNED = "-";

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
    Entry* get(const std::string& card, const std::string& cipher);
    void print() const;
    void clear();
    int size() const;
    bool has(const std::string& card, const std::string& cipher) const;
    std::string getCiphersByCard(const std::string& card) const;
    void fillTableWidget(QTableWidget *tableWidget);
    void sort();
    void remove(const std::string &card, const std::string &cipher);
    std::string getCardsByCipher(const std::string &cipher, bool notReturned = false) const;
private:
    Entry* head;
    Entry* tail;
};

#endif // ENTRIESL_H
