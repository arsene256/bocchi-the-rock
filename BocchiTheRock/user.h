#ifndef USER_H
#define USER_H

#include <QString>
#include <vector>
#include "userstock.h"

using namespace std;

class User
{
public:
    User();
    User(QString name,QString pw,float money);
    User(QString name,QString pw,vector<UserStock> Stocks,float money);
    static vector<User>::iterator userFind(QString name);
    void userAdd();
    bool userDelete();
    QString & getUserName();
    QString & getPassWord();
    float & getMoney();
    vector<UserStock> & getUserStocks();
//    bool stockBuy(QString name,int num);
//    bool stockSell(QString name,int num);
    bool stockBuy(int rCode,int num);
    bool stockSell(int rCode,int num);

private:
    QString userName;
    QString passWord;
    float money;
    vector<UserStock> userStocks;


};

extern vector<User> allUser;

#endif // USER_H
