#include "user.h"
#include "stock.h"

vector<User> allUser;

User::User()
{
}

User::User(QString name,QString pw,float money)
{
    this->userName = name;
    this->passWord = pw;
    this->money = money;
}

User::User(QString name,QString pw,vector<UserStock> Stocks,float money)
{
    this->userName = name;
    this->passWord = pw;
    userStocks.assign(Stocks.begin(),Stocks.end());
    this->money = money;
}

vector<User>::iterator User::userFind(QString name)
{
    vector<User>::iterator i;
    for(i=allUser.begin();i!=allUser.end();i++)
    {
        if(i->userName == name) break;
    }
    return i;
}

void User::userAdd()
{
    allUser.push_back(*this);
}

bool User::userDelete()
{
    vector<User>::iterator tarUser = User::userFind(this->userName);
    if(tarUser == allUser.end()) return false;
    allUser.erase(tarUser);
    return true;
}

QString& User::getUserName()
{
    return this->userName;
}

QString& User::getPassWord()
{
    return this->passWord;
}

float & User::getMoney()
{
    return this->money;
}

vector<UserStock> & User::getUserStocks()
{
    return this->userStocks;
}

bool User::stockBuy(int rCode,int num)
{
    if(num<=0) return false;
    vector<Stock>::iterator tarStock = Stock::findStock(rCode);
    float total = num * tarStock->getPrice();
    money -= total;
    if(money<0)
    {
        money += total;
        return false;
    }
    for(vector<UserStock>::iterator i=this->userStocks.begin();i<this->userStocks.end();i++)
    {
        if(i->RealCode == rCode)
        {
            i->num += num;
            i->totalPrice += num * i->price;
            return true;
        }
    }
    UserStock myStock(rCode,num,total,tarStock->getPrice());
    this->userStocks.push_back(myStock);
    return true;
}

bool User::stockSell(int rCode,int num)
{
    vector<UserStock>::iterator tarStock;
    for(tarStock=userStocks.begin();tarStock!=userStocks.end();tarStock++)
    {
        if(tarStock->RealCode == rCode) break;
    }
    if(tarStock == userStocks.end()) return false;
    if(num>tarStock->num) return false;
    else if(num==tarStock->num)
    {
        money += tarStock->totalPrice;
        userStocks.erase(tarStock);
        return true;
    }
    else if(num<tarStock->num && num >0)
    {
        tarStock->num -= num;
        tarStock->totalPrice -= num * tarStock->price;
        money += num * tarStock->price;
        return true;
    }
    return false;
}


