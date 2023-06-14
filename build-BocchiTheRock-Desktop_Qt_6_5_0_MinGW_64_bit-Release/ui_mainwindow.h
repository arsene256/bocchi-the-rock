/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionQuit;
    QAction *actionUserInfo;
    QAction *actionStocks;
    QAction *actionLogout;
    QAction *actionMain;
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *mainPage;
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QWidget *stock_page;
    QTableWidget *tableStock;
    QPushButton *btnStockFind;
    QLineEdit *lineStockFind;
    QLabel *label_5;
    QWidget *DetailStock;
    QPushButton *btnBuy;
    QPushButton *btnPredict;
    QSpinBox *spinBuy;
    QSpinBox *spinSell;
    QPushButton *btnSell;
    QListWidget *listWidget;
    QWidget *userInfo;
    QTableWidget *tableUserInfo;
    QLabel *label_6;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_9;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_7;
    QLabel *labelName;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *linePassMod;
    QLabel *label_8;
    QLabel *labelPass;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineNameMod;
    QLabel *labelMoney;
    QSpacerItem *verticalSpacer_4;
    QPushButton *btnModName;
    QPushButton *btnModPass;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1080, 600);
        MainWindow->setMinimumSize(QSize(1080, 600));
        MainWindow->setMaximumSize(QSize(1080, 600));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName("actionQuit");
        actionUserInfo = new QAction(MainWindow);
        actionUserInfo->setObjectName("actionUserInfo");
        actionStocks = new QAction(MainWindow);
        actionStocks->setObjectName("actionStocks");
        actionLogout = new QAction(MainWindow);
        actionLogout->setObjectName("actionLogout");
        actionMain = new QAction(MainWindow);
        actionMain->setObjectName("actionMain");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1081, 541));
        mainPage = new QWidget();
        mainPage->setObjectName("mainPage");
        tableWidget = new QTableWidget(mainPage);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(50, 40, 361, 471));
        label = new QLabel(mainPage);
        label->setObjectName("label");
        label->setGeometry(QRect(480, 20, 261, 261));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/bocchi.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(mainPage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(770, 270, 261, 281));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/image/ryou.png")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(mainPage);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(760, 20, 261, 251));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/image/kita.png")));
        label_3->setScaledContents(true);
        label_4 = new QLabel(mainPage);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(470, 260, 271, 281));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/image/nijika.png")));
        label_4->setScaledContents(true);
        stackedWidget->addWidget(mainPage);
        stock_page = new QWidget();
        stock_page->setObjectName("stock_page");
        tableStock = new QTableWidget(stock_page);
        tableStock->setObjectName("tableStock");
        tableStock->setGeometry(QRect(30, 10, 361, 471));
        btnStockFind = new QPushButton(stock_page);
        btnStockFind->setObjectName("btnStockFind");
        btnStockFind->setGeometry(QRect(760, 170, 75, 23));
        lineStockFind = new QLineEdit(stock_page);
        lineStockFind->setObjectName("lineStockFind");
        lineStockFind->setGeometry(QRect(520, 170, 221, 21));
        label_5 = new QLabel(stock_page);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(520, 144, 141, 21));
        stackedWidget->addWidget(stock_page);
        DetailStock = new QWidget();
        DetailStock->setObjectName("DetailStock");
        btnBuy = new QPushButton(DetailStock);
        btnBuy->setObjectName("btnBuy");
        btnBuy->setGeometry(QRect(320, 470, 75, 23));
        btnPredict = new QPushButton(DetailStock);
        btnPredict->setObjectName("btnPredict");
        btnPredict->setGeometry(QRect(740, 470, 75, 23));
        spinBuy = new QSpinBox(DetailStock);
        spinBuy->setObjectName("spinBuy");
        spinBuy->setGeometry(QRect(240, 470, 81, 22));
        spinBuy->setMaximum(1000);
        spinSell = new QSpinBox(DetailStock);
        spinSell->setObjectName("spinSell");
        spinSell->setGeometry(QRect(490, 470, 71, 22));
        btnSell = new QPushButton(DetailStock);
        btnSell->setObjectName("btnSell");
        btnSell->setGeometry(QRect(560, 470, 75, 23));
        listWidget = new QListWidget(DetailStock);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(300, 50, 451, 361));
        stackedWidget->addWidget(DetailStock);
        userInfo = new QWidget();
        userInfo->setObjectName("userInfo");
        tableUserInfo = new QTableWidget(userInfo);
        tableUserInfo->setObjectName("tableUserInfo");
        tableUserInfo->setGeometry(QRect(430, 110, 551, 401));
        label_6 = new QLabel(userInfo);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(670, 90, 201, 16));
        widget = new QWidget(userInfo);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(80, 180, 241, 271));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        label_9 = new QLabel(widget);
        label_9->setObjectName("label_9");

        gridLayout->addWidget(label_9, 5, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 4, 0, 1, 1);

        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        labelName = new QLabel(widget);
        labelName->setObjectName("labelName");

        gridLayout->addWidget(labelName, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 6, 0, 1, 1);

        linePassMod = new QLineEdit(widget);
        linePassMod->setObjectName("linePassMod");

        gridLayout->addWidget(linePassMod, 10, 0, 1, 1);

        label_8 = new QLabel(widget);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        labelPass = new QLabel(widget);
        labelPass->setObjectName("labelPass");

        gridLayout->addWidget(labelPass, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 8, 0, 1, 1);

        lineNameMod = new QLineEdit(widget);
        lineNameMod->setObjectName("lineNameMod");

        gridLayout->addWidget(lineNameMod, 7, 0, 1, 1);

        labelMoney = new QLabel(widget);
        labelMoney->setObjectName("labelMoney");

        gridLayout->addWidget(labelMoney, 5, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_4, 1, 0, 1, 1);

        btnModName = new QPushButton(widget);
        btnModName->setObjectName("btnModName");

        gridLayout->addWidget(btnModName, 7, 1, 1, 1);

        btnModPass = new QPushButton(widget);
        btnModPass->setObjectName("btnModPass");

        gridLayout->addWidget(btnModPass, 10, 1, 1, 1);

        stackedWidget->addWidget(userInfo);
        MainWindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1080, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName("menu_3");
        MainWindow->setMenuBar(menuBar);

        toolBar->addAction(actionMain);
        toolBar->addSeparator();
        toolBar->addAction(actionSave);
        toolBar->addSeparator();
        toolBar->addAction(actionQuit);
        toolBar->addAction(actionUserInfo);
        toolBar->addAction(actionLogout);
        toolBar->addSeparator();
        toolBar->addAction(actionStocks);
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(actionSave);
        menu_2->addAction(actionQuit);
        menu_2->addAction(actionUserInfo);
        menu_2->addAction(actionLogout);
        menu_3->addAction(actionStocks);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Bocchi", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\207\272", nullptr));
        actionUserInfo->setText(QCoreApplication::translate("MainWindow", "\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        actionStocks->setText(QCoreApplication::translate("MainWindow", "\350\202\241\347\245\250\344\277\241\346\201\257", nullptr));
        actionLogout->setText(QCoreApplication::translate("MainWindow", "\346\263\250\351\224\200", nullptr));
        actionMain->setText(QCoreApplication::translate("MainWindow", "\344\270\273\351\241\265", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        btnStockFind->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\350\276\223\345\205\245\350\246\201\346\237\245\346\211\276\347\232\204\350\202\241\347\245\250\344\273\243\347\240\201", nullptr));
        btnBuy->setText(QCoreApplication::translate("MainWindow", "\344\271\260\345\205\245", nullptr));
        btnPredict->setText(QCoreApplication::translate("MainWindow", "\351\242\204\346\265\213", nullptr));
        btnSell->setText(QCoreApplication::translate("MainWindow", "\345\215\226\345\207\272", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\346\214\201\346\234\211\350\202\241\347\245\250", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\350\264\246\346\210\267\350\265\204\351\207\221\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        labelName->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\257\206\347\240\201\357\274\232", nullptr));
        labelPass->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelMoney->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        btnModName->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\347\224\250\346\210\267\345\220\215", nullptr));
        btnModPass->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\350\202\241\347\245\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
