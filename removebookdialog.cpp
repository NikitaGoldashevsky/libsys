#include "removebookdialog.h"
#include "ui_removebookdialog.h"

removebookdialog::removebookdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::removebookdialog)
{
    ui->setupUi(this);

    ui->leCipher->setFocus();
}

removebookdialog::~removebookdialog()
{
    delete ui;
}

std::string removebookdialog::getCipher() const {
    return ui->leCipher->text().toStdString();
}
