#ifndef TESTSHASHTABLE_H
#define TESTSHASHTABLE_H

#include <cassert>
#include <iostream>
#include <QDebug>

#include "ReadersHT.h"

void testAddAndGet() {
    ReadersHT ht(10);

    Reader* reader1 = new Reader{"A1234-23", "John Doe", 1990, "123 Main St", "Tech Corp"};
    Reader* reader2 = new Reader{"B5678-24", "Jane Smith", 1985, "456 Elm St", "Health Inc"};

    // Test adding readers
    assert(ht.add(reader1) == true);
    assert(ht.add(reader2) == true);

    // Test retrieving readers
    Reader* retrieved1 = ht.get("A1234-23");
    assert(retrieved1 != nullptr);
    assert(retrieved1->fio == "John Doe");
    assert(retrieved1->birthYear == 1990);

    Reader* retrieved2 = ht.get("B5678-24");
    assert(retrieved2 != nullptr);
    assert(retrieved2->fio == "Jane Smith");
    assert(retrieved2->birthYear == 1985);

    // Test retrieving non-existent reader
    assert(ht.get("C9999-99") == nullptr);

    std::cout << "testAddAndGet passed!" << std::endl;

    // Cleanup
    delete reader1;
    delete reader2;
}

void testHas() {
    ReadersHT ht(10);

    Reader* reader1 = new Reader{"A1234-23", "John Doe", 1990, "123 Main St", "Tech Corp"};
    Reader* reader2 = new Reader{"B5678-24", "Jane Smith", 1985, "456 Elm St", "Health Inc"};

    ht.add(reader1);
    ht.add(reader2);

    // Test existence of readers
    assert(ht.has("A1234-23") == true);
    assert(ht.has("B5678-24") == true);
    assert(ht.has("C9999-99") == false); // Non-existent reader

    std::cout << "testHas passed!" << std::endl;

    // Cleanup
    delete reader1;
    delete reader2;
}

void testRemove() {
    ReadersHT ht(10);

    Reader* reader1 = new Reader{"A1234-23", "John Doe", 1990, "123 Main St", "Tech Corp"};
    Reader* reader2 = new Reader{"B5678-24", "Jane Smith", 1985, "456 Elm St", "Health Inc"};

    ht.add(reader1);
    ht.add(reader2);

    // Test removing readers
    assert(ht.remove("A1234-23") == true);
    assert(ht.has("A1234-23") == false); // Verify reader1 is removed
    assert(ht.get("A1234-23") == nullptr);

    // Test removing non-existent reader
    assert(ht.remove("C9999-99") == false);

    // Verify reader2 is still present
    assert(ht.has("B5678-24") == true);
    assert(ht.get("B5678-24") != nullptr);

    std::cout << "testRemove passed!" << std::endl;

    // Cleanup
    delete reader1;
    delete reader2;
}

void testCollisionsAndResizing() {
    ReadersHT ht(5); // Small size to force collisions and resizing

    Reader* reader1 = new Reader{"A1234-23", "John Doe", 1990, "123 Main St", "Tech Corp"};
    Reader* reader2 = new Reader{"B5678-24", "Jane Smith", 1985, "456 Elm St", "Health Inc"};
    Reader* reader3 = new Reader{"C9999-99", "Alice Johnson", 1995, "789 Oak St", "Finance LLC"};
    Reader* reader4 = new Reader{"D1111-11", "Bob Brown", 1980, "321 Pine St", "Education Org"};
    Reader* reader5 = new Reader{"E2222-22", "Charlie Davis", 1975, "654 Birch St", "Retail Inc"};

    // Add readers to force collisions and resizing
    assert(ht.add(reader1) == true);
    assert(ht.add(reader2) == true);
    assert(ht.add(reader3) == true);
    assert(ht.add(reader4) == true);
    assert(ht.add(reader5) == true);

    // Verify all readers are present
    assert(ht.has("A1234-23") == true);
    assert(ht.has("B5678-24") == true);
    assert(ht.has("C9999-99") == true);
    assert(ht.has("D1111-11") == true);
    assert(ht.has("E2222-22") == true);

    // Verify retrieval after resizing
    assert(ht.get("A1234-23") != nullptr);
    assert(ht.get("B5678-24") != nullptr);
    assert(ht.get("C9999-99") != nullptr);
    assert(ht.get("D1111-11") != nullptr);
    assert(ht.get("E2222-22") != nullptr);

    std::cout << "testCollisionsAndResizing passed!" << std::endl;

    // Cleanup
    delete reader1;
    delete reader2;
    delete reader3;
    delete reader4;
    delete reader5;
}

void testAndLog() {
    Reader* r1 = new Reader{"A1111-00", "Rose", 0, "ab", "cd"};
    Reader* r2 = new Reader{"A2222-00", "John", 0, "ab", "cd"};
    Reader* r3 = new Reader{"A3333-00", "River", 0, "ab", "cd"};
    Reader* r4 = new Reader{"A4444-00", "Amy", 0, "ab", "cd"};
    Reader* r5 = new Reader{"A5555-00", "Rory", 0, "ab", "cd"};

    ReadersHT ht = ReadersHT(3);
    ht.add(r1);
    ht.log();
    ht.add(r2);
    ht.log();
    ht.add(r3);
    ht.log();
    ht.add(r4);
    ht.log();
    ht.add(r5);
    ht.log();

    // Cleanup
    delete r1;
    delete r2;
    delete r3;
    delete r4;
    delete r5;
}

void testHashTable() {
    std::cout << "Start testing ReadersHT.\n" << std::endl;

    // static assert tests
    testAddAndGet();
    testHas();
    testRemove();
    testCollisionsAndResizing();

    // runtime test
    testAndLog();

    std::cout << "\nAll tests passed!\n" << std::endl;
}

#endif // TESTSHASHTABLE_H
