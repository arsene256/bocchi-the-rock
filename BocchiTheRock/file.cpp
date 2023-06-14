#include "stock.h"
#include "user.h"
#include "userstock.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <QDebug>

using namespace std;

void saveStockDataToFile()
{
    ofstream file("stock.txt");
    if (!file.is_open())
    {
        qDebug() << "Failed to open file for writing.";
        return;
    }

    for (Stock& stock : allStocks)
    {
        file << stock.getStockName().toStdString() << ","
             << stock.getStockCode().toStdString() << ","
             << stock.getRealCode() << ","
             << stock.predictPrice << ",";

        for (int i = 0; i < 30; ++i)
        {
            file << stock.getOpen()[i] << ",";
        }

        for (int i = 0; i < 30; ++i)
        {
            file << stock.getClose()[i] << ",";
        }

        for (int i = 0; i < 30; ++i)
        {
            file << stock.getMax()[i] << ",";
        }

        for (int i = 0; i < 30; ++i)
        {
            file << stock.getMin()[i] << ",";
        }

        for (int i = 0; i < 10; ++i)
        {
            file << stock.modelParam[i] << ",";
        }

        file << endl;
    }

    file.close();
//    cout << "Stock data saved to file." << endl;
}

void loadStockDataFromFile()
{
    ifstream file("stock.txt");
    if (!file.is_open())
    {
//        cout << "Failed to open file for reading." << endl;
        return;
    }

    allStocks.clear();

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

//        if (tokens.size() != 134) // 4 + 30*4 + 10 = 134
//        {
//           cout << "Invalid data format: " << line << endl;
//            continue;
//        }

        QString name = QString::fromStdString(tokens[0]);
        QString code = QString::fromStdString(tokens[1]);
        int realCode = stoi(tokens[2]);
        float predict = stof(tokens[3]);

        float open[30];
        float close[30];
        float max[30];
        float min[30];
        float modelParam[10];

        for (int i = 0; i < 30; ++i)
        {
            open[i] = stof(tokens[4 + i]);
        }

        for (int i = 0; i < 30; ++i)
        {
            close[i] = stof(tokens[34 + i]);
        }

        for (int i = 0; i < 30; ++i)
        {
            max[i] = stof(tokens[64 + i]);
        }

        for (int i = 0; i < 30; ++i)
        {
            min[i] = stof(tokens[94 + i]);
        }

        for (int i = 0; i < 10; ++i)
        {
            modelParam[i] = stof(tokens[124 + i]);
        }

        Stock stock(name, code, open, close, max, min, realCode);
        stock.predictPrice = predict;
        for (int i = 0; i < 10; ++i)
        {
            stock.modelParam[i] = modelParam[i];
        }
        allStocks.push_back(stock);
    }

    file.close();
//    cout << "Stock data loaded from file." << endl;
}

//void saveUserToFile(vector<User>& users) {
//    ofstream outFile("user.txt");
//    if (!outFile) {
//        qDebug() << "Failed to open file for writing: " << QString::fromStdString("user.txt");
//        return;
//    }

//    for (User& user : users) {
//        outFile << user.getUserName().toStdString() << ","
//                << user.getPassWord().toStdString() << ","
//                << user.getMoney() << ",";

//        const vector<UserStock>& userStocks = user.getUserStocks();
//        for (const UserStock& stock : userStocks) {
//            outFile << stock.RealCode << ":"
//                    << stock.num << ":"
//                    << stock.totalPrice << ":"
//                    << stock.price << ";";
//        }

//        outFile << "\n";
//    }

//    outFile.close();
//}

//vector<User> loadUsersFromFile() {
//    vector<User> users;
//    ifstream inFile("user.txt");
//    if (!inFile) {
//        qDebug() << "Failed to open file for reading: " << QString::fromStdString("user.txt");
//        return users;
//    }
//
//    string line;
//    while (getline(inFile, line)) {
//        stringstream ss(line);
//        string username, password;
//        float money;
//        getline(ss, username, ',');
//        getline(ss, password, ',');
//        ss >> money;

//        if (!username.empty() && !password.empty()) {
//            QString qUsername = QString::fromStdString(username);
//            QString qPassword = QString::fromStdString(password);

//            vector<UserStock> userStocks;
//            string stockData;
//            getline(ss, stockData);
//            stringstream stockStream(stockData);
//            string stockItem;

//            while (getline(stockStream, stockItem, ';')) {
//                stringstream itemStream(stockItem);
//                string stockFields[4];
//                int fieldCount = 0;

//                while (getline(itemStream, stockFields[fieldCount], ':')) {
//                    fieldCount++;
//                }

//                if (fieldCount == 4) {
//                    int rCode = stoi(stockFields[0]);
//                    int num = stoi(stockFields[1]);
//                    float totalPrice = stof(stockFields[2]);
//                    float price = stof(stockFields[3]);

//                    UserStock stock(rCode, num, totalPrice, price);
//                    userStocks.push_back(stock);
//                }
//            }

//            //users.emplace_back(qUsername, qPassword, userStocks, money);
//            User user(qUsername,qPassword,userStocks,money);
//            allUser.push_back(user);
//        }
//    }

//    inFile.close();
//    return users;
//}

void saveUserDataToFile()
{
    ofstream file("user.txt");
    if (file.is_open())
    {
        for (auto& user : allUser)
        {
            file << user.getUserName().toStdString() << ","
                 << user.getPassWord().toStdString() << ","
                 << user.getMoney() << "\n";

            for (const auto& stock : user.getUserStocks())
            {
                file << stock.RealCode << ","
                     << stock.num << ","
                     << stock.totalPrice << ","
                     << stock.price << "\n";
            }

            file << "\n";
        }

        file.close();
    }
}

void loadUserDataFromFile()
{
    ifstream file("user.txt");
    if (file.is_open())
    {
        allUser.clear();

        string line;
        while (getline(file, line))
        {
            if (line.empty())
                continue;

            stringstream ss(line);
            string token;

            // Read user information
            getline(ss, token, ',');
            QString userName = QString::fromStdString(token);

            getline(ss, token, ',');
            QString passWord = QString::fromStdString(token);

            getline(ss, token, ',');
            float money = stof(token);

            User user(userName, passWord, money);

            // Read user stocks
            while (getline(file, line) && !line.empty())
            {
                stringstream ss2(line);

                getline(ss2, token, ',');
                int rCode = stoi(token);

                getline(ss2, token, ',');
                int num = stoi(token);

                getline(ss2, token, ',');
                float totalPrice = stof(token);

                getline(ss2, token, ',');
                float price = stof(token);

                UserStock stock(rCode, num, totalPrice, price);
                user.getUserStocks().push_back(stock);
            }

            allUser.push_back(user);
        }

        file.close();
    }
}

