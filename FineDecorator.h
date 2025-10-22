#ifndef FINEDECORATOR_H
#define FINEDECORATOR_H

#include "IEntryComponent.h"
#include <string>

#include <QDebug>
#include <QString>
#include <QTableView>
#include <QStandardItemModel>

class FineDecorator : public IEntryComponent {
public:
    FineDecorator(IEntryComponent* entry, const std::string& id, double amount,
                  const std::string& reason, bool paid = false)
        : wrappedEntry(entry), id(id), amount(amount), reason(reason), paid(paid) {}

    // Делегирование базовых данных
    std::string getCard() const override { return wrappedEntry->getCard(); }
    std::string getCipher() const override { return wrappedEntry->getCipher(); }
    std::string getIssueDate() const override { return wrappedEntry->getIssueDate(); }
    std::string getReturnDate() const override { return wrappedEntry->getReturnDate(); }
    std::string getLibrarianId() const override { return wrappedEntry->getLibrarianId(); }

    // Расширенная функциональность
    std::string getId() const { return id; }
    double getAmount() const { return amount; }
    std::string getReason() const { return reason; }
    bool isPaid() const { return paid; }
    void setPaid(bool p) { paid = p; }

    void print() const override {
        wrappedEntry->print();
        qDebug() << "  + Fine:" << QString::fromStdString(id)
                 << "Amount:" << amount << "Paid:" << paid;
    }

private:
    IEntryComponent* wrappedEntry;
    std::string id;
    double amount;
    std::string reason;
    bool paid;
};

#endif // FINEDECORATOR_H
