#ifndef ADDENTRYDIALOG_H
#define ADDENTRYDIALOG_H

#include <QDialog>

namespace Ui {
class AddEntryDialog;
}

class AddEntryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEntryDialog(QWidget *parent = nullptr);
    ~AddEntryDialog();

    std::string getCard() const;
    std::string getCipher() const;
    std::string getCheckInDate() const;
    std::string getCheckOutDate() const;
private:
    Ui::AddEntryDialog *ui;
};

#endif // ADDENTRYDIALOG_H
