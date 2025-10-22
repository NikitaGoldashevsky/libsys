#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MainWindowObserver.h"
#include "PublisherBuilder.h"
#include "Fine.h"
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    regexCard(R"(^\d\d\d\d-\d\d$)"),
    regexCipher(R"(^\d{2}\d\.\d{2}\d$)")
{
    ui->setupUi(this);
    ui->btnBookAdd->setFocus();

    // Set models' headers
    booksModel.setHorizontalHeaderLabels(QStringList() << "Шифр" << "Авторы" << "Название" << "Издательство" << "Год публикации" << "В наличии");
    readersModel.setHorizontalHeaderLabels(QStringList() << "Номер билета" << "ФИО" << "Год рождения" << "Адрес" << "Место работы");
    entriesModel.setHorizontalHeaderLabels(QStringList() << "Номер билета" << "Шифр" << "Дата выдачи" << "Дата возврата");

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

    MainWindowObserver* observer = new MainWindowObserver(this);
    entries.addObserver(observer);
    qDebug() << "Создан наблюдатель: " << observer;

    // Startup Data--------------
    if (!publishers.has("Some American publisher idk")) {
        Publisher* p1 = new Publisher{"Some American publisher idk", "Unknown address", "unknown@pub.com"};
        publishers.add(p1);
    }
    if (!publishers.has("Some British publisher idk")) {
        Publisher* p2 = new Publisher{"Some British publisher idk", "Unknown address", "unknown@pub.co.uk"};
        publishers.add(p2);
    }

    Publisher* p1 = publishers.get("Some American publisher idk");
    Publisher* p2 = publishers.get("Some British publisher idk");

    books.add(new Book{"001.002", "Stephen King", "Billy summers", p1, 2015, true});
    books.add(new Book{"001.001", "Thomas De Quincey", "Confessions of an English Opium-Eater", p2, 1822, false});

    readers.add(new Reader{"Ч0001-25", "David Lockridge", 1973, "Jersey City", "Crescent Hotel"});
    readers.add(new Reader{"Ч0002-25", "John Smith", 1963, "Gallifrey", "Whole time and space"});

    librarians.add(new Librarian{"L001", "Анна Сергеевна", "Библиотекарь", "Утренняя"});
    librarians.add(new Librarian{"L002", "Ольга Ивановна", "Старший библиотекарь", "Вечерняя"});
    currentLibrarian = librarians.get("L001");

    entries.add("Ч0001-25", "001.002", "21.03.2011", "25.03.2011", "L001");
    entries.add("Ч0002-25", "001.001", "27.03.2011", "-", "L002");
    // --------------------------

    updateTableViews();
}

MainWindow::~MainWindow() {
    books.clear();
    readers.clear();
    entries.clear();
    librarians.clear();
    publishers.clear();
    fines.clear();
    delete ui;
}

void MainWindow::btnBookAdd_clicked() {
    // Create a dialog factory
    AddBookDialogFactory factory;

    // Use the factory to create a dialog
    QDialog* dialogPtr = factory.createDialog(this);
    AddBookDialog* d = static_cast<AddBookDialog*>(dialogPtr);

    while (true) {
        if (d->exec() == QDialog::Accepted) {
            if (!std::regex_search(d->getCipher(), regexCipher)) {
                QMessageBox::critical(this, "Ошибка", "Введенный шифр некорректен!");
                continue;
            }

            if (d->getName().empty()) {
                QMessageBox::critical(this, "Ошибка", "Не указаны авторы книги!");
                continue;
            }

            if (d->getName().empty()) {
                QMessageBox::critical(this, "Ошибка", "Не указано название книги!");
                continue;
            }

            if (d->getPublisher().empty()) {
                QMessageBox::critical(this, "Ошибка", "Не указан издатель!");
                continue;
            }

            if (!books.has(d->getCipher())) {
                const std::string pubName = d->getPublisher();
                Publisher* pub = publishers.get(pubName);

                if (!pub) {
                    // Запрашиваем недостающие данные у пользователя
                    bool ok1, ok2;
                    QString address = QInputDialog::getText(
                        this, "Адрес издательства",
                        "Введите адрес издательства \"" + QString::fromStdString(pubName) + "\":",
                        QLineEdit::Normal, "", &ok1
                        );
                    if (!ok1) {
                        delete dialogPtr;
                        return;
                    }
                    QString contactInfo = QInputDialog::getText(
                        this, "Контактная информация",
                        "Введите телефон или email издательства \"" + QString::fromStdString(pubName) + "\":",
                        QLineEdit::Normal, "", &ok2
                        );
                    if (!ok2) {
                        delete dialogPtr;
                        return;
                    }

                    // Создаём через Builder — это и есть реализация паттерна
                    pub = PublisherBuilder()
                              .setName(pubName)
                              .setAddress(address.toStdString())
                              .setContactInfo(contactInfo.toStdString())
                              .build();

                    publishers.add(pub);
                }

                // Теперь добавляем книгу с уже существующим или новым издательством
                books.add(new Book{
                    d->getCipher(),
                    d->getAuthors(),
                    d->getName(),
                    pub,
                    d->getPublicationYear(),
                    d->getInStock()
                });

                updateTableViews();
                delete dialogPtr;
                return;
            }
            else {
                QMessageBox::critical(this, "Ошибка", "Книга с указанным шифром уже есть в базе данных!");
                continue;
            }
        }
        else {
            delete dialogPtr;
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
                std::string msg = "Удаление невозможно. Экземпляр указанной книги имеет читатель с билетом ";
                msg += cards;
                QMessageBox::critical(this, "Ошибка", QString::fromStdString(msg));
                return;
            } else {
                books.remove(cipher);
                entries.removeAllByCipher(cipher);
                updateTableViews();
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
                updateTableViews();
            }
        } else {
            QMessageBox::critical(this, "Ошибка", "Читателя с указанным номером билета нет в базе данных!");
            return;
        }
    }
}

void MainWindow::btnClearBooks_clicked() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Вопрос");
    msgBox.setText("Удалить все книги или только не выданные в данный момент?");

    const QString opt1Text = "Все";
    const QString opt2Text = "Не выданные";
    msgBox.addButton(opt1Text, QMessageBox::YesRole);
    msgBox.addButton(opt2Text, QMessageBox::NoRole);
    msgBox.exec();

    if (msgBox.clickedButton()->text() == opt1Text) {
        QMessageBox::information(this, "Внимание",
                                 "В целях обеспечения корректности информации, будет очищена вся база данных.",
                                 QMessageBox::Ok);
        books.clear();
        readers.clear();
        entries.clear();
        updateTableViews();

    } else {
        int rowCount = ui->tvBooks->model()->rowCount();

        for (int row = 0; row < rowCount; ++row) {
            QAbstractItemModel *model = ui->tvBooks->model();
            QVariant data = model->data(model->index(row, 0));

            const std::string cipher = data.toString().toStdString();
            const std::string cardsString = entries.getCardsByCipher(cipher, true);

            if (cardsString.empty()) {
                books.remove(cipher);
            }
            else {
                continue; // someone has the book, so it shouldnt be removed
            }
        }
        updateTableViews();
    }
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
                updateTableViews();
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
    QMessageBox msgBox;
    msgBox.setWindowTitle("Вопрос");
    msgBox.setText("Удалить всех читателей или только не имеющих в данный момент книг?");

    const QString opt1Text = "Всех";
    const QString opt2Text = "Не имеющих книг";
    msgBox.addButton(opt1Text, QMessageBox::YesRole);
    msgBox.addButton(opt2Text, QMessageBox::NoRole);
    msgBox.exec();

    if (msgBox.clickedButton()->text() == opt1Text) {
        QMessageBox::information(this, "Внимание",
                                 "В целях обеспечения корректности информации, будет очищена вся база данных.",
                                 QMessageBox::Ok);
        books.clear();
        readers.clear();
        entries.clear();
        updateTableViews();

    } else {
        int rowCount = ui->tvReaders->model()->rowCount();

        for (int row = 0; row < rowCount; ++row) {
            QAbstractItemModel *model = ui->tvReaders->model();
            QVariant data = model->data(model->index(row, 0));

            const std::string card = data.toString().toStdString();
            const std::string ciphersString = entries.getCiphersByCard(card, true);

            if (ciphersString.empty()) {
                readers.remove(card);
            }
            else {
                continue; // reader has some books, so he shouldnt be removed
            }
        }
        updateTableViews();
    }
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
                books.get(entry->cipher)->inStock = true;
                updateTableViews();
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

            if (book->inStock == false) {
                QMessageBox::critical(this, "Ошибка", "Указанной книги нет в наличии!");
                continue;
            }

            entries.add(card, cipher, d.getCheckOutDate(), NOT_RETURNED,
                        currentLibrarian ? currentLibrarian->id : "");

            // Добавляем ID библиотекаря в запись
            if (currentLibrarian) {
                qDebug() << "Выдачу оформил библиотекарь:" << QString::fromStdString(currentLibrarian->fio);
            }

            book->inStock = false;
            updateTableViews();
            return;
        }
        else {
            return;
        }
    }
}

void MainWindow::btnClearEntries_clicked() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Вопрос");
    msgBox.setText("Удалить все записи или только записи о возвращенных книгах?");

    const QString opt1Text = "Все";
    const QString opt2Text = "О возвращенных книгах";
    msgBox.addButton(opt1Text, QMessageBox::YesRole);
    msgBox.addButton(opt2Text, QMessageBox::NoRole);
    msgBox.exec();

    if (msgBox.clickedButton()->text() == opt1Text) {
        QMessageBox::information(this, "Внимание",
                                 "В целях обеспечения корректности информации, будет очищена вся база данных.",
                                 QMessageBox::Ok);
        books.clear();
        readers.clear();
        entries.clear();
        updateTableViews();

    } else {
        int rowCount = ui->tvEntries->model()->rowCount();

        for (int row = 0; row < rowCount; ++row) {
            QAbstractItemModel *model = ui->tvEntries->model();

            QVariant cipherData = model->data(model->index(row, 1));
            QVariant cardData = model->data(model->index(row, 0));
            QVariant returnDateData = model->data(model->index(row, 3));

            const std::string cipher = cipherData.toString().toStdString();
            const std::string card = cardData.toString().toStdString();
            const std::string returnDate = returnDateData.toString().toStdString();

            if (returnDate == NOT_RETURNED) {
                entries.remove(card, cipher);
            }
            else {
                continue; // entry isnt closed, i.e. the book hasnt been returned yet
            }
        }
        updateTableViews();
    }
}

void MainWindow::on_btnFineImpose_clicked()
{
    FineDialog d(this);
    if (d.exec() == QDialog::Accepted)
    {
        QString id = d.getId();
        QString card = d.getCard();
        QString cipher = d.getCipher();
        QString reason = d.getReason();
        double amount = d.getAmount();

        if (id.isEmpty() || card.isEmpty() || cipher.isEmpty()) {
            QMessageBox::warning(this, "Ошибка", "Поля ID, билет и шифр обязательны!");
            return;
        }
        if (fines.get(id.toStdString())) {
            QMessageBox::warning(this, "Ошибка", "Штраф с таким ID уже существует!");
            return;
        }
        if (!readers.has(card.toStdString())) {
            QMessageBox::warning(this, "Ошибка", "Читатель не найден!");
            return;
        }
        if (!books.has(cipher.toStdString())) {
            QMessageBox::warning(this, "Ошибка", "Книга не найдена!");
            return;
        }

        Entry* entry = entries.get(card.toStdString(), cipher.toStdString());
        if (!entry) {
            QMessageBox::warning(this, "Ошибка", "Запись о выдаче не найдена!");
            return;
        }

        FineDecorator* fine = new FineDecorator(
            entry,
            id.toStdString(),
            amount,
            reason.toStdString(),
            false
            );

        fines.add(fine);
        fines.fillTableView(ui->tvFines, &finesModel);
        QMessageBox::information(this, "Штраф добавлен", "Штраф успешно добавлен.");
    }
}

void MainWindow::on_btnFinePayIn_clicked()
{
    auto selection = ui->tvFines->selectionModel()->selectedRows();
    if (selection.isEmpty()) {
        QMessageBox::information(this, "Инфо", "Выберите штраф для оплаты.");
        return;
    }

    QModelIndex index = selection.first();
    QString fineId = ui->tvFines->model()->data(ui->tvFines->model()->index(index.row(), 0)).toString();

    FineDecorator* fine = fines.get(fineId.toStdString());  // ← изменено: FineDecorator*
    if (!fine) {
        QMessageBox::warning(this, "Ошибка", "Не удалось найти выбранный штраф.");
        return;
    }

    fine->setPaid(true);  // ← используем геттер/сеттер, а не прямой доступ к полю
    QMessageBox::information(this, "Оплата", "Штраф успешно отмечен как оплаченный.");

    fines.fillTableView(ui->tvFines, &finesModel);
}

void MainWindow::updateTableViews() {
    books.fillTableView(ui->tvBooks, &booksModel);
    readers.fillTableView(ui->tvReaders, &readersModel);
    entries.fillTableView(ui->tvEntries, &entriesModel);

    for (const auto tv : {ui->tvBooks, ui->tvReaders, ui->tvEntries}) {
        tv->resizeColumnsToContents();
    }
    fines.fillTableView(ui->tvFines, &finesModel);
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
