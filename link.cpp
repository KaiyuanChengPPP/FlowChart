#include "link.h"
#include <symbol.h>
#include <QPen>


Link::Link(Symbol *fromNode, Symbol *toNode)
{
    myFromNode = fromNode;
    myToNode = toNode;

    myFromNode->to_link = this;
    myToNode->from_link = this;

    setFlags(QGraphicsItem::ItemIsSelectable);
    setZValue(-1);

    setColor(Qt::black);
    trackNodes();
}

Link::Link(Symbol *fromNode, Symbol *toNode, my_symbol ms)
{
    myFromNode = fromNode;
    myToNode = toNode;

    if (ms == Then){
        myFromNode->then_link = this;
        myToNode->from_link = this;
        setColor(Qt::green);
    }
    else if (ms == Else){
        myFromNode->else_link = this;
        myToNode->from_link = this;
        setColor(Qt::red);
    }
    else if (ms == For){
        if (myFromNode->getSymbolMeaning() == For){
            myFromNode->then_link = this;
            myToNode->from_link = this;
        }
        else {
            myFromNode->to_link = this;
            myToNode->else_link = this;
        }
        setColor(Qt::green);
    }

    //setFlags(QGraphicsItem::ItemIsSelectable);
    setZValue(-1);


    trackNodes();
}

Link::~Link()
{

    myFromNode->to_link = NULL;
    myToNode->from_link = NULL;

    if (myToNode->getSymbolMeaning() == Then || myToNode->getSymbolMeaning() == Else)
        delete myToNode;
    if (myFromNode->getSymbolMeaning() == For)
        delete myToNode;
}

void Link::setColor(const QColor &color)
{
    setPen(QPen(color, 1.0));
}

void Link::trackNodes()
{
    if (myFromNode!= NULL && myToNode != NULL){
        setLine(QLineF(myFromNode->pos(), myToNode->pos()));
    }
}

Symbol * Link::fromNode(){
    return myFromNode;
}
Symbol * Link::toNode(){
    if (myToNode)
        return myToNode;
    else
        return NULL;
}
