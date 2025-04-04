#include "ReadersHT.h"

// Конструктор
ReadersHT::ReadersHT(const int size) {
    this->size = size;
    data = new HTVal*[size]();
}

// Деструктор
ReadersHT::~ReadersHT() {
    clear();
    delete[] data;
}

// Хеш-функция
int ReadersHT::hash(const std::string& str) const {
    int hashRes = 0;
    for (const char ch : str) {
        hashRes += ((int)ch) * ((int)ch);
    }
    return hashRes % size;
}

// Добавление элемента
bool ReadersHT::add(Reader* reader) {
    int hashKey = hash(reader->card);
    HTVal* newNode = new HTVal{reader, reader->card, nullptr};

    if (data[hashKey] == nullptr) {
        data[hashKey] = newNode;
    } else {
        newNode->next = data[hashKey];
        data[hashKey] = newNode;
    }

    return true;
}

// Проверка наличия элемента
bool ReadersHT::has(const std::string& card) const {
    return get(card) != nullptr;
}

// Получение элемента
Reader* ReadersHT::get(const std::string& card) const {
    int hashKey = hash(card);
    HTVal* current = data[hashKey];

    while (current) {
        if (current->hashKey == card && current->reader != nullptr) {
            return current->reader;
        }
        current = current->next;
    }

    return nullptr;
}

// Удаление элемента
bool ReadersHT::remove(const std::string& card) {
    int hashKey = hash(card);
    HTVal* current = data[hashKey];
    HTVal* prev = nullptr;

    while (current) {
        if (current->hashKey == card && current->reader != nullptr) {
            if (prev) {
                prev->next = current->next; // Удаляем из середины или конца списка
            } else {
                data[hashKey] = current->next; // Удаляем из начала списка
            }

            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false;
}

// Вывод таблицы в консоль
void ReadersHT::log() const {
    qDebug() << "Hash Table Size:" << this->size;

    for (int i = 0; i < this->size; ++i) {
        qDebug() << i << ")";
        HTVal* current = data[i];

        while (current) {
            qDebug() << " -> " << QString::fromStdString(current->hashKey)
            << " - " << QString::fromStdString(current->reader->fio);
            current = current->next;
        }
    }
    qDebug() << "\n";
}

// Очистка таблицы
void ReadersHT::clear() {
    for (int i = 0; i < size; ++i) {
        HTVal* current = data[i];

        while (current) {
            HTVal* next = current->next;
            delete current;
            current = next;
        }

        data[i] = nullptr;
    }
}

void ReadersHT::fillTableWidget(QTableWidget* tableWidget, const std::string& fioFilter) {
    if (!tableWidget) return;

    auto kmpSearch = [](const std::string& text, const std::string& pattern) -> bool {
        if (pattern.empty()) return true;

        auto toLower = [](const std::string& str) {
            std::string res = str;
            for (auto& ch : res) ch = std::tolower(ch);
            return res;
        };

        std::string lowerText = toLower(text);
        std::string lowerPattern = toLower(pattern);

        int m = lowerPattern.size();
        int n = lowerText.size();

        std::vector<int> lps(m, 0);
        int len = 0, i = 1;
        while (i < m) {
            if (lowerPattern[i] == lowerPattern[len]) {
                lps[i++] = ++len;
            } else if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        i = 0;
        int j = 0;
        while (i < n) {
            if (lowerPattern[j] == lowerText[i]) {
                i++; j++;
            }

            if (j == m) {
                return true;
            } else if (i < n && lowerPattern[j] != lowerText[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return false;
    };

    tableWidget->setRowCount(0);
    int row = 0;

    for (int i = 0; i < size; ++i) {
        HTVal* current = data[i];

        while (current) {  // Проход по цепочке
            if (current->reader != nullptr) {
                Reader* reader = current->reader;
                if (fioFilter.empty() || kmpSearch(reader->fio, fioFilter)) {
                    tableWidget->insertRow(row);
                    tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(reader->card)));
                    tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(reader->fio)));
                    tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(reader->birthYear)));
                    tableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(reader->address)));
                    tableWidget->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(reader->workplace)));
                    row++;
                }
            }
            current = current->next;  // Переход к следующему элементу цепочки
        }
    }

    for (int column = 0; column < tableWidget->columnCount(); ++column) {
        tableWidget->resizeColumnToContents(column);
    }
}
