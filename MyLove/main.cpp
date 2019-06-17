#include "mainwidget.h"
#include <QApplication>

#include "rose.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainWidget w;
    w.show();

//    Rose rose(1);
//    rose.show();


    return a.exec();
}
