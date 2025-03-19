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
    sort();
}

Entry* EntriesL::get(const std::string& card, const std::string& cipher) {
    Entry* current = head;
    while (current) {
        if (current->card == card && current->cipher == cipher) {
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

void EntriesL::sort() {
    if (!head || !head->next) return;

    bool swapped;
    do {
        swapped = false;
        Entry* current = head;
        while (current->next) {
            if (current->cipher > current->next->cipher) {
                std::swap(current->card, current->next->card);
                std::swap(current->cipher, current->next->cipher);
                std::swap(current->issueDate, current->next->issueDate);
                std::swap(current->returnDate, current->next->returnDate);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

void EntriesL::remove(const std::string& card, const std::string& cipher) {
    Entry* current = head;
    while (current) {
        if (current->card == card && current->cipher == cipher) {
            if (current->prev) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            delete current;
            sort();
            return;
        }
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

std::string EntriesL::getCardsByCipher(const std::string& cipher, bool notReturned) const {
    std::string result;
    Entry* current = head;
    while (current) {
        if (current->cipher == cipher) {
            if (!notReturned || (notReturned && (current->returnDate == "-"))) {
                if (!result.empty()) {
                    result += " ";
                }
                result += current->card;
            }
        }
        current = current->next;
    }
    return result;
}

std::string EntriesL::getCiphersByCard(const std::string& card) const {
    std::string result;
    Entry* current = head;
    while (current) {
        if (current->card == card) {
            if (!result.empty()) {
                result += " ";
            }
            result += current->cipher;
        }
        current = current->next;
    }
    return result;
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
