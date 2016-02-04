#ifndef NODEVIEW_H
#define NODEVIEW_H
#include "sudokuboardnode.h"
#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QBrush>
#include <QFont>
#include <QMouseEvent>
#include <QKeyEvent>

class NodeView:public QObject ,public QGraphicsRectItem
{
    Q_OBJECT
public:
    NodeView(SudokuBoardNode* node);
    SudokuBoardNode* node;
    QGraphicsTextItem* text;
    QBrush *brush;
    void setPosition(std::string key);
    void update();
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);

    static const int size = 72;
    bool isActive;


};

#endif // NODEVIEW_H
