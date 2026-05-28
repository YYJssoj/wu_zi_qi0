/********************************************************************************
** Form generated from reading UI file 'choose.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSE_H
#define UI_CHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_choose
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;

    void setupUi(QWidget *choose)
    {
        if (choose->objectName().isEmpty())
            choose->setObjectName("choose");
        choose->resize(400, 300);
        pushButton = new QPushButton(choose);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(60, 170, 56, 18));
        pushButton_2 = new QPushButton(choose);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(200, 170, 56, 18));
        label = new QLabel(choose);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 70, 101, 51));

        retranslateUi(choose);

        QMetaObject::connectSlotsByName(choose);
    } // setupUi

    void retranslateUi(QWidget *choose)
    {
        choose->setWindowTitle(QCoreApplication::translate("choose", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("choose", "\344\277\235\345\255\230", nullptr));
        pushButton_2->setText(QCoreApplication::translate("choose", "\344\270\215\344\277\235\345\255\230", nullptr));
        label->setText(QCoreApplication::translate("choose", "\346\230\257\345\220\246\344\277\235\345\255\230\345\257\271\345\261\200\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class choose: public Ui_choose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSE_H
