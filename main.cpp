#include <QApplication>
#include "examplewindow.h"
#include <QPushButton>
#include <QLineEdit>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#if 0
    QWidget *mw = new QWidget;
    ExampleWindow *w = new ExampleWindow(mw);

    w->show();
    mw->show();
#else
    ExampleWindow *w = new ExampleWindow;
    w->show();
#endif




    return a.exec();
}
