/********************************************************************************
** Form generated from reading UI file 'shuru.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHURU_H
#define UI_SHURU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_shuru
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *qd1;
    QPushButton *qd2;
    QLineEdit *player1ac;
    QLineEdit *player1mm;
    QLineEdit *player2ac;
    QLineEdit *player2mm;
    QPushButton *pushButton;

    void setupUi(QWidget *shuru)
    {
        if (shuru->objectName().isEmpty())
            shuru->setObjectName("shuru");
        shuru->resize(400, 300);
        label = new QLabel(shuru);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 50, 61, 51));
        label_2 = new QLabel(shuru);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 120, 61, 61));
        label_3 = new QLabel(shuru);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(120, 50, 40, 12));
        label_4 = new QLabel(shuru);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(120, 80, 40, 12));
        label_5 = new QLabel(shuru);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(120, 140, 40, 12));
        label_6 = new QLabel(shuru);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(120, 160, 40, 12));
        qd1 = new QPushButton(shuru);
        qd1->setObjectName("qd1");
        qd1->setGeometry(QRect(320, 70, 56, 18));
        qd2 = new QPushButton(shuru);
        qd2->setObjectName("qd2");
        qd2->setGeometry(QRect(320, 160, 56, 18));
        player1ac = new QLineEdit(shuru);
        player1ac->setObjectName("player1ac");
        player1ac->setGeometry(QRect(160, 50, 113, 20));
        player1mm = new QLineEdit(shuru);
        player1mm->setObjectName("player1mm");
        player1mm->setGeometry(QRect(160, 80, 113, 20));
        player2ac = new QLineEdit(shuru);
        player2ac->setObjectName("player2ac");
        player2ac->setGeometry(QRect(160, 130, 113, 20));
        player2mm = new QLineEdit(shuru);
        player2mm->setObjectName("player2mm");
        player2mm->setGeometry(QRect(160, 160, 113, 20));
        pushButton = new QPushButton(shuru);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(140, 230, 121, 31));
        QFont font;
        font.setPointSize(15);
        pushButton->setFont(font);

        retranslateUi(shuru);

        QMetaObject::connectSlotsByName(shuru);
    } // setupUi

    void retranslateUi(QWidget *shuru)
    {
        shuru->setWindowTitle(QCoreApplication::translate("shuru", "Form", nullptr));
        label->setText(QCoreApplication::translate("shuru", "\347\216\251\345\256\2661\357\274\210\346\211\247\351\273\221\357\274\211", nullptr));
        label_2->setText(QCoreApplication::translate("shuru", "\347\216\251\345\256\2662\357\274\210\346\211\247\347\231\275\357\274\211", nullptr));
        label_3->setText(QCoreApplication::translate("shuru", "\350\264\246\345\217\267", nullptr));
        label_4->setText(QCoreApplication::translate("shuru", "\345\257\206\347\240\201", nullptr));
        label_5->setText(QCoreApplication::translate("shuru", "\350\264\246\345\217\267", nullptr));
        label_6->setText(QCoreApplication::translate("shuru", "\345\257\206\347\240\201", nullptr));
        qd1->setText(QCoreApplication::translate("shuru", "\347\241\256\345\256\232\347\216\251\345\256\2661", nullptr));
        qd2->setText(QCoreApplication::translate("shuru", "\347\241\256\345\256\232\347\216\251\345\256\2662", nullptr));
        pushButton->setText(QCoreApplication::translate("shuru", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class shuru: public Ui_shuru {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHURU_H
