#ifndef SETTING_H
#define SETTING_H

#include <QWidget>

namespace Ui {
class setting;
}

class setting : public QWidget
{
    Q_OBJECT

public:
    explicit setting(QWidget *parent = nullptr);
    ~setting();
    int total=0;
    int every=0;

private slots:
    void sett1();
    void sett2();
    void on_pushButton_clicked(bool checked);

private:
    Ui::setting *ui;

};

#endif // SETTING_H
