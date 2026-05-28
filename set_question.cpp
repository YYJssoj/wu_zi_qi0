#include "set_question.h"
#include "ui_set_question.h"
#include"global.h"
#include"demo1.h"


set_question::set_question(key k1,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::set_question)
    ,k(k1)
{
    ui->setupUi(this);
    setAutoFillBackground(true);
    this->setFixedSize(773, 396);

    QPixmap bgPix(":/new/prefix1/2.png");
    bgPix = bgPix.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, bgPix);
    this->setPalette(palette);
}

set_question::~set_question()
{
    delete ui;
}

void set_question::on_confirm_answer_button_clicked()
{
    QString myprocess1=ui->question_edit->text();
    QString myprocess2=ui->answer_edit->text();
    const char * question=qPrintable(myprocess1);
    const char * Answer=qPrintable(myprocess2);
    int len1=(int)qstrlen(question);
    int len2=(int)qstrlen(Answer);
    if(len1==0||len2==0)
    {
        QMessageBox::information(this,"提示","请完整设置问题和答案！");
        return;
    }
    if(judge_question_answer(question)==false||judge_question_answer(Answer)==false)
    {
        QMessageBox::critical(this,"错误","请正确设置问题和答案");
        return;
    }
    QString c1=convert(myprocess1);
    QString c2=convert(myprocess2);
    //将读取的数据和问题存入answer.csv（账号、问题、答案）
    add_key(k);
    answer a;
    a.answers=myprocess2;
    a.question=myprocess1;
    a.account=current_account;
    qDebug()<<current_account;
    add_answer(a);

    //注册成功
    QMessageBox::information(this,"提示","注册成功");
    this->hide();
    Mainw * M=new Mainw;
    M->show();

}

