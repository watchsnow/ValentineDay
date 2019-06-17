#-------------------------------------------------
#
# Project created by QtCreator 2016-07-19T17:26:07
#
#-------------------------------------------------

QT       += core gui \
            multimedia \
            widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET          = MyLove
TEMPLATE        = app
MOC_DIR         = temp/moc
RCC_DIR         = temp/rcc
UI_DIR          = temp/ui
OBJECTS_DIR     = temp/obj
DESTDIR         = $$PWD/bin


SOURCES +=  main.cpp\
            mainwidget.cpp \
            rose.cpp

HEADERS  += mainwidget.h \
            GBK.h \
            rose.h

FORMS    += mainwidget.ui

RESOURCES += \
            resource.qrc
RC_FILE =   MyLove.rc
