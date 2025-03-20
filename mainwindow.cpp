#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    regexCard(R"(^\d\d\d\d-\d\d$)"),
    regexCipher(R"(^\d{2}[1-9]\.\d{2}[1-9]$)")
{
    ui->setupUi(this);
    ui->btnBookAdd->setFocus();

    connect(ui->btnBookAdd, &QPushButton::clicked, this, &MainWindow::btnBookAdd_clicked);
    connect(ui->btnBookRemove, &QPushButton::clicked, this, &MainWindow::btnBookRemove_clicked);
    connect(ui->btnClearBooks, &QPushButton::clicked, this, &MainWindow::btnClearBooks_clicked);
    connect(ui->btnBookSearch, &QPushButton::clicked, this, &MainWindow::btnBookSearch_clicked);

    connect(ui->btnReaderAdd, &QPushButton::clicked, this, &MainWindow::btnReaderAdd_clicked);
    connect(ui->btnReaderRemove, &QPushButton::clicked, this, &MainWindow::btnReaderRemove_clicked);
    connect(ui->btnClearReaders, &QPushButton::clicked, this, &MainWindow::btnClearReaders_clicked);
    connect(ui->btnReaderSearch, &QPushButton::clicked, this, &MainWindow::btnReaderSearch_clicked);

    connect(ui->btnEntryCheckOut, &QPushButton::clicked, this, &MainWindow::btnEntryCheckOut_clicked);
    connect(ui->btnEntryCheckIn, &QPushButton::clicked, this, &MainWindow::btnEntryCheckIn_clicked);
    connect(ui->btnClearEntries, &QPushButton::clicked, this, &MainWindow::btnClearEntries_clicked);

    // Startup Data--------------
    books.add(new Book{"001.002", "Stephen King", "Billy summers", "Some American publisher idk", 2015, 4, 1});
    books.add(new Book{"001.001", "Thomas De Quincey", "Confessions of an English Opium-Eater", "Some publisher idk", 1822, 3, 0});

    readers.add(new Reader{"Ч0001-25", "David Lockridge", 1978, "Colorado", "Serial killer"});
    readers.add(new Reader{"Ч0002-25", "John Smith", 1234, "Gallifrey", "Time traveller"});

    entries.add("Ч0001-25", "001.002", "21.03.2011", "25.03.2011");
    entries.add("Ч0002-25", "001.001", "27.03.2011", "-");

    // --------------------------

    updateTableWidgets();
}

MainWindow::~MainWindow() {
    books.clear();
    readers.clear();
    entries.clear();
    delete ui;
}

void MainWindow::btnBookAdd_clicked() {
    AddBookDialog d(this);
    while (true) {
        if (d.exec() == QDialog::Accepted) {
            if (!std::regex_search(d.getCipher(), regexCipher)) {
                QMessageBox::critical(this, "Ошибка", "Введенный шифр некорректен!");
                continue;
            }

            if (d.getCopiesAll() < 1 || (d.getCopiesStock() > d.getCopiesAll())) {
                QMessageBox::critical(this, "Ошибка", "Указано некорректное число экземпляров!");
                continue;
            }

            if (d.getName().empty()) {
                QMessageBox::critical(this, "Ошибка", "Не указаны авторы книги!");
                continue;
            }

            if (d.getName().empty()) {
                QMessageBox::critical(this, "Ошибка", "Не указано название книги!");
                continue;
            }

            if (d.getPublisher().empty()) {
                QMessageBox::critical(this, "Ошибка", "Не указан издатель!");
                continue;
            }

            if (!books.has(d.getCipher())) {
                books.add(new Book{
                    d.getCipher(), d.getAuthors(), d.getName(), d.getPublisher(),
                    d.getPublicationYear(), d.getCopiesAll(), d.getCopiesStock()
                });
                updateTableWidgets();
                return;
            }
            else {
                QMessageBox::critical(this, "Ошибка", "Книга с указанным шифром уже есть в базе данных!");
                continue;
            }
        }
        else {
            return;
        }
    }
}

void MainWindow::btnBookRemove_clicked() {
    removebookdialog d(this);
    if (d.exec() == QDialog::Accepted) {
        const std::string cipher = d.getCipher();
        if (books.has(cipher)) {
            const std::string cards = entries.getCardsByCipher(cipher, true);
            if (!cards.empty()) {
                std::string msg = "Удаление невозможно. Следующие читатели имеют экземпляры указанной книги: ";
                msg += cards;
                QMessageBox::critical(this, "Ошибка", QString::fromStdString(msg));
                return;
            } else {
                books.remove(cipher);
                entries.removeAllByCipher(cipher);
                updateTableWidgets();
            }
        } else {
            QMessageBox::critical(this, "Ошибка", "Книги с указанным шифром нет в базе данных!");
            return;
        }
    }
}

void MainWindow::btnReaderRemove_clicked() {
    RemoveReaderDialog d(this);
    if (d.exec() == QDialog::Accepted) {
        const std::string card = d.getCard();
        if (readers.has(card)) {
            const std::string ciphers = entries.getCiphersByCard(card, true);
            if (!ciphers.empty()) {
                std::string msg = "Удаление невозможно. Читатель имеет невозвращенные экземпляры следующих книг: ";
                msg += ciphers;
                QMessageBox::critical(this, "Ошибка", QString::fromStdString(msg));
                return;
            } else {
                readers.remove(card);
                entries.removeAllByCard(card);
                updateTableWidgets();
            }
        } else {
            QMessageBox::critical(this, "Ошибка", "Читателя с указанным номером билета нет в базе данных!");
            return;
        }
    }
}

void MainWindow::btnClearBooks_clicked() {
    books.clear();
    updateTableWidgets();
}

void MainWindow::btnReaderAdd_clicked() {
    AddReaderDialog d(this);

    const auto isValidFirstChar = [](const std::string& str) -> bool {
        if (str.empty()) return false;
        char firstChar = str[0];
        return (firstChar == '\xD0' && (str[1] == '\xA7' || str[1] == '\x90' || str[1] == '\x92'));
    };

    while (true) {
        if (d.exec() == QDialog::Accepted) {
            if (!std::regex_search(d.getCard().erase(0, 2), regexCard) || !isValidFirstChar(d.getCard())) {
                QMessageBox::critical(this, "Ошибка", "Указанный номер билета некорректен!");
                continue;
            }

            if (d.getFIO().empty()) {
                QMessageBox::critical(this, "Ошибка", "Не указаны ФИО читателя!");
                continue;
            }

            if (d.getAddress().empty()) {
                QMessageBox::critical(this, "Ошибка", "Не указан адрес проживания читателя!");
                continue;
            }

            if (d.getWorkplace().empty()) {
                QMessageBox::critical(this, "Ошибка", "Не указано место работы читателя!");
                continue;
            }

            if (!readers.has(d.getCard())) {
                readers.add(new Reader{
                    d.getCard(), d.getFIO(), d.getBirthYear(),
                    d.getAddress(), d.getWorkplace()});
                updateTableWidgets();
                return;
            }
            else {
                QMessageBox::critical(this, "Ошибка", "Читатель с указанным номером билета уже есть в базе данных!");
                continue;
            }
        } else {
            return;
        }
    }
}

void MainWindow::btnClearReaders_clicked() {
    readers.clear();
    updateTableWidgets();
}

void MainWindow::btnEntryCheckIn_clicked() {
    CloseEntryDialog d(this);
    while (true) {
        if (d.exec() == QDialog::Accepted) {
            const std::string card = d.getCard();
            const std::string cipher = d.getCipher();

            if (!readers.has(card)) {
                QMessageBox::critical(this, "Ошибка", "Указанный номер билета не соответствует ни одному читателю!");
                continue;
            }

            if (!books.has(cipher)) {
                QMessageBox::critical(this, "Ошибка", "Указанный шифр не соответствует ни одной книге!");
                continue;
            }

            Entry* const entry = entries.get(d.getCard(), d.getCipher());
            if (entry) {
                entry->returnDate = d.getCheckInDate();
                books.get(entry->cipher)->copiesStock++;
                updateTableWidgets();
                return;
            }
            else {
                QMessageBox::critical(this, "Ошибка", "Читатель с указанным номером билета не имеет"
                                                      " книгу с указанным шифром!");
                continue;
            }
        }
        else {
            return;
        }
    }
}

void MainWindow::btnEntryCheckOut_clicked() {
    AddEntryDialog d(this);
    while (true) {
        if (d.exec() == QDialog::Accepted) {
            const std::string card = d.getCard();
            const std::string cipher = d.getCipher();
            Book* const book = books.get(cipher);

            if (!readers.has(card)) {
                QMessageBox::critical(this, "Ошибка", "Указанный номер билета не соответствует ни одному читателю!");
                continue;
            }

            if (!books.has(cipher)) {
                QMessageBox::critical(this, "Ошибка", "Указанный шифр не соответствует ни одной книге!");
                continue;
            }

            Entry* const entry = entries.get(card, cipher);
            if (entry) {
                QMessageBox::critical(this, "Ошибка", "Читатель с указанным номером билета"
                                                      " уже имеет книгу с указанным шифром!");
                continue;
            }

            if (book->copiesStock < 1) {
                QMessageBox::critical(this, "Ошибка", "Экземпляров указанной книги не осталось в наличии!");
                continue;
            }

            entries.add(card, cipher, d.getCheckOutDate(), NOT_RETURNED);
            book->copiesStock--;
            updateTableWidgets();
            return;
        }
        else {
            return;
        }
    }
}

void MainWindow::btnClearEntries_clicked() {
    entries.clear();
    updateTableWidgets();
}

void MainWindow::updateTableWidgets() {
    // Books
    ui->twBooks->setColumnCount(7);
    ui->twBooks->setHorizontalHeaderLabels(QStringList{"Шифр", "Авторы", "Название", "Издательство", "Год публикации", "Копий всего", "Копий в наличии"});
    books.fillTableWidget(ui->twBooks);

    // Readers
    ui->twReaders->setColumnCount(5);
    ui->twReaders->setHorizontalHeaderLabels(QStringList{"Номер билета", "ФИО", "Год рождения", "Адрес", "Место работы"});
    readers.fillTableWidget(ui->twReaders);

    // Entries
    ui->twEntries->setColumnCount(4);
    ui->twEntries->setHorizontalHeaderLabels(QStringList{"Номер билета", "Шифр", "Дата выдачи", "Дата возврата"});
    entries.fillTableWidget(ui->twEntries);
}

void MainWindow::btnReaderSearch_clicked() {
    SearchReaderDialog *dialog = new SearchReaderDialog(this);
    dialog->exec();
    delete dialog;
}

void MainWindow::btnBookSearch_clicked() {
    SearchBookDialog *dialog = new SearchBookDialog(this);
    dialog->exec();
    delete dialog;
}

ReadersHT* MainWindow::getReadersHT() {
    return &readers;
}

BooksT* MainWindow::getBooksT() {
    return &books;
}

EntriesL* MainWindow::getEntriesL() {
    return &entries;
}
