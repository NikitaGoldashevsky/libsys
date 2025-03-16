#ifndef ADDBOOKDIALOG_H
#define ADDBOOKDIALOG_H

#include <QDialog>
#include <string>

namespace Ui {
class AddBookDialog;
}

class AddBookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddBookDialog(QWidget *parent = nullptr);
    ~AddBookDialog();

    std::string getName() const;
    std::string getAuthors() const;
    std::string getCipher() const;
    std::string getPublisher() const;
    int getPublicationYear() const;
    int getCopiesAll() const;
    int getCopiesStock() const;
private:
    Ui::AddBookDialog *ui;
};

#endif // ADDBOOKDIALOG_H
