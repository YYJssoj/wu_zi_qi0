#include "win1.h"

#include <fstream>
#include <iostream>
#include <ostream>
#include "./ui_win1.h"
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QTimer>
#include <QApplication>

static bool isWin(const std::vector<std::vector<int>>& board, const int row, const int col) {
    const int player=board[row][col];
    if (player==0) {return false;}
    int sum1=1,sum2=1,sum3=1,sum4=1;
    for (int c=col-1;c>=0 && board[row][c]==player;--c) {sum1++;}
    for (int c=col+1;c<15 && board[row][c]==player;++c) {sum1++;}
    for (int r=row-1;r>=0 && board[r][col]==player;--r) {sum2++;}
    for (int r=row+1;r<15 && board[r][col]==player;++r) {sum2++;}
    for (int r=row-1,c=col-1;r>=0 && c>=0 && board[r][c]==player;--r,--c) {sum3++;}
    for (int r=row+1,c=col+1;r<15 && c<15 && board[r][c]==player;++r,++c) {sum3++;}
    for (int r=row-1,c=col+1;r>=0 && c<15 && board[r][c]==player;--r,++c) {sum4++;}
    for (int r=row+1,c=col-1;r<15 && c>=0 && board[r][c]==player;++r,--c) {sum4++;}
    return sum1>=5 || sum2>=5 || sum3>=5 || sum4>=5;
}
extern long long int timestamp_ms;
static int aaa111=0;
win1::win1(QWidget *parent): QWidget(parent), ui(new Ui::win1),
    board(15, std::vector(15, 0)), isWhiteTurn(false), gameOver(false), playerIsWhite(false){
    ui->setupUi(this);
    auto now = std::chrono::system_clock::now();
    timestamp_ms=std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
    this->setObjectName("win1");
    this->setStyleSheet("QWidget#win1 { background-color: #DEB887; }");
    this->setFixedSize(800, 664);
    ai.setDifficulty(2);
    auto *rightPanel = new QWidget(this);
    rightPanel->setGeometry(660, 52, 120, 400);
    rightPanel->setStyleSheet("background-color: rgba(0,0,0,0);");
    auto *layout = new QVBoxLayout(rightPanel);
    auto *titleLabel = new QLabel("五子棋 AI", rightPanel);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 18px; font-weight: bold; color: #5D3A1A;");
    layout->addWidget(titleLabel);
    auto *colorGroup = new QGroupBox("玩家执", rightPanel);
    auto *colorLayout = new QVBoxLayout(colorGroup);
    blackBtn = new QRadioButton("黑棋（先手）", colorGroup);
    whiteBtn = new QRadioButton("白棋（后手）", colorGroup);
    blackBtn->setChecked(true);
    colorLayout->addWidget(blackBtn);
    colorLayout->addWidget(whiteBtn);
    layout->addWidget(colorGroup);
    connect(blackBtn, &QRadioButton::toggled, this, &win1::onColorToggled);
    connect(whiteBtn, &QRadioButton::toggled, this, &win1::onColorToggled);
    auto *resetBtn = new QPushButton("新一局", rightPanel);
    resetBtn->setFixedSize(100, 35);
    resetBtn->setStyleSheet("background-color: #8B5A2B; color: white; font-weight: bold; border-radius: 5px;");
    layout->addWidget(resetBtn, 0, Qt::AlignCenter);
    connect(resetBtn, &QPushButton::clicked, this, &win1::onResetGame);
    auto *undoBtn = new QPushButton("悔棋", rightPanel);
    undoBtn->setFixedSize(100, 35);
    undoBtn->setStyleSheet("background-color: #8B5A2B; color: white; font-weight: bold; border-radius: 5px;");
    layout->addWidget(undoBtn, 0, Qt::AlignCenter);
    connect(undoBtn, &QPushButton::clicked, this, &win1::onUndoMove);
    layout->addStretch();
    onResetGame();
}
win1::~win1() {delete ui;}
void win1::recordMove(int row,int col,int piece) {history.emplace_back(row, col, piece);}
bool win1::undoLastTwoMoves() {
    if (gameOver) {return false;}
    if (history.size()<2) {
        QMessageBox::information(this, "提示", "没有足够的步数可以悔棋！");
        return false;
    }
    auto [row2, col2, piece2] = history.back();
    history.pop_back();
    auto [row1, col1, piece1] = history.back();
    history.pop_back();
    board[row1][col1] = 0;
    board[row2][col2] = 0;
    isWhiteTurn = playerIsWhite;
    gameOver = false;
    update();
    return true;
}
static bool aaa222;
void win1::onUndoMove() {if (undoLastTwoMoves()) {}}
void win1::onColorToggled(const bool checked) {
    if (!checked) return;
    if (sender()==blackBtn) {
        playerIsWhite=false;
        aaa222 = false;
    }
    else if (sender()==whiteBtn) {
        playerIsWhite=true;
        aaa222 = true;
    }
    onResetGame();
}
void win1::onResetGame() {
    for (auto& row : board)
        std::fill(row.begin(), row.end(), 0);
    history.clear();
    auto now = std::chrono::system_clock::now();
    timestamp_ms=std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
    gameOver = false;
    isWhiteTurn = false;
    AI::clear();
    update();
    if (!gameOver && playerIsWhite) {
        QTimer::singleShot(0, this, &win1::performAIMove);
    }
}
void win1::performAIMove() {
    if (gameOver) return;
    const bool aiIsWhite = !playerIsWhite;
    if (aiIsWhite != isWhiteTurn) return;
    if (const auto [fst, snd] = ai.getBestMove(board, aiIsWhite); fst != -1 && board[fst][snd]==0) {
        const int aiColor = aiIsWhite ? 2 : 1;
        board[fst][snd] = aiColor;
        recordMove(fst, snd, aiColor);
        update();
        QApplication::processEvents();
        if (isWin(board, fst, snd)) {
            aaa111=aiIsWhite?2:1;
            endGame(aiIsWhite ? "白方（AI）" : "黑方（AI）");
            return;
        }
        isWhiteTurn=!isWhiteTurn;
        if (isBoardFull()) {endGame("平局！");}
    }
    else {if (isBoardFull()) endGame("平局！");}
}
void win1::mouseReleaseEvent(QMouseEvent *event) {
    if (gameOver) {return;}
    if (event->button() != Qt::LeftButton) {return;}
    if (playerIsWhite != isWhiteTurn) {return;}
    constexpr int x0 = 52, y0 = 52, delta = 40, radium = 19;
    const int x=event->pos().x()-x0;
    const int y=event->pos().y()-y0;
    const int x2=20-abs(20-x%delta);
    if (const int y2=20-abs(20-y%delta); x2*x2 + y2*y2 > radium*radium) {return;}
    const int col=x/delta+(x%delta>=20?1:0);
    const int row=y/delta+(y%delta>=20?1:0);
    if (row<0 || row>=15 || col<0 || col>=15) {return;}
    if (board[row][col]!=0) {return;}
    const int playerColor=playerIsWhite ? 2 : 1;
    board[row][col]=playerColor;
    recordMove(row, col, playerColor);
    update();
    QApplication::processEvents();
    if (isWin(board, row, col)) {
        endGame(playerIsWhite ? "白方（玩家）" : "黑方（玩家）");
        return;
    }
    isWhiteTurn = !isWhiteTurn;
    if (isBoardFull()) {
        endGame("平局！");
        return;
    }
    if (!gameOver && playerIsWhite!=isWhiteTurn) {QTimer::singleShot(0, this, &win1::performAIMove);}
}
extern QString current_account;
void win1::endGame(const QString& message) {
    gameOver = true;
    if (current_account!="com") {
        freopen("record_2.csv", "a", stdout);
        std::cout<<current_account.toStdString()<<"\t";
        if (aaa222){printf("1");}
        else{printf("0");}
        printf("\t%lld\t",timestamp_ms);
        if (aaa111==0){printf("2");}
        else if (aaa111-aaa222==1){printf("0");}
        else{printf("1");}
        printf("\t_%lld.csv\n", timestamp_ms);
        const std::string filename2 = current_account.toStdString() + "_" + std::to_string(timestamp_ms) + ".csv";
        std::ofstream file2(filename2);
        freopen(filename2.c_str(), "w", stdout);
        printf("%llu\n",history.size());
        for (auto &it:history) {
            auto [a,b,c]=it;
            printf("%d\t%d\n",b,a);
        }
        freopen("CON","w",stdout);
    }
    QMessageBox::information(this, "游戏结束", message);
}
bool win1::isBoardFull() const {
    for (int i=0; i<15; ++i) {
        for (int j=0; j<15; ++j) {
            if (board[i][j] == 0) {return false;}
        }
    }
    return true;
}
void win1::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    painter.setPen(Qt::black);
    constexpr int x0 = 52, y0 = 52, delta = 40;
    painter.drawRect(30, 30, 604, 604);
    painter.drawRect(31, 31, 602, 602);
    painter.drawRect(32, 32, 600, 600);
    for (int i = 0; i < 15; i++) {
        painter.drawLine(x0 + delta * i, y0, x0 + delta * i, y0 + delta * 14);
        painter.drawLine(x0, y0 + delta * i, x0 + delta * 14, y0 + delta * i);
    }
    painter.setBrush(Qt::black);
    painter.drawEllipse(x0 + delta * 3 - 5, y0 + delta * 3 - 5, 10, 10);
    painter.drawEllipse(x0 + delta * 3 - 5, y0 + delta * 11 - 5, 10, 10);
    painter.drawEllipse(x0 + delta * 7 - 5, y0 + delta * 7 - 5, 10, 10);
    painter.drawEllipse(x0 + delta * 11 - 5, y0 + delta * 3 - 5, 10, 10);
    painter.drawEllipse(x0 + delta * 11 - 5, y0 + delta * 11 - 5, 10, 10);
    for (int row = 0; row < 15; ++row) {
        for (int col = 0; col < 15; ++col) {
            if (board[row][col]) {
                constexpr int radium = 19;
                painter.setBrush(board[row][col] == 1 ? Qt::black : Qt::white);
                const int cx = x0 + col * delta;
                const int cy = y0 + row * delta;
                painter.drawEllipse(cx - radium, cy - radium, radium * 2, radium * 2);
            }
        }
    }
    if (!history.empty()) {
        auto [row, col, piece] = history.back();
        int cx = x0 + col * delta;
        int cy = y0 + row * delta;
        painter.setPen(QPen(Qt::red, 3));
        painter.drawLine(cx - 12, cy, cx -4, cy);
        painter.drawLine(cx, cy - 12, cx, cy -4);
        painter.drawLine(cx +4, cy, cx + 12, cy);
        painter.drawLine(cx, cy +4, cx, cy + 12);
    }
}