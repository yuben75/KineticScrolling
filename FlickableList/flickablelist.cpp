#include "flickablelist.h"


FlickableList::FlickableList(bool withIcons, QWidget *parent) : QWidget(parent)
{
    //for Arabic text support
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("CP1256"));
    QSize size = parent->size();
    resize(size.width(), size.height());

    c_withIcons = withIcons;

    //============= Setting Some Variables =================
    m_offset = 0;
    m_height = QFontMetrics(font()).height() + 30; /*the extra number is to increase item height, but not font size*/
    m_highlight = -1;
    m_selected = -1;

    //=================Setting Some Variables======================
    c_backgroundColor = QColor(255, 255, 255);
    c_selectedItemColor = QColor(0, 128, 240);
    setAttribute(Qt::WA_OpaquePaintEvent, true);
    setAttribute(Qt::WA_NoSystemBackground, true);

    setMouseTracking(true);
    Flickable::setAcceptMouseClick(this);
    //=============================================================
}

void FlickableList::addItem(QString itemString)
{
    c_itemsList.append(itemString);
    update();
}

void FlickableList::addItem(QString itemString, QPixmap icon)
{
    c_itemsList.append(itemString);
    c_iconsList.append(icon);
    update();
}

void FlickableList::setBackgroundColor(QColor backgroundColor)
{
    c_backgroundColor = backgroundColor;
}

void FlickableList::setSelectedItemColor(QColor selectedItemColor)
{
    c_selectedItemColor = selectedItemColor;
}

    //======================Reimplement from Flickable===============
    // reimplement from Flickable
QPoint FlickableList::scrollOffset() const {
        return QPoint(0, m_offset);
    }

    // reimplement from Flickable
void FlickableList::setScrollOffset(const QPoint &offset) {
        int yy = offset.y();
        if (yy != m_offset) {
            m_offset = qBound(0, yy, m_height * c_itemsList.count() /*list lenght*/- height());
            update();
        }
    }

    //=================================================================
void FlickableList::paintEvent(QPaintEvent *event) {
        QPainter p(this);
        p.fillRect(event->rect(), c_backgroundColor);//background color
        int start = m_offset / m_height;
        int y = start * m_height - m_offset;
        if (m_offset <= 0) {
            start = 0;
            y = -m_offset;
        }
        int end = start + height() / m_height + 1;
        if (end > c_itemsList.count() /*list*/ - 1)
            end = c_itemsList.count() /*list*/ - 1;
        for (int i = start; i <= end; ++i, y += m_height) {

            p.setBrush(Qt::NoBrush);
            p.setPen(Qt::black);//text color
            if (i == m_highlight) {
                p.fillRect(0, y, width(), m_height, QColor(0, 64, 128));
                p.setPen(Qt::white);
            }
            if (i == m_selected) {
                p.fillRect(0, y, width(), m_height, c_selectedItemColor); //background color of selected item
                p.setPen(Qt::white);
            }

            if(c_withIcons)
            {

                //==============Draw Text==================================
                p.drawText(m_height + 2, y, width() - 2*m_height /*minus 2*m_height to avoid clipping and leave place for icon*/,
                           m_height, Qt::AlignVCenter|Qt::AlignRight , c_itemsList[i]/*list*/);

                //=============Draw Icons===================================
                p.drawPixmap(width()-m_height+2, y, m_height, m_height, c_iconsList[i]);
            }
            else
            {
                //==============Draw Text==================================
                p.drawText(m_height + 2, y, width() - m_height /*minus m_height to avoid clipping*/,
                           m_height, Qt::AlignVCenter|Qt::AlignRight , c_itemsList[i]/*list*/);
            }
        }
        p.end();
    }

void FlickableList::keyReleaseEvent(QKeyEvent *event) {
        if (event->key() == Qt::Key_Down) {
            m_offset += 20;
            event->accept();
            update();
            return;
        }
        if (event->key() == Qt::Key_Up) {
            m_offset -= 20;
            event->accept();
            update();
            return;
        }
    }

void FlickableList::mousePressEvent(QMouseEvent *event) {
        Flickable::handleMousePress(event);
        if (event->isAccepted())
            return;

        if (event->button() == Qt::LeftButton) {
            int y = event->pos().y() + m_offset;
            int i = y / m_height;
            if (i != m_highlight) {
                m_highlight = i;
                m_selected = -1;
                update();
            }
            event->accept();
        }
    }

void FlickableList::mouseMoveEvent(QMouseEvent *event) {
        Flickable::handleMouseMove(event);
    }

void FlickableList::mouseReleaseEvent(QMouseEvent *event) {
        Flickable::handleMouseRelease(event);
        if (event->isAccepted())
            return;

        if (event->button() == Qt::LeftButton) {
            m_selected = m_highlight;
            /*the chosen item is updated*/
            checkClickedItem(m_selected);
            event->accept();
            update();
        }
    }

//if an item is selected twice, a signal is emitted with row number
void FlickableList::checkClickedItem(int row)
{
    if(row == lastClickedItem)
    {
        emit itemSelected(row);
    }
    else
    {
        lastClickedItem = row;
    }
}
