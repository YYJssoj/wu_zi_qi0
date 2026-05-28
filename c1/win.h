//
// Created by 17708 on 2026/5/9.
//

#ifndef C1_WIN_H
#define C1_WIN_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class win;
}

QT_END_NAMESPACE

class win : public QWidget {
    Q_OBJECT

public:
    explicit win(QWidget *parent = nullptr);

    ~win() override;

private:
    Ui::win *ui;
};


#endif //C1_WIN_H