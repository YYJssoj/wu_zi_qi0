/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setting
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *t1;
    QRadioButton *t2;
    QRadioButton *t3;
    QRadioButton *t0;
    QLabel *label;
    QLabel *label_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *l1;
    QRadioButton *l2;
    QRadioButton *l3;
    QRadioButton *l0;
    QPushButton *pushButton;

    void setupUi(QWidget *setting)
    {
        if (setting->objectName().isEmpty())
            setting->setObjectName("setting");
        setting->resize(400, 300);
        verticalLayoutWidget = new QWidget(setting);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 50, 160, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        t1 = new QRadioButton(verticalLayoutWidget);
        t1->setObjectName("t1");

        verticalLayout->addWidget(t1);

        t2 = new QRadioButton(verticalLayoutWidget);
        t2->setObjectName("t2");

        verticalLayout->addWidget(t2);

        t3 = new QRadioButton(verticalLayoutWidget);
        t3->setObjectName("t3");

        verticalLayout->addWidget(t3);

        t0 = new QRadioButton(verticalLayoutWidget);
        t0->setObjectName("t0");

        verticalLayout->addWidget(t0);

        label = new QLabel(setting);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 20, 71, 16));
        label_2 = new QLabel(setting);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(260, 20, 61, 16));
        verticalLayoutWidget_2 = new QWidget(setting);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(210, 50, 160, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        l1 = new QRadioButton(verticalLayoutWidget_2);
        l1->setObjectName("l1");

        verticalLayout_2->addWidget(l1);

        l2 = new QRadioButton(verticalLayoutWidget_2);
        l2->setObjectName("l2");

        verticalLayout_2->addWidget(l2);

        l3 = new QRadioButton(verticalLayoutWidget_2);
        l3->setObjectName("l3");

        verticalLayout_2->addWidget(l3);

        l0 = new QRadioButton(verticalLayoutWidget_2);
        l0->setObjectName("l0");

        verticalLayout_2->addWidget(l0);

        pushButton = new QPushButton(setting);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(200, 230, 56, 18));

        retranslateUi(setting);

        QMetaObject::connectSlotsByName(setting);
    } // setupUi

    void retranslateUi(QWidget *setting)
    {
        setting->setWindowTitle(QCoreApplication::translate("setting", "Form", nullptr));
        t1->setText(QCoreApplication::translate("setting", "5\345\210\206\351\222\237", nullptr));
        t2->setText(QCoreApplication::translate("setting", "10\345\210\206\351\222\237", nullptr));
        t3->setText(QCoreApplication::translate("setting", "15\345\210\206\351\222\237", nullptr));
        t0->setText(QCoreApplication::translate("setting", "\346\227\240\351\231\220\345\210\266\346\250\241\345\274\217", nullptr));
        label->setText(QCoreApplication::translate("setting", "\345\220\204\350\207\252\346\213\245\346\234\211\346\227\266\351\225\277", nullptr));
        label_2->setText(QCoreApplication::translate("setting", "\350\220\275\345\255\220\346\227\266\351\225\277", nullptr));
        l1->setText(QCoreApplication::translate("setting", "20\347\247\222", nullptr));
        l2->setText(QCoreApplication::translate("setting", "40\347\247\222", nullptr));
        l3->setText(QCoreApplication::translate("setting", "60\347\247\222", nullptr));
        l0->setText(QCoreApplication::translate("setting", "\346\227\240\351\231\220\345\210\266\346\250\241\345\274\217", nullptr));
        pushButton->setText(QCoreApplication::translate("setting", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setting: public Ui_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
