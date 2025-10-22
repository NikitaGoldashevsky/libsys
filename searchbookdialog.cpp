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
        books->fillTableView(ui->tvBooks, &currentModel, input);
        break;
    case BY_CIPHER:
        currentModel.clear();
        currentModel.setHorizontalHeaderLabels(QStringList() << "Шифр" << "Авторы" << "Название" << "Издательство" << "Год публикации" << "В наличии" << "Имеющие книгу читатели");

        const Book* book = books->get(input);
        if (book) {
            QList<QVariant> row =
                {QString::fromStdString(book->cipher), QString::fromStdString(book->authors),
                 QString::fromStdString(book->name), QString::fromStdString(book->publisher->name),
                 QString::number(book->pubYear), QString(book->inStock == true ? "да" : "нет")};

            QList<QStandardItem*> items;
            for (const auto &value : row) {
                items.append(new QStandardItem(value.toString()));
            }

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
            items.append(new QStandardItem(QString::fromStdString(cardsAndFIOs)));
            currentModel.appendRow(items);
            ui->tvBooks->setModel(&currentModel);
        }
        break;
    }
    ui->tvBooks->resizeColumnsToContents();
}
