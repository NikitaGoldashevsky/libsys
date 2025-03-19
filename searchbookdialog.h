#ifndef SEARCHBOOKDIALOG_H
#define SEARCHBOOKDIALOG_H

#include <QDialog>
#include <QString>
#include <sstream>

#include "mainwindow.h"
#include "BooksT.h"
#include "ReadersHT.h"
#include "EntriesL.h"

class MainWindow;

namespace Ui {
class SearchBookDialog;
}

class SearchBookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchBookDialog(MainWindow* mainWindow, QWidget *parent = nullptr);
    ~SearchBookDialog();

private:
    Ui::SearchBookDialog *ui;

    enum SEARCH_TYPE {
        BY_CIPHER,
        BY_NAME_OR_AUTHOR
    };

    SEARCH_TYPE curSearchType = BY_CIPHER;
    void rbByCipher_clicked();
    void rbByNameOrAuthor_clicked();
    void btnSearch_clicked();

    MainWindow* mainWindow;
    BooksT* books;
    ReadersHT* readers;
    EntriesL* entries;
};

#endif // SEARCHBOOKDIALOG_H
