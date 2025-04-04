#ifndef TESTSTREE_H
#define TESTSTREE_H

#include "BooksT.h"

void testTree() {
    BooksT tr;
    tr.add(new Book{"111.000", "fd", "gfd", "cx", 1, 2, 3});
    tr.print();

    tr.add(new Book{"113.004", "fd", "gfd", "cx", 1, 2, 3});
    tr.print();

    tr.add(new Book{"112.000", "fd", "gfd", "cx", 1, 2, 3});
    tr.print();

    tr.add(new Book{"113.000", "fd", "gfd", "cx", 1, 2, 3});
    tr.print();

    tr.add(new Book{"113.001", "fd", "gfd", "cx", 1, 2, 3});
    tr.print();

    tr.add(new Book{"113.002", "fd", "gfd", "cx", 1, 2, 3});
    tr.print();

    tr.add(new Book{"113.003", "fd", "gfd", "cx", 1, 2, 3});
    tr.print();

    std::cout << tr.add(new Book{"113.003", "fd", "gfd", "cx", 1, 2, 3}) << std::endl;

    std::cout << tr.get("113.003")->cipher << std::endl;

    std::cout << tr.get("999.999") << std::endl;

    std::cout << tr.remove("113.003") << std::endl;

    std::cout << tr.remove("999.999") << std::endl;

    tr.clear();
}

#endif // TESTTREE_H
