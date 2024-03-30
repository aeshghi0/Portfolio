#include "shapeparser.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    shapeParser w;
    w.show();
    return a.exec();
}
