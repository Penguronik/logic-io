#include "graphicscircuitio.h"
#include "Frontend/constants.h"
#include "Frontend/graphicspinin.h"
#include "Frontend/graphicspinout.h"
#include "qgraphicsscene.h"

GraphicsCircuitIO::GraphicsCircuitIO(CircuitIO *circuitIO, QGraphicsItem *parent):
    QGraphicsItem{parent},
    inPinList_{new QList<GraphicsPinBase*>{}},
    outPinList_{new QList<GraphicsPinBase*>{}},
    circuitIO_{circuitIO}
{
// Call generate pins after added to scene
}

void GraphicsCircuitIO::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    //Empty paint, container item
}

QRectF GraphicsCircuitIO::boundingRect() const{
//    return scene()->sceneRect(); // I dunno what to replace this with yet
}

void GraphicsCircuitIO::generateOutPins() {
    qreal interval {scene()->sceneRect().height()/circuitIO_->outSize()};
    QPointF topLeft {scene()->sceneRect().topLeft()};
    topLeft.setY(topLeft.y() + interval/2 - constant::PIN_DIAMETER/2);
    topLeft.setX(topLeft.x() - constant::PIN_DIAMETER/2);
    for (int i {0}; i < circuitIO_->outSize(); i++) {
        outPinList_->append(new GraphicsPinOut{topLeft.x(), topLeft.y() + interval*i, constant::PIN_DIAMETER, constant::PIN_DIAMETER, circuitIO_->pinOutArray() + i, i, this});
    }
}

void GraphicsCircuitIO::generateInPins() {
    qreal interval {scene()->sceneRect().height()/circuitIO_->inSize()};
    QPointF topRight {scene()->sceneRect().topRight()};
    topRight.setY(topRight.y() + interval/2 - constant::PIN_DIAMETER/2);
    topRight.setX(topRight.x() - constant::PIN_DIAMETER/2);
    for (int i {0}; i < circuitIO_->inSize(); i++) {
        inPinList_->append(new GraphicsPinIn{topRight.x(), topRight.y() + interval*i, constant::PIN_DIAMETER, constant::PIN_DIAMETER, circuitIO_->pinInArray() + i, i, this});
    }
}

void GraphicsCircuitIO::generatePins() {
    generateInPins();
    generateOutPins();
}