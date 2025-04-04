#include "mainwindow.h"

#include <QApplication>

#include "ReadersHT.h"
#include "BooksT.h"

#include "TestsHashTable.h"
#include "TestsTree.h"
#include "TestsList.h"
#include "TestsAll.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //testTree();
    //testList();
    testHashTable();

    return a.exec();
}
