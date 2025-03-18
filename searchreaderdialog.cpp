#include "searchreaderdialog.h"
#include "ui_searchreaderdialog.h"

SearchReaderDialog::SearchReaderDialog(MainWindow* mainWindow, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SearchReaderDialog),
    mainWindow(mainWindow)
{
    ui->setupUi(this);

    books = mainWindow->getBooksT();
    readers = mainWindow->getReadersHT();
    entries = mainWindow->getEntriesL();

    connect(ui->rbByCard, &QRadioButton::clicked, this, &SearchReaderDialog::rbByCard_clicked);
    connect(ui->rbByFIO, &QRadioButton::clicked, this, &SearchReaderDialog::rbByFIO_clicked);
    connect(ui->btnSearch, &QPushButton::clicked, this, &SearchReaderDialog::btnSearch_clicked);
}

SearchReaderDialog::~SearchReaderDialog()
{
    delete ui;
}

void SearchReaderDialog::rbByCard_clicked() {
    curSearchType = BY_CARD;
}

void SearchReaderDialog::rbByFIO_clicked() {
    curSearchType = BY_FIO;
}

void SearchReaderDialog::btnSearch_clicked() {
    const std::string input = ui->leInput->text().toStdString();

    switch (curSearchType) {
    case BY_FIO:
        ui->twReaders->setColumnCount(5);
        ui->twReaders->setHorizontalHeaderLabels(QStringList{"Номер билета", "ФИО", "Год рождения", "Адрес", "Место работы"});

        readers->fillTableWidget(ui->twReaders, input);
        break;
    case BY_CARD:
        ui->twReaders->setColumnCount(6);
        ui->twReaders->setHorizontalHeaderLabels(QStringList{"Номер билета", "ФИО", "Год рождения", "Адрес", "Место работы", "Шифры выданных книг"});

        ui->twReaders->setRowCount(0);
        const Reader* reader = readers->get(input);
        if (reader) {
            ui->twReaders->insertRow(0);
            ui->twReaders->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(reader->card)));
            ui->twReaders->setItem(0, 1, new QTableWidgetItem(QString::fromStdString(reader->fio)));
            ui->twReaders->setItem(0, 2, new QTableWidgetItem(QString::number(reader->birthYear)));
            ui->twReaders->setItem(0, 3, new QTableWidgetItem(QString::fromStdString(reader->address)));
            ui->twReaders->setItem(0, 4, new QTableWidgetItem(QString::fromStdString(reader->workplace)));
            ui->twReaders->setItem(0, 5, new QTableWidgetItem(QString::fromStdString(entries->getCiphersByCard(reader->card))));
        }
        for (int column = 0; column < ui->twReaders->columnCount(); ++column) {
            ui->twReaders->resizeColumnToContents(column);
        }
        break;
    }
}
