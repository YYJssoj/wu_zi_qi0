#include "zhu_ce.h"
#include "ui_zhu_ce.h"
#include<login.h>
#include<QAbstractButton>
#include"demo1.h"
#include"global.h"
#include"set_question.h"

zhu_ce::zhu_ce(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::zhu_ce)
{
    ui->setupUi(this);
    setAutoFillBackground(true);
    this->setFixedSize(800, 600);

    QPixmap bgPix(":/new/prefix1/2.png");
    bgPix = bgPix.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, bgPix);
    this->setPalette(palette);
}

zhu_ce::~zhu_ce()
{
    delete ui;
}



void zhu_ce::on_reveal_policy_button_clicked()
{
    QMessageBox::information(this,"隐私协议","...");
}


void zhu_ce::on_confirm_login_button_clicked()
{
    QString myprocess1=ui->ac_line_edit_2->text();
    QString myprocess2=ui->pw_line_edit->text();
    QString myprocess3=ui->confirm_pw_line_edit->text();
    const char * ac=qPrintable(myprocess1);
    const char * pw=qPrintable(myprocess2);
    const char * pw_=qPrintable(myprocess3);
    if(!judgeac(ac))
    {
        QMessageBox::information(this,"账号错误","账号不符合格式（长度需8-20位且无空格、Tab键）");
        ui->ac_line_edit_2->clear();
        return ;
    }
    if(!judgepw(pw))
    {
        QMessageBox::information(this,"密码错误","密码不符合格式（长度8-20位且必须包含字母，数字和特殊字符");
        ui->pw_line_edit->clear();
        return ;
    }
    if(!issame(pw,pw_))
    {
        QMessageBox::information(this,"密码不一致","两次输入的密码不一致，请重新输入");
        ui->pw_line_edit->clear();
        ui->confirm_pw_line_edit->clear();
        return ;
    }
    if(!ui->agree_policy_button->isChecked())
    {
        QMessageBox::information(this,"提醒","请勾选“我已同意用户协议”");
        return;
    }
    //文件比对+追加操作（待补全）
    if(find_ac_key(myprocess1))
    {
        QMessageBox::information(this,"提示","账号已存在");
        return ;
    }
    current_account=myprocess1;
    char rand1[50]={0},cipher1[50]={0};
    tran1(pw,rand1,cipher1);
    key k;
    QString rand=QString(rand1);
    QString cipher=QString(cipher1);
    k.account=myprocess1;
    k.cipher=cipher;
    k.random_key=rand;

    //设置自定义问题（忘记密码时用）
    set_question * s=new set_question(k,nullptr);
    s->show();
    this->hide();



}


void zhu_ce::on_return_button_clicked()
{
    this->close();
    login * l=new login;
    l->show();
}

