// LibrariansHT.cpp
#include "LibrariansHT.h"

LibrariansHT::LibrariansHT(int size) : size(size) {
    data = new LibVal*[size]();
}

LibrariansHT::~LibrariansHT() {
    clear();
    delete[] data;
}

int LibrariansHT::hash(const std::string& s) const {
    unsigned long h = 0;
    for (char c : s)
        h = (h * 31 + (unsigned char)c) % size;
    return (int)h;
}

bool LibrariansHT::add(Librarian* l) {
    if (!l) return false;
    int idx = hash(l->id);
    LibVal* node = new LibVal{l, l->id, data[idx]};
    data[idx] = node;
    return true;
}

Librarian* LibrariansHT::get(const std::string& id) const {
    int idx = hash(id);
    LibVal* cur = data[idx];
    while (cur) {
        if (cur->key == id)
            return cur->librarian;
        cur = cur->next;
    }
    return nullptr;
}

bool LibrariansHT::has(const std::string& id) const {
    return get(id) != nullptr;
}

bool LibrariansHT::remove(const std::string& id) {
    int idx = hash(id);
    LibVal* cur = data[idx];
    LibVal* prev = nullptr;
    while (cur) {
        if (cur->key == id) {
            if (prev) prev->next = cur->next;
            else data[idx] = cur->next;
            delete cur->librarian;
            delete cur;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

void LibrariansHT::clear() {
    for (int i = 0; i < size; ++i) {
        LibVal* cur = data[i];
        while (cur) {
            LibVal* next = cur->next;
            delete cur->librarian;
            delete cur;
            cur = next;
        }
        data[i] = nullptr;
    }
}

void LibrariansHT::log() const {
    for (int i = 0; i < size; ++i) {
        LibVal* cur = data[i];
        while (cur) {
            qDebug() << "Librarian:" << QString::fromStdString(cur->key)
            << "-" << QString::fromStdString(cur->librarian->fio);
            cur = cur->next;
        }
    }
}
