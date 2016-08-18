#ifndef EXAMPLEWINDOW_H
#define EXAMPLEWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QListWidget>
#include <QMessageBox>
#include <QTextCodec>

#include <FlickableList/flickablelist.h>

typedef QWidget QExampleParent;

class ExampleWindow: public QExampleParent
{
    Q_OBJECT

public:
    ExampleWindow(QWidget* parent = 0);

private slots:
    void dummySlot(int rowNumber);
};

#endif // EXAMPLEWINDOW_H
