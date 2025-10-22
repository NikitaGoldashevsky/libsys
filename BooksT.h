#ifndef BOOKST_H
#define BOOKST_H

#include <QDebug>
#include <QTableWidget>
#include <iostream>
#include <string>
#include <QStandardItemModel>

#include "Publisher.h"

struct Book {
    std::string cipher;
    std::string authors;
    std::string name;
    Publisher* publisher;   // ← указатель
    int pubYear;
    bool inStock;

    // переопределение операторов сравнения для сравнения указателей на книги по шифрам книг
    bool operator==(const Book& other) const {
        return cipher == other.cipher;
    }

    bool operator!=(const Book& other) const {
        return !(*this == other);
    }

    bool operator<(const Book& other) const {
        return cipher < other.cipher;
    }

    bool operator>(const Book& other) const {
        return other < *this;
    }
};

// книги хранятся в памяти компьютера в виде бинарного дерева, Node - элемент дерева
struct Node {
    Node* prev = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
    Book* book;
};

class BooksT
{
public:
    BooksT();
    int height();
    void clear(); // удаление всех книг
    bool add(Book* book); // добавление книги
    void print();
    void printTraversalList();
    bool remove(Book* book); // удаление книги по указателю
    bool has(Book* book); // проверка наличия книги по указателю
    bool has(const std::string& cipher); // проверка наличия книги по шифру

    Book *get(const std::string &cipher); // получение указателя на книгу
    bool remove(const std::string &cipher); // удаление книги по шифру
    void printTraversalList(const char *sep);

    // внесение данных о книгах в модель и отображение их в QTableView
    void fillTableView(QTableView* tableView, QStandardItemModel* model, const std::string& filter = "");
private:

    // рекурсивные реализации методов
    int heightR(Node* node);
    void eraseTreeR(Node*& cur);
    bool addElemR(Node*& root, Book* book);
    void printR(Node* cur, const int level = 0);
    void printTraversalListR(Node* cur, const char* sep);
    Node* findMin(Node* node);
    bool removeElemR(Node*& root, Book* book);
    bool hasElemR(Node* cur, Book* book);

    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);
    Node* removeNode(Node* root, Book* book, bool &removed);
    int getBalance(Node* node);
    void balanceBranch(Node*& root, Node*& final);

    Node* root;
    Book *getElemR(Node *cur, const std::string &cipher);
};

#endif // BOOKST_H
