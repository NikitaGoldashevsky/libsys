#include "addentrydialog.h"
#include "ui_addentrydialog.h"

AddEntryDialog::AddEntryDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddEntryDialog)
{
    ui->setupUi(this);
    ui->leCard->setFocus();
}

AddEntryDialog::~AddEntryDialog()
{
    delete ui;
}

std::string AddEntryDialog::getCard() const {
    return ui->leCard->text().toStdString();
}

std::string AddEntryDialog::getCipher() const {
    return ui->leCipher->text().toStdString();
}

std::string AddEntryDialog::getCheckOutDate() const {
    return ui->deCheckOutDate->date().toString("dd.MM.yyyy").toStdString();
}
