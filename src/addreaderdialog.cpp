#include "addreaderdialog.h"
#include "ui_addreaderdialog.h"

AddReaderDialog::AddReaderDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddReaderDialog)
{
    ui->setupUi(this);
    ui->leCard->setFocus();
}

AddReaderDialog::~AddReaderDialog()
{
    delete ui;
}

std::string AddReaderDialog::getCard() const
{
    return ui->leCard->text().toStdString();
}

std::string AddReaderDialog::getFIO() const
{
    return ui->leFIO->text().toStdString();
}

int AddReaderDialog::getBirthYear() const
{
    return ui->deBirthYear->date().year();
}

std::string AddReaderDialog::getAddress() const
{
    return ui->leAddress->text().toStdString();
}

std::string AddReaderDialog::getWorkplace() const
{
    return ui->leWorkplace->text().toStdString();
}
