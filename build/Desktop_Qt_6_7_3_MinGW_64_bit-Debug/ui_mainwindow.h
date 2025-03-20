/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *twBooks;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btnBookAdd;
    QPushButton *btnBookRemove;
    QPushButton *btnBookSearch;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnClearBooks;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *twReaders;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnReaderAdd;
    QPushButton *btnReaderRemove;
    QPushButton *btnReaderSearch;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnClearReaders;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_8;
    QTableWidget *twEntries;
    QVBoxLayout *verticalLayout_9;
    QPushButton *btnEntryCheckOut;
    QPushButton *btnEntryCheckIn;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btnClearEntries;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(820, 700);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(820, 700));
        MainWindow->setMaximumSize(QSize(820, 700));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::AddressBookNew));
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget_6 = new QWidget(centralwidget);
        verticalLayoutWidget_6->setObjectName("verticalLayoutWidget_6");
        verticalLayoutWidget_6->setGeometry(QRect(20, 10, 781, 671));
        verticalLayout_10 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_3 = new QLabel(verticalLayoutWidget_6);
        label_3->setObjectName("label_3");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_3->setFont(font);

        verticalLayout_4->addWidget(label_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        twBooks = new QTableWidget(verticalLayoutWidget_6);
        twBooks->setObjectName("twBooks");
        twBooks->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

        verticalLayout_5->addWidget(twBooks);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        btnBookAdd = new QPushButton(verticalLayoutWidget_6);
        btnBookAdd->setObjectName("btnBookAdd");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnBookAdd->sizePolicy().hasHeightForWidth());
        btnBookAdd->setSizePolicy(sizePolicy1);
        btnBookAdd->setMinimumSize(QSize(0, 28));

        verticalLayout_6->addWidget(btnBookAdd);

        btnBookRemove = new QPushButton(verticalLayoutWidget_6);
        btnBookRemove->setObjectName("btnBookRemove");
        sizePolicy1.setHeightForWidth(btnBookRemove->sizePolicy().hasHeightForWidth());
        btnBookRemove->setSizePolicy(sizePolicy1);
        btnBookRemove->setMinimumSize(QSize(0, 28));

        verticalLayout_6->addWidget(btnBookRemove);

        btnBookSearch = new QPushButton(verticalLayoutWidget_6);
        btnBookSearch->setObjectName("btnBookSearch");
        sizePolicy1.setHeightForWidth(btnBookSearch->sizePolicy().hasHeightForWidth());
        btnBookSearch->setSizePolicy(sizePolicy1);
        btnBookSearch->setMinimumSize(QSize(0, 28));

        verticalLayout_6->addWidget(btnBookSearch);


        horizontalLayout_2->addLayout(verticalLayout_6);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_10->addLayout(verticalLayout_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        btnClearBooks = new QPushButton(verticalLayoutWidget_6);
        btnClearBooks->setObjectName("btnClearBooks");
        sizePolicy1.setHeightForWidth(btnClearBooks->sizePolicy().hasHeightForWidth());
        btnClearBooks->setSizePolicy(sizePolicy1);
        btnClearBooks->setMinimumSize(QSize(0, 30));

        horizontalLayout_4->addWidget(btnClearBooks);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_10->addLayout(horizontalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        label_2 = new QLabel(verticalLayoutWidget_6);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        twReaders = new QTableWidget(verticalLayoutWidget_6);
        twReaders->setObjectName("twReaders");
        twReaders->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

        verticalLayout_2->addWidget(twReaders);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        btnReaderAdd = new QPushButton(verticalLayoutWidget_6);
        btnReaderAdd->setObjectName("btnReaderAdd");
        sizePolicy1.setHeightForWidth(btnReaderAdd->sizePolicy().hasHeightForWidth());
        btnReaderAdd->setSizePolicy(sizePolicy1);
        btnReaderAdd->setMinimumSize(QSize(0, 28));

        verticalLayout_3->addWidget(btnReaderAdd);

        btnReaderRemove = new QPushButton(verticalLayoutWidget_6);
        btnReaderRemove->setObjectName("btnReaderRemove");
        sizePolicy1.setHeightForWidth(btnReaderRemove->sizePolicy().hasHeightForWidth());
        btnReaderRemove->setSizePolicy(sizePolicy1);
        btnReaderRemove->setMinimumSize(QSize(0, 28));

        verticalLayout_3->addWidget(btnReaderRemove);

        btnReaderSearch = new QPushButton(verticalLayoutWidget_6);
        btnReaderSearch->setObjectName("btnReaderSearch");
        sizePolicy1.setHeightForWidth(btnReaderSearch->sizePolicy().hasHeightForWidth());
        btnReaderSearch->setSizePolicy(sizePolicy1);
        btnReaderSearch->setMinimumSize(QSize(0, 28));

        verticalLayout_3->addWidget(btnReaderSearch);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_10->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        btnClearReaders = new QPushButton(verticalLayoutWidget_6);
        btnClearReaders->setObjectName("btnClearReaders");
        sizePolicy1.setHeightForWidth(btnClearReaders->sizePolicy().hasHeightForWidth());
        btnClearReaders->setSizePolicy(sizePolicy1);
        btnClearReaders->setMinimumSize(QSize(0, 30));

        horizontalLayout_5->addWidget(btnClearReaders);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_10->addLayout(horizontalLayout_5);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_7->addItem(verticalSpacer_4);

        label_4 = new QLabel(verticalLayoutWidget_6);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        verticalLayout_7->addWidget(label_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        twEntries = new QTableWidget(verticalLayoutWidget_6);
        twEntries->setObjectName("twEntries");
        twEntries->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

        verticalLayout_8->addWidget(twEntries);


        horizontalLayout_3->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        btnEntryCheckOut = new QPushButton(verticalLayoutWidget_6);
        btnEntryCheckOut->setObjectName("btnEntryCheckOut");
        sizePolicy1.setHeightForWidth(btnEntryCheckOut->sizePolicy().hasHeightForWidth());
        btnEntryCheckOut->setSizePolicy(sizePolicy1);
        btnEntryCheckOut->setMinimumSize(QSize(0, 28));

        verticalLayout_9->addWidget(btnEntryCheckOut);

        btnEntryCheckIn = new QPushButton(verticalLayoutWidget_6);
        btnEntryCheckIn->setObjectName("btnEntryCheckIn");
        sizePolicy1.setHeightForWidth(btnEntryCheckIn->sizePolicy().hasHeightForWidth());
        btnEntryCheckIn->setSizePolicy(sizePolicy1);
        btnEntryCheckIn->setMinimumSize(QSize(0, 28));

        verticalLayout_9->addWidget(btnEntryCheckIn);

        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_9->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_9);


        verticalLayout_7->addLayout(horizontalLayout_3);


        verticalLayout_10->addLayout(verticalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        btnClearEntries = new QPushButton(verticalLayoutWidget_6);
        btnClearEntries->setObjectName("btnClearEntries");
        btnClearEntries->setMinimumSize(QSize(0, 30));

        horizontalLayout_6->addWidget(btnClearEntries);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout_10->addLayout(horizontalLayout_6);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 820, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(btnBookAdd, btnBookRemove);
        QWidget::setTabOrder(btnBookRemove, btnBookSearch);
        QWidget::setTabOrder(btnBookSearch, btnClearBooks);
        QWidget::setTabOrder(btnClearBooks, btnReaderAdd);
        QWidget::setTabOrder(btnReaderAdd, btnReaderRemove);
        QWidget::setTabOrder(btnReaderRemove, btnReaderSearch);
        QWidget::setTabOrder(btnReaderSearch, btnClearReaders);
        QWidget::setTabOrder(btnClearReaders, btnEntryCheckOut);
        QWidget::setTabOrder(btnEntryCheckOut, btnEntryCheckIn);
        QWidget::setTabOrder(btnEntryCheckIn, twBooks);
        QWidget::setTabOrder(twBooks, twReaders);
        QWidget::setTabOrder(twReaders, btnClearEntries);
        QWidget::setTabOrder(btnClearEntries, twEntries);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\261\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\276\320\271", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\232\320\275\320\270\320\263\320\270", nullptr));
        btnBookAdd->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        btnBookRemove->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        btnBookSearch->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        btnClearBooks->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\247\320\270\321\202\320\260\321\202\320\265\320\273\320\270", nullptr));
        btnReaderAdd->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        btnReaderRemove->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        btnReaderSearch->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        btnClearReaders->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\264\320\260\321\207\320\260/\320\277\321\200\320\270\320\265\320\274 \320\272\320\275\320\270\320\263", nullptr));
        btnEntryCheckOut->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\264\320\260\321\202\321\214", nullptr));
        btnEntryCheckIn->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", nullptr));
        btnClearEntries->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
