#ifndef USERSTOCK_H
#define USERSTOCK_H

#include <stock.h>

class UserStock
{
public:
    explicit UserStock();
    UserStock(int rCode,int num,float total,float price);


    int RealCode;
    int num;
    float price;
    float totalPrice;
};

#endif // USERSTOCK_H
