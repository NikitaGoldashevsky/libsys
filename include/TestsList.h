#ifndef TESTSLIST_H
#define TESTSLIST_H

#include <iostream>
#include "EntriesL.h"

void testList() {
    EntriesL list;

    list.add("A1111-00", "111.111", "21-05-2005", NOT_RETURNED);
    list.add("A2222-00", "222.222", "21-06-2005", NOT_RETURNED);
    list.add("A3333-00", "333.333", "21-07-2005", NOT_RETURNED);
    list.print();

    std::cout << list.get("A3333-00", "333.333")->issueDate << std::endl;

    std::cout << list.get("A999-99", "999.999") << std::endl;

    list.remove("A3333-00", "333.333");
    std::cout << list.size() << std::endl;

    list.clear();

    list.add("A1111-00", "777.777", "21-05-2005", "22-05-2015");
    list.add("A2222-00", "555.555", "21-06-2005", "22-06-2015");
    list.add("A3333-00", "222.222", "21-07-2005", "22-07-2015");
    list.add("A4444-00", "666.555", "21-06-2005", "22-06-2015");

    list.sort();
    list.print();
}

#endif // TESTLIST_H
