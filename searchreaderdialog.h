#ifndef SEARCHREADERDIALOG_H
#define SEARCHREADERDIALOG_H

#include <QDialog>
#include "QString"

#include "mainwindow.h"
#include "BooksT.h"
#include "ReadersHT.h"
#include "EntriesL.h"

class MainWindow;

namespace Ui {
class SearchReaderDialog;
}

class SearchReaderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchReaderDialog(MainWindow* mainWindow, QWidget *parent = nullptr);
    ~SearchReaderDialog();

private:
    Ui::SearchReaderDialog *ui;

    enum SEARCH_TYPE {
        BY_CARD,
        BY_FIO
    };

    SEARCH_TYPE curSearchType = BY_CARD;
    void rbByCard_clicked();
    void btnSearch_clicked();
    void rbByFIO_clicked();

    MainWindow* mainWindow;
    BooksT* books;
    ReadersHT* readers;
    EntriesL* entries;

    const QString inputPlaceholderCard = QString("Номер билета...");
    const QString inputPlaceholderFIO = QString("ФИО...");
};

#endif // SEARCHREADERDIALOG_H
