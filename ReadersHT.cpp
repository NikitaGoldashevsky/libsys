#include "ReadersHT.h"


bool ReadersHT::add(Reader* reader) {
    int hashKey = hash(reader->card);

    while (true) {
        for (int i = 0; i < collisionTries; i++) {
            if (data[hashKey] == nullptr || data[hashKey]->reader == nullptr) { // Check for empty slot or tombstone
                if (data[hashKey] == nullptr) {
                    data[hashKey] = new HTVal{reader, reader->card};
                } else {
                    data[hashKey]->reader = reader;
                }
                return true;
            } else {
                hashKey = (hashKey + collisionStep) % size;
            }
        }
        resizeTable();
    }
}

int ReadersHT::hash(const std::string& str) const {
    int hashRes = 0;
    for (const char ch : str) {
        hashRes += ((int)ch)*((int)ch);
    }
    hashRes = hashRes % size;
    return hashRes;
}

void ReadersHT::resizeTable() {
    int oldSize = size;
    HTVal** oldData = data;

    int newSize = oldSize * 2;
    data = new HTVal*[newSize]();
    size = newSize;

    for (int i = 0; i < oldSize; ++i) {
        HTVal* oldVal = oldData[i];
        if (oldVal != nullptr && oldVal->reader != nullptr) {
            Reader* reader = oldVal->reader;
            int hashKey = hash(reader->card);
            bool inserted = false;
            for (int j = 0; j < collisionTries; ++j) {
                if (data[hashKey] == nullptr) {
                    data[hashKey] = new HTVal{reader, reader->card};
                    inserted = true;
                    break;
                } else {
                    hashKey = (hashKey + collisionStep) % size;
                }
            }
            if (!inserted) {
                if (newSize > 1000000) {
                    throw std::runtime_error("Hash table resize failed: too many elements");
                }
                resizeTable();
                break;
            }
        }
    }
    for (int i = 0; i < oldSize; ++i) {
        delete oldData[i];
    }
    delete[] oldData;
}

ReadersHT::ReadersHT(const int size) {
    this->size = size;
    data = new HTVal*[size];
    for (int i = 0; i < size; i++) {
        data[i] = nullptr;
    }
}

Reader* ReadersHT::at(const int index) const {
    if (index >= size) return nullptr;
    if (data[index] != nullptr) {
        return this->data[index]->reader;
    }
    return nullptr;
}

bool ReadersHT::has(const std::string& card) const {
    return get(card) != nullptr;
}

Reader* ReadersHT::get(const std::string& card) const {
    int originalHash = hash(card);
    int currentHash = originalHash;
    for (int i = 0; i < collisionTries; i++) {
        HTVal* cur = data[currentHash];
        if (cur == nullptr) {
            return nullptr;
        }
        if (cur->hashKey == card && cur->reader != nullptr && cur->reader->card == card) {
            return cur->reader;
        }
        currentHash = (currentHash + collisionStep) % size;
    }
    return nullptr;
}

bool ReadersHT::remove(const std::string& card) {
    int originalHash = hash(card);
    int currentHash = originalHash;

    for (int i = 0; i < collisionTries; ++i) {
        HTVal* curVal = data[currentHash];
        if (curVal == nullptr) {
            return false;
        }
        if (curVal->hashKey == card && curVal->reader != nullptr && curVal->reader->card == card) {
            curVal->reader = nullptr;
            return true;
        }
        currentHash = (currentHash + collisionStep) % size;
    }
    return false;
}

void ReadersHT::log() const {
    qDebug() << "Hash Table Size:" << this->size;

    for (int i = 0; i < this->size; ++i) {
        HTVal* current = data[i];
        if (current == nullptr) {
            qDebug() << i << ") undef";
        } else if (current->reader == nullptr) {
            qDebug() << i << ") tomb";
        } else {
            qDebug() << i << ") Def - " << current->reader->fio << " - HashKey:" << QString::fromStdString(current->hashKey) << "- Hash:" << QString::number(hash(current->reader->card));
        }
    }
    qDebug() << "\n";
}

void ReadersHT::fillTableWidget(QTableWidget* tableWidget, const std::string& fioFilter) {
    if (!tableWidget) return;

    auto toLower = [](char c) -> char {
        return std::tolower(static_cast<unsigned char>(c));
    };

    auto boyerMooreSearchCaseInsensitive = [&](const std::string& text, const std::string& pattern) -> bool {
        if (pattern.empty()) return true;

        std::string lowerText;
        lowerText.reserve(text.size());
        for (char c : text) lowerText.push_back(toLower(c));

        std::string lowerPattern;
        lowerPattern.reserve(pattern.size());
        for (char c : pattern) lowerPattern.push_back(toLower(c));

        int m = lowerPattern.size();
        int n = lowerText.size();

        if (m > n) return false;

        int badChar[256];
        for (int i = 0; i < 256; i++) badChar[i] = -1;
        for (int i = 0; i < m; i++) badChar[(unsigned char)lowerPattern[i]] = i;

        int s = 0; // shift of pattern with respect to text
        while (s <= (n - m)) {
            int j = m - 1;

            while (j >= 0 && lowerPattern[j] == lowerText[s + j]) j--;

            if (j < 0) {
                return true; // found
            } else {
                s += std::max(1, j - badChar[(unsigned char)lowerText[s + j]]);
            }
        }

        return false;
    };

    tableWidget->setRowCount(0);
    int row = 0;

    for (int i = 0; i < size; ++i) {
        HTVal* current = data[i];
        if (current != nullptr && current->reader != nullptr) {
            Reader* reader = current->reader;
            if (fioFilter.empty() || boyerMooreSearchCaseInsensitive(reader->fio, fioFilter)) {
                tableWidget->insertRow(row);
                tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(reader->card)));
                tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(reader->fio)));
                tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(reader->birthYear)));
                tableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(reader->address)));
                tableWidget->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(reader->workplace)));
                row++;
            }
        }
    }

    for (int column = 0; column < tableWidget->columnCount(); ++column) {
        tableWidget->resizeColumnToContents(column);
    }
}

void ReadersHT::clear() {
    for (int i = 0; i < size; ++i) {
        delete data[i];  // Free memory
        data[i] = nullptr;
    }
    delete[] data;  // Free hash table array
    data = new HTVal*[size]();  // Allocate fresh array
}
