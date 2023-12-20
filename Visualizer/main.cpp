#include "stdafx.h"
#include "Visualizerr.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Visualizer w;
    w.show();
    return a.exec();
}
