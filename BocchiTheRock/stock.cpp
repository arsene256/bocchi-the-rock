#include "stock.h"
#include <vector>
#include <cmath>
std::vector<Stock> allStocks;

Stock::Stock()
{

}

Stock::Stock(QString name,QString code,float open[30],float close[30],float max[30],float min[30])
{
    this->stockName = name;
    this->stockCode = code;
    memcpy(this->openPrice,open,30 * sizeof(float));
    memcpy(this->closePrice,close,30 * sizeof(float));
    memcpy(this->maxPrice,max,30 * sizeof(float));
    memcpy(this->minPrice,min,30 * sizeof(float));
}

Stock::Stock(QString name,QString code,float open[30],float close[30],float max[30],float min[30],int realCode)
{
    this->stockName = name;
    this->stockCode = code;
    memcpy(this->openPrice,open,30 * sizeof(float));
    memcpy(this->closePrice,close,30 * sizeof(float));
    memcpy(this->maxPrice,max,30 * sizeof(float));
    memcpy(this->minPrice,min,30 * sizeof(float));
    this->RealCode = realCode;
}

vector<Stock>::iterator Stock::findStock(int rCode)
{
    vector<Stock>::iterator i;
    for(i = allStocks.begin();i!=allStocks.end();i++)
    {
        if(i->RealCode == rCode) break;
    }
    return i;
}

vector<Stock>::iterator Stock::findStock(QString name)
{
    vector<Stock>::iterator i;
    for(i = allStocks.begin();i!=allStocks.end();i++)
    {
        if(i->stockCode == name) break;
    }
    return i;
}

void Stock::addStock()
{
    allStocks.push_back(*this);
}

bool Stock::deleteStock()
{
    vector<Stock>::iterator i = findStock(this->RealCode);
    if(i==allStocks.end()) return false;
    allStocks.erase(i);
    return true;
}

QString& Stock::getStockName()
{
    return this->stockName;
}

QString& Stock::getStockCode()
{
    return this->stockCode;
}

float* Stock::getOpen()
{
    return this->openPrice;
}

float* Stock::getClose()
{
    return this->closePrice;
}

float* Stock::getMax()
{
    return this->maxPrice;
}

float* Stock::getMin()
{
    return this->minPrice;
}

float Stock::getPrice()
{
    return this->openPrice[29];
}

int Stock::getRealCode()
{
    return this->RealCode;
}

#include <algorithm>
#include <numeric>

float Stock::getPredict()
{
    float* closePrices = getClose();  // 获取收盘价格数组
    int numDays = 30;  // 数据的天数

    float a0, a1;

    // 计算系数 a0 和 a1 使用线性回归

    // 计算收盘价格的和
    float sumX = std::accumulate(closePrices, closePrices + numDays - 1, 0.0);

    // 计算开盘价格的和（从第二天开始）
    float sumY = std::accumulate(openPrice + 1, openPrice + numDays, 0.0);

    float sumXY = 0.0;  // x*y 的和
    float sumXX = 0.0;  // x*x 的和

    for (int i = 0; i < numDays - 1; i++) {
        sumXY += closePrices[i] * openPrice[i + 1];  // 计算 x*y 的和
        sumXX += closePrices[i] * closePrices[i];   // 计算 x*x 的和
    }

    // 计算系数 a0 和 a1
    a1 = (numDays * sumXY - sumX * sumY) / (numDays * sumXX - sumX * sumX);
    a0 = (sumY - a1 * sumX) / numDays;

    // 使用计算出的系数来预测当天的开盘价格

    // 使用预测模型 y = a0 + a1 * x1 来计算预测的股票价格
    predictPrice = a0 + a1 * closePrices[numDays - 1];

    return predictPrice;  // 返回预测的股票价格
}

//float Stock::getPredict()
//{
//        const int n = 10; // 使用前10天的收盘价格进行预测

//        // 构建最小二乘法矩阵
//        std::vector<std::vector<float>> matrix(n, std::vector<float>(n + 1, 0.0f));

//        for (int i = 0; i < n; i++)
//        {
//            // 填充矩阵的第一列（常数项为1）
//            matrix[i][0] = 1.0f;

//            // 填充矩阵的剩余列（收盘价格）
//            for (int j = 1; j <= n; j++)
//            {
//                matrix[i][j] = closePrice[i + n - j];
//            }
//        }

//        // 进行最小二乘法计算，求得参数向量 a = [a0, a1, a2, ..., an]
//        std::vector<float> a(n + 1, 0.0f);

//        for (int i = 0; i <= n; i++)
//        {
//            for (int j = 0; j <= n; j++)
//            {
//                for (int k = 0; k < n; k++)
//                {
//                    a[i] += matrix[k][i] * matrix[k][j];
//                }
//            }
//        }

//        for (int i = 0; i <= n; i++)
//        {
//            for (int j = 0; j < n; j++)
//            {
//                a[i] -= matrix[j][i] * closePrice[j + n];
//            }
//        }

//        // 计算预测值
//        float prediction = a[0];
//        for (int i = 1; i <= n; i++)
//        {
//            prediction += a[i] * closePrice[30 - i];
//        }

//        return prediction;

//}
