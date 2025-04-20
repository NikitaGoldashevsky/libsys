#ifndef ENTRIESL_H
#define ENTRIESL_H

#include <string>
#include <QDebug>
#include <QTableView>
#include <functional>
#include <QStandardItemModel>

#include "EntryObserver.h"

const static std::string NOT_RETURNED = "-"; // значения по умолчанию поля, содержащего дату возврата книги

// хранение указателей в памяти реализовано в виде линейного двунаправленного списка
struct Entry {
    Entry* next;
    Entry* prev;

    std::string card; // номер билета читателя, взявшего книгу
    std::string cipher; // шифр взятой книги
    std::string issueDate; // дата взятия книги
    std::string returnDate; // дата возврата книги
};

class EntriesL {
public:
    EntriesL();
    ~EntriesL();

    void add(const std::string& card, const std::string& cipher, const std::string& issueDate, const std::string& returnDate); // добавление записи в базу данных
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
