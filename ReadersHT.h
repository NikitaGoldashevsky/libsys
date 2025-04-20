#ifndef READERSHT_H
#define READERSHT_H

#include <string>
#include <QDebug>
#include <QTableWidget>
#include <QStandardItemModel>

struct Reader {
    std::string card; // номер читательского билета (ANNNN-YY)
    std::string fio; // фио читателя
    int birthYear; // год рождения читателя
    std::string address; // адрес проживания читателя
    std::string workplace; // место работы (учебы) читателя
};

// в памяти компьютера читатели хранятся в виде хеш-таблицы с цепочками элементов
struct HTVal {
    Reader* reader; //
    std::string hashKey;
    HTVal* next; // указатель на следующий элемент цепочки
};

class ReadersHT {
private:
    HTVal** data; // массив указателей на начало цепочек
    int size;

    Reader* at(const int index) const; // получение элемента по индексу (для внутреннего использования)

public:
    ReadersHT(const int size);
    ~ReadersHT();

    bool add(Reader* reader); // добавление читателя
    int hash(const std::string& str) const;
    bool has(const std::string& card) const; // проверка наличия читателя
    Reader* get(const std::string& card) const; // получения указателя на объект читателя
    bool remove(const std::string& card); // удаление читателя
    void log() const;
    void clear(); // очистка базы данных

    // внесение данных о читателях в модель и отображение их в QTableView
    void fillTableView(QTableView *tableView, QStandardItemModel* model, const std::string& fioFilter = "");
};

#endif // READERSHT_H
