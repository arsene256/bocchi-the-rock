#include "login_widget.h"
#include "ui_login_widget.h"
#include <QMessageBox>
#include <QPushButton>
#include "mainwindow.h"
#include "user.h"
#include <QFile>
#include <fstream>
#include <string>
#include "file.h"
#include "admin.h"
#include "adminwidget.h"

Login_Widget::Login_Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login_Widget)
{
    ui->setupUi(this);

//    allUser = loadUsersFromFile();
    loadUserDataFromFile();
    loadStockDataFromFile();

    connect(ui->btnLogin,&QPushButton::clicked,this,&Login_Widget::loginBtn_Clicked);
    connect(ui->btnQuit,&QPushButton::clicked,this,&Login_Widget::close);
    connect(ui->btnRegist,&QPushButton::clicked,this,&Login_Widget::RegistBtn_Clicked);
}

Login_Widget::~Login_Widget()
{
    delete ui;
}

void Login_Widget::loginBtn_Clicked()
{
    if((ui->lineName->text() == "")||(ui->linePass->text() == ""))
    {
        QMessageBox::warning(this,"警告","用户名和密码不能为空");
    }
    else if(User::userFind(ui->lineName->text()) == allUser.end() && ui->lineName->text() != admin.userName)
    {
        QMessageBox::warning(this,"警告","用户名错误");
    }
    else if(User::userFind(ui->lineName->text())->getPassWord() != ui->linePass->text() && ui->linePass->text() != admin.passWord)
    {
        QMessageBox::warning(this,"警告","密码错误");
    }
    else
    {
        if(ui->lineName->text() != admin.userName)
        {
            User* theUser =&(*User::userFind(ui->lineName->text()));
            MainWindow *mainWindow = new MainWindow(theUser);
            this->hide();
            mainWindow->show();
        }
        else
        {
            AdminWidget * adminWidget = new AdminWidget;
            this->hide();
            adminWidget->show();
        }
    }
}

float opendata[30] = {14.1,15.9,14.0,15.2,17.8,17.3,13.5,16.1,15.6,17.1,17.1,15.0,14.3,17.3,15.3,16.0,14.8,13.9,15.0,17.6,15.6,15.7,16.6,17.6,17.6,17.7,17.8,13.4,16.8,16.7};
float closedata[30] = {13.1,15.9,17.6,15.7,14.0,17.5,13.3,14.3,15.0,17.8,13.9,15.6,16.3,14.6,17.0,13.8,17.7,15.8,16.9,13.3,13.8,14.3,13.5,16.9,16.3,17.8,14.3,15.2,15.7,16.0};
float maxdata[30] = {18.5,18.6,18.5,18.6,18.5,18.7,18.9,19.0,18.7,18.9,18.4,18.4,18.1,18.3,18.4,18.5,18.3,18.5,18.3,18.1,18.1,18.4,18.9,18.3,18.8,18.1,19.0,18.8,18.7,19.0};
float mindata[30] = {12.9,12.1,12.2,12.9,13.0,12.2,12.4,12.8,12.5,12.4,12.3,12.7,12.4,12.3,12.3,12.4,12.6,12.7,12.3,12.1,12.1,12.5,12.1,12.4,12.1,12.3,12.8,12.3,12.5,12.1};

void Login_Widget::RegistBtn_Clicked()
{
    if((ui->lineName->text() == "")||(ui->linePass->text() == ""))
        QMessageBox::warning(this,"警告","用户名和密码不能为空","确定");
    else if(User::userFind(ui->lineName->text()) != allUser.end())
    {
        QMessageBox::warning(this,"警告","已存在此账户","确定");
    }
    else
    {
        allUser.push_back(User(ui->lineName->text(),ui->linePass->text(),100000));
        QMessageBox::information(this,"","注册成功");
        Stock a("超电磁炮","91094",opendata,closedata,maxdata,mindata,20);
        allStocks.push_back(a);
        saveStockDataToFile();
        saveUserDataToFile();
    }
}


