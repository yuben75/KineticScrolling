#ifndef FLICKABLELIST_H
#define FLICKABLELIST_H

#include <FlickableList/flickable.h>
#include <QList>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QTextCodec>
#include <QWidget>



class FlickableList : public QWidget, public Flickable
{
    Q_OBJECT

public:
    FlickableList(bool withIcons = false, QWidget *parent = 0);

    void addItem(QString itemString);
    void addItem(QString itemString, QPixmap icon);

    void setBackgroundColor(QColor backgroundColor);
    void setSelectedItemColor(QColor selectedItemColor);

protected:
    virtual QPoint scrollOffset() const;
    virtual void setScrollOffset(const QPoint &offset);
    void paintEvent(QPaintEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void checkClickedItem(int row);

private:
    int m_offset;
    int m_height;
    int m_highlight;
    int m_selected; /*number of row of selected item*/
    int lastClickedItem;
    QList<QString> c_itemsList;
    QList<QPixmap> c_iconsList;
    bool c_withIcons;
    QColor c_backgroundColor;
    QColor c_selectedItemColor;

signals:
    void itemDobuleClick(int row);
    void itemSelected(int row);
};

#endif // FLICKABLELIST_H
