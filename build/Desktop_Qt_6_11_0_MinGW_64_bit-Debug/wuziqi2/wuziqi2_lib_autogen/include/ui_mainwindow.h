/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *renshu;
    QPushButton *huiqi;
    QPushButton *qiuhe;
    QPushButton *pause;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        renshu = new QPushButton(centralwidget);
        renshu->setObjectName("renshu");
        renshu->setGeometry(QRect(710, 390, 56, 18));
        huiqi = new QPushButton(centralwidget);
        huiqi->setObjectName("huiqi");
        huiqi->setGeometry(QRect(720, 370, 56, 18));
        qiuhe = new QPushButton(centralwidget);
        qiuhe->setObjectName("qiuhe");
        qiuhe->setGeometry(QRect(710, 350, 56, 18));
        pause = new QPushButton(centralwidget);
        pause->setObjectName("pause");
        pause->setGeometry(QRect(700, 310, 61, 21));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(630, 150, 2, 2));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        renshu->setText(QCoreApplication::translate("MainWindow", "\350\256\244\350\276\223", nullptr));
        huiqi->setText(QCoreApplication::translate("MainWindow", "\346\202\224\346\243\213", nullptr));
        qiuhe->setText(QCoreApplication::translate("MainWindow", "\346\261\202\345\222\214", nullptr));
        pause->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234/\347\273\247\347\273\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
