#include "qiuhechos.h"
#include "ui_qiuhechos.h"

qiuhechos::qiuhechos(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::qiuhechos)
{
    ui->setupUi(this);
    this->setFixedSize(400, 300);
}

qiuhechos::~qiuhechos()
{
    delete ui;
}


void qiuhechos::on_no_clicked()
{
    i=0; emit no();this->close();

}

void  qiuhechos::on_yes_clicked()
{
    i=1;emit yes();this->close();


}

