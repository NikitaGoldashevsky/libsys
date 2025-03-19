/********************************************************************************
** Form generated from reading UI file 'removebookdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOVEBOOKDIALOG_H
#define UI_REMOVEBOOKDIALOG_H

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

class Ui_removebookdialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *leCipher;

    void setupUi(QDialog *removebookdialog)
    {
        if (removebookdialog->objectName().isEmpty())
            removebookdialog->setObjectName("removebookdialog");
        removebookdialog->resize(303, 161);
        buttonBox = new QDialogButtonBox(removebookdialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(-60, 110, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        verticalLayoutWidget = new QWidget(removebookdialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 10, 261, 84));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        leCipher = new QLineEdit(verticalLayoutWidget);
        leCipher->setObjectName("leCipher");

        horizontalLayout->addWidget(leCipher);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(removebookdialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, removebookdialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, removebookdialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(removebookdialog);
    } // setupUi

    void retranslateUi(QDialog *removebookdialog)
    {
        removebookdialog->setWindowTitle(QCoreApplication::translate("removebookdialog", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\272\320\275\320\270\320\263\320\270", nullptr));
        label->setText(QCoreApplication::translate("removebookdialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\210\320\270\321\204\321\200 \320\272\320\275\320\270\320\263\320\270, \320\277\320\276\320\264\320\273\320\265\320\266\320\260\321\211\320\265\320\271 \321\203\320\264\320\260\320\273\320\265\320\275\320\270\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class removebookdialog: public Ui_removebookdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOVEBOOKDIALOG_H
