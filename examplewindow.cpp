#include "examplewindow.h"
#include <QLabel>
#include <QDebug>
ExampleWindow::ExampleWindow(QWidget *parent): QExampleParent(parent)
{
    resize(200, 600);
    //for Arabic text support
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP1256"));

    FlickableList *fList = new FlickableList(true, this);
    //FlickableList *fList = new FlickableList(false, this);
    QString numStr;
    for(int i = 0; i < 100; i++)
    {
        numStr.sprintf("%04i", i);
        fList->addItem(numStr + ":", QPixmap(":/ubuntu.png"));
        //fList->addItem(numStr + ":");
    }

    fList->setBackgroundColor(QColor(0,128,0));
    fList->setSelectedItemColor(QColor(255,0,0));

    connect(fList, SIGNAL(itemSelected(int)), this, SLOT(dummySlot(int)));
    this->setCentralWidget(fList);
}

//just a dummy slot to prove the concept
void ExampleWindow::dummySlot(int rowNumber)
{
    qDebug() << __func__ << ":" << QString::number(rowNumber);
    //QMessageBox::information(this, "", "XX123: "+ QString::number(rowNumber));
}
