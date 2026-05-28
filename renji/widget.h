#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTimer>
#include<QProgressBar>
#include<QMessageBox>
#include<login.h>
#include <QPixmap>
#include <QPalette>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private slots:
    void on_progressBar_valueChanged(int value);


private:
    Ui::Widget *ui;
    QTimer *timer;
};
#endif // WIDGET_H
