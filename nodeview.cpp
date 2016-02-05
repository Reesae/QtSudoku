#include "nodeview.h"
#include "main.cpp"
#include <QDebug>

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
    setPos(size * (static_cast<int>(key[1] - '1')),size * static_cast<int>(key[0] - 'A'));
    text->setPos(12 + size * (static_cast<int>(key[1] - '1')), size * static_cast<int>(key[0] - 'A'));
}

void NodeView::updateText()
{
    if(node->currentValue != 0)
        text->setPlainText(QString::number(node->currentValue));
}

void NodeView::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event)
{
    isActive = true;
    emit nodeSelect();
}

void NodeView::onValueChanged()
{
    updateText();
}



