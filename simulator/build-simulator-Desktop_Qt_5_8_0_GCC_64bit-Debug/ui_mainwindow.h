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
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionnew;
    QAction *actionopen;
    QAction *actionsave;
    QAction *actionmanage;
    QAction *actionload;
    QAction *actionunload;
    QAction *actionshow;
    QAction *actionsettings;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *leftWidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *controlTabWidget;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
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
    QMenu *menucomponents;
    QMenu *menuconsole;
    QMenu *menupause;
    QMenu *menureset;
    QMenu *menuemulators;
    QMenu *menuminitors;
    QMenu *menurun;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menutime;
    QMenu *menusettings;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1331, 551);
        actionnew = new QAction(MainWindow);
        actionnew->setObjectName(QStringLiteral("actionnew"));
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName(QStringLiteral("actionopen"));
        actionsave = new QAction(MainWindow);
        actionsave->setObjectName(QStringLiteral("actionsave"));
        actionmanage = new QAction(MainWindow);
        actionmanage->setObjectName(QStringLiteral("actionmanage"));
        actionload = new QAction(MainWindow);
        actionload->setObjectName(QStringLiteral("actionload"));
        actionunload = new QAction(MainWindow);
        actionunload->setObjectName(QStringLiteral("actionunload"));
        actionshow = new QAction(MainWindow);
        actionshow->setObjectName(QStringLiteral("actionshow"));
        actionsettings = new QAction(MainWindow);
        actionsettings->setObjectName(QStringLiteral("actionsettings"));
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
        leftWidget->setMaximumSize(QSize(350, 16777215));
        verticalLayout_2 = new QVBoxLayout(leftWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        controlTabWidget = new QTabWidget(leftWidget);
        controlTabWidget->setObjectName(QStringLiteral("controlTabWidget"));
        controlTabWidget->setCursor(QCursor(Qt::ArrowCursor));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout = new QVBoxLayout(tab_3);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(tab_3);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem3);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem4);
        new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(__qtreewidgetitem5);
        QTreeWidgetItem *__qtreewidgetitem7 = new QTreeWidgetItem(__qtreewidgetitem6);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(__qtreewidgetitem7);
        new QTreeWidgetItem(__qtreewidgetitem5);
        new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem8 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem8);
        new QTreeWidgetItem(__qtreewidgetitem8);
        new QTreeWidgetItem(__qtreewidgetitem8);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        verticalLayout->addWidget(treeWidget);

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
        menuBar->setGeometry(QRect(0, 0, 1331, 19));
        menuXddd = new QMenu(menuBar);
        menuXddd->setObjectName(QStringLiteral("menuXddd"));
        menucomponents = new QMenu(menuBar);
        menucomponents->setObjectName(QStringLiteral("menucomponents"));
        menuconsole = new QMenu(menuBar);
        menuconsole->setObjectName(QStringLiteral("menuconsole"));
        menupause = new QMenu(menuBar);
        menupause->setObjectName(QStringLiteral("menupause"));
        menureset = new QMenu(menuBar);
        menureset->setObjectName(QStringLiteral("menureset"));
        menuemulators = new QMenu(menuBar);
        menuemulators->setObjectName(QStringLiteral("menuemulators"));
        menuminitors = new QMenu(menuBar);
        menuminitors->setObjectName(QStringLiteral("menuminitors"));
        menurun = new QMenu(menuBar);
        menurun->setObjectName(QStringLiteral("menurun"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menutime = new QMenu(menuBar);
        menutime->setObjectName(QStringLiteral("menutime"));
        menusettings = new QMenu(menuBar);
        menusettings->setObjectName(QStringLiteral("menusettings"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuXddd->menuAction());
        menuBar->addAction(menucomponents->menuAction());
        menuBar->addAction(menuconsole->menuAction());
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menurun->menuAction());
        menuBar->addAction(menupause->menuAction());
        menuBar->addAction(menureset->menuAction());
        menuBar->addAction(menutime->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menuemulators->menuAction());
        menuBar->addAction(menuminitors->menuAction());
        menuBar->addAction(menusettings->menuAction());
        menuXddd->addAction(actionnew);
        menuXddd->addAction(actionopen);
        menuXddd->addAction(actionsave);
        menucomponents->addAction(actionmanage);
        menucomponents->addAction(actionload);
        menucomponents->addAction(actionunload);
        menuconsole->addAction(actionshow);
        menuconsole->addAction(actionsettings);

        retranslateUi(MainWindow);

        controlTabWidget->setCurrentIndex(0);
        logsTabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionnew->setText(QApplication::translate("MainWindow", "new", Q_NULLPTR));
        actionopen->setText(QApplication::translate("MainWindow", "open", Q_NULLPTR));
        actionsave->setText(QApplication::translate("MainWindow", "save", Q_NULLPTR));
        actionmanage->setText(QApplication::translate("MainWindow", "manage", Q_NULLPTR));
        actionload->setText(QApplication::translate("MainWindow", "load", Q_NULLPTR));
        actionunload->setText(QApplication::translate("MainWindow", "unload", Q_NULLPTR));
        actionshow->setText(QApplication::translate("MainWindow", "show/hide", Q_NULLPTR));
        actionsettings->setText(QApplication::translate("MainWindow", "settings", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "name", Q_NULLPTR));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "type", Q_NULLPTR));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Gadgets", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "Input", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "Sensor", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem3->child(0);
        ___qtreewidgetitem4->setText(0, QApplication::translate("MainWindow", "InfraredSensor", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem5->setText(0, QApplication::translate("MainWindow", "Output", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem5->child(0);
        ___qtreewidgetitem6->setText(0, QApplication::translate("MainWindow", "Motor", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem7->setText(0, QApplication::translate("MainWindow", "IO", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem7->child(0);
        ___qtreewidgetitem8->setText(0, QApplication::translate("MainWindow", "Cable", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem9 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem9->setText(0, QApplication::translate("MainWindow", "Devices", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem9->child(0);
        ___qtreewidgetitem10->setText(0, QApplication::translate("MainWindow", "Robot", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem10->child(0);
        ___qtreewidgetitem11->setText(1, QApplication::translate("MainWindow", "\"goofy\"", Q_NULLPTR));
        ___qtreewidgetitem11->setText(0, QApplication::translate("MainWindow", "Goofy", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem11->child(0);
        ___qtreewidgetitem12->setText(1, QApplication::translate("MainWindow", "\"left motor\"", Q_NULLPTR));
        ___qtreewidgetitem12->setText(0, QApplication::translate("MainWindow", "Motor", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem11->child(1);
        ___qtreewidgetitem13->setText(1, QApplication::translate("MainWindow", "\"right motor\"", Q_NULLPTR));
        ___qtreewidgetitem13->setText(0, QApplication::translate("MainWindow", "Motor", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem14 = ___qtreewidgetitem11->child(2);
        ___qtreewidgetitem14->setText(1, QApplication::translate("MainWindow", "\"ir sensor\"", Q_NULLPTR));
        ___qtreewidgetitem14->setText(0, QApplication::translate("MainWindow", "Sensor", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem15 = ___qtreewidgetitem9->child(1);
        ___qtreewidgetitem15->setText(0, QApplication::translate("MainWindow", "Motherboard", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem16 = treeWidget->topLevelItem(4);
        ___qtreewidgetitem16->setText(0, QApplication::translate("MainWindow", "Objects", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem17 = ___qtreewidgetitem16->child(0);
        ___qtreewidgetitem17->setText(1, QApplication::translate("MainWindow", "static wall", Q_NULLPTR));
        ___qtreewidgetitem17->setText(0, QApplication::translate("MainWindow", "Obstacle", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem18 = ___qtreewidgetitem16->child(1);
        ___qtreewidgetitem18->setText(1, QApplication::translate("MainWindow", "moving wall", Q_NULLPTR));
        ___qtreewidgetitem18->setText(0, QApplication::translate("MainWindow", "Obstacle", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem19 = ___qtreewidgetitem16->child(2);
        ___qtreewidgetitem19->setText(1, QApplication::translate("MainWindow", "goofy", Q_NULLPTR));
        ___qtreewidgetitem19->setText(0, QApplication::translate("MainWindow", "Goofy", Q_NULLPTR));
        treeWidget->setSortingEnabled(__sortingEnabled);

        controlTabWidget->setTabText(controlTabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "settings", Q_NULLPTR));
        controlTabWidget->setTabText(controlTabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "runtime", Q_NULLPTR));
        controlTabWidget->setTabText(controlTabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "map", Q_NULLPTR));
        logsTabWidget->setTabText(logsTabWidget->indexOf(tab), QApplication::translate("MainWindow", "logs", Q_NULLPTR));
        logsTabWidget->setTabText(logsTabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "idk", Q_NULLPTR));
        menuXddd->setTitle(QApplication::translate("MainWindow", "simulation", Q_NULLPTR));
        menucomponents->setTitle(QApplication::translate("MainWindow", "components", Q_NULLPTR));
        menuconsole->setTitle(QApplication::translate("MainWindow", "console", Q_NULLPTR));
        menupause->setTitle(QApplication::translate("MainWindow", "pause", Q_NULLPTR));
        menureset->setTitle(QApplication::translate("MainWindow", "reset", Q_NULLPTR));
        menuemulators->setTitle(QApplication::translate("MainWindow", "emulators", Q_NULLPTR));
        menuminitors->setTitle(QApplication::translate("MainWindow", "monitors", Q_NULLPTR));
        menurun->setTitle(QApplication::translate("MainWindow", "run", Q_NULLPTR));
        menu->setTitle(QString());
        menu_2->setTitle(QString());
        menutime->setTitle(QApplication::translate("MainWindow", "frames: N", Q_NULLPTR));
        menusettings->setTitle(QApplication::translate("MainWindow", "settings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
