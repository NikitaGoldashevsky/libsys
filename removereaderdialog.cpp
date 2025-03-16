#include "removereaderdialog.h"
#include "ui_removereaderdialog.h"

RemoveReaderDialog::RemoveReaderDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RemoveReaderDialog)
{
    ui->setupUi(this);
    ui->leCard->setFocus();
}

RemoveReaderDialog::~RemoveReaderDialog()
{
    delete ui;
}

std::string RemoveReaderDialog::getCard() const
{
    return ui->leCard->text().toStdString();
}
