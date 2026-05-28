#ifndef CHESSBOARD3_H
#define CHESSBOARD3_H
#include<QApplication>
#include <QWidget>
#include <QPushButton>
#include <QList>
#include "demo.h"
#include"QDialog"
#include"QPainter"
#include<QPoint>

namespace Ui {
class chessboard3;
}

class chessboard3 : public QDialog
{
    Q_OBJECT

public:
    explicit chessboard3(QWidget *parent = nullptr,QString filename=" ");
    ~chessboard3();
    void loadFromFile(const QString& filename);
protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_prev_button_clicked();

    void on_next_button_clicked();

private:
    QString filename;
    Ui::chessboard3 *ui;
    QList<point> steps;
    int currentStep;

};

#endif // CHESSBOARD3_H
