#ifndef SHURU_H
#define SHURU_H
#include"stdshared.h"
#include <QWidget>

namespace Ui {
class shuru;
}

class shuru : public QWidget
{
    Q_OBJECT

public:    result r;
    std::vector<movehistory> history;
    explicit shuru(QWidget *parent = nullptr);
    ~shuru();

private slots:
    void on_qd1_clicked();

    void on_qd2_clicked();

    void on_pushButton_clicked();

private:

    Ui::shuru *ui;
    QString acc1,acc2;
};

#endif // SHURU_H
