#ifndef SET_PW_H
#define SET_PW_H

#include <QWidget>
#include"demo1.h"

namespace Ui {
class set_pw;
}

class set_pw : public QWidget
{
    Q_OBJECT

public:
    explicit set_pw(QWidget *parent = nullptr,QString account=" ");
    ~set_pw();

private slots:
    void on_confirm_button_clicked();

private:
    Ui::set_pw *ui;
    QString account;
};

#endif // SET_PW_H

