#include "record_2.h"
#include "ui_record_2.h"
#include"demo.h"
#include"chessboard2.h"

record_2::record_2(QList<Record_2> result,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::record_2)
{
    ui->setupUi(this);
    this->setFixedSize(1000, 600);
    this->result=result;
        ui->tableWidget->setRowCount(result.size());
        for(int i=0; i<result.size(); i++)
        {
            Record_2 data = result[i];
            QString begintime=timestamp_timestring(data.begin_time);
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(data.account_person));
            QString color;
            if(data.com_color==0)
            {
                color="白";
            }
            else
            {
                color="黑";
            }
            ui->tableWidget->setItem(i, 1, new QTableWidgetItem(color));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(begintime));
            QString strResult;
            if (data.result == 2)
            {
                strResult = "玩家胜利";
            }
            else if(data.result==1)
            {
                strResult = "电脑胜利";
            }
            else
            {
                strResult="平局";
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

record_2::~record_2()
{
    delete ui;
}

void record_2::on_tableWidget_cellClicked(int row, int column)
{
    if(column!=4)
    {
        return;
    }
    QString filename=ui->tableWidget->item(row,4)->text();
    QString filename1=ui->tableWidget->item(row,0)->text();
    QString filename2=filename1+filename;
    chessboard2 *c=new chessboard2(nullptr,filename2);
    c->show();
    c->loadFromFile(filename2);
}

