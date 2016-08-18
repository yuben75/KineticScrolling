#include <QtGui/QApplication>
#include "examplewindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExampleWindow *w = new ExampleWindow();
#if defined(Q_WS_S60)
    w->showMaximized();
#else
    w->show();
#endif

    return a.exec();
}
