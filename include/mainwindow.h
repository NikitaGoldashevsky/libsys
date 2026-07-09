#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <regex>
#include <string>

#include "addbookdialog.h"
#include "removebookdialog.h"
#include "addreaderdialog.h"
#include "removereaderdialog.h"
#include "addentrydialog.h"
#include "closeentrydialog.h"
#include "searchreaderdialog.h"
#include "searchbookdialog.h"
#include "dialogfactory.h"
#include "FineDialog.h"

#include "BooksT.h"
#include "ReadersHT.h"
#include "EntriesL.h"
#include "PublishersHT.h"
#include "LibrariansHT.h"
#include "FinesL.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ReadersHT* getReadersHT();
    BooksT* getBooksT();
    EntriesL *getEntriesL();
    void btnBookSearch_clicked();

    QStandardItemModel booksModel;
    QStandardItemModel readersModel;
    QStandardItemModel entriesModel;

    void updateTableViews();

private:
    Ui::MainWindow *ui;
    BooksT books = BooksT();
    LibrariansHT librarians = LibrariansHT(31);
    ReadersHT readers = ReadersHT(100);
    EntriesL entries = EntriesL();
    PublishersHT publishers = PublishersHT(53);
    Librarian* currentLibrarian = nullptr;
    FinesL fines;
    QStandardItemModel finesModel;

    const std::regex regexCard;
    const std::regex regexCipher;
private slots:
    void btnBookAdd_clicked();
    void btnBookRemove_clicked();
    void btnClearBooks_clicked();

    void btnReaderAdd_clicked();
    void btnClearReaders_clicked();
    void btnReaderRemove_clicked();
    void btnReaderSearch_clicked();

    void btnEntryCheckIn_clicked();
    void btnEntryCheckOut_clicked();
    void btnClearEntries_clicked();

    void on_btnFineImpose_clicked();
    void on_btnFinePayIn_clicked();

};

#endif // MAINWINDOW_H
