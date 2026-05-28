#ifndef SET_QUESTION_H
#define SET_QUESTION_H

#include <QWidget>
#include<QByteArray>
#include<mainw.h>
#include<QMessageBox>
#include"demo1.h"

namespace Ui {
class set_question;
}

class set_question : public QWidget
{
    Q_OBJECT

public:
    explicit set_question(key k1,QWidget *parent = nullptr);
    ~set_question();

private slots:
    void on_confirm_answer_button_clicked();

private:
    Ui::set_question *ui;
    key k;
};

#endif // SET_QUESTION_H
