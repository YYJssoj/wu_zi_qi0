#include "shuru.h"
#include "ui_shuru.h"
#include "login.h"
#include"demo1.h"
#include"global.h"
#include"mainw.h"
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>

shuru::shuru(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::shuru),acc1("\n"),acc2("\n")
{
    ui->setupUi(this);
    this->setFixedSize(400, 300);
}

shuru::~shuru()
{
    delete ui;
}

void shuru::on_qd1_clicked()
{
    QString ac1=ui->player1ac->text();
    const char * ac=qPrintable(ac1);
    QString pw1=ui->player1mm->text();
    const char * pw=qPrintable(pw1);
    //账号、密码校验
    if(judgeac(ac)==false)
    {
        QMessageBox::information(this,"账号错误","账号不符合格式（长度需8-20位且无空格、Tab键）");
        ui->player1ac->clear();
        return ;
    }
    if(judgepw(pw)==false)
    {
        QMessageBox::information(this,"密码错误","密码不符合格式（长度8-20位且必须包含字母，数字和特殊字符）");
        ui->player1mm->clear();
        return ;
    }
    //文件操作
    int res1=judge_key(ac1,pw1);
    if(res1==0)
    {
       // current_account=ac1;
        QMessageBox::information(this,"提示","成功确定");
        ui->player1ac->setEnabled(false);
        ui->player1mm->setEnabled(false);
        acc1=ac1;

    }
    else if(res1==1)
    {
        QMessageBox::critical(this,"错误","密码错误");
        ui->player1mm->clear();
        ui->player1ac->clear();
        return;
    }
    else
    {
        QMessageBox::critical(this,"错误","账号不存在，请先注册");
        ui->player1mm->clear();
        ui->player1ac->clear();
        return;
    }

}



void shuru::on_qd2_clicked()
{
    QString ac2=ui->player2ac->text();
    const char * ac=qPrintable(ac2);
    QString pw2=ui->player2mm->text();
    const char * pw=qPrintable(pw2);
    //账号、密码校验
    if(judgeac(ac)==false)
    {
        QMessageBox::information(this,"账号错误","账号不符合格式（长度需8-20位且无空格、Tab键）");
        ui->player2ac->clear();
        return ;
    }
    if(judgepw(pw)==false)
    {
        QMessageBox::information(this,"密码错误","密码不符合格式（长度8-20位且必须包含字母，数字和特殊字符）");
        ui->player2mm->clear();
        return ;
    }
    //文件操作
    int res1=judge_key(ac2,pw2);
    if(res1==0)
    {
      //  current_account=ac2;
        QMessageBox::information(this,"提示","成功确定");
        ui->player2ac->setEnabled(false);
        ui->player2mm->setEnabled(false);
        acc2=ac2;

    }
    else if(res1==1)
    {
        QMessageBox::critical(this,"错误","密码错误");
        ui->player2mm->clear();
        ui->player2ac->clear();
        return;
    }
    else
    {
        QMessageBox::critical(this,"错误","账号不存在，请先注册");
        ui->player2mm->clear();
        ui->player2ac->clear();
        return;
    }
}


void shuru::on_pushButton_clicked()
{
    if(acc1=="\n"){        QMessageBox::critical(this,"错误","未确定玩家1");return;
}
    if(acc2=="\n"){        QMessageBox::critical(this,"错误","未确定玩家2");return;
}
    qint64 timestamp_ms = QDateTime::currentMSecsSinceEpoch();

    QString timestampStr = QString::number(timestamp_ms, 10);

    QString filePath =  qApp->applicationDirPath() + "/record.csv";

    QFile file(filePath);

    // 2. 以只写和文本模式打开文件
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        QString rc=acc1;rc+="\t";
        rc+=acc2;rc+="\t";
        rc+=timestampStr;rc+="\t";
        if(r==he){rc+="0\t";}
        if(r==black){rc+="1\t";}
        if(r==white){rc+="2\t";}
        rc+=acc1+"_"+timestampStr+".csv";
        out<<rc<<"\n";

        file.close();
        qDebug() << "CSV 文件写入成功！";
    }
    else {
        qDebug() << "文件打开失败！";
    }

    QString path=qApp->applicationDirPath()+"/"+ acc1+"_"+timestampStr+".csv";
    QFile file2(path);
     if (file2.open(QIODevice::WriteOnly | QIODevice::Text))
    { QTextStream out2(&file2);
        for(int i = 0; i <history.size(); ++i   ){
             out2<<QString::number(history[i].r)<<"\t"<<QString::number(history[i].c)<<"\n";

        }
     }
        else {
            qDebug() << "文件创建/打开失败！";
        }

     this->close();
}

