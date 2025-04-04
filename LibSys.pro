QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BooksT.cpp \
    EntriesL.cpp \
    ReadersHT.cpp \
    addbookdialog.cpp \
    addentrydialog.cpp \
    addreaderdialog.cpp \
    closeentrydialog.cpp \
    dialogfactory.cpp \
    main.cpp \
    mainwindow.cpp \
    removebookdialog.cpp \
    removereaderdialog.cpp \
    searchbookdialog.cpp \
    searchreaderdialog.cpp

HEADERS += \
    BooksT.h \
    EntriesL.h \
    ReadersHT.h \
    TestsAll.h \
    TestsHashTable.h \
    TestsList.h \
    TestsTree.h \
    addbookdialog.h \
    addentrydialog.h \
    addreaderdialog.h \
    closeentrydialog.h \
    dialogfactory.h \
    mainwindow.h \
    removebookdialog.h \
    removereaderdialog.h \
    searchbookdialog.h \
    searchreaderdialog.h

FORMS += \
    addbookdialog.ui \
    addentrydialog.ui \
    addreaderdialog.ui \
    closeentrydialog.ui \
    mainwindow.ui \
    removebookdialog.ui \
    removereaderdialog.ui \
    searchbookdialog.ui \
    searchreaderdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
