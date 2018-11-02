#include "pamainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PAMainWidget w;
    w.show();

    return a.exec();
}
