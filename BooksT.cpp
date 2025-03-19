#include "BooksT.h"

BooksT::BooksT() {
    root = nullptr;
}

Node* BooksT::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    if (T2) T2->prev = y;
    x->prev = y->prev;
    y->prev = x;

    if (x->prev) {
        if (x->prev->left == y) {
            x->prev->left = x;
        }
        else if (x->prev->right == y) {
            x->prev->right = x;
        }
        else {
            qDebug() << "wtf"; exit(0);
        }
    }
    return x;
}

Node* BooksT::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    if (T2) T2->prev = x;
    y->prev = x->prev;
    x->prev = y;

    if (y->prev) {
        if (y->prev->left == x) {
            y->prev->left = y;
        }
        else if (y->prev->right == x) {
            y->prev->right = y;
        }
        else {
            qDebug() << "wtf"; exit(0);
        }
    }
    return y;
}

int BooksT::height() {
    return heightR(root);
}

int BooksT::heightR(Node* node) {
    if (node == NULL) {
        return 0;
    }

    int leftHeight = heightR(node->left);
    int rightHeight = heightR(node->right);

    return 1 + std::max(leftHeight, rightHeight);
}

int BooksT::getBalance(Node* node) {
    if (!node) return 0;
    return heightR(node->left) - heightR(node->right);
}

void BooksT::balanceBranch(Node*& root, Node*& final) {
    Node* current = final;
    while (current != NULL && current != root->prev) {
        int balance = getBalance(current);

        if (balance > 1) {
            if (getBalance(current->left) >= 0) {
                if (current == root) {
                    root = rightRotate(current);
                }
                else {
                    current = rightRotate(current);
                }
            }
            else {
                current->left = leftRotate(current->left);
                if (current == root) {
                    root = rightRotate(current);
                }
                else {
                    current = rightRotate(current);
                }
            }
        }
        else if (balance < -1) {
            if (getBalance(current->right) <= 0) {
                if (current == root) {
                    root = leftRotate(current);
                }
                else {
                    current = leftRotate(current);
                }
            }
            else {
                current->right = rightRotate(current->right);
                if (current == root) {
                    root = leftRotate(current);
                }
                else {
                    current = leftRotate(current);
                }
            }
        }
        current = current->prev;
    }
}


void BooksT::clear() {
    eraseTreeR(root);
}

void BooksT::eraseTreeR(Node*& cur) {
    if (!cur) {
        return;
    }

    eraseTreeR(cur->left);
    eraseTreeR(cur->right);

    delete cur;
    cur = NULL;
}

bool BooksT::add(Book* book){
    return addElemR(root, book);
}

bool BooksT::addElemR(Node*& root, Book* book) {
    if (!root) {
        root = new Node;
        root->book = book;
        return true;
    }

    Node* cur = root;

    bool res;
    while (true) {
        if (*(cur->book) > *book) {
            if (cur->left) {
                cur = cur->left;
            }
            else {
                cur->left = new Node;
                cur->left->book = book;
                cur->left->prev = cur;
                balanceBranch(root, cur->left);
                return true;
            }
        }
        else if (*(cur->book) < *book) {
            if (cur->right) {
                cur = cur->right;
            }
            else {
                cur->right = new Node;
                cur->right->book = book;
                cur->right->prev = cur;
                balanceBranch(root, cur->right);
                return true;
            }
        }
        else if (*(cur->book) == *book) {
            return false;
        }
    }
}

void BooksT::print() {
    printR(root);
}

void BooksT::printR(Node* cur, const int level) {
    if (cur) {
        for (int i = 0; i < level; i++) {
            std::cout << "    ";
        }
        std::cout << cur->book->cipher << "\n";
        printR(cur->right, level + 1);
        printR(cur->left, level + 1);
    }
    else if (level == 0) {
        std::cout << "The tree is empty.\n";
    }
}

void BooksT::printTraversalList(const char* sep) {
    printTraversalListR(root, sep);
}

void BooksT::printTraversalListR(Node* cur, const char* sep) {
    if (!cur) {
        return;
    }
    printTraversalListR(cur->left, sep);

    printTraversalListR(cur->right, sep);
}

void BooksT::fillTableWidget(QTableWidget* tableWidget, const std::string& filter) {
    if (!tableWidget) return;

    tableWidget->setRowCount(0);
    int row = 0;

    auto toLower = [](const std::string& str) {
        std::string lowerStr = str;
        std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
        return lowerStr;
    };

    // Case-insensitive Boyer–Moore search
    auto boyerMooreSearch = [&](const std::string& text, const std::string& pattern) -> bool {
        if (pattern.empty()) return true;

        std::string lowerText = toLower(text);
        std::string lowerPattern = toLower(pattern);

        int m = lowerPattern.size();
        int n = lowerText.size();
        if (m > n) return false;

        int badChar[256];
        for (int i = 0; i < 256; ++i)
            badChar[i] = -1;
        for (int i = 0; i < m; ++i)
            badChar[(unsigned char)lowerPattern[i]] = i;

        int s = 0;
        while (s <= n - m) {
            int j = m - 1;
            while (j >= 0 && lowerPattern[j] == lowerText[s + j])
                j--;
            if (j < 0) {
                return true;
            } else {
                s += std::max(1, j - badChar[(unsigned char)lowerText[s + j]]);
            }
        }
        return false;
    };

    std::function<void(Node*)> traverseAndFill = [&](Node* cur) {
        if (!cur) return;
        traverseAndFill(cur->left);

        if (filter.empty() ||
            boyerMooreSearch(cur->book->name, filter) ||
            boyerMooreSearch(cur->book->authors, filter)) {

            tableWidget->insertRow(row);
            tableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(cur->book->cipher)));
            tableWidget->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(cur->book->authors)));
            tableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(cur->book->name)));
            tableWidget->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(cur->book->publisher)));
            tableWidget->setItem(row, 4, new QTableWidgetItem(QString::number(cur->book->pubYear)));
            tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(cur->book->copiesAll)));
            tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(cur->book->copiesStock)));
            row++;
        }
        traverseAndFill(cur->right);
    };

    traverseAndFill(root);

    for (int column = 0; column < tableWidget->columnCount(); ++column) {
        tableWidget->resizeColumnToContents(column);
    }
}


Node* BooksT::findMin(Node* node) {
    while (node->left != NULL) node = node->left;
    return node;
}

Node* BooksT::removeNode(Node* root, Book* book, bool& removed) {
    if (root == NULL) return root;

    if (*book < *(root->book))
        root->left = removeNode(root->left, book, removed);
    else if (*book > *(root->book))
        root->right = removeNode(root->right, book, removed);
    else {
        removed = true;
        // Узел с одним ребенком или без детей
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Узел с двумя детьми
        Node* temp = findMin(root->right);
        root->book = temp->book;
        root->right = removeNode(root->right, temp->book, removed);
    }

    if (root == NULL) return root;

    int balance = getBalance(root);

    // Левый левый случай
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Левый правый случай
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Правый правый случай
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Правый левый случай
    if ((balance < -1) && (getBalance(root->right) > 0)) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

bool BooksT::remove(Book* book) {
    removeElemR(root, book);
}

bool BooksT::remove(const std::string& cipher) {
    Book* book = get(cipher);
    removeElemR(root, book);
}

bool BooksT::removeElemR(Node*& root, Book* book) {
    bool removed = false;
    root = removeNode(root, book, removed);
    return removed;
}

Book* BooksT::get(const std::string& cipher) {
    return getElemR(root, cipher);
}

Book* BooksT::getElemR(Node* cur, const std::string& cipher) {
    if (!cur) {
        return nullptr;
    }

    if (cur->book->cipher == cipher) {
        return cur->book;
    }

    if (cipher < cur->book->cipher) {
        return getElemR(cur->left, cipher);
    } else {
        return getElemR(cur->right, cipher);
    }
}


bool BooksT::has(Book* book) {
    hasElemR(root, book);
}

bool BooksT::has(const std::string &cipher)
{
    if (get(cipher) != nullptr) {
        return true;
    }
}

bool BooksT::hasElemR(Node* cur, Book* book) {
    if (!cur) {
        return false;
    }
    return cur->book == book || hasElemR(cur->left, book) || hasElemR(cur->right, book);
}
