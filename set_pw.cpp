#include "set_pw.h"
#include<QMessageBox>
#include "ui_set_pw.h"
#include"login.h"
#include"demo1.h"


set_pw::set_pw(QWidget *parent,QString account)
    : QWidget(parent)
    , ui(new Ui::set_pw)
{
    ui->setupUi(this);
    this->account=account;
    setAutoFillBackground(true);
    this->setFixedSize(800, 600);

    QPixmap bgPix(":/new/prefix1/2.png");
    bgPix = bgPix.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, bgPix);
    this->setPalette(palette);
}


set_pw::~set_pw()
{
    delete ui;
}

void set_pw::on_confirm_button_clicked()
{
    QString acc=account;
    QString myprocess1=ui->new_pw_edit->text();
    QString myprocess2=ui->new_pw_confirm_edit->text();
    const char* Npw=myprocess1.toLocal8Bit().constData();
    const char* Npw_=myprocess2.toLocal8Bit().constData();
    if(!judgepw(Npw))
    {
        QMessageBox::critical(this,"密码错误","密码不符合格式（长度8-20位且必须包含字母，数字和特殊字符）");
        ui->new_pw_edit->clear();
        ui->new_pw_confirm_edit->clear();
        return ;
    }
    if(!issame(Npw,Npw_))
    {
        QMessageBox::critical(this,"提示","两次输入的密码不一致");
        ui->new_pw_confirm_edit->clear();
        ui->new_pw_edit->clear();
        return ;
    }
    QString str=pw_key(acc);
    if(issame(Npw,str.toLocal8Bit().constData()))
    {
        QMessageBox::critical(this,"错误","新密码与原密码一致，无需修改");
        ui->new_pw_confirm_edit->clear();
        ui->new_pw_edit->clear();
        return;
    }
    int res=QMessageBox::question(this,"提示","确认修改？",QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if(res==QMessageBox::No)
    {
        return;
    }
    change_pw_key(acc,myprocess1);
    QMessageBox::information(this,"提示","密码修改成功!");
    login *l=new login;
    l->show();
    this->close();
}

