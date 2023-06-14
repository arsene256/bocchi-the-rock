#include "login_widget.h"
#include <QApplication>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login_Widget loginWidget;
    loginWidget.show();
    return a.exec();
}
