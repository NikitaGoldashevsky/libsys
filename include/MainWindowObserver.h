#include "EntryObserver.h"

class MainWindowObserver : public EntryObserver {
public:
    MainWindowObserver(MainWindow* mainWindow) : mainWindow(mainWindow) {}

    void update() override {
        mainWindow->updateTableViews();
    }

private:
    MainWindow* mainWindow;
};
