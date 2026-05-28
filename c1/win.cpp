//
// Created by 17708 on 2026/5/9.
//

// You may need to build the project (run Qt uic code generator) to get "ui_win.h" resolved

#include "win.h"
#include "./ui_win.h"


win::win(QWidget *parent) : QWidget(parent), ui(new Ui::win) {
    ui->setupUi(this);
}

win::~win() {
    delete ui;
}