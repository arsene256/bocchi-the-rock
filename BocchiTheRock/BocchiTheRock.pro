QT       += core gui
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    adminwidget.cpp \
    file.cpp \
    main.cpp \
    login_widget.cpp \
    mainwindow.cpp \
    stock.cpp \
    user.cpp \
    userstock.cpp

HEADERS += \
    admin.h \
    adminwidget.h \
    file.h \
    login_widget.h \
    mainwindow.h \
    stock.h \
    user.h \
    userstock.h

FORMS += \
    adminwidget.ui \
    login_widget.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
