// PublishersHT.cpp
#include "PublishersHT.h"
#include <cstring>

PublishersHT::PublishersHT(int size) : size(size) {
    data = new PubVal*[size]();
}

PublishersHT::~PublishersHT() {
    clear();
    delete[] data;
}

int PublishersHT::hash(const std::string& s) const {
    unsigned long h = 0;
    for (char c : s) h = h * 31 + (unsigned char)c;
    return (int)(h % size);
}

bool PublishersHT::add(Publisher* p) {
    if (!p) return false;
    std::string key = p->name;
    int idx = hash(key);
    PubVal* node = new PubVal{p, key, nullptr};
    node->next = data[idx];
    data[idx] = node;
    return true;
}

Publisher* PublishersHT::get(const std::string& name) const {
    int idx = hash(name);
    PubVal* cur = data[idx];
    while (cur) {
        if (cur->key == name) return cur->publisher;
        cur = cur->next;
    }
    return nullptr;
}

bool PublishersHT::has(const std::string& name) const {
    return get(name) != nullptr;
}

bool PublishersHT::remove(const std::string& name) {
    int idx = hash(name);
    PubVal* cur = data[idx];
    PubVal* prev = nullptr;
    while (cur) {
        if (cur->key == name) {
            if (prev) prev->next = cur->next;
            else data[idx] = cur->next;
            delete cur->publisher;
            delete cur;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

void PublishersHT::clear() {
    for (int i = 0; i < size; ++i) {
        PubVal* cur = data[i];
        while (cur) {
            PubVal* next = cur->next;
            delete cur->publisher;
            delete cur;
            cur = next;
        }
        data[i] = nullptr;
    }
}
