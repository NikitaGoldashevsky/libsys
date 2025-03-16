#ifndef TESTSLIST_H
#define TESTSLIST_H

#include <iostream>
#include "EntriesL.h"

void testList() {
    EntriesL list;

    qDebug() << "Тестирование списка.";

    qDebug() << "Тест 1: Добавление элементов";
    list.add("A1111-00", "123", "21-05-2005", "22-05-2015");
    list.add("A2222-00", "345", "21-06-2005", "22-06-2015");
    list.add("A3333-00", "567", "21-07-2005", "22-07-2015");
    list.print();

    qDebug() << "Тест 2: Проверка размера списка";
    qDebug() << "Ожидаемый размер: 3, Фактический размер: " << list.size();
}

#endif // TESTLIST_H
