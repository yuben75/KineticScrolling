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
    ~ExampleWindow();
private:
    FlickableList *fList;


private slots:
    void dummySlot(int rowNumber);
    void dobuleClickSlot(int rowNumber);
};

#endif // EXAMPLEWINDOW_H
