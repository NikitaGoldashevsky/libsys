#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "addbookdialog.h"
#include "removebookdialog.h"
#include "addreaderdialog.h"
#include "removereaderdialog.h"

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
};

#endif // MAINWINDOW_H
