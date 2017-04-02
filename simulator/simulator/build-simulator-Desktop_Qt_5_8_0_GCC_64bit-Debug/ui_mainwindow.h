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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *mainMenu;
    QVBoxLayout *verticalLayout;
    QLabel *logoText;
    QPushButton *startButton;
    QPushButton *exitButton;
    QWidget *mainPage;
    QGridLayout *gridLayout_3;
    QTabWidget *uppperTabs;
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
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        mainMenu = new QWidget();
        mainMenu->setObjectName(QStringLiteral("mainMenu"));
        verticalLayout = new QVBoxLayout(mainMenu);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        logoText = new QLabel(mainMenu);
        logoText->setObjectName(QStringLiteral("logoText"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(logoText->sizePolicy().hasHeightForWidth());
        logoText->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        logoText->setFont(font);
        logoText->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(logoText);

        startButton = new QPushButton(mainMenu);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(startButton);

        exitButton = new QPushButton(mainMenu);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setMinimumSize(QSize(0, 50));
        exitButton->setSizeIncrement(QSize(0, 0));
        exitButton->setBaseSize(QSize(0, 0));

        verticalLayout->addWidget(exitButton);

        stackedWidget->addWidget(mainMenu);
        mainPage = new QWidget();
        mainPage->setObjectName(QStringLiteral("mainPage"));
        gridLayout_3 = new QGridLayout(mainPage);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        uppperTabs = new QTabWidget(mainPage);
        uppperTabs->setObjectName(QStringLiteral("uppperTabs"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(uppperTabs->sizePolicy().hasHeightForWidth());
        uppperTabs->setSizePolicy(sizePolicy1);
        uppperTabs->setTabShape(QTabWidget::Rounded);
        uppperTabs->setMovable(true);
        tab001 = new QWidget();
        tab001->setObjectName(QStringLiteral("tab001"));
        uppperTabs->addTab(tab001, QString());
        tab002 = new QWidget();
        tab002->setObjectName(QStringLiteral("tab002"));
        uppperTabs->addTab(tab002, QString());

        gridLayout_3->addWidget(uppperTabs, 0, 0, 1, 1);

        lowerTabs = new QTabWidget(mainPage);
        lowerTabs->setObjectName(QStringLiteral("lowerTabs"));
        sizePolicy1.setHeightForWidth(lowerTabs->sizePolicy().hasHeightForWidth());
        lowerTabs->setSizePolicy(sizePolicy1);
        lowerTabs->setMovable(true);
        tab003 = new QWidget();
        tab003->setObjectName(QStringLiteral("tab003"));
        lowerTabs->addTab(tab003, QString());
        tab004 = new QWidget();
        tab004->setObjectName(QStringLiteral("tab004"));
        lowerTabs->addTab(tab004, QString());

        gridLayout_3->addWidget(lowerTabs, 1, 0, 1, 1);

        workspace = new QFrame(mainPage);
        workspace->setObjectName(QStringLiteral("workspace"));
        workspace->setFrameShape(QFrame::StyledPanel);
        workspace->setFrameShadow(QFrame::Raised);

        gridLayout_3->addWidget(workspace, 0, 1, 2, 1);

        stackedWidget->addWidget(mainPage);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

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

        stackedWidget->setCurrentIndex(1);
        uppperTabs->setCurrentIndex(0);
        lowerTabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        logoText->setText(QApplication::translate("MainWindow", "Simulator", Q_NULLPTR));
        startButton->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        exitButton->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        uppperTabs->setTabText(uppperTabs->indexOf(tab001), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        uppperTabs->setTabText(uppperTabs->indexOf(tab002), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
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
