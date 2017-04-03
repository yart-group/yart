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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *upperTabs;
    QWidget *tab001;
    QWidget *tab002;
    QTabWidget *lowerTabs;
    QWidget *tab003;
    QWidget *tab004;
    QFrame *workspace;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        upperTabs = new QTabWidget(centralWidget);
        upperTabs->setObjectName(QStringLiteral("upperTabs"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(upperTabs->sizePolicy().hasHeightForWidth());
        upperTabs->setSizePolicy(sizePolicy);
        upperTabs->setMovable(true);
        tab001 = new QWidget();
        tab001->setObjectName(QStringLiteral("tab001"));
        upperTabs->addTab(tab001, QString());
        tab002 = new QWidget();
        tab002->setObjectName(QStringLiteral("tab002"));
        upperTabs->addTab(tab002, QString());

        gridLayout->addWidget(upperTabs, 0, 0, 1, 1);

        lowerTabs = new QTabWidget(centralWidget);
        lowerTabs->setObjectName(QStringLiteral("lowerTabs"));
        sizePolicy.setHeightForWidth(lowerTabs->sizePolicy().hasHeightForWidth());
        lowerTabs->setSizePolicy(sizePolicy);
        lowerTabs->setMovable(true);
        tab003 = new QWidget();
        tab003->setObjectName(QStringLiteral("tab003"));
        lowerTabs->addTab(tab003, QString());
        tab004 = new QWidget();
        tab004->setObjectName(QStringLiteral("tab004"));
        lowerTabs->addTab(tab004, QString());

        gridLayout->addWidget(lowerTabs, 1, 0, 1, 1);

        workspace = new QFrame(centralWidget);
        workspace->setObjectName(QStringLiteral("workspace"));
        workspace->setFrameShape(QFrame::StyledPanel);
        workspace->setFrameShadow(QFrame::Raised);

        gridLayout->addWidget(workspace, 0, 1, 2, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 19));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        upperTabs->setCurrentIndex(0);
        lowerTabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        upperTabs->setTabText(upperTabs->indexOf(tab001), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        upperTabs->setTabText(upperTabs->indexOf(tab002), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
        lowerTabs->setTabText(lowerTabs->indexOf(tab003), QApplication::translate("MainWindow", "Tab 3", Q_NULLPTR));
        lowerTabs->setTabText(lowerTabs->indexOf(tab004), QApplication::translate("MainWindow", "Tab 4", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
