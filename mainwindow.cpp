#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btnBookAdd->setFocus();

    connect(ui->btnBookAdd, &QPushButton::clicked, this, &MainWindow::btnBookAdd_clicked);
    connect(ui->btnBookRemove, &QPushButton::clicked, this, &MainWindow::btnBookRemove_clicked);
    connect(ui->btnClearBooks, &QPushButton::clicked, this, &MainWindow::btnClearBooks_clicked);

    connect(ui->btnReaderAdd, &QPushButton::clicked, this, &MainWindow::btnReaderAdd_clicked);
    connect(ui->btnReaderRemove, &QPushButton::clicked, this, &MainWindow::btnReaderRemove_clicked);
    connect(ui->btnClearReaders, &QPushButton::clicked, this, &MainWindow::btnClearReaders_clicked);

    connect(ui->btnEntryCheckOut, &QPushButton::clicked, this, &MainWindow::btnEntryCheckOut_clicked);
    connect(ui->btnEntryCheckIn, &QPushButton::clicked, this, &MainWindow::btnEntryCheckIn_clicked);
    connect(ui->btnClearEntries, &QPushButton::clicked, this, &MainWindow::btnClearEntries_clicked);

    // Startup Data--------------
    books.add(new Book{"001.002", "Stephen King", "Billy summers", "Some American publisher idk", 2015, 4, 1});
    books.add(new Book{"001.001", "Thomas De Quincey", "Confessions of an English Opium-Eater", "Some publisher idk", 1822, 3, 0});

    readers.add(new Reader{"Ч0001-25", "David Lockridge", 1978, "Colorado", "Serial killer"});
    readers.add(new Reader{"Ч0002-25", "John Smith", 1234, "Gallifrey", "Time traveller"});

    entries.add("Ч0001-25", "001.001", "21.03.2011", "25.03.2011");
    entries.add("Ч0002-25", "001.002", "27.03.2011", "-");

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
    if (d.exec() == QDialog::Accepted) {
        if (d.getCipher() == "") {
            QMessageBox::critical(this, "Ошибка", "Введенный шифр некорректен!");
            return;
        }

        if (!books.has(d.getCipher()))
        books.add(new Book{
            d.getCipher(), d.getAuthors(), d.getName(), d.getPublisher(),
            d.getPublicationYear(), d.getCopiesAll(), d.getCopiesStock()
        });
        else {
            QMessageBox::critical(this, "Ошибка", "Книга с указанным шифром уже есть в базе данных!");
            return;
        }
        updateTableWidgets();
    }
}

void MainWindow::btnBookRemove_clicked() {
    removebookdialog d(this);
    if (d.exec() == QDialog::Accepted) {
        const std::string cipher = d.getCipher();
        if (books.has(cipher)) {
            books.remove(cipher);
        } else {
            QMessageBox::critical(this, "Ошибка", "Книги с указанным шифром нет в базе данных!");
            return;
        }
    }

    updateTableWidgets();
}

void MainWindow::btnReaderRemove_clicked() {
    RemoveReaderDialog d(this);
    if (d.exec() == QDialog::Accepted) {
        const std::string card = d.getCard();
        if (readers.has(card)) {
            readers.remove(card);
        } else {
            QMessageBox::critical(this, "Ошибка", "Читателя с указанным номером билета нет в базе данных!");
            return;
        }
    }

    updateTableWidgets();
}

void MainWindow::btnClearBooks_clicked() {
    books.clear();
    updateTableWidgets();
}

void MainWindow::btnReaderAdd_clicked() {
    AddReaderDialog d(this);
    if (d.exec() == QDialog::Accepted) {
        if (d.getCard() == "") {
            QMessageBox::critical(this, "Ошибка", "Введенный номер билета некорректен!");
            return;
        }

        if (!readers.has(d.getCard()))
            readers.add(new Reader{
                d.getCard(), d.getFIO(), d.getBirthYear(),
                d.getAddress(), d.getWorkplace()});
        else {
            QMessageBox::critical(this, "Ошибка", "Читатель с указанным номером билета уже есть в базе данных!");
            return;
        }
        updateTableWidgets();
    }
}

void MainWindow::btnClearReaders_clicked() {
    readers.clear();
    updateTableWidgets();
}

void MainWindow::btnEntryCheckIn_clicked() {
    updateTableWidgets();
}

void MainWindow::btnEntryCheckOut_clicked() {
    AddEntryDialog d(this);
    if (d.exec() == QDialog::Accepted) {
        // // error handling
        // if (d.getCard() == "") {
        //     QMessageBox::critical(this, "Ошибка", "Введенный номер билета некорректен!");
        //     return;
        // }

        if (!entries.has(d.getCard(), d.getCipher()))
            entries.add(d.getCard(), d.getCipher(), d.getCheckOutDate(), "-");
        else {
            QMessageBox::critical(this, "Ошибка", "Запись с указанными номером билета"
                                                  " и шифром уже есть в базе данных!");
            return;
        }
        updateTableWidgets();
    }

    updateTableWidgets();
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
