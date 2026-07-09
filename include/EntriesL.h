#ifndef ENTRIESL_H
#define ENTRIESL_H

#include <string>
#include <QDebug>
#include <QTableView>
#include <functional>
#include <QStandardItemModel>

#include "EntryObserver.h"
#include "IEntryComponent.h"

const static std::string NOT_RETURNED = "-"; // значения по умолчанию поля, содержащего дату возврата книги

#include "IEntryComponent.h"

class Entry : public IEntryComponent {
public:
    Entry* next = nullptr;
    Entry* prev = nullptr;

    std::string card;
    std::string cipher;
    std::string issueDate;
    std::string returnDate;
    std::string librarianId;

    Entry(Entry* next, Entry* prev,
          const std::string& card,
          const std::string& cipher,
          const std::string& issueDate,
          const std::string& returnDate,
          const std::string& librarianId)
        : next(next), prev(prev),
        card(card), cipher(cipher),
        issueDate(issueDate), returnDate(returnDate),
        librarianId(librarianId)
    {}

    // Реализация интерфейса
    std::string getCard() const override { return card; }
    std::string getCipher() const override { return cipher; }
    std::string getIssueDate() const override { return issueDate; }
    std::string getReturnDate() const override { return returnDate; }
    std::string getLibrarianId() const override { return librarianId; }

    void print() const override {
        qDebug() << "Entry:" << QString::fromStdString(card) << cipher.c_str();
    }
};

class EntriesL {
public:
    EntriesL();
    ~EntriesL();

    void add(const std::string& card, const std::string& cipher, const std::string& issueDate, const std::string& returnDate, const std::string& librarianId = "");
    Entry* get(const std::string& card, const std::string& cipher); // получение указателя на объект записи
    void print() const;
    void clear(); // удаление всех записей
    int size() const; // получение числа записей
    bool has(const std::string& card, const std::string& cipher) const; // проверка наличия записи

    void addObserver(EntryObserver* observer); // Метод для добавления наблюдателя
    void removeObserver(EntryObserver* observer); // Метод для удаления наблюдателя

    // получение записей, соответствующих указанному номеру читательского билета
    std::string getCiphersByCard(const std::string& card, bool notReturned = false) const;

    // внесение данных о книгах в модель и отображение их в QTableView
    void fillTableView(QTableView *tableView, QStandardItemModel* model);

    void sort(); // сортировка записей по шифрам взятых книг
    void remove(const std::string &card, const std::string &cipher); // удаление записи по соответствующим номеру билета и книге

    // получение записей, соответствующих указанному шифру взятой книги
    std::string getCardsByCipher(const std::string &cipher, bool notReturned = false) const;

    // удаление всех записей связанных с указанным шифром или номером читательского билета
    void removeAllByCard(const std::string &card);
    void removeAllByCipher(const std::string &cipher);

    // реализация паттерна "Observer"
    void setOnEntryAdded(std::function<void()> callback);

private:
    Entry* head;
    Entry* tail;

    std::vector<EntryObserver*> observers;
    void notifyObservers();
};

#endif // ENTRIESL_H
