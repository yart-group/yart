/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *leftWidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *controlTabWidget;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QTabWidget *logsTabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QWidget *rightWidget;
    QHBoxLayout *horizontalLayout_2;
    QGraphicsView *workspace;
    QMenuBar *menuBar;
    QMenu *menuXddd;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(781, 389);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        leftWidget = new QWidget(centralWidget);
        leftWidget->setObjectName(QStringLiteral("leftWidget"));
        leftWidget->setMinimumSize(QSize(210, 0));
        leftWidget->setMaximumSize(QSize(210, 16777215));
        verticalLayout_2 = new QVBoxLayout(leftWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        controlTabWidget = new QTabWidget(leftWidget);
        controlTabWidget->setObjectName(QStringLiteral("controlTabWidget"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        controlTabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        controlTabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        controlTabWidget->addTab(tab_5, QString());

        verticalLayout_2->addWidget(controlTabWidget);

        logsTabWidget = new QTabWidget(leftWidget);
        logsTabWidget->setObjectName(QStringLiteral("logsTabWidget"));
        logsTabWidget->setTabPosition(QTabWidget::North);
        logsTabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        logsTabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        logsTabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(logsTabWidget);


        horizontalLayout->addWidget(leftWidget);

        rightWidget = new QWidget(centralWidget);
        rightWidget->setObjectName(QStringLiteral("rightWidget"));
        horizontalLayout_2 = new QHBoxLayout(rightWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        workspace = new QGraphicsView(rightWidget);
        workspace->setObjectName(QStringLiteral("workspace"));

        horizontalLayout_2->addWidget(workspace);


        horizontalLayout->addWidget(rightWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 781, 19));
        menuXddd = new QMenu(menuBar);
        menuXddd->setObjectName(QStringLiteral("menuXddd"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuXddd->menuAction());

        retranslateUi(MainWindow);

        controlTabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        controlTabWidget->setTabText(controlTabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "settings", Q_NULLPTR));
        controlTabWidget->setTabText(controlTabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "runtime", Q_NULLPTR));
        controlTabWidget->setTabText(controlTabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "map", Q_NULLPTR));
        logsTabWidget->setTabText(logsTabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        logsTabWidget->setTabText(logsTabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
        menuXddd->setTitle(QApplication::translate("MainWindow", "xddd", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
