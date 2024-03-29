//HEADERS
#include "graphicspinbase.h"
#include "graphicswire.h"

//QT
#include <QtGui/qbrush.h>
#include <QGraphicsSceneMouseEvent>
#include <QRect>
#include <QGraphicsView>

#include <iostream>

GraphicsPinBase::GraphicsPinBase(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent):
    QGraphicsEllipseItem{0, 0, width, height, parent}, // Original rectangle is set to 0, 0 in order to use pos() instead of boundingrect() to follow position
    wireList_{}
{
    setPos(x, y);
    setAcceptHoverEvents(true);
    setBrush(QBrush{Qt::green});
    setTransformOriginPoint(0,0);
    std::cout << "pin scene x: " << scenePos().x() << std::endl << "pin scene y: " << scenePos().y() << std::endl;
    std::cout << "pin local x: " << pos().x() << std::endl << "pin local y: " << pos().y() << std::endl;
    std::cout << "bouunding rect x: " << mapToScene(boundingRect().center()).x() << "bouunding rect y: " << mapToScene(boundingRect().center()).y() << std::endl;
}

GraphicsPinBase::GraphicsPinBase(const QRectF &rect, QGraphicsItem *parent):
    GraphicsPinBase{rect.x(), rect.y(), rect.width(), rect.height(), parent}
{

}

GraphicsPinBase::~GraphicsPinBase() {
    qDebug() << "deleting pin";
    qDeleteAll(wireList_); // you may run into an issue with using this, do some tests to see, you may need to create a copy and delete each that way because iterating through the list may be affected otherwise
    wireList_.clear(); // this clear should be unnecessary realistically because the wire deletes should clear all occurences of every wire from the list anyways
}

//void GraphicsPinBase::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
//    Q_UNUSED (event); // INCLUDE Q_UNUSED WHENEVER NEEDED
//    QBrush tempBrush = brush();
//    tempBrush.setColor(QColor{Qt::green}.lighter(150));
//    setBrush(tempBrush);
//    update();
//}

//void GraphicsPinBase::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
//    QBrush tempBrush = brush();
//    tempBrush.setColor(Qt::green);
//    setBrush(tempBrush);
//    update();
//}

void GraphicsPinBase::addWire(GraphicsWire *wire) {
    wireList_.append(wire);
}

void GraphicsPinBase::removeWire(GraphicsWire *wire) {
    wireList_.removeAll(wire);
}


void GraphicsPinBase::updatePinColor() {
    if (state()) {
        if (brush().color() != Qt::green) {
            QBrush tempBrush = brush();
            tempBrush.setColor(Qt::green);
            setBrush(tempBrush);
            update(); // figure out the exact purpose of update and if it is actually required here
        }
    } else {
        if (brush().color() != Qt::red) {
            QBrush tempBrush = brush();
            tempBrush.setColor(Qt::red);
            setBrush(tempBrush);
            update();
        }
    }
}
