#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"chessboard.h"
#include <QLabel>
#include<QTimer>
#include"qiuhechos.h"
#include"choose.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int total,int every,QWidget *parent = nullptr);
    explicit MainWindow(QWidget *parent = nullptr){};
    ~MainWindow() override;

signals:void endding(result x,std::vector<movehistory> history);
public slots:
    void yesh();
    void noh();
    void ssr();
    void ge(result xx,std::vector<movehistory> h);
private slots:
    void on_pushButton_clicked();
    void onStepTimeout();        // 单步30秒倒计时结束（超时判负）
    void onTotalTimeTick();
     void switchTurn();
 void onStepTick();     // 总时间每秒递减
     void on_renshu_clicked();

 void on_qiuhe_clicked();



 void on_pause_clicked();

 private:
 qiuhechos *q;choose* choice;
 void updateTimeDisplay();
    Ui::MainWindow *ui;
QLabel *statusLabel;
    chessboard*qipan;
int tot,eve;
    QTimer playertimer;

    QTimer everytime;
QLabel* labeltime;
    int playertime1;
int playertime2;
    int evestep;

};
#endif // MAINWINDOW_H
