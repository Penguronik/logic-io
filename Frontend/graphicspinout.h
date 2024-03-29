#ifndef GRAPHICSPINOUT_H
#define GRAPHICSPINOUT_H

#include "Backend/pinout.h"
#include "graphicspinbase.h"

class GraphicsPinOut : public GraphicsPinBase
{
public:

    // Qt Type
    enum{Type = 0b10000000000000010};
    int type() const override { return Type; }

    GraphicsPinOut(qreal x, qreal y, qreal width, qreal height, PinOut *pin, QGraphicsItem *parent = nullptr);

    ~GraphicsPinOut();

    virtual QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) override;

    PinOut *pin() const;

    virtual bool state() const override;

private:
    PinOut *pin_;
};

#endif // GRAPHICSPINOUT_H
