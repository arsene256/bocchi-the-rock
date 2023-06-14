#include "adminwidget.h"
#include "ui_adminwidget.h"
#include <QStringList>
#include "user.h"
#include "stock.h"
#include "userstock.h"
#include <QTreeWidgetItem>
#include <QString>

AdminWidget::AdminWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminWidget)
{
    ui->setupUi(this);

    this->setWindowTitle("管理员界面");
    this->setWindowIcon(QIcon(":/image/loginTitle.png"));

    ui->treeWidget->setColumnCount(8);
    ui->treeWidget->setHeaderLabels(QStringList() << "用户名" << "密码" << "资金" << "股票名称" << "股票代码" << "持有量" << "价格" << "总价");

    for(vector<User>::iterator user = allUser.begin();user!=allUser.end();user++)
    {
        //QString obj = QString("%1").arg(user->getUserStocks()[i].totalPrice, 0, 'f', 2);
        QTreeWidgetItem * userItem = new QTreeWidgetItem(QStringList() << user->getUserName() << user->getPassWord() << QString::number(user->getMoney()));
        ui->treeWidget->addTopLevelItem(userItem);
        for(int i = 0;i<user->getUserStocks().size();i++)
        {
            Stock stock = *Stock::findStock(user->getUserStocks()[i].RealCode);
            QStringList list;
            QString obj = QString("%1").arg(user->getUserStocks()[i].totalPrice, 0, 'f', 2);
            list << "" << "" << "" << stock.getStockName() << stock.getStockCode() << QString::number(user->getUserStocks()[i].num) << QString::number(stock.getPrice()) << obj;
            QTreeWidgetItem * childItem = new QTreeWidgetItem(list);
            userItem->addChild(childItem);
        }
    }
}

AdminWidget::~AdminWidget()
{
    delete ui;
}
