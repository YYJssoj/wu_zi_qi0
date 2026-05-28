/********************************************************************************
** Form generated from reading UI file 'ending.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDING_H
#define UI_ENDING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ending
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *ending)
    {
        if (ending->objectName().isEmpty())
            ending->setObjectName("ending");
        ending->resize(400, 300);
        QFont font;
        font.setPointSize(15);
        ending->setFont(font);
        pushButton = new QPushButton(ending);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 50, 111, 71));
        pushButton_2 = new QPushButton(ending);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(120, 160, 111, 71));

        retranslateUi(ending);

        QMetaObject::connectSlotsByName(ending);
    } // setupUi

    void retranslateUi(QWidget *ending)
    {
        ending->setWindowTitle(QCoreApplication::translate("ending", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("ending", "\351\200\200\345\207\272\346\270\270\346\210\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ending", "\345\206\215\346\235\245\344\270\200\345\261\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ending: public Ui_ending {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDING_H
