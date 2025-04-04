#ifndef READERSHT_H
#define READERSHT_H

#include <string>
#include <QDebug>
#include <QTableWidget>

struct Reader {
    std::string card; // ANNNN-YY
    std::string fio;
    int birthYear;
    std::string address;
    std::string workplace;
};

struct HTVal {
    Reader* reader;
    std::string hashKey;
    HTVal* next; // Указатель на следующий элемент
};

class ReadersHT {
private:
    HTVal** data; // Массив указателей на начало цепочек
    int size;

    Reader* at(const int index) const;

public:
    ReadersHT(const int size);
    ~ReadersHT();

    bool add(Reader* reader);
    int hash(const std::string& str) const;
    bool has(const std::string& card) const;
    Reader* get(const std::string& card) const;
    bool remove(const std::string& card);
    void log() const;
    void clear();
    void fillTableWidget(QTableWidget *tableWidget, const std::string& fioFilter = "");
};

#endif // READERSHT_H
