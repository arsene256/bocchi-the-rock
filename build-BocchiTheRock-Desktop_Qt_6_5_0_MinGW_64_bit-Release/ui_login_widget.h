/********************************************************************************
** Form generated from reading UI file 'login_widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_WIDGET_H
#define UI_LOGIN_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login_Widget
{
public:
    QLabel *labelTitle;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnLogin;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnRegist;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btnQuit;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineName;
    QLabel *labelName;
    QLabel *labelPass;
    QLineEdit *linePass;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *toolButton;

    void setupUi(QWidget *Login_Widget)
    {
        if (Login_Widget->objectName().isEmpty())
            Login_Widget->setObjectName("Login_Widget");
        Login_Widget->resize(500, 350);
        Login_Widget->setMinimumSize(QSize(500, 350));
        Login_Widget->setMaximumSize(QSize(500, 350));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/loginTitle.png"), QSize(), QIcon::Normal, QIcon::Off);
        Login_Widget->setWindowIcon(icon);
        labelTitle = new QLabel(Login_Widget);
        labelTitle->setObjectName("labelTitle");
        labelTitle->setGeometry(QRect(60, 50, 501, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("\350\220\235\350\216\211\344\275\223")});
        font.setPointSize(15);
        font.setBold(false);
        labelTitle->setFont(font);
        labelTitle->setAlignment(Qt::AlignCenter);
        widget = new QWidget(Login_Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 230, 501, 41));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnLogin = new QPushButton(widget);
        btnLogin->setObjectName("btnLogin");

        horizontalLayout->addWidget(btnLogin);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        btnRegist = new QPushButton(widget);
        btnRegist->setObjectName("btnRegist");

        horizontalLayout->addWidget(btnRegist);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        btnQuit = new QPushButton(widget);
        btnQuit->setObjectName("btnQuit");

        horizontalLayout->addWidget(btnQuit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        widget_2 = new QWidget(Login_Widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 120, 501, 87));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        lineName = new QLineEdit(widget_2);
        lineName->setObjectName("lineName");

        gridLayout->addWidget(lineName, 0, 2, 1, 1);

        labelName = new QLabel(widget_2);
        labelName->setObjectName("labelName");

        gridLayout->addWidget(labelName, 0, 1, 1, 1);

        labelPass = new QLabel(widget_2);
        labelPass->setObjectName("labelPass");

        gridLayout->addWidget(labelPass, 1, 1, 1, 1);

        linePass = new QLineEdit(widget_2);
        linePass->setObjectName("linePass");
        linePass->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        gridLayout->addWidget(linePass, 1, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        toolButton = new QToolButton(Login_Widget);
        toolButton->setObjectName("toolButton");
        toolButton->setGeometry(QRect(70, 0, 121, 121));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/loginBack.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon1);
        toolButton->setIconSize(QSize(160, 160));
        toolButton->setAutoRaise(true);

        retranslateUi(Login_Widget);

        QMetaObject::connectSlotsByName(Login_Widget);
    } // setupUi

    void retranslateUi(QWidget *Login_Widget)
    {
        Login_Widget->setWindowTitle(QCoreApplication::translate("Login_Widget", "\350\202\241\347\245\250\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        labelTitle->setText(QCoreApplication::translate("Login_Widget", "BOCCHI\350\202\241\347\245\250\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        btnLogin->setText(QCoreApplication::translate("Login_Widget", "\347\231\273\345\275\225", nullptr));
        btnRegist->setText(QCoreApplication::translate("Login_Widget", "\346\263\250\345\206\214", nullptr));
        btnQuit->setText(QCoreApplication::translate("Login_Widget", "\351\200\200\345\207\272", nullptr));
        labelName->setText(QCoreApplication::translate("Login_Widget", "\347\224\250\346\210\267\345\220\215", nullptr));
        labelPass->setText(QCoreApplication::translate("Login_Widget", "\345\257\206\347\240\201", nullptr));
        toolButton->setText(QCoreApplication::translate("Login_Widget", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login_Widget: public Ui_Login_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_WIDGET_H
