#include "FineDialog.h"
#include "ui_FineDialog.h"
#include <QIntValidator>
#include <QDoubleValidator>

FineDialog::FineDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FineDialog)
{
    ui->setupUi(this);
    ui->leId->setValidator(new QIntValidator(0, 999999, this));

    QDoubleValidator* doubleValidator = new QDoubleValidator(0, 1000000, 2, this);
    doubleValidator->setNotation(QDoubleValidator::StandardNotation);
    ui->leAmount->setValidator(doubleValidator);
}

FineDialog::~FineDialog()
{
    delete ui;
}

QString FineDialog::getId() const { return ui->leId->text(); }
QString FineDialog::getCard() const { return ui->leCard->text(); }
QString FineDialog::getCipher() const { return ui->leCipher->text(); }
QString FineDialog::getReason() const { return ui->leReason->text(); }
double FineDialog::getAmount() const { return ui->leAmount->text().toDouble(); }
