#include "FineDecorator.h"
#include "Fine.h"

struct FineNode {
    FineDecorator* fine;  // ← теперь это декоратор
    FineNode* next;
    FineNode* prev;
};

class FinesL {
public:
    FinesL();
    ~FinesL();
    void add(FineDecorator* fine);  // ← принимает декоратор
    FineDecorator* get(const std::string& id) const;
    void remove(const std::string& id);
    void clear();
    void fillTableView(QTableView* tableView, QStandardItemModel* model);
private:
    FineNode* head = nullptr;
    FineNode* tail = nullptr;
};
