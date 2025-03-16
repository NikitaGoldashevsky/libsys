#include "addbookdialog.h"
#include "ui_addbookdialog.h"

AddBookDialog::AddBookDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddBookDialog)
{
    ui->setupUi(this);

    ui->leCipher->setFocus();
    ui->sbCopiesAll->setRange(0, 999999);
    ui->sbCopiesStock->setRange(0, 999999);
}

AddBookDialog::~AddBookDialog()
{
    delete ui;
}

std::string AddBookDialog::getName() const
{
    return ui->leName->text().toStdString();
}

std::string AddBookDialog::getAuthors() const
{
    return ui->leAuthors->text().toStdString();
}

std::string AddBookDialog::getCipher() const
{
    return ui->leCipher->text().toStdString();
}

std::string AddBookDialog::getPublisher() const
{
    return ui->lePublisher->text().toStdString();
}

int AddBookDialog::getPublicationYear() const
{
    return ui->dePubYear->date().year();
}

int AddBookDialog::getCopiesAll() const
{
    return ui->sbCopiesAll->value();
}

int AddBookDialog::getCopiesStock() const
{
    return ui->sbCopiesStock->value();
}
