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
        readers->fillTableView(ui->tvReaders, &currentModel, input);
        break;
    case BY_CARD:
        currentModel.clear();
        currentModel.setHorizontalHeaderLabels(QStringList() << "Номер билета" << "ФИО" << "Год рождения" << "Адрес" << "Место работы" << "Выданные читателю книги");

        const Reader* reader = readers->get(input);
        if (reader) {
            QList<QVariant> row =
                {QString::fromStdString(reader->card), QString::fromStdString(reader->fio),
                 QString::number(reader->birthYear), QString::fromStdString(reader->address),
                 QString::fromStdString(reader->workplace)};

            QList<QStandardItem*> items;
            for (const auto &value : row) {
                items.append(new QStandardItem(value.toString()));
            }

            std::string ciphersString = entries->getCiphersByCard(reader->card, true);
            if (ciphersString.empty()) {
                ciphersString = "-";
            }

            items.append(new QStandardItem(QString::fromStdString(ciphersString)));
            currentModel.appendRow(items);
            ui->tvReaders->setModel(&currentModel);
        }
        break;
    }
    ui->tvReaders->resizeColumnsToContents();
}
