/********************************************************************************
** Form generated from reading UI file 'qiuhechos.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QIUHECHOS_H
#define UI_QIUHECHOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qiuhechos
{
public:
    QPushButton *yes;
    QPushButton *no;
    QLabel *label;

    void setupUi(QWidget *qiuhechos)
    {
        if (qiuhechos->objectName().isEmpty())
            qiuhechos->setObjectName("qiuhechos");
        qiuhechos->resize(400, 300);
        yes = new QPushButton(qiuhechos);
        yes->setObjectName("yes");
        yes->setGeometry(QRect(80, 180, 56, 18));
        no = new QPushButton(qiuhechos);
        no->setObjectName("no");
        no->setGeometry(QRect(210, 180, 56, 18));
        label = new QLabel(qiuhechos);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 70, 91, 51));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        retranslateUi(qiuhechos);

        QMetaObject::connectSlotsByName(qiuhechos);
    } // setupUi

    void retranslateUi(QWidget *qiuhechos)
    {
        qiuhechos->setWindowTitle(QCoreApplication::translate("qiuhechos", "Form", nullptr));
        yes->setText(QCoreApplication::translate("qiuhechos", "\345\220\214\346\204\217", nullptr));
        no->setText(QCoreApplication::translate("qiuhechos", "\344\270\215\345\220\214\346\204\217", nullptr));
        label->setText(QCoreApplication::translate("qiuhechos", "\346\230\257\345\220\246\345\220\214\346\204\217\346\261\202\345\222\214\357\274\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qiuhechos: public Ui_qiuhechos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QIUHECHOS_H
