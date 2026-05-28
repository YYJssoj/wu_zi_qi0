#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include<QProgressBar>
#include<QTimer>
#include<QMainWindow>
#include <QMessageBox>
#include<QByteArray>
#include<QChar>
#include<zhu_ce.h>
#include<mainw.h>
#include<forget_pw.h>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
signals:
private slots:

    void on_login_button_clicked();

    void on_check_in_button_clicked();

    void on_forget_pw_button_clicked();

    void on_visitor_button_clicked();

private:

    Ui::login *ui;
};



#endif // LOGIN_H
