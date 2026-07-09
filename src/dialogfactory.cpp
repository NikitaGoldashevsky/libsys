#include "dialogfactory.h"
#include "addbookdialog.h"
#include "removebookdialog.h"
#include "addreaderdialog.h"
#include "removereaderdialog.h"
#include "addentrydialog.h"
#include "closeentrydialog.h"
#include "searchreaderdialog.h"
#include "searchbookdialog.h"
#include "mainwindow.h"

QDialog* AddBookDialogFactory::createDialog(QWidget* parent) {
    return new AddBookDialog(parent);
}

QDialog* RemoveBookDialogFactory::createDialog(QWidget* parent) {
    return new removebookdialog(parent);
}

QDialog* AddReaderDialogFactory::createDialog(QWidget* parent) {
    return new AddReaderDialog(parent);
}

QDialog* RemoveReaderDialogFactory::createDialog(QWidget* parent) {
    return new RemoveReaderDialog(parent);
}

QDialog* AddEntryDialogFactory::createDialog(QWidget* parent) {
    return new AddEntryDialog(parent);
}

QDialog* CloseEntryDialogFactory::createDialog(QWidget* parent) {
    return new CloseEntryDialog(parent);
}

QDialog* SearchReaderDialogFactory::createDialog(QWidget* parent) {
    MainWindow* mainWindow = dynamic_cast<MainWindow*>(parent);
    if (mainWindow) {
        return new SearchReaderDialog(mainWindow, parent);
    }
    return nullptr;
}

QDialog* SearchBookDialogFactory::createDialog(QWidget* parent) {
    MainWindow* mainWindow = dynamic_cast<MainWindow*>(parent);
    if (mainWindow) {
        return new SearchBookDialog(mainWindow, parent);
    }
    return nullptr;
}
