#ifndef MAINW_H
#define MAINW_H

#include <QWidget>
#include"wuziqi2/setting.h"
#include"renji/record_2.h"
#include"renren/record.h"
#include"c1/win1.h"
namespace Ui {
class Mainw;
}

class Mainw : public QWidget
{
    Q_OBJECT

public:
    explicit Mainw(QWidget *parent = nullptr);
    ~Mainw();

private slots:
    void on_ShuangRenButton_clicked();



    void on_renji_clicked();



    void on_renren_clicked();

    void on_RenJiButton_clicked();

private:
    Ui::Mainw *ui;setting *s;win1 *w;
};

#endif // MAINW_H
