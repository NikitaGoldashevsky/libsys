/********************************************************************************
** Form generated from reading UI file 'addbookdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBOOKDIALOG_H
#define UI_ADDBOOKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddBookDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *leCipher;
    QLabel *label_2;
    QLineEdit *lePublisher;
    QDateEdit *dePubYear;
    QSpinBox *sbCopiesAll;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *leName;
    QLineEdit *leAuthors;
    QLabel *label;
    QLabel *label_7;
    QSpinBox *sbCopiesStock;
    QDialogButtonBox *buttonBox_2;

    void setupUi(QDialog *AddBookDialog)
    {
        if (AddBookDialog->objectName().isEmpty())
            AddBookDialog->setObjectName("AddBookDialog");
        AddBookDialog->resize(419, 373);
        buttonBox = new QDialogButtonBox(AddBookDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(50, 320, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        gridLayoutWidget = new QWidget(AddBookDialog);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(20, 20, 371, 281));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        leCipher = new QLineEdit(gridLayoutWidget);
        leCipher->setObjectName("leCipher");

        gridLayout->addWidget(leCipher, 0, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lePublisher = new QLineEdit(gridLayoutWidget);
        lePublisher->setObjectName("lePublisher");

        gridLayout->addWidget(lePublisher, 3, 1, 1, 1);

        dePubYear = new QDateEdit(gridLayoutWidget);
        dePubYear->setObjectName("dePubYear");

        gridLayout->addWidget(dePubYear, 4, 1, 1, 1);

        sbCopiesAll = new QSpinBox(gridLayoutWidget);
        sbCopiesAll->setObjectName("sbCopiesAll");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sbCopiesAll->sizePolicy().hasHeightForWidth());
        sbCopiesAll->setSizePolicy(sizePolicy);

        gridLayout->addWidget(sbCopiesAll, 5, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        leName = new QLineEdit(gridLayoutWidget);
        leName->setObjectName("leName");

        gridLayout->addWidget(leName, 2, 1, 1, 1);

        leAuthors = new QLineEdit(gridLayoutWidget);
        leAuthors->setObjectName("leAuthors");

        gridLayout->addWidget(leAuthors, 1, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        sbCopiesStock = new QSpinBox(gridLayoutWidget);
        sbCopiesStock->setObjectName("sbCopiesStock");

        gridLayout->addWidget(sbCopiesStock, 6, 1, 1, 1);

        buttonBox_2 = new QDialogButtonBox(AddBookDialog);
        buttonBox_2->setObjectName("buttonBox_2");
        buttonBox_2->setGeometry(QRect(100, 390, 341, 32));
        buttonBox_2->setOrientation(Qt::Orientation::Horizontal);
        buttonBox_2->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        QWidget::setTabOrder(leCipher, leAuthors);
        QWidget::setTabOrder(leAuthors, leName);
        QWidget::setTabOrder(leName, lePublisher);
        QWidget::setTabOrder(lePublisher, dePubYear);
        QWidget::setTabOrder(dePubYear, sbCopiesAll);
        QWidget::setTabOrder(sbCopiesAll, sbCopiesStock);

        retranslateUi(AddBookDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddBookDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddBookDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddBookDialog);
    } // setupUi

    void retranslateUi(QDialog *AddBookDialog)
    {
        AddBookDialog->setWindowTitle(QCoreApplication::translate("AddBookDialog", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("AddBookDialog", "\320\223\320\276\320\264 \320\277\321\203\320\261\320\273\320\270\320\272\320\260\321\206\320\270\320\270", nullptr));
        label_6->setText(QCoreApplication::translate("AddBookDialog", "\320\232\320\276\320\277\320\270\320\271 \320\262\321\201\320\265\320\263\320\276", nullptr));
        label_2->setText(QCoreApplication::translate("AddBookDialog", "\320\220\320\262\321\202\320\276\321\200\321\213", nullptr));
        dePubYear->setDisplayFormat(QCoreApplication::translate("AddBookDialog", "yyyy", nullptr));
        label_4->setText(QCoreApplication::translate("AddBookDialog", "\320\230\320\267\320\264\320\260\321\202\320\265\320\273\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("AddBookDialog", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label->setText(QCoreApplication::translate("AddBookDialog", "\320\250\320\270\321\204\321\200", nullptr));
        label_7->setText(QCoreApplication::translate("AddBookDialog", "\320\232\320\276\320\277\320\270\320\271 \320\262 \320\275\320\260\320\273\320\270\321\207\320\270\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddBookDialog: public Ui_AddBookDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOOKDIALOG_H
