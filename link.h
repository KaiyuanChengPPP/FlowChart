#ifndef LINK_H
#define LINK_H
#include <QGraphicsLineItem>
#include <QColor>
#include <symbol.h>

//class Symbol;

class Link : public QGraphicsLineItem
{
public:
    Link(Symbol *, Symbol *);
    Link(Symbol *, Symbol *, my_symbol);
    ~Link();

    Symbol *fromNode();
    Symbol *toNode();

    void setColor(const QColor &color);
    QColor color() const;

    void trackNodes();

private:
    Symbol *myFromNode;
    Symbol *myToNode;
};


#endif // LINK_H
