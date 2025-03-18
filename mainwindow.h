#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "addbookdialog.h"
#include "removebookdialog.h"
#include "addreaderdialog.h"
#include "removereaderdialog.h"
#include "addentrydialog.h"
#include "closeentrydialog.h"
#include "searchreaderdialog.h"

#include "BooksT.h"
#include "ReadersHT.h"
#include "EntriesL.h"

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
private:
    Ui::MainWindow *ui;
    BooksT books = BooksT();
    ReadersHT readers = ReadersHT(100);
    EntriesL entries = EntriesL();

    void updateTableWidgets();
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
};

#endif // MAINWINDOW_H
