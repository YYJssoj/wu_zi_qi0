#include "setting.h"
#include "ui_setting.h"
#include"mainwindow.h"
setting::setting(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::setting)
{
     this->setWindowFlags(Qt::Window); setWindowTitle("设置对局时间");

    ui->setupUi(this);
    this->setFixedSize(400, 300);
    connect(ui->l0,&QRadioButton::clicked,this,&setting::sett2);
    connect(ui->l1,&QRadioButton::clicked,this,&setting::sett2);
    connect(ui->l2,&QRadioButton::clicked,this,&setting::sett2);
    connect(ui->l3,&QRadioButton::clicked,this,&setting::sett2);
    connect(ui->t0,&QRadioButton::clicked,this,&setting::sett1);
    connect(ui->t1,&QRadioButton::clicked,this,&setting::sett1);
    connect(ui->t2,&QRadioButton::clicked,this,&setting::sett1);
    connect(ui->t3,&QRadioButton::clicked,this,&setting::sett1);

}

setting::~setting()
{
    delete ui;
}
void setting::sett1(){
    if(ui->t1->isChecked()){
        total=5;
    }else     if(ui->t2->isChecked()){
        total=10;
    }else     if(ui->t3->isChecked()){
        total=15;
    }else     if(ui->t0->isChecked()){
        total=-1;
    }

}
void setting::sett2(){
    if(ui->l1->isChecked()){
        every=20;
    }else     if(ui->l2->isChecked()){
        every=40;
    }else     if(ui->l3->isChecked()){
        every=60;
    }else     if(ui->l0->isChecked()){
        every=-1;
    }

}
void setting::on_pushButton_clicked(bool checked)
{
    if(every==0||total==0){return ;}
    MainWindow *mainWin = new MainWindow(total,every,nullptr);

    // 3. 设置主界面退出时自动释放内存（防止内存泄漏）
    mainWin->setAttribute(Qt::WA_DeleteOnClose);

    // 4. 显示主界面
    mainWin->show();

    // 5. 安全地关闭并销毁当前的登录界面
    // 此时登录界面销毁，由于主界面不是它的子对象，所以主界面会安然无恙。
    this->close();
}

