#include "admin.h"

Admin admin("hitori","guitarhero");

Admin::Admin(QString name,QString pw)
{
    this->userName = name;
    this->passWord = pw;
}
