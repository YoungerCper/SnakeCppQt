#include "window.h"

#include <QApplication>

int GameStat::difficult = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    w.show();
    return a.exec();
}
