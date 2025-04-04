#ifndef TESTSALL_H
#define TESTSALL_H

void testAll() {
    std::cout << "ТЕСТИРОВАНИЕ СТРУКТУР ДАННЫХ БИБЛИОТЕЧНОЙ СИСТЕМЫ" << std::endl << std::endl;

    //=========================================================================
    std::cout << "АВЛ-ДЕРЕВО (BooksT)" << std::endl;
    //=========================================================================

    std::cout << "Тест 1 - Создание пустого дерева" << std::endl;
    BooksT tree;
    assert(tree.height() == 0);
    std::cout << "Пустое дерево успешно создано" << std::endl << std::endl;

    std::cout << "Тест 2 - Добавление элементов и проверка балансировки" << std::endl;
    Book* book1 = new Book{"001.001", "Author 1", "Book 1", "Publisher 1", 2020, 5, 5};
    Book* book2 = new Book{"002.002", "Author 2", "Book 2", "Publisher 2", 2021, 3, 3};
    Book* book3 = new Book{"003.003", "Author 3", "Book 3", "Publisher 3", 2022, 7, 7};

    assert(tree.add(book1));
    assert(tree.height() == 1);

    assert(tree.add(book2));
    assert(tree.height() == 2);

    assert(tree.add(book3));
    assert(tree.height() == 2); // Дерево должно быть сбалансировано с book2 в качестве корня
    std::cout << "Элементы успешно добавлены, дерево сбалансировано" << std::endl << std::endl;

    std::cout << "Тест 3 - Проверка балансировки при добавлении элементов, вызывающих вращения" << std::endl;
    Book* book4 = new Book{"000.001", "Author 4", "Book 4", "Publisher 4", 2023, 2, 2};
    Book* book5 = new Book{"000.002", "Author 5", "Book 5", "Publisher 5", 2023, 4, 4};

    assert(tree.add(book4));
    assert(tree.add(book5));
    assert(tree.height() <= 3);
    std::cout << "Дерево остается сбалансированным после вращений" << std::endl << std::endl;

    std::cout << "Тест 4 - Проверка методов has() и get()" << std::endl;
    assert(tree.has("001.001"));
    assert(tree.has(book1));
    assert(!tree.has("999.999"));

    Book* retrieved = tree.get("002.002");
    assert(retrieved != nullptr);
    assert(retrieved->cipher == "002.002");
    assert(retrieved->authors == "Author 2");
    std::cout << "Методы has() и get() работают корректно" << std::endl << std::endl;

    std::cout << "Тест 5 - Проверка защиты от дубликатов" << std::endl;
    assert(!tree.add(new Book{"001.001", "Duplicate", "Duplicate", "Duplicate", 2000, 1, 1}));
    std::cout << "Дубликаты корректно отклоняются" << std::endl << std::endl;

    std::cout << "Тест 6 - Удаление элементов и проверка балансировки" << std::endl;
    assert(tree.remove("003.003"));
    assert(!tree.has("003.003"));
    assert(tree.height() <= 3);
    std::cout << "Элементы успешно удаляются, дерево остается сбалансированным" << std::endl << std::endl;

    std::cout << "Тест 7 - Очистка дерева" << std::endl;
    tree.clear();
    assert(tree.height() == 0);
    assert(!tree.has("001.001"));
    std::cout << "Дерево успешно очищено" << std::endl << std::endl;

    //=========================================================================
    std::cout << "ДВУСВЯЗНЫЙ СПИСОК (EntriesL)" << std::endl;
    //=========================================================================

    std::cout << "Тест 1 - Создание пустого списка" << std::endl;
    EntriesL list;
    assert(list.size() == 0);
    std::cout << "Пустой список успешно создан" << std::endl << std::endl;

    std::cout << "Тест 2 - Добавление записей и проверка размера" << std::endl;
    list.add("CAR", "003.001", "01.01.2023", NOT_RETURNED);
    assert(list.size() == 1);

    list.add("CARD001", "001.002", "02.01.2023", NOT_RETURNED);
    list.add("CARD002", "002.003", "03.01.2023", "10.01.2023");
    assert(list.size() == 3);
    std::cout << "Записи успешно добавлены, размер списка корректен" << std::endl << std::endl;

    std::cout << "Тест 3 - Проверка метода get() для невозвращенных книг" << std::endl;
    Entry* entry = list.get("CARD001", "003.001");
    assert(entry != nullptr);
    assert(entry->card == "CARD001");
    assert(entry->cipher == "003.001");
    assert(entry->returnDate == NOT_RETURNED);
    std::cout << "Метод get() корректно возвращает невозвращенные книги" << std::endl << std::endl;

    std::cout << "Тест 4 - Проверка метода get() для возвращенных книг" << std::endl;
    entry = list.get("CARD002", "002.003");
    assert(entry == nullptr); // Должен вернуть nullptr, так как книга возвращена
    std::cout << "Метод get() корректно возвращает nullptr для возвращенных книг" << std::endl << std::endl;

    std::cout << "Тест 5 - Проверка метода has()" << std::endl;
    assert(list.has("CARD001", "003.001"));
    assert(!list.has("CARD001", "999.999"));
    assert(!list.has("CARD002", "002.003")); // Возвращенная книга должна давать false
    std::cout << "Метод has() работает корректно" << std::endl << std::endl;

    std::cout << "Тест 6 - Проверка сортировки" << std::endl;
    list.add("CARD003", "000.001", "04.01.2023", NOT_RETURNED);
    std::string ciphers = list.getCiphersByCard("CARD001", false);
    // Порядок должен быть "001.002 003.001" (отсортировано по шифру)
    assert(ciphers.find("001.002") < ciphers.find("003.001"));
    std::cout << "Список корректно сортируется по шифру" << std::endl << std::endl;

    std::cout << "Тест 7 - Проверка методов getCiphersByCard и getCardsByCipher" << std::endl;
    ciphers = list.getCiphersByCard("CARD001", true);
    assert(ciphers.find("001.002") != std::string::npos);
    assert(ciphers.find("003.001") != std::string::npos);

    std::string cards = list.getCardsByCipher("003.001", true);
    assert(cards.find("CARD001") != std::string::npos);
    std::cout << "Методы получения информации работают корректно" << std::endl << std::endl;

    std::cout << "Тест 8 - Удаление записи" << std::endl;
    list.remove("CARD001", "001.002");
    assert(!list.has("CARD001", "001.002"));
    assert(list.size() == 3);
    std::cout << "Запись успешно удалена" << std::endl << std::endl;

    std::cout << "Тест 9 - Удаление всех записей по карточке" << std::endl;
    list.removeAllByCard("CARD001");
    assert(!list.has("CARD001", "003.001"));
    assert(list.size() == 2);
    std::cout << "Все записи для указанной карточки успешно удалены" << std::endl << std::endl;

    std::cout << "Тест 10 - Удаление всех записей по шифру" << std::endl;
    list.removeAllByCipher("000.001");
    assert(list.size() == 1);
    std::cout << "Все записи для указанного шифра успешно удалены" << std::endl << std::endl;

    std::cout << "Тест 11 - Очистка списка" << std::endl;
    list.clear();
    assert(list.size() == 0);
    std::cout << "Список успешно очищен" << std::endl << std::endl;

    //=========================================================================
    std::cout << "ХЕШ-ТАБЛИЦА (ReadersHT)" << std::endl;
    //=========================================================================

    std::cout << "Тест 1 - Создание хеш-таблицы с малым начальным размером" << std::endl;
    ReadersHT table(5);
    std::cout << "Хеш-таблица создана с начальным размером 5" << std::endl << std::endl;

    std::cout << "Тест 2 - Добавление читателей" << std::endl;
    Reader* reader1 = new Reader{"CARD001", "John Doe", 1990, "123 Main St", "ABC Corp"};
    Reader* reader2 = new Reader{"CARD002", "Jane Smith", 1985, "456 Oak St", "XYZ Inc"};

    assert(table.add(reader1));
    assert(table.add(reader2));
    std::cout << "Читатели успешно добавлены" << std::endl << std::endl;

    std::cout << "Тест 3 - Проверка метода has()" << std::endl;
    assert(table.has("CARD001"));
    assert(table.has("CARD002"));
    assert(!table.has("NONEXISTENT"));
    std::cout << "Метод has() работает корректно" << std::endl << std::endl;

    std::cout << "Тест 4 - Проверка метода get()" << std::endl;
    Reader* retrieved_reader = table.get("CARD001");
    assert(retrieved_reader != nullptr);
    assert(retrieved_reader->card == "CARD001");
    assert(retrieved_reader->fio == "John Doe");
    std::cout << "Метод get() работает корректно" << std::endl << std::endl;

    std::cout << "Тест 5 - Проверка обработки коллизий и увеличения размера таблицы" << std::endl;
    for (int i = 0; i < 10; i++) {
        std::string card = "Ч0001-0" + std::to_string(i);
        Reader* reader = new Reader{card, "Test Reader " + std::to_string(i), 2000, "Test Address", "Test Workplace"};
        assert(table.add(reader));
    }

    // Проверка, что все читатели все еще доступны
    for (int i = 0; i < 10; i++) {
        std::string card = "Ч0001-0" + std::to_string(i);
        qDebug() << card;
        assert(table.has(card));
        Reader* r = table.get(card);
        assert(r != nullptr);
        assert(r->fio == "Test Reader " + std::to_string(i));
    }
    std::cout << "Коллизии обрабатываются корректно, таблица успешно увеличивается" << std::endl << std::endl;

    std::cout << "Тест 6 - Удаление элемента" << std::endl;
    assert(table.remove("Ч0001-01"));
    assert(!table.has("Ч0001-01"));
    std::cout << "Удаление работает корректно" << std::endl << std::endl;

    std::cout << "Тест 7 - Проверка работы с надгробиями (удаленными элементами)" << std::endl;
    Reader* newReader1 = new Reader{"Ч0001-01", "New John Doe", 1995, "New Address", "New Workplace"};
    assert(table.add(newReader1));
    retrieved_reader = table.get("Ч0001-01");
    assert(retrieved_reader != nullptr);
    assert(retrieved_reader->fio == "New John Doe");
    std::cout << "Надгробия обрабатываются корректно" << std::endl << std::endl;

    std::cout << "Тест 8 - Очистка хеш-таблицы" << std::endl;
    table.clear();
    assert(!table.has("CARD001"));
    assert(!table.has("CARD002"));
    std::cout << "Хеш-таблица успешно очищена" << std::endl << std::endl;

    std::cout << "ВСЕ ТЕСТЫ УСПЕШНО ПРОЙДЕНЫ!" << std::endl;
}

#endif // TESTSALL_H
