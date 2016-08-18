#include "examplewindow.h"

ExampleWindow::ExampleWindow(QWidget *parent): QMainWindow(parent)
{
    //for Arabic text support
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP1256"));

    FlickableList *fList = new FlickableList(true, this);

    for(int i = 0; i < 100; i++)
    {
        fList->addItem("√Ê»Ê‰ Ê", QPixmap(":/ubuntu.png"));
    }

    fList->setBackgroundColor(QColor(255,255,255));
    fList->setSelectedItemColor(QColor(0,0,0));

    connect(fList, SIGNAL(itemSelected(int)), this, SLOT(dummySlot(int)));
    this->setCentralWidget(fList);
}

//just a dummy slot to prove the concept
void ExampleWindow::dummySlot(int rowNumber)
{
    QMessageBox::information(this, "", "·ﬁœ «Œ —  «·’› —ﬁ„: "+ QString::number(rowNumber));
}
