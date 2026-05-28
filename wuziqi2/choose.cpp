#include "choose.h"
#include "ui_choose.h"
#include"shuru.h"
#include<QDebug>
#include"../global.h"
choose::choose(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::choose),ss(nullptr)
{
    ui->setupUi(this);
    this->setFixedSize(400, 300);
}

choose::~choose()
{
    delete ui;
}
void choose::get(result x,std::vector<movehistory> history2){
    if(current_account=="com")return;
    s=x;history=history2;this->show();

}

void choose::on_saving_clicked()
{
    ss.r=s;ss.history=history;
    ss.show();
this->hide();

}


void choose::on_unsaving_clicked()
{
this->close();
}

