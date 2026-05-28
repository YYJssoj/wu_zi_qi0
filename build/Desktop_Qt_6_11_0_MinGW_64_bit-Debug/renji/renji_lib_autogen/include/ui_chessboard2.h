/********************************************************************************
** Form generated from reading UI file 'chessboard2.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHESSBOARD2_H
#define UI_CHESSBOARD2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chessboard2
{
public:
    QPushButton *prev_button;
    QPushButton *next_button;

    void setupUi(QWidget *chessboard2)
    {
        if (chessboard2->objectName().isEmpty())
            chessboard2->setObjectName("chessboard2");
        chessboard2->resize(800, 600);
        prev_button = new QPushButton(chessboard2);
        prev_button->setObjectName("prev_button");
        prev_button->setGeometry(QRect(710, 30, 75, 24));
        next_button = new QPushButton(chessboard2);
        next_button->setObjectName("next_button");
        next_button->setGeometry(QRect(710, 90, 75, 24));

        retranslateUi(chessboard2);

        QMetaObject::connectSlotsByName(chessboard2);
    } // setupUi

    void retranslateUi(QWidget *chessboard2)
    {
        chessboard2->setWindowTitle(QCoreApplication::translate("chessboard2", "Form", nullptr));
        prev_button->setText(QCoreApplication::translate("chessboard2", "\344\270\212\344\270\200\346\255\245", nullptr));
        next_button->setText(QCoreApplication::translate("chessboard2", "\344\270\213\344\270\200\346\255\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chessboard2: public Ui_chessboard2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHESSBOARD2_H
