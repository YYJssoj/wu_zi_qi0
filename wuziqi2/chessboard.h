#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include"stdshared.h"
#include <QWidget>
#include<Qvector>
#include<QMouseEvent>
#include"choose.h"

class  MainWindow;
class chessboard : public QWidget
{
    Q_OBJECT

public:result r;ROLE present; std:: vector<movehistory> history;
int pausesi;
    explicit chessboard(QWidget *parent = nullptr);
    void undomove();
    void mousePressEvent(QMouseEvent *event) override;

protected:
    void paintEvent(QPaintEvent*event) override;
    void mouseMoveEvent(QMouseEvent* event) override;


signals:
    void ss();
    void currentPlayerChanged(const QString &text);
     void piecePlaced();
    void end(result x,std::vector<movehistory> history2);
private:
    MainWindow *s;
   static const int m_boardsize=15;
   static const int m_cell=40;
  static  const int instance=20;

ROLE board[m_boardsize][m_boardsize];
  int hoverrow;
int hovercol;
  bool hoverflag;
choose *choice2;
  int checkWin();

};

#endif // CHESSBOARD_H
