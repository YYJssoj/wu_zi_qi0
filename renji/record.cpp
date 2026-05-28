#include "record.h"
#include "ui_record.h"
#include"demo.h"
#include"chessboard.h"
#include<QDebug>

record::record(QList<Record> result,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::record)
{
    ui->setupUi(this);
    this->result=result;
    ui->tableWidget->setRowCount(result.size());
    this->setFixedSize(721, 531);
    for(int i=0; i<result.size(); i++)
    {
        Record data = result[i];
        QString begintime=timestamp_timestring(data.begin_time);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(data.account1));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(data.account2));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(begintime));
        QString strResult;
        if (data.result == 0)
        {
            strResult = "和棋";
        }
        else if(data.result==1)
        {
            strResult = "玩家1胜利";
        }
        else
        {
            strResult="玩家2胜利";
        }
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(strResult));
        QTableWidgetItem *item = new QTableWidgetItem(data.filename);
        item->setForeground(Qt::blue);
        QFont font=item->font();
        font.setUnderline(true);
        item->setFont(font);
        ui->tableWidget->setItem(i, 4, item);
    }
}



record::~record()
{
    delete ui;
}

void record::on_tableWidget_cellClicked(int row, int column)
{
    if(column!=4)
    {
        return;
    }
    QString filename=ui->tableWidget->item(row,4)->text();
    chessboard *c=new chessboard(nullptr,filename);
    qDebug()<<filename;
    c->show();
    c->loadFromFile(filename);
}

