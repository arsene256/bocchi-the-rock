#include "userstock.h"

UserStock::UserStock()
{

}

UserStock::UserStock(int rCode,int num,float total,float price)
{
    this->RealCode = rCode;
    this->num = num;
    this->totalPrice = total;
    this->price = price;
}



