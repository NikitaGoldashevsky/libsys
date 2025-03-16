#ifndef REMOVEREADERDIALOG_H
#define REMOVEREADERDIALOG_H

#include <QDialog>

namespace Ui {
class RemoveReaderDialog;
}

class RemoveReaderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveReaderDialog(QWidget *parent = nullptr);
    ~RemoveReaderDialog();
    std::string getCard() const;

private:
    Ui::RemoveReaderDialog *ui;
};

#endif // REMOVEREADERDIALOG_H
