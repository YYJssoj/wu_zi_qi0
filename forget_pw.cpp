#include "forget_pw.h"
#include "ui_forget_pw.h"
#include"demo1.h"
#include<QString>
#include<QByteArray>
#include<QMessageBox>
#include"set_pw.h"

forget_pw::forget_pw(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::forget_pw)
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

forget_pw::~forget_pw()
{
    delete ui;
}


void forget_pw::on_confirm_answer_button_clicked()
{
    QString account = ui->account_line_edit->text();
    QString userAnswer = ui->answer_edit->text();
    if(account.isEmpty())
    {
        QMessageBox::critical(this,"错误","账号不能为空！");
        return;
    }
    if(judgeac(account.toLocal8Bit().constData()) == false)
    {
        QMessageBox::critical(this,"错误","账号不符合格式（8-20位无空格）");
        ui->account_line_edit->clear();
        return;
    }
    if(find_ac_answer(account) == false)
    {
        QMessageBox::critical(this,"错误","账号不存在");
        ui->account_line_edit->clear();
        return;
    }
    QString question = find_question_answer(account);
    ui->question_edit->setText(question);
    QString realAnswer = find_answer_answer(account);
    if(userAnswer!= realAnswer)
    {
        QMessageBox::critical(this,"错误","答案错误！");
        ui->answer_edit->clear();
        return;
    }
    QMessageBox::information(this,"提示","回答正确");
    set_pw *s = new set_pw(nullptr,account);
    s->show();
    this->close();
}

void forget_pw::on_confirm_account_button_clicked()
{
    QString process=ui->account_line_edit->text();
    QByteArray data = process.toUtf8();
    const char* ac=data.constData();
    if(judgeac(ac)==false)
    {
        QMessageBox::critical(this,"错误","账号不符合格式（长度需8-20位且无空格、Tab键）");
        ui->account_line_edit->clear();
        return;
    }
    if(find_ac_answer(process)==false)
    {
        QMessageBox::critical(this,"错误","账号不存在");
        ui->account_line_edit->clear();
        return ;
    }
    QString process1=find_question_answer(process);
    ui->question_edit->setText(process1);
}

