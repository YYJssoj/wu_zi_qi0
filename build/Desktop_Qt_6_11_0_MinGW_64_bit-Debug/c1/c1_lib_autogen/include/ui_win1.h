/********************************************************************************
** Form generated from reading UI file 'win1.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIN1_H
#define UI_WIN1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_win1
{
public:

    void setupUi(QWidget *win1)
    {
        if (win1->objectName().isEmpty())
            win1->setObjectName("win1");
        win1->resize(652, 342);

        retranslateUi(win1);

        QMetaObject::connectSlotsByName(win1);
    } // setupUi

    void retranslateUi(QWidget *win1)
    {
        win1->setWindowTitle(QCoreApplication::translate("win1", "win1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class win1: public Ui_win1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIN1_H
