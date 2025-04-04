#ifndef TESTSHASHTABLE_H
#define TESTSHASHTABLE_H

#include <cassert>
#include <iostream>
#include <QDebug>

#include "ReadersHT.h"

void testHashTable() {
    ReadersHT ht = ReadersHT(3);
    ht.log();

    ht.add(new Reader{"А0123-00", "John", 0, "ab", "cd"});
    ht.log();

    ht.add(new Reader{"А3333-00", "Rose", 0, "ab", "cd"});
    ht.log();

    ht.add(new Reader{"А7777-00", "River", 0, "ab", "cd"});
    ht.log();

    ht.add(new Reader{"А4444-00", "Amy", 0, "ab", "cd"});
    ht.log();

    ht.add(new Reader{"А5555-00", "Rory", 0, "ab", "cd"});
    ht.log();

    std::cout << ht.get("А7777-00")->fio << std::endl;

    std::cout << ht.get("А9999-00") << std::endl;

    ht.remove("А0123-00");
    ht.remove("А7777-00");
    ht.remove("А9999-00");
    ht.log();
}

#endif // TESTSHASHTABLE_H
