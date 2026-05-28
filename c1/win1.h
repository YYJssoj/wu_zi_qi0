#ifndef WIN1_H
#define WIN1_H

#include <QWidget>
#include <vector>
#include <tuple>
#include "AI.h"

class QRadioButton;

QT_BEGIN_NAMESPACE
namespace Ui { class win1; }
QT_END_NAMESPACE

class win1 final : public QWidget {
    Q_OBJECT

public:
    explicit win1(QWidget *parent = nullptr);
    ~win1() override;
protected:
    void paintEvent(QPaintEvent *) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private slots:
    void onResetGame();
    void onColorToggled(bool checked);
    void onUndoMove();
private:
    Ui::win1 *ui;
    std::vector<std::vector<int>> board;
    bool isWhiteTurn;
    bool gameOver;
    bool playerIsWhite;
    AI ai;
    QRadioButton *blackBtn;
    QRadioButton *whiteBtn;
    std::vector<std::tuple<int,int,int>> history;
    void performAIMove();
    void endGame(const QString& message);
    [[nodiscard]] bool isBoardFull() const;
    void recordMove(int row, int col, int piece);
    bool undoLastTwoMoves();
};

#endif // WIN1_H