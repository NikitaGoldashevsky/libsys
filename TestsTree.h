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

    tr.clear();
}

#endif // TESTTREE_H
