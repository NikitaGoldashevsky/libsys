#ifndef DIALOGFACTORY_H
#define DIALOGFACTORY_H

#include <QDialog>
#include <QWidget>

// Abstract dialog factory
class DialogFactory {
public:
    virtual ~DialogFactory() {}
    virtual QDialog* createDialog(QWidget* parent = nullptr) = 0;
};

// Concrete factories for specific dialog types
class AddBookDialogFactory : public DialogFactory {
public:
    QDialog* createDialog(QWidget* parent = nullptr) override;
};

class RemoveBookDialogFactory : public DialogFactory {
public:
    QDialog* createDialog(QWidget* parent = nullptr) override;
};

class AddReaderDialogFactory : public DialogFactory {
public:
    QDialog* createDialog(QWidget* parent = nullptr) override;
};

class RemoveReaderDialogFactory : public DialogFactory {
public:
    QDialog* createDialog(QWidget* parent = nullptr) override;
};

class AddEntryDialogFactory : public DialogFactory {
public:
    QDialog* createDialog(QWidget* parent = nullptr) override;
};

class CloseEntryDialogFactory : public DialogFactory {
public:
    QDialog* createDialog(QWidget* parent = nullptr) override;
};

class SearchReaderDialogFactory : public DialogFactory {
public:
    QDialog* createDialog(QWidget* parent = nullptr) override;
};

class SearchBookDialogFactory : public DialogFactory {
public:
    QDialog* createDialog(QWidget* parent = nullptr) override;
};

#endif // DIALOGFACTORY_H
