#ifndef CHESSBOARD2_H
#define CHESSBOARD2_H
#include<QApplication>
#include <QWidget>
#include <QPushButton>
#include <QList>
#include "demo.h"
#include"QDialog"
#include"QPainter"
#include<QPoint>

namespace Ui {
class chessboard2;
}

class chessboard2 : public QDialog
{
    Q_OBJECT

public:
    explicit chessboard2(QWidget *parent = nullptr,QString filename=" ");
    ~chessboard2();
    void loadFromFile(const QString& filename);
protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_prev_button_clicked();

    void on_next_button_clicked();

private:
    QString filename;
    Ui::chessboard2 *ui;
    QList<point> steps;
    int currentStep;

};

#endif // CHESSBOARD2_H
