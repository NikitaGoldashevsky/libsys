/********************************************************************************
** Form generated from reading UI file 'searchreaderdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHREADERDIALOG_H
#define UI_SEARCHREADERDIALOG_H

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

class Ui_SearchReaderDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *rbByCard;
    QRadioButton *rbByFIO;
    QHBoxLayout *horizontalLayout;
    QLineEdit *leInput;
    QPushButton *btnSearch;
    QFrame *line;
    QLabel *label;
    QTableWidget *twReaders;

    void setupUi(QDialog *SearchReaderDialog)
    {
        if (SearchReaderDialog->objectName().isEmpty())
            SearchReaderDialog->setObjectName("SearchReaderDialog");
        SearchReaderDialog->resize(414, 313);
        verticalLayoutWidget = new QWidget(SearchReaderDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 20, 371, 271));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        rbByCard = new QRadioButton(verticalLayoutWidget);
        rbByCard->setObjectName("rbByCard");
        rbByCard->setChecked(true);

        verticalLayout->addWidget(rbByCard);

        rbByFIO = new QRadioButton(verticalLayoutWidget);
        rbByFIO->setObjectName("rbByFIO");

        verticalLayout->addWidget(rbByFIO);

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

        twReaders = new QTableWidget(verticalLayoutWidget);
        twReaders->setObjectName("twReaders");

        verticalLayout->addWidget(twReaders);


        retranslateUi(SearchReaderDialog);

        QMetaObject::connectSlotsByName(SearchReaderDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchReaderDialog)
    {
        SearchReaderDialog->setWindowTitle(QCoreApplication::translate("SearchReaderDialog", "Dialog", nullptr));
        rbByCard->setText(QCoreApplication::translate("SearchReaderDialog", "\320\237\320\276 \320\275\320\276\320\274\320\265\321\200\321\203 \320\261\320\270\320\273\320\265\321\202\320\260", nullptr));
        rbByFIO->setText(QCoreApplication::translate("SearchReaderDialog", "\320\237\320\276 \320\244\320\230\320\236", nullptr));
        leInput->setPlaceholderText(QString());
        btnSearch->setText(QCoreApplication::translate("SearchReaderDialog", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        label->setText(QCoreApplication::translate("SearchReaderDialog", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213 \320\277\320\276\320\270\321\201\320\272\320\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchReaderDialog: public Ui_SearchReaderDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHREADERDIALOG_H
