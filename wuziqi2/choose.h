#ifndef CHOOSE_H
#define CHOOSE_H

#include <QWidget>
#include<QVector>
#include"stdshared.h"
#include"shuru.h"
namespace Ui {
class choose;
}

class choose : public QWidget
{
    Q_OBJECT

public:
    explicit choose(QWidget *parent = nullptr);
    ~choose();
public slots:void get(result x,std::vector<movehistory> history2);

private slots:


    void on_saving_clicked();

    void on_unsaving_clicked();

private:
    shuru ss;
    Ui::choose *ui;result s;std::vector<movehistory> history;
};

#endif // CHOOSE_H
