#ifndef REMOVEBOOKDIALOG_H
#define REMOVEBOOKDIALOG_H

#include <QDialog>

namespace Ui {
class removebookdialog;
}

class removebookdialog : public QDialog
{
    Q_OBJECT

public:
    explicit removebookdialog(QWidget *parent = nullptr);
    ~removebookdialog();

    std::string getCipher() const;

private:
    Ui::removebookdialog *ui;
};

#endif // REMOVEBOOKDIALOG_H
