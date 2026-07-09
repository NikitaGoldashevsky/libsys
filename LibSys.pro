QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += include
DEPENDPATH += include src

SOURCES += \
    src/BooksT.cpp \
    src/EntriesL.cpp \
    src/FineDialog.cpp \
    src/FinesL.cpp \
    src/LibrariansHT.cpp \
    src/PublishersHT.cpp \
    src/ReadersHT.cpp \
    src/addbookdialog.cpp \
    src/addentrydialog.cpp \
    src/addreaderdialog.cpp \
    src/closeentrydialog.cpp \
    src/dialogfactory.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/removebookdialog.cpp \
    src/removereaderdialog.cpp \
    src/searchbookdialog.cpp \
    src/searchreaderdialog.cpp

HEADERS += \
    include/BooksT.h \
    include/EntriesL.h \
    include/EntryObserver.h \
    include/Fine.h \
    include/FineDecorator.h \
    include/FineDialog.h \
    include/FinesL.h \
    include/IEntryComponent.h \
    include/Librarian.h \
    include/LibrariansHT.h \
    include/MainWindowObserver.h \
    include/Publisher.h \
    include/PublisherBuilder.h \
    include/PublishersHT.h \
    include/ReadersHT.h \
    include/TestsAll.h \
    include/TestsHashTable.h \
    include/TestsList.h \
    include/TestsTree.h \
    include/addbookdialog.h \
    include/addentrydialog.h \
    include/addreaderdialog.h \
    include/closeentrydialog.h \
    include/dialogfactory.h \
    include/mainwindow.h \
    include/removebookdialog.h \
    include/removereaderdialog.h \
    include/searchbookdialog.h \
    include/searchreaderdialog.h

FORMS += \
    forms/FineDialog.ui \
    forms/addbookdialog.ui \
    forms/addentrydialog.ui \
    forms/addreaderdialog.ui \
    forms/closeentrydialog.ui \
    forms/mainwindow.ui \
    forms/removebookdialog.ui \
    forms/removereaderdialog.ui \
    forms/searchbookdialog.ui \
    forms/searchreaderdialog.ui
