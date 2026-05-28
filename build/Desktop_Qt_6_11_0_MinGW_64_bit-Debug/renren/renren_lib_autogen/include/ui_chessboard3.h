/********************************************************************************
** Form generated from reading UI file 'chessboard3.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSBOARD3_H
#define UI_CHESSBOARD3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chessboard3
{
public:
    QPushButton *prev_button;
    QPushButton *next_button;

    void setupUi(QWidget *chessboard3)
    {
        if (chessboard3->objectName().isEmpty())
            chessboard3->setObjectName("chessboard3");
        chessboard3->resize(800, 600);
        prev_button = new QPushButton(chessboard3);
        prev_button->setObjectName("prev_button");
        prev_button->setGeometry(QRect(710, 30, 75, 24));
        next_button = new QPushButton(chessboard3);
        next_button->setObjectName("next_button");
        next_button->setGeometry(QRect(710, 90, 75, 24));

        retranslateUi(chessboard3);

        QMetaObject::connectSlotsByName(chessboard3);
    } // setupUi

    void retranslateUi(QWidget *chessboard3)
    {
        chessboard3->setWindowTitle(QCoreApplication::translate("chessboard3", "Form", nullptr));
        prev_button->setText(QCoreApplication::translate("chessboard3", "\344\270\212\344\270\200\346\255\245", nullptr));
        next_button->setText(QCoreApplication::translate("chessboard3", "\344\270\213\344\270\200\346\255\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chessboard3: public Ui_chessboard3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSBOARD3_H
