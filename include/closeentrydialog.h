#ifndef CLOSEENTRYDIALOG_H
#define CLOSEENTRYDIALOG_H

#include <QDialog>

namespace Ui {
class CloseEntryDialog;
}

class CloseEntryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CloseEntryDialog(QWidget *parent = nullptr);
    ~CloseEntryDialog();

    std::string getCard() const;
    std::string getCipher() const;
    std::string getCheckInDate() const;
private:
    Ui::CloseEntryDialog *ui;
};

#endif // CLOSEENTRYDIALOG_H
