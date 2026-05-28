#include "chessboard.h"
#include<QPainter>
#include<QDebug>
#include<QVector>
#include<QDebug>
#include"mainwindow.h"
chessboard::chessboard(QWidget *parent)
    : QWidget{parent},choice2(nullptr)
{  //  choice=new choose(this);
    connect(this,&chessboard::end,choice2,&choose::get);
    present=player1;
    /**/
    for(int i=0;i<m_boardsize;i++){
        for(int j=0;j<m_boardsize;j++){
            board[i][j]=empty;
        }

    }
    hovercol=-1;
    hoverrow=-1;
    hoverflag=false;
    setMouseTracking(true);
    pausesi=1;
}
void chessboard:: paintEvent(QPaintEvent*event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::TextAntialiasing);


    QColor back(205,228,205);

    painter.fillRect(rect(),back);

    for(int index=0;index<m_boardsize;index++){
        painter.drawLine(instance+index*m_cell,instance,instance+index*m_cell,instance+m_cell*(m_boardsize-1));
        painter.drawLine(instance,instance+index*m_cell,instance+m_cell*(m_boardsize-1),instance+index*m_cell);
    }


    if(hoverflag==true&&hoverrow>=0&&hoverrow<m_boardsize&&hovercol>=0&&hovercol<m_boardsize&&board[hoverrow][hovercol]==empty){
        painter.setBrush(Qt::red);
        painter.drawEllipse(QPoint(instance+hoverrow*m_cell,instance+hovercol*m_cell),m_cell/6,m_cell/6);
    }


    for(int row=0;row<m_boardsize;row++){
        for(int col=0;col<m_boardsize;col++){
            if(board[row][col]==player1){
                painter.setBrush(Qt::black);
                painter.drawEllipse(QPoint(instance+row*m_cell,instance+col*m_cell),m_cell/3,m_cell/3);
            }
            else if(board[row][col]==player2){
                painter.setBrush(Qt::white);
                painter.drawEllipse(QPoint(instance+row*m_cell,instance+col*m_cell),m_cell/3,m_cell/3);
            }
        }
    }

}
void chessboard:: mouseMoveEvent(QMouseEvent* event) {
    int row=(event->x()-instance+m_cell/2)/m_cell;
    int col=(event->y()-instance+m_cell/2)/m_cell;

    if(row>=0&&row<m_boardsize&&col>=0&&col<m_boardsize){
        if(hoverrow!=row||hovercol!=col){
            hovercol=col;hoverrow=row;
            hoverflag=true;
            update();
        }
    }
    else{
        hoverflag=false;
        hoverrow=hovercol=-1;
        update();
    }


}

void chessboard:: mousePressEvent(QMouseEvent *event)
{   if(pausesi==0){qDebug()<<"df";return;}
    int row=(event->x()-instance+m_cell/2)/m_cell;
    int col=(event->y()-instance+m_cell/2)/m_cell;
    if(row>=0&&row<m_boardsize&col>=0&&col<m_boardsize&&board[row][col]==empty){
        board[row][col]=present;

       history.push_back({row,col,present});
        if(checkWin()==1){r=black;this->close();
           choice2 = new choose(this);
            connect(this, &chessboard::end, choice2, &choose::get);
            emit end(black,history);
            emit ss();
            }
         if(checkWin()==2){r=white;this->close();
           choice2 = new choose(this);
             connect(this, &chessboard::end, choice2, &choose::get);
             emit end(white,history);  emit ss();
             return;}
        if(present==player1)present=player2;
        else if(present==player2)present=player1;
       if (present==player2) {
           emit currentPlayerChanged("当前玩家：白棋");
            emit piecePlaced();
       }
     else
       {
           emit currentPlayerChanged("当前玩家：黑棋");
            emit piecePlaced();
       }
        update();

    }

}
void chessboard::undomove(){

    if(history.empty()){return ;}
    movehistory last=history.back();
    board[last.r][last.c]=empty;
    history.pop_back();

    present=last.player;
    if (present==player2) {
        emit currentPlayerChanged("当前玩家：白棋");
        emit piecePlaced();
    } else {
        emit currentPlayerChanged("当前玩家：黑棋");
        emit piecePlaced();
    }
    emit piecePlaced();
    update();


}


int chessboard:: checkWin() {

    for (int r = 0; r < 15; ++r) {
        for (int c = 0; c < 15; ++c) {
            if (board[r][c] == empty) {
                continue;
            }

            ROLE current_player = board[r][c];
            if (current_player == empty) continue;

            int directions[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};

            for (auto& dir : directions) {
                int dr = dir[0];
                int dc = dir[1];

                int opp_dr = -dr;
                int opp_dc = -dc;

                int count = 1;

                int nr = r + dr;
                int nc = c + dc;
                while (nr >= 0 && nr < 15 && nc >= 0 && nc < 15 && board[nr][nc] == current_player) {
                    count++;
                    nr += dr;
                    nc += dc;
                }

                nr = r + opp_dr;
                nc = c + opp_dc;
                while (nr >= 0 && nr < 15 && nc >= 0 && nc < 15 && board[nr][nc] == current_player) {
                    count++;
                    nr += opp_dr;
                    nc += opp_dc;
                }

                if (count >= 5) {
                    if (current_player == player1) {
                        return 1;
                    } else if (current_player == player2) {
                        return 2;
                    }
                }
            }
        }
    }

    return 0;
}
























