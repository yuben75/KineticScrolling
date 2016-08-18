#ifndef EXAMPLEWINDOW_H
#define EXAMPLEWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTextCodec>

#include <FlickableList/flickablelist.h>

class ExampleWindow: public QMainWindow
{
    Q_OBJECT

public:
    ExampleWindow(QWidget* parent = 0);

private slots:
    void dummySlot(int rowNumber);
};

#endif // EXAMPLEWINDOW_H
