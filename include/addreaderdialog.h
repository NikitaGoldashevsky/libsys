#ifndef ADDREADERDIALOG_H
#define ADDREADERDIALOG_H

#include <QDialog>

namespace Ui {
class AddReaderDialog;
}

class AddReaderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddReaderDialog(QWidget *parent = nullptr);
    ~AddReaderDialog();

    std::string getCard() const;
    std::string getFIO() const;
    int getBirthYear() const;
    std::string getAddress() const;
    std::string getWorkplace() const;

private:
    Ui::AddReaderDialog *ui;
};

#endif // ADDREADERDIALOG_H
