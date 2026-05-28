#ifndef RECORD_H
#define RECORD_H

#include <QWidget>
#include"demo.h"

namespace Ui {
class record;
}

class record : public QWidget
{
    Q_OBJECT

public:
    explicit record(QList<Record> result,QWidget *parent = nullptr);
    ~record();

private slots:
    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::record *ui;
    QList<Record> result;
};

#endif // RECORD_H
