#ifndef READERSHT_H
#define READERSHT_H

#include <string>
#include <QDebug>
#include <QTableWidget>

struct Reader {
    std::string card; // ANNNN-YY
    std::string fio;
    int birthYear;
    std::string address;
    std::string workplace;
};

struct HTVal {
    Reader* reader;
    std::string hashKey;
};

// QDebug operator<<(QDebug dbg, const HTVal* htval) {
//     if (htval == nullptr) {
//         dbg.nospace() << "HTVal is nullptr";
//     } else {
//         dbg.nospace() << "Hash Key: " << htval->hashKey << "\n";
//         if (htval->reader == nullptr) {
//             dbg.nospace() << "\tReader is nullptr";
//         } else {
//             dbg.nospace() << "\tCard: " << QString::fromStdString(htval->reader->card) << "\n"
//                           << "\tFIO: " << QString::fromStdString(htval->reader->fio) << "\n"
//                           << "\tBirth Year: " << htval->reader->birthYear << "\n"
//                           << "\tAddress: " << QString::fromStdString(htval->reader->address) << "\n"
//                           << "\tWorkplace: " << QString::fromStdString(htval->reader->workplace);
//         }
//     }
//     return dbg;
// }


class ReadersHT {
private:
    const int collisionStep = 17;
    const int collisionTries = 30;
    HTVal** data;
    int size;

    Reader* at(const int index) const;
    void resizeTable();

public:
    ReadersHT(const int size);

    bool add(Reader* reader);
    int hash(const std::string& str) const;
    bool has(const std::string& card) const;
    Reader* get(const std::string& card) const;
    bool remove(const std::string& card);
    void log() const;
    void clear();
    void fillTableWidget(QTableWidget *tableWidget);
};


#endif // READERSHT_H
