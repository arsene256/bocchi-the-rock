#ifndef STOCK_H
#define STOCK_H

#include <QString>

using namespace std;

class Stock
{
public:
    Stock();
    Stock(QString name,QString code,float open[30],float close[30],float max[30],float min[30]);
    Stock(QString name,QString code,float open[30],float close[30],float max[30],float min[30],int realCode);
    static vector<Stock>::iterator findStock(int rCode);
    static vector<Stock>::iterator findStock(QString name);
    void addStock();
    bool deleteStock();
//    static Stock & getStock(int rCode);
//    static Stock & getStock(QString name);
    QString & getStockName();
    QString & getStockCode();
    float* getOpen();
    float* getClose();
    float* getMax();
    float* getMin();
    float getPrice();
    bool modelGenerate();
    float getPredict();
    int getRealCode();

    float predictPrice = 0;
    float modelParam[10] = {0};

private:
    QString stockName;
    QString stockCode;
    float openPrice[30];
    float closePrice[30];
    float maxPrice[30];
    float minPrice[30];
    int RealCode;

};

extern std::vector<Stock> allStocks;

#endif // STOCK_H
