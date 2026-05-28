#ifndef FORGET_PW_H
#define FORGET_PW_H

#include <QWidget>
#include<set_pw.h>
#include<QMessageBox>

namespace Ui {
class forget_pw;
}

class forget_pw : public QWidget
{
    Q_OBJECT

public:
    explicit forget_pw(QWidget *parent = nullptr);
    ~forget_pw();

private slots:
    void on_confirm_answer_button_clicked();

    void on_confirm_account_button_clicked();

private:
    Ui::forget_pw *ui;
};

#endif // FORGET_PW_H
