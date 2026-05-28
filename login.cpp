#include "login.h"
#include "ui_login.h"
#include"demo1.h"
#include"global.h"
#include"mainw.h"

QString current_account;

login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
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

login::~login()
{
    delete ui;
}

//注册按钮
void login::on_login_button_clicked()
{
    ui->account_edit->clear();
    ui->pw_edit->clear();
    zhu_ce * z=new zhu_ce;
    z->show();
    this->hide();
}

//登录按钮
void login::on_check_in_button_clicked()
{
    QString account=ui->account_edit->text();
    const char * ac=qPrintable(account);
    QString password=ui->pw_edit->text();
    const char * pw=qPrintable(password);
    //账号、密码校验
    if(judgeac(ac)==false)
    {
        QMessageBox::information(this,"账号错误","账号不符合格式（长度需8-20位且无空格、Tab键）");
        ui->account_edit->clear();
        return ;
    }
    if(judgepw(pw)==false)
    {
        QMessageBox::information(this,"密码错误","密码不符合格式（长度8-20位且必须包含字母，数字和特殊字符）");
        ui->pw_edit->clear();
        return ;
    }
    //文件操作
    int res1=judge_key(account,password);
    if(res1==0)
    {
        current_account=account;
        QMessageBox::information(this,"提示","登录成功");
        this->hide();
        Mainw * M=new Mainw;
        M->show();
    }
    else if(res1==1)
    {
        QMessageBox::critical(this,"错误","密码错误");
        ui->pw_edit->clear();
        ui->account_edit->clear();
        return;
    }
    else
    {
        QMessageBox::critical(this,"错误","账号不存在，请先注册");
        ui->account_edit->clear();
        ui->pw_edit->clear();
        return;
    }
}


void login::on_forget_pw_button_clicked()
{

    forget_pw * f=new forget_pw;
    f->show();
}


void login::on_visitor_button_clicked()
{
    current_account="com";
    Mainw *m =new Mainw;
    m->show();
    this->close();
}

