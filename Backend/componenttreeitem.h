#ifndef COMPONENTTREEITEM_H
#define COMPONENTTREEITEM_H

#include <QString>
#include <QVariant>
#include <QJsonObject>
#include <QJsonArray>

// Adapted from https://github.com/dridk/QJsonModel

class ComponentTreeItem
{
public:
    explicit ComponentTreeItem(ComponentTreeItem *parent = nullptr);
    ~ComponentTreeItem();
    void appendChild(ComponentTreeItem *child);
    ComponentTreeItem *child(int row);
    ComponentTreeItem *parent();
    int childCount() const;
    int row() const;
    void setKey(const QString &key);
    void setValue(const QVariant &value);
    QString key() const;
    QVariant value() const;

    static ComponentTreeItem* load(const QJsonObject &value);

private:
    QString key_;
    QVariant value_;
    QList<ComponentTreeItem *> childsList_;
    ComponentTreeItem *parent_;
};

#endif // COMPONENTTREEITEM_H
