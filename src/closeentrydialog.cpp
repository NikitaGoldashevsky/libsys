#include "closeentrydialog.h"
#include "ui_closeentrydialog.h"

CloseEntryDialog::CloseEntryDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CloseEntryDialog)
{
    ui->setupUi(this);
    ui->leCard->setFocus();
}

CloseEntryDialog::~CloseEntryDialog()
{
    delete ui;
}

std::string CloseEntryDialog::getCard() const {
    return ui->leCard->text().toStdString();
}

std::string CloseEntryDialog::getCipher() const {
    return ui->leCipher->text().toStdString();
}

std::string CloseEntryDialog::getCheckInDate() const {
    return ui->deCheckInDate->date().toString("dd.MM.yyyy").toStdString();
}
