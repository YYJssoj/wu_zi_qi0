#include "widget.h"
#include "login.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setAutoFillBackground(true);
    this->setFixedSize(500, 500);

    QPixmap bgPix(":/new/prefix1/1.png");
    bgPix = bgPix.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, bgPix);
    this->setPalette(palette);

    this->setWindowTitle("五子棋游戏");
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setFont(QFont("华文琥珀",36,QFont::Bold));
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setStyleSheet(R"(
    QLabel {
        color: #2c3e50;
        font-size: 36px;
        font-weight: bold;
        text-shadow: 2px 2px 4px rgba(0,0,0,0.3);
    }
)");
    ui->progressBar->setStyleSheet(R"(
    QProgressBar {
        background-color: #F0F0F0;
        border: 1px solid #AAAAAA;
        border-radius: 12px;
        height: 24px;
        text-align: center;
    }

    QProgressBar::chunk {
        background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                                    stop:0 #0000FF,
                                    stop:1 #00FF00);
        border-radius: 12px;
    }
)");

    ui->progressBar->setValue(0);

    timer=new QTimer(this);

    connect(timer,&QTimer::timeout,this,[=]()
            {
                int now=ui->progressBar->value();
                ui->progressBar->setValue(now+1);
            });
    timer->start(50);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_progressBar_valueChanged(int value)
{
    qDebug()<<"当前进度："<<value<<"%";

    if(value==100)
    {
        qDebug()<<"加载完成！打开主页面！";
        this->close();
        login *l=new login;
        l->show();
    }
}



