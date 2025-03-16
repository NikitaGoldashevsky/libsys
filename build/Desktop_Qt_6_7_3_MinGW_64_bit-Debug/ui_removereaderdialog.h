/********************************************************************************
** Form generated from reading UI file 'removereaderdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOVEREADERDIALOG_H
#define UI_REMOVEREADERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RemoveReaderDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *leCard;

    void setupUi(QDialog *RemoveReaderDialog)
    {
        if (RemoveReaderDialog->objectName().isEmpty())
            RemoveReaderDialog->setObjectName("RemoveReaderDialog");
        RemoveReaderDialog->resize(301, 170);
        buttonBox = new QDialogButtonBox(RemoveReaderDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(-60, 120, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        verticalLayoutWidget = new QWidget(RemoveReaderDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 20, 261, 84));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        leCard = new QLineEdit(verticalLayoutWidget);
        leCard->setObjectName("leCard");

        horizontalLayout->addWidget(leCard);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(RemoveReaderDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, RemoveReaderDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, RemoveReaderDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(RemoveReaderDialog);
    } // setupUi

    void retranslateUi(QDialog *RemoveReaderDialog)
    {
        RemoveReaderDialog->setWindowTitle(QCoreApplication::translate("RemoveReaderDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RemoveReaderDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \320\261\320\270\320\273\320\265\321\202\320\260 \321\207\320\270\321\202\320\260\321\202\320\265\320\273\321\217, \320\277\320\276\320\264\320\273\320\265\320\266\320\260\321\211\320\265\320\263\320\276 \321\203\320\264\320\260\320\273\320\265\320\275\320\270\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RemoveReaderDialog: public Ui_RemoveReaderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOVEREADERDIALOG_H
