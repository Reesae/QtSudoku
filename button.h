#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
class Button : public QObject,public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Button(QObject *parent = 0);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    QGraphicsTextItem * text;
signals:
    void clicked();
public slots:
};

#endif // BUTTON_H
