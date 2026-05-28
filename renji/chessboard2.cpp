#include "chessboard2.h"
#include "ui_chessboard2.h"
#include"demo.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include<QApplication>
#include<QDebug>

chessboard2::chessboard2(QWidget *parent,QString filename)
    : QDialog(parent)
    , ui(new Ui::chessboard2),currentStep(0)
{
    ui->setupUi(this);
    this->setFixedSize(800, 600);
    this->filename=filename;
}

chessboard2::~chessboard2()
{
    delete ui;
}

void chessboard2::on_prev_button_clicked()
{
    if(currentStep>0)
    {
        currentStep--;
        update();
    }
    else
    {
        QMessageBox::information(this,"提示","已是第一手棋");
        return;
    }
}


void chessboard2::on_next_button_clicked()
{
    if (currentStep < steps.size())
    {
        currentStep++;
        update();
    }
    else
    {
        QMessageBox::information(this,"提示","已是最后一手棋");
        return;
    }
}

void chessboard2::paintEvent(QPaintEvent *e)
{
    QDialog::paintEvent(e);
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    p.fillRect(rect(),QColor(245,230,180));
    p.setPen(Qt::black);
    const int grid = 30;
    const int startX = 20;
    const int startY = 20;

    // 1. 画 15×15 棋盘线
    for (int i = 0; i <= 14; i++)
    {
        // 横线
        p.drawLine(startX, startY + i*grid, startX+14*grid, startY + i*grid);
        // 竖线
        p.drawLine(startX + i*grid, startY, startX + i*grid, startY+14*grid);
    }

    // 2. 画棋子：只画到 currentStep 步
    for (int i = 0; i < currentStep; i++)
    {
        point pos = steps[i];
        int px = startX + pos.x* grid;
        int py = startY + pos.y* grid;

        // 偶数黑棋，奇数白棋
        if (i % 2 == 0)
            p.setBrush(Qt::black);
        else
            p.setBrush(Qt::white);

        p.drawEllipse(px - 12, py - 12, 24, 24);
    }
}

void chessboard2::loadFromFile(const QString& filename)
{
    steps.clear();
    currentStep = 0;
    QString path = QCoreApplication::applicationDirPath()+"/"+filename;
    QFile f(path);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "错误", "无法打开对局文件");
        return;
    }
    QTextStream in(&f);
    if(!in.atEnd())
    {
        in.readLine();
    }
    while (!in.atEnd())
    {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;
        point p;
        QStringList xy = line.split("\t", Qt::SkipEmptyParts);
        p.x= xy[0].toInt();
        p.y= xy[1].toInt();
        steps.append(p);
    }
    f.close();
    update();
}