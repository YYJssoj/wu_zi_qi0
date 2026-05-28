#include "mainw.h"
#include "ui_mainw.h"
#include"wuziqi2/setting.h"
#include"QScreen"
#include"global.h"
#include"c1/mainai.h"
#include"c1/win1.h"
#include"QDebug"
Mainw::Mainw(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Mainw),s(nullptr)
{
    ui->setupUi(this);
    this->setFixedSize(521, 522);
    if(current_account=="com")
    {
        ui->renren->hide();
        ui->renji->hide();
    }
    setAutoFillBackground(true);

    QPixmap bgPix(":/new/prefix1/2.png");
    bgPix = bgPix.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, bgPix);
    this->setPalette(palette);

    this->setWindowTitle("主界面");
}

Mainw::~Mainw()
{
    delete ui;
}

void Mainw::on_ShuangRenButton_clicked()
{
s = new setting(this);
    s->setWindowModality(Qt::NonModal); // 或 Qt::ApplicationModal
    s->show();
}





void Mainw::on_renji_clicked()
{
      QString process=current_account;
    QList<Record_2> p1=read_record();
    QList<Record_2> result;
    for(int i=0;i<p1.size();i++)
    {
        if(p1[i].account_person==process)
        {
            result.append(p1[i]);
        }
    }
    record_2 *r=new record_2(result,nullptr);
    r->show();

}


void Mainw::on_renren_clicked()
{
    QString process=current_account;
    qDebug()<<current_account;
    QList<Record> p1=read_record_1();
    QList<Record> result;
    for(int i=0;i<p1.size();i++)
    {
        if(p1[i].account1==process||p1[i].account2==process)
        {
            result.append(p1[i]);
        }
    }
    record *r=new record(result,nullptr);
    r->show();

}


void Mainw::on_RenJiButton_clicked()
{
    mainai();
    w=new win1;
     w->setWindowModality(Qt::NonModal);
    w->resize(670,670);
    w->show();
}

