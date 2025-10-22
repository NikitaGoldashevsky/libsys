#ifndef FINEDIALOG_H
#define FINEDIALOG_H

#include <QDialog>

namespace Ui {
class FineDialog;
}

class FineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FineDialog(QWidget *parent = nullptr);
    ~FineDialog();

    QString getId() const;
    QString getCard() const;
    QString getCipher() const;
    QString getReason() const;
    double getAmount() const;

private:
    Ui::FineDialog *ui;
};

#endif // FINEDIALOG_H
