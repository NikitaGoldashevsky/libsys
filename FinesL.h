// FinesL.h
#ifndef FINESL_H
#define FINESL_H

#include "Fine.h"
#include <QTableView>
#include <QStandardItemModel>
#include <QDebug>

struct FineNode {
    Fine* fine;
    FineNode* next;
    FineNode* prev;
};

class FinesL {
public:
    FinesL();
    ~FinesL();

    void add(Fine* fine);
    void remove(const std::string& id);
    Fine* get(const std::string& id) const;
    void clear();
    void fillTableView(QTableView* tableView, QStandardItemModel* model);

private:
    FineNode* head;
    FineNode* tail;
};

#endif // FINESL_H
