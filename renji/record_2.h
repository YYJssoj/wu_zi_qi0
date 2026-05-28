#ifndef RECORD_2_H
#define RECORD_2_H

#include <QWidget>
#include"demo.h"

namespace Ui {
class record_2;
}

class record_2 : public QWidget
{
    Q_OBJECT

public:
    explicit record_2(QList<Record_2> result,QWidget *parent = nullptr);
    ~record_2();

private slots:
    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::record_2 *ui;
    QList<Record_2> result;
};

#endif // RECORD_2_H
