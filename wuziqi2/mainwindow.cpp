#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QVBoxLayout>
#include <QHBoxLayout>
#include<QLabel>
#include<QTimer>
#include"chessboard.h"
#include"qiuhechos.h"
#include<QDebug>
MainWindow::MainWindow(int total,int every,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),tot(total),eve(every),playertimer(this),labeltime(nullptr),  everytime(this), q(nullptr),choice(nullptr)
{playertime1=total*60;playertime2=total*60;evestep=eve;   // choice=new choose(this);
    ui->setupUi(this);

    setWindowTitle("五子棋");
    qipan=new chessboard(this);
     qipan->setFixedSize(700, 700);

     this->setFixedSize(850,800);
    QWidget *mainWidget = ui->centralwidget;
    QHBoxLayout *mainLayout = new QHBoxLayout(mainWidget);

    // 把棋盘和按钮加入布局

    mainLayout->addWidget(qipan);

    QVBoxLayout *btnLayout = new QVBoxLayout;
    labeltime = new QLabel("等待开始...", this);

    btnLayout->addWidget(labeltime);
    btnLayout->addWidget(ui->renshu);
    btnLayout->addWidget(ui->huiqi);
btnLayout->addWidget(ui->qiuhe);

btnLayout->addWidget(ui->pause);

// 把按钮的布局加入到主布局中

    mainLayout->addLayout(btnLayout);

    mainWidget->setLayout(mainLayout);



   statusLabel = new QLabel("当前玩家：黑棋", this);
    statusLabel->setMinimumWidth(500);

   connect(qipan,&chessboard::end,this,&MainWindow::ge);
   connect(this,&MainWindow::endding,choice,&choose::get);

connect(&everytime, &QTimer::timeout, this, &MainWindow::onStepTick);
    connect(&playertimer, &QTimer::timeout, this, &MainWindow::onTotalTimeTick);

    // 将标签添加到状态栏
    ui->statusbar->addWidget(statusLabel);
connect(qipan, &chessboard::piecePlaced, this, &MainWindow::switchTurn);
    connect(qipan, &chessboard::currentPlayerChanged,
            statusLabel, &QLabel::setText);
connect(qipan,&chessboard::ss,this,&MainWindow::ssr);

    //悔棋
    connect(ui->huiqi, &QPushButton::clicked, [this]() {

        qipan->undomove();
    });
    //暂停
    connect(ui->pause, &QPushButton::clicked, this,&MainWindow::on_pause_clicked);

everytime.start(1000);
    playertimer.start(1000);
    updateTimeDisplay();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}
void MainWindow::updateTimeDisplay() {

    QString string="黑方剩余时长：";
    int minutes = playertime1/ 60;
    int seconds =playertime1 % 60;

string+=std::to_string(minutes) + "分" + std::to_string(seconds) + "秒\n";
    string+="白方剩余时长：";
minutes = playertime2/ 60;
seconds =playertime2 % 60;

string+=std::to_string(minutes) + "分" + std::to_string(seconds) + "秒\n";

if(tot<0){string="黑方剩余时间：无穷\n白方剩余时间：无穷\n";}
string+="该子剩余时间：";
if(eve<0){string+="无穷";}
else{
string+=std::to_string(evestep) + "秒\n";
}
    labeltime->setText(string);
}

void MainWindow::onStepTick() {
    if(eve<0)return;
    evestep--;
    updateTimeDisplay();
    if (evestep<= 0) {
        onStepTimeout();
    }
}
void MainWindow::onStepTimeout() {
    if(eve<0)return;
    everytime.stop();
    playertimer.stop();
    if(qipan->present==player1)
    {qipan->r=black;
        choice=new choose(this);qipan->close();everytime.stop();playertimer.stop();
        connect(this,&MainWindow::endding,choice,&choose::get);emit endding(black,qipan->history);ssr();
    }
    else{qipan->r=white;        choice=new choose(this);qipan->close();everytime.stop();playertimer.stop();
        connect(this,&MainWindow::endding,choice,&choose::get);emit endding(white,qipan->history);ssr();}



}
void MainWindow::onTotalTimeTick() {
    if(tot<0)return;
    if (qipan->present==player1) {
        playertime1--;
        if (playertime1 <= 0) {
        everytime.stop(); playertimer.stop();
        qipan->r=white;        choice=new choose(this);qipan->close();everytime.stop();playertimer.stop();
        connect(this,&MainWindow::endding,choice,&choose::get);emit endding(white,qipan->history);ssr();
        }
    } else {
        playertime2--;
        if (playertime2<= 0) {
            everytime.stop(); playertimer.stop();
            qipan->r=black;        choice=new choose(this);qipan->close();everytime.stop();playertimer.stop();
            connect(this,&MainWindow::endding,choice,&choose::get);emit endding(black,qipan->history);ssr();
        }
    }
    updateTimeDisplay();


}

void MainWindow::switchTurn(){
evestep=eve;
    if(qipan->r==black)return;
    if(qipan->r==white)return;
    everytime.start(1000);

    updateTimeDisplay();
}

void MainWindow::on_renshu_clicked()
{
    if(qipan->present==player1){
        qipan->r=white;      qipan->close();   choice=new choose(this);everytime.stop();playertimer.stop();
        connect(this,&MainWindow::endding,choice,&choose::get);  emit endding(white,qipan->history);ssr();}

    else{
        qipan->r=black;       qipan->close();  choice=new choose(this);everytime.stop();playertimer.stop();
        connect(this,&MainWindow::endding,choice,&choose::get);emit endding(black,qipan->history);ssr();

    }

}


void MainWindow::on_qiuhe_clicked()
{

    q = new qiuhechos(this);
    connect(q, &qiuhechos::yes, this, &MainWindow::yesh);
    connect(q, &qiuhechos::no, this, &MainWindow::noh);
    connect(q, &qiuhechos::destroyed, [this](){ q = nullptr; });

    q->show(); // 显示窗口
}
void MainWindow::yesh(){
    qipan->r=he;//棋局和棋
    q->close();        choice=new choose(this);everytime.stop();playertimer.stop();
    connect(this,&MainWindow::endding,choice,&choose::get);qipan->close();emit endding(he,qipan->history);
    ssr();
    //新界面
}
void MainWindow::noh(){
    q->close();
}




void MainWindow::ssr(){

    everytime.stop();playertimer.stop();
       ui->renshu->setEnabled(false);
    ui->huiqi->setEnabled(false);
       ui->pause->setEnabled(false);
    ui->qiuhe->setEnabled(false);
}
void MainWindow::ge(result xx,std::vector<movehistory> h){

    choice=new choose(this);everytime.stop();playertimer.stop();
    connect(this,&MainWindow::endding,choice,&choose::get);qipan->close();emit endding(xx,h);
    ssr();
}




void MainWindow::on_pause_clicked()
{
    if (playertimer.isActive()) {
        qipan->pausesi=0;qDebug()<<"pausesi=0";
        playertimer.stop();
        everytime.stop();

        ui->pause->setText("继续");
    } else {
       qipan->pausesi=1;qDebug()<<"pausesi=1";
        playertimer.start(1000);

        if (evestep > 0) {
            everytime.start(1000);
        }

        ui->pause->setText("暂停");
    }
}

