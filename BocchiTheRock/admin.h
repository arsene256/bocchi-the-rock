#ifndef ADMIN_H
#define ADMIN_H

#include <QString>

class Admin
{
public:
    Admin(QString name,QString pw);

    bool userDelete(QString name);

    QString userName;
    QString passWord;
};

extern Admin admin;

#endif // ADMIN_H
