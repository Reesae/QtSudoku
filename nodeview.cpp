#include "nodeview.h"
#include "main.cpp"
#include <QDebug>

extern QtSudoku w;

NodeView::NodeView(SudokuBoardNode *node):node(node),isActive(false)
{
    setRect(0,0,size,size);
    brush = new QBrush();
    brush->setStyle(Qt::SolidPattern);
    brush->setColor(QColor(255,255,255));
    setBrush(*brush);

    text = new QGraphicsTextItem();
    text->setFont(QFont("Calbri", 32, QFont::Bold));
    text->setDefaultTextColor(Qt::black);
    text->setPos(12,0);

    if(node->currentValue)
    {
        text->setPlainText(QString::number(node->currentValue));
        text->show();
    }

}

void NodeView::setPosition(std::string key)
{
    setPos(size * static_cast<int>(key[0] - 'A') ,size * (static_cast<int>(key[1] - '1')));
    text->setPos(12 + size * static_cast<int>(key[0] - 'A') ,size * (static_cast<int>(key[1] - '1')));
}

void NodeView::update()
{

}

void NodeView::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event)
{
    qDebug()<<"mouse click";
    isActive = true;

}



