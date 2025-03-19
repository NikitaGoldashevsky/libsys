/********************************************************************************
** Form generated from reading UI file 'addreaderdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDREADERDIALOG_H
#define UI_ADDREADERDIALOG_H

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

class Ui_AddReaderDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLineEdit *leFIO;
    QLabel *label;
    QLineEdit *leAddress;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *leCard;
    QLabel *label_2;
    QDateEdit *deBirthYear;
    QLineEdit *leWorkplace;

    void setupUi(QDialog *AddReaderDialog)
    {
        if (AddReaderDialog->objectName().isEmpty())
            AddReaderDialog->setObjectName("AddReaderDialog");
        AddReaderDialog->resize(411, 286);
        buttonBox = new QDialogButtonBox(AddReaderDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(50, 230, 341, 31));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        gridLayoutWidget = new QWidget(AddReaderDialog);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 20, 371, 201));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        leFIO = new QLineEdit(gridLayoutWidget);
        leFIO->setObjectName("leFIO");

        gridLayout->addWidget(leFIO, 1, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        leAddress = new QLineEdit(gridLayoutWidget);
        leAddress->setObjectName("leAddress");

        gridLayout->addWidget(leAddress, 3, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        leCard = new QLineEdit(gridLayoutWidget);
        leCard->setObjectName("leCard");

        gridLayout->addWidget(leCard, 0, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        deBirthYear = new QDateEdit(gridLayoutWidget);
        deBirthYear->setObjectName("deBirthYear");

        gridLayout->addWidget(deBirthYear, 2, 1, 1, 1);

        leWorkplace = new QLineEdit(gridLayoutWidget);
        leWorkplace->setObjectName("leWorkplace");

        gridLayout->addWidget(leWorkplace, 4, 1, 1, 1);

        QWidget::setTabOrder(leCard, leFIO);
        QWidget::setTabOrder(leFIO, deBirthYear);
        QWidget::setTabOrder(deBirthYear, leAddress);
        QWidget::setTabOrder(leAddress, leWorkplace);

        retranslateUi(AddReaderDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddReaderDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddReaderDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddReaderDialog);
    } // setupUi

    void retranslateUi(QDialog *AddReaderDialog)
    {
        AddReaderDialog->setWindowTitle(QCoreApplication::translate("AddReaderDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\207\320\270\321\202\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_5->setText(QCoreApplication::translate("AddReaderDialog", "\320\234\320\265\321\201\321\202\320\276 \321\200\320\260\320\261\320\276\321\202\321\213", nullptr));
        label->setText(QCoreApplication::translate("AddReaderDialog", "\320\235\320\276\320\274\320\265\321\200 \320\261\320\270\320\273\320\265\321\202\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("AddReaderDialog", "\320\220\320\264\321\200\320\265\321\201 \320\277\321\200\320\276\320\266\320\270\320\262\320\260\320\275\320\270\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("AddReaderDialog", "\320\223\320\276\320\264 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("AddReaderDialog", "\320\244\320\230\320\236", nullptr));
        deBirthYear->setDisplayFormat(QCoreApplication::translate("AddReaderDialog", "yyyy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddReaderDialog: public Ui_AddReaderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDREADERDIALOG_H
