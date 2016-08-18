#include <QApplication>
#include "examplewindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow *mw = new QMainWindow;
    ExampleWindow *w = new ExampleWindow(mw);
#if defined(Q_WS_S60)
    w->showMaximized();
#else
    w->show();
#endif

    return a.exec();
}
