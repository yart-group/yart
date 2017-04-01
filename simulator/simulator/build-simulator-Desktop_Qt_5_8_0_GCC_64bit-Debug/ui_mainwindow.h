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
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QWidget *tab_4;
    QFrame *frame;
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
        tabWidget = new QTabWidget(mainPage);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMovable(true);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout_3->addWidget(tabWidget, 0, 0, 1, 1);

        tabWidget_2 = new QTabWidget(mainPage);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        sizePolicy1.setHeightForWidth(tabWidget_2->sizePolicy().hasHeightForWidth());
        tabWidget_2->setSizePolicy(sizePolicy1);
        tabWidget_2->setMovable(true);
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget_2->addTab(tab_4, QString());

        gridLayout_3->addWidget(tabWidget_2, 1, 0, 1, 1);

        frame = new QFrame(mainPage);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout_3->addWidget(frame, 0, 1, 2, 1);

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

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        logoText->setText(QApplication::translate("MainWindow", "Simulator", Q_NULLPTR));
        startButton->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        exitButton->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "Tab 1", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
