#include "graphicspinin.h"

GraphicsPinIn::GraphicsPinIn(qreal x, qreal y, qreal width, qreal height, PinIn *pin, QGraphicsItem *parent):
    GraphicsPinBase{x, y, width, height, parent},
    pin_{pin}
{
    qDebug() << "Another inpin" << pin;
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
}

GraphicsPinIn::~GraphicsPinIn() {
    pin_ = nullptr; // The expectation is that the backend component will delete the backend pin
}

PinIn *GraphicsPinIn::pin() const {
    return pin_;
}

bool GraphicsPinIn::state() const {
    return pin()->state();
}

QVariant GraphicsPinIn::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) {
    if (change == QGraphicsItem::ItemScenePositionHasChanged) {
        QList<GraphicsWire*>::iterator i{};
        for (i = wireList_.begin(); i != wireList_.end(); ++i) {
            (*i)->setPinInPosition(sceneBoundingRect().center());
        }
    }

    return QGraphicsItem::itemChange(change, value);
}
