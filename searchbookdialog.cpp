#include "searchbookdialog.h"
#include "ui_searchbookdialog.h"

SearchBookDialog::SearchBookDialog(MainWindow* mainWindow, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SearchBookDialog),
    mainWindow(mainWindow)
{
    ui->setupUi(this);

    books = mainWindow->getBooksT();
    readers = mainWindow->getReadersHT();
    entries = mainWindow->getEntriesL();

    connect(ui->rbByCipher, &QRadioButton::clicked, this, &SearchBookDialog::rbByCipher_clicked);
    connect(ui->rbByNameOrAuthor, &QRadioButton::clicked, this, &SearchBookDialog::rbByNameOrAuthor_clicked);
    connect(ui->btnSearch, &QPushButton::clicked, this, &SearchBookDialog::btnSearch_clicked);
}

SearchBookDialog::~SearchBookDialog()
{
    delete ui;
}

void SearchBookDialog::rbByCipher_clicked() {
    curSearchType = BY_CIPHER;
}

void SearchBookDialog::rbByNameOrAuthor_clicked() {
    curSearchType = BY_NAME_OR_AUTHOR;
}

void SearchBookDialog::btnSearch_clicked() {
    const std::string input = ui->leInput->text().toStdString();

    switch (curSearchType) {
    case BY_NAME_OR_AUTHOR:
        ui->twBooks->setColumnCount(7);
        ui->twBooks->setHorizontalHeaderLabels(QStringList{"Шифр", "Авторы", "Название", "Издательство", "Год публикации", "Копий всего", "Копий в наличии"});

        books->fillTableWidget(ui->twBooks, input);
        break;
    case BY_CIPHER:
        ui->twBooks->setColumnCount(8);
        ui->twBooks->setHorizontalHeaderLabels(QStringList{"Шифр", "Авторы", "Название", "Издательство", "Год публикации", "Копий всего", "Копий в наличии", "Держатели"});

        ui->twBooks->setRowCount(0);
        const Book* book = books->get(input);
        if (book) {
            ui->twBooks->insertRow(0);
            ui->twBooks->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(book->cipher)));
            ui->twBooks->setItem(0, 1, new QTableWidgetItem(QString::fromStdString(book->authors)));
            ui->twBooks->setItem(0, 2, new QTableWidgetItem(QString::fromStdString(book->name)));
            ui->twBooks->setItem(0, 3, new QTableWidgetItem(QString::fromStdString(book->publisher)));
            ui->twBooks->setItem(0, 4, new QTableWidgetItem(QString::number(book->pubYear)));
            ui->twBooks->setItem(0, 5, new QTableWidgetItem(QString::number(book->copiesAll)));
            ui->twBooks->setItem(0, 6, new QTableWidgetItem(QString::number(book->copiesStock)));

            const std::string cardsString = entries->getCardsByCipher(book->cipher, true);
            std::string cardsAndFIOs = "";

            if (cardsString.empty()) {
                cardsAndFIOs = "-";
            } else {
                std::istringstream iss(cardsString);
                std::string card;
                std::vector<std::string> cards;

                while (iss >> card) {
                    cards.push_back(card);
                }
                for (const auto& card : cards) {
                    cardsAndFIOs += card + "-\'" + readers->get(card)->fio + "\' ";
                }
            }
            ui->twBooks->setItem(0, 7, new QTableWidgetItem(QString::fromStdString(cardsAndFIOs)));

        }
        for (int column = 0; column < ui->twBooks->columnCount(); ++column) {
            ui->twBooks->resizeColumnToContents(column);
        }
        break;
    }
}
