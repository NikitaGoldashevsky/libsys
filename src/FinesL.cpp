// FinesL.cpp
#include "FinesL.h"

FinesL::FinesL() : head(nullptr), tail(nullptr) {}

FinesL::~FinesL() {
    clear();
}

void FinesL::add(FineDecorator* fine) {
    if (!fine) return;
    FineNode* node = new FineNode{fine, nullptr, tail};
    if (tail) tail->next = node;
    else head = node;
    tail = node;
}

void FinesL::remove(const std::string& id) {
    FineNode* cur = head;
    while (cur) {
        if (cur->fine->getId() == id) {
            if (cur->prev) cur->prev->next = cur->next;
            else head = cur->next;
            if (cur->next) cur->next->prev = cur->prev;
            else tail = cur->prev;
            delete cur->fine;
            delete cur;
            return;
        }
        cur = cur->next;
    }
}

FineDecorator* FinesL::get(const std::string& id) const {
    FineNode* cur = head;
    while (cur) {
        if (cur->fine->getId() == id)
            return cur->fine;
        cur = cur->next;
    }
    return nullptr;
}

void FinesL::clear() {
    FineNode* cur = head;
    while (cur) {
        FineNode* next = cur->next;
        delete cur->fine;
        delete cur;
        cur = next;
    }
    head = tail = nullptr;
}

void FinesL::fillTableView(QTableView* tableView, QStandardItemModel* model) {
    if (!tableView) return;

    model->clear();
    model->setHorizontalHeaderLabels(QStringList() << "ID штрафа" << "Билет" << "Шифр книги"
                                                   << "Сумма" << "Причина" << "Оплачен");

    FineNode* cur = head;
    while (cur) {
        QList<QVariant> row = {
            QString::fromStdString(cur->fine->getId()),
            QString::fromStdString(cur->fine->getCard()),
            QString::fromStdString(cur->fine->getCipher()),
            QString::number(cur->fine->getAmount()),
            QString::fromStdString(cur->fine->getReason()),
            cur->fine->isPaid() ? "да" : "нет"
        };
        QList<QStandardItem*> items;
        for (const auto &val : row) items.append(new QStandardItem(val.toString()));
        model->appendRow(items);
        cur = cur->next;
    }
    tableView->setModel(model);
}
