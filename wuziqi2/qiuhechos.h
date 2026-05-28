#ifndef QIUHECHOS_H
#define QIUHECHOS_H

#include <QWidget>

namespace Ui {
class qiuhechos;
}

class qiuhechos : public QWidget
{
    Q_OBJECT

public:
    explicit qiuhechos(QWidget *parent = nullptr);
    ~qiuhechos();

signals:void yes();void no();
private slots:

    void on_yes_clicked();

    void on_no_clicked();

private:
    int i=0;
    Ui::qiuhechos *ui;
};

#endif // QIUHECHOS_H
