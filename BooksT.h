#ifndef BOOKST_H
#define BOOKST_H

#include <QDebug>
#include <QTableWidget>
#include <iostream>
#include <string>

struct Book {
    std::string cipher; // NNN.MMM
    std::string authors;
    std::string name;
    std::string publisher;
    int pubYear;
    int copiesAll;
    int copiesStock;

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
    void clear();
    bool add(Book* book);
    void print();
    void printTraversalList();
    bool remove(Book* book);
    bool has(Book* book);
    bool has(const std::string& cipher);

    Book *get(const std::string &cipher);
    bool remove(const std::string &cipher);
    void printTraversalList(const char *sep);
    void fillTableWidget(QTableWidget *tableWidget, const std::string &filter = "");
private:
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
