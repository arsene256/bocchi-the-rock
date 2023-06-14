#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QIcon"
#include "user.h"
#include "stock.h"
#include "userstock.h"
#include <QStringList>
#include <QAction>
#include "file.h"
#include <QMessageBox>
#include <QPushButton>
#include <QLineSeries>
#include <QChartView>
#include <QListWidgetItem>

MainWindow::MainWindow(User * theUser,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    //连接信号与槽
    connect(ui->actionSave,&QAction::triggered,this,&MainWindow::onSaveConfirmed);
    connect(ui->actionStocks,&QAction::triggered,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->actionMain,&QAction::triggered,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->btnStockFind,&QPushButton::clicked,this,&MainWindow::stockFind);
    connect(ui->btnBuy,&QPushButton::clicked,[=](){
        vector<Stock>::iterator stock = Stock::findStock(ui->lineStockFind->text());
        if(theUser->stockBuy(stock->getRealCode(),ui->spinBuy->value()))
        {
            QMessageBox::information(this,"提示","购买成功");
        }
        else
        {
            QMessageBox::warning(this,"警告","购买失败");
        }
    });
    connect(ui->btnSell,&QPushButton::clicked,[=](){
        vector<Stock>::iterator stock = Stock::findStock(ui->lineStockFind->text());
        if(theUser->stockSell(stock->getRealCode(),ui->spinSell->value()))
        {
            QMessageBox::information(this,"提示","卖出成功");
        }
        else
        {
            QMessageBox::warning(this,"警告","卖出失败");
        }
    });
    connect(ui->actionUserInfo,&QAction::triggered,[=](){
        ui->stackedWidget->setCurrentIndex(3);
        ui->labelName->setText(theUser->getUserName());
        ui->labelPass->setText(theUser->getPassWord());
        ui->labelMoney->setText(QString::number(theUser->getMoney()));

        ui->tableUserInfo->setColumnCount(5);
        ui->tableUserInfo->setRowCount(theUser->getUserStocks().size());
        ui->tableUserInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableUserInfo->setHorizontalHeaderLabels(QStringList() << "股票名称" << "股票代码" << "今日价格"<<"持有量"<<"总价");
        ui->tableUserInfo->horizontalHeader()->setStretchLastSection(true);
        ui->tableUserInfo->setAlternatingRowColors(true);
        ui->tableUserInfo->setStyleSheet("QHeaderView::section{background-color:rgb(242, 247, 255);border:1px solid black;}");

        for(int i = 0;i<theUser->getUserStocks().size();i++)
        {
            Stock theStock = *Stock::findStock(theUser->getUserStocks()[i].RealCode);
            ui->tableUserInfo->setItem(i,0,new QTableWidgetItem(theStock.getStockName()));
            ui->tableUserInfo->setItem(i,1,new QTableWidgetItem(theStock.getStockCode()));
            ui->tableUserInfo->setItem(i,2,new QTableWidgetItem(QString::number(theStock.getPrice(),'g',3)));
            ui->tableUserInfo->setItem(i,3,new QTableWidgetItem(QString::number(theUser->getUserStocks()[i].num)));
            QString obj = QString("%1").arg(theUser->getUserStocks()[i].totalPrice, 0, 'f', 2);
            ui->tableUserInfo->setItem(i,4,new QTableWidgetItem(obj));
        }
    });
    connect(ui->actionQuit,&QAction::triggered,[=](){
        if(QMessageBox::question(this,"提示","确定退出?") == QMessageBox::Yes)
        {
            this->close();
        }
    });
    connect(ui->actionLogout,&QAction::triggered,[=](){
        if(QMessageBox::question(this,"提示","确定注销账户?") == QMessageBox::Yes)
            {
                if(theUser->userDelete())
                {
                    saveUserDataToFile();
                    this->close();
                }
            }
    });
    connect(ui->btnModName,&QPushButton::clicked,[=](){
        if(ui->lineNameMod->text() == "")
            QMessageBox::warning(this,"警告","用户名不能为空");
        else
        {
            theUser->getUserName() = ui->lineNameMod->text();
            ui->labelName->setText(theUser->getUserName());
        }
    });
    connect(ui->btnModPass,&QPushButton::clicked,[=](){
        if(ui->linePassMod->text() == "")
            QMessageBox::warning(this,"警告","密码不能为空");
        else
        {
            theUser->getPassWord() = ui->lineNameMod->text();
            ui->labelPass->setText(theUser->getPassWord());
        }
    });
    connect(ui->btnPredict,&QPushButton::clicked,[=](){
        vector<Stock>::iterator stock = Stock::findStock(ui->lineStockFind->text());
        QString str("预测次日开盘价为：");
        QString obj = QString("%1").arg(stock->getPredict(), 0, 'f', 2);
        str += obj;
        QListWidgetItem * listItem = new QListWidgetItem(str);
        ui->listWidget->addItem(listItem);
    });

    //界面处理
    this->setWindowTitle("孤独摇滚");
    this->setWindowIcon(QIcon(":/image/loginTitle.png"));

    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(allStocks.size());
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "股票名称" << "股票代码" << "今日价格");
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setStyleSheet("QHeaderView::section{background-color:rgb(242, 247, 255);border:1px solid black;}");

    for(int i = 0;i<allStocks.size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(allStocks[i].getStockName()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(allStocks[i].getStockCode()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(allStocks[i].getPrice(),'g',6)));
    }

    ui->tableStock->setColumnCount(3);
    ui->tableStock->setRowCount(allStocks.size());
    ui->tableStock->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableStock->setHorizontalHeaderLabels(QStringList() << "股票名称" << "股票代码" << "今日价格");
    ui->tableStock->horizontalHeader()->setStretchLastSection(true);
    ui->tableStock->setAlternatingRowColors(true);
    ui->tableStock->setStyleSheet("QHeaderView::section{background-color:rgb(242, 247, 255);border:1px solid black;}");

    for(int i = 0;i<allStocks.size();i++)
    {
        ui->tableStock->setItem(i,0,new QTableWidgetItem(allStocks[i].getStockName()));
        ui->tableStock->setItem(i,1,new QTableWidgetItem(allStocks[i].getStockCode()));
        ui->tableStock->setItem(i,2,new QTableWidgetItem(QString::number(allStocks[i].getPrice(),'g',3)));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSaveConfirmed()
{
//    saveUserToFile(allUser);
    saveUserDataToFile();
    saveStockDataToFile();
    QMessageBox::information(this,"","保存成功");
}

void MainWindow::stockFind()
{
    vector<Stock>::iterator i=Stock::findStock(ui->lineStockFind->text());
    if(i == allStocks.end())
    {
        QMessageBox::warning(this,"警告","未找到此股票");
    }
    else
    {
        ui->stackedWidget->setCurrentIndex(2);
 //       ui->tableDetailStock->setColumnCount()

            QLineSeries *seriesOpen = new QLineSeries();
            QLineSeries *seriesClose = new QLineSeries();
            QLineSeries *seriesMax = new QLineSeries();
            QLineSeries *seriesMin = new QLineSeries();

            seriesOpen ->setName("开盘价");
            seriesClose ->setName("收盘价");
            seriesMax ->setName("最高价");
            seriesMin ->setName("最低价");

            for(int j = 0;j<30;j++)
            {
                seriesOpen->append(j,i->getOpen()[j]);
            }

            for(int j = 0;j<30;j++)
            {
                seriesClose->append(j,i->getClose()[j]);
            }

            for(int j = 0;j<30;j++)
            {
                seriesMax->append(j,i->getMax()[j]);
            }

            for(int j = 0;j<30;j++)
            {
                seriesMin->append(j,i->getMin()[j]);
            }

            QChart *chart = new QChart();
            chart->addSeries(seriesOpen);
            chart->addSeries(seriesClose);
            chart->addSeries(seriesMax);
            chart->addSeries(seriesMin);

            seriesOpen->setUseOpenGL(true);

            // 创建默认的坐标系（笛卡尔坐标）
           chart->createDefaultAxes();
            // 设置图表标题
            chart->setTitle(QStringLiteral("近30天数据"));

            QChartView *view = new QChartView(chart);
            // 开启抗锯齿
            view->setRenderHint(QPainter::Antialiasing);
            view->resize(1000,300);
            // 显示图表
            view->show();
    }
}

//void MainWindow::stockBuy()
//{
//    vector<Stock>::iterator stock=Stock::findStock(ui->lineStockFind->text());

//}
