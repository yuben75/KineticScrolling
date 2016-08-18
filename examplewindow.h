#ifndef EXAMPLEWINDOW_H
#define EXAMPLEWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QMessageBox>
#include <QTextCodec>

#include <FlickableList/flickablelist.h>

typedef QMainWindow QExampleWidget;

class ExampleWindow: public QExampleWidget
{
    Q_OBJECT

public:
    ExampleWindow(QWidget* parent = 0);

private slots:
    void dummySlot(int rowNumber);
};

#endif // EXAMPLEWINDOW_H
