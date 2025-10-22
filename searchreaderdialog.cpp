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
        readers->fillTableView(ui->tvReaders, &currentModel, input, false); // ← false = по ФИО → KMP
        break;
    case BY_CARD:
        readers->fillTableView(ui->tvReaders, &currentModel, input, true);  // ← true = по card → exact
        break;
    }
    ui->tvReaders->resizeColumnsToContents();
}
