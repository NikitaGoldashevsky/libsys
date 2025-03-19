/********************************************************************************
** Form generated from reading UI file 'searchbookdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHBOOKDIALOG_H
#define UI_SEARCHBOOKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchBookDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *rbByCipher;
    QRadioButton *rbByNameOrAuthor;
    QHBoxLayout *horizontalLayout;
    QLineEdit *leInput;
    QPushButton *btnSearch;
    QFrame *line;
    QLabel *label;
    QTableWidget *twBooks;

    void setupUi(QDialog *SearchBookDialog)
    {
        if (SearchBookDialog->objectName().isEmpty())
            SearchBookDialog->setObjectName("SearchBookDialog");
        SearchBookDialog->resize(411, 314);
        verticalLayoutWidget = new QWidget(SearchBookDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 20, 371, 271));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        rbByCipher = new QRadioButton(verticalLayoutWidget);
        rbByCipher->setObjectName("rbByCipher");
        rbByCipher->setChecked(true);

        verticalLayout->addWidget(rbByCipher);

        rbByNameOrAuthor = new QRadioButton(verticalLayoutWidget);
        rbByNameOrAuthor->setObjectName("rbByNameOrAuthor");

        verticalLayout->addWidget(rbByNameOrAuthor);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        leInput = new QLineEdit(verticalLayoutWidget);
        leInput->setObjectName("leInput");

        horizontalLayout->addWidget(leInput);

        btnSearch = new QPushButton(verticalLayoutWidget);
        btnSearch->setObjectName("btnSearch");

        horizontalLayout->addWidget(btnSearch);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout->addWidget(line);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        twBooks = new QTableWidget(verticalLayoutWidget);
        twBooks->setObjectName("twBooks");

        verticalLayout->addWidget(twBooks);


        retranslateUi(SearchBookDialog);

        QMetaObject::connectSlotsByName(SearchBookDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchBookDialog)
    {
        SearchBookDialog->setWindowTitle(QCoreApplication::translate("SearchBookDialog", "\320\237\320\276\320\270\321\201\320\272 \320\272\320\275\320\270\320\263", nullptr));
        rbByCipher->setText(QCoreApplication::translate("SearchBookDialog", "\320\237\320\276 \321\210\320\270\321\204\321\200\321\203", nullptr));
        rbByNameOrAuthor->setText(QCoreApplication::translate("SearchBookDialog", "\320\237\320\276 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\216 \320\270\320\273\320\270 \320\260\320\262\321\202\320\276\321\200\320\260\320\274", nullptr));
        leInput->setPlaceholderText(QString());
        btnSearch->setText(QCoreApplication::translate("SearchBookDialog", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        label->setText(QCoreApplication::translate("SearchBookDialog", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213 \320\277\320\276\320\270\321\201\320\272\320\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchBookDialog: public Ui_SearchBookDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHBOOKDIALOG_H
