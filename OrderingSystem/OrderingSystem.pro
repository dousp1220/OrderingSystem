#-------------------------------------------------
#
# Project created by QtCreator 2017-09-15T14:07:34
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OrderingSystem
TEMPLATE = app


SOURCES += main.cpp\
        MainWidget.cpp \
    OreringWidget.cpp \
    SelectedWidget.cpp \
    GLXSqlUtils.cpp \
    OrderDetailsWidget.cpp \
    CookBookMain.cpp \
    ClassifyBox.cpp \
    CookBookClassilyWidget.cpp \
    CookBookItemInfo.cpp \
    CookBookItemWidget.cpp \
    CookBooikFlipPageBar.cpp \
    SelectedOrderFormModel.cpp \
    CookBookSelectedInfo.cpp \
    Common.cpp \
    SelectedOrderFormDelegate.cpp

HEADERS  += MainWidget.h \
    OreringWidget.h \
    SelectedWidget.h \
    GLXSqlUtils.h \
    OrderDetailsWidget.h \
    CookBookMain.h \
    ClassifyBox.h \
    CookBookClassilyWidget.h \
    CookBookItemInfo.h \
    CookBookItemWidget.h \
    CookBooikFlipPageBar.h \
    SelectedOrderFormModel.h \
    CookBookSelectedInfo.h \
    Common.h \
    SelectedOrderFormDelegate.h

FORMS +=

RESOURCES += \
    icon.qrc
