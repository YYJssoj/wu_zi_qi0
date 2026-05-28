#ifndef ZHU_CE_H
#define ZHU_CE_H

#include <QWidget>
#include<QAbstractButton>
#include<set_question.h>


namespace Ui {
class zhu_ce;
}

class zhu_ce : public QWidget
{
    Q_OBJECT

public:
    explicit zhu_ce(QWidget *parent = nullptr);
    ~zhu_ce();

private slots:

    void on_reveal_policy_button_clicked();

    void on_confirm_login_button_clicked();

    void on_return_button_clicked();

private:
    Ui::zhu_ce *ui;
};

#endif // ZHU_CE_H
