#include "examplewindow.h"
#include <QDebug>
#include <QPushButton>
#include <QLabel>
ExampleWindow::ExampleWindow(QWidget *parent): QExampleParent(parent)
{
#define POINT_Y 25

    resize(300, 500);
    //setGeometry(100, 20, this->width(), this->height());

    fList = new FlickableList(true, this);
    //FlickableList *fList = new FlickableList(false, this);
    QString numStr;
    for(int i = 0; i < 50; i++)
    {
        numStr.sprintf("%04i", i);
        fList->addItem(numStr + ":   ------------", QPixmap(":/ubuntu.png"));
        //fList->addItem(numStr + ":");
    }

    fList->setBackgroundColor(QColor(0,64,255));
    fList->setSelectedItemColor(QColor(0,0,0));

    connect(fList, SIGNAL(itemSelected(int)), this, SLOT(dummySlot(int)));
    connect(fList, SIGNAL(itemDobuleClick(int)), this, SLOT(dobuleClickSlot(int)));
    //this->setCentralWidget(fList);

#if 0

    QSize size = this->size();
    fList->move(0, 0);
    fList->resize(size.width(), size.height() + fList->y());
    resize(fList->width(), fList->height() + fList->y());
#else
    //================================================================
    QSize size = this->size();
    fList->move(0, POINT_Y);
    fList->resize(size.width(), size.height() + fList->y());
    resize(fList->width(), fList->height() + fList->y());


    static QLabel head1("No.", this);
    static QLabel head2("Name", this);
    head1.setStyleSheet("background-color:#0080FF;color:#000000");
    head2.setStyleSheet("background-color:#0080FF;color:#000000");
    head1.resize(80, POINT_Y);
    head2.resize(width()-80, POINT_Y);
    head1.move(head1.x(), head1.y());
    head2.move(80, 0);
    head1.setAlignment( Qt::AlignVCenter| Qt::AlignHCenter);
    head2.setAlignment( Qt::AlignVCenter| Qt::AlignHCenter);

    //================================================================
    static QWidget widget(this);
    static QLabel msg(&widget);
    msg.setText("100+");
    msg.setAlignment( Qt::AlignVCenter| Qt::AlignHCenter);
    //msg.setAutoFillBackground(0);
    //msg.setAttribute(Qt::WA_TranslucentBackground, true);
    //QPalette pal = widget.palette();
    //pal.setColor(QPalette::Background, QColor(0x00,0xff,0xff,0xff));
    //msg.setPalette(pal);
    //msg.setGeometry(400, 0, msg.width(), msg.height());

    msg.setStyleSheet("background-color:rgba(255, 255, 255, 30%);color:#FFFFFF");
    msg.resize(fList->width(), POINT_Y);

    widget.move(0, fList->height());
    this->setWindowOpacity(0.8);
#endif
#undef POINT_Y
}
ExampleWindow::~ExampleWindow()
{
    delete fList;
}


//just a dummy slot to prove the concept
void ExampleWindow::dummySlot(int rowNumber)
{
    qDebug() << __func__ << ":" << QString::number(rowNumber);
    //QMessageBox::information(this, "", "XX123: "+ QString::number(rowNumber));
}
void ExampleWindow::dobuleClickSlot(int rowNumber)
{
    qDebug() << __func__ << ":" << QString::number(rowNumber);
    //QMessageBox::information(this, "", "XX123: "+ QString::number(rowNumber));
}
