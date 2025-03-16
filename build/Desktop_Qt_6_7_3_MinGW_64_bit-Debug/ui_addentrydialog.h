/********************************************************************************
** Form generated from reading UI file 'addentrydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDENTRYDIALOG_H
#define UI_ADDENTRYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddEntryDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *leCipher;
    QLabel *label;
    QDateEdit *deCheckOutDate;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *leCard;

    void setupUi(QDialog *AddEntryDialog)
    {
        if (AddEntryDialog->objectName().isEmpty())
            AddEntryDialog->setObjectName("AddEntryDialog");
        AddEntryDialog->resize(417, 207);
        buttonBox = new QDialogButtonBox(AddEntryDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(50, 160, 341, 31));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        gridLayoutWidget = new QWidget(AddEntryDialog);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 20, 371, 121));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        leCipher = new QLineEdit(gridLayoutWidget);
        leCipher->setObjectName("leCipher");

        gridLayout->addWidget(leCipher, 1, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        deCheckOutDate = new QDateEdit(gridLayoutWidget);
        deCheckOutDate->setObjectName("deCheckOutDate");

        gridLayout->addWidget(deCheckOutDate, 2, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        leCard = new QLineEdit(gridLayoutWidget);
        leCard->setObjectName("leCard");

        gridLayout->addWidget(leCard, 0, 1, 1, 1);

        QWidget::setTabOrder(leCard, leCipher);
        QWidget::setTabOrder(leCipher, deCheckOutDate);

        retranslateUi(AddEntryDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddEntryDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddEntryDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddEntryDialog);
    } // setupUi

    void retranslateUi(QDialog *AddEntryDialog)
    {
        AddEntryDialog->setWindowTitle(QCoreApplication::translate("AddEntryDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddEntryDialog", "\320\235\320\276\320\274\320\265\321\200 \320\261\320\270\320\273\320\265\321\202\320\260", nullptr));
        deCheckOutDate->setDisplayFormat(QCoreApplication::translate("AddEntryDialog", "dd.MM.yyyy", nullptr));
        label_2->setText(QCoreApplication::translate("AddEntryDialog", "\320\250\320\270\321\204\321\200", nullptr));
        label_3->setText(QCoreApplication::translate("AddEntryDialog", "\320\224\320\260\321\202\320\260 \320\262\321\213\320\264\320\260\321\207\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddEntryDialog: public Ui_AddEntryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDENTRYDIALOG_H
