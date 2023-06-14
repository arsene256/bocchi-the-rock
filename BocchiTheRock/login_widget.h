#ifndef LOGIN_WIDGET_H
#define LOGIN_WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Login_Widget; }
QT_END_NAMESPACE

class Login_Widget : public QWidget
{
    Q_OBJECT

public:
    Login_Widget(QWidget *parent = nullptr);
    ~Login_Widget();

signals:

private slots:
    void loginBtn_Clicked();
    void RegistBtn_Clicked();

private:
    Ui::Login_Widget *ui;
};
#endif // LOGIN_WIDGET_H
