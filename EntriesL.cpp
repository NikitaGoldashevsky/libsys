#include "EntriesL.h"
#include <iostream>

EntriesL::EntriesL() : head(nullptr), tail(nullptr) {}

EntriesL::~EntriesL() {
    clear();
}

void EntriesL::add(const std::string& card, const std::string& cipher, const std::string& issueDate, const std::string& returnDate) {
    Entry* newEntry = new Entry{ nullptr, tail, card, cipher, issueDate, returnDate };
    if (tail) {
        tail->next = newEntry;
    } else {
        head = newEntry;
    }
    tail = newEntry;
}

Entry* EntriesL::find(const std::string& card) {
    Entry* current = head;
    while (current) {
        if (current->card == card) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void EntriesL::print() const {
    Entry* current = head;
    while (current) {
        qDebug() << "Card: " << current->card << ", Cipher: " << current->cipher
                  << ", Issue Date: " << current->issueDate << ", Return Date: " << current->returnDate;
        current = current->next;
    }
}

void EntriesL::clear() {
    Entry* current = head;
    while (current) {
        Entry* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}

int EntriesL::size() const {
    int count = 0;
    Entry* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

bool EntriesL::has(const std::string& card, const std::string& cipher) const {
    Entry* current = head;
    while (current) {
        if (current->card == card && current->cipher == cipher) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void EntriesL::fillTableWidget(QTableWidget* tableWidget) {
    if (!tableWidget) return;

    tableWidget->setRowCount(0);
    int row = 0;

    Entry* current = head;
    while (current) {
        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(current->card)));
        tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(current->cipher)));
        tableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(current->issueDate)));
        tableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(current->returnDate)));

        row++;
        current = current->next;
    }
}
