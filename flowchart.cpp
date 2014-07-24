#include "flowchart.h"
#include <iostream>
#include <symbol.h>
#include <link.h>
#include <mainwindow.h>
#include <QString>
using namespace std;

flowchart::flowchart()
{
    nb_symbol = 0;
    minZ = 0;
    maxZ = 0;
    seqNumber = 0;

    scene = new QGraphicsScene(0, 0, 1000, 1000);
}

flowchart::~flowchart()
{
    for(Symbol * s: symbols){
        delete s;
    }
    delete scene;
}

Symbol * flowchart::addSymbol(my_symbol ms){
    nb_symbol++;

    Symbol * node = new Symbol(ms);
    node->setText(node->getSymbolText());
    symbols.push_back(node);
    setupNode(node, ms);
    symbols.push_back(node);
    return node;
}

void flowchart::setupNode(Symbol *node, my_symbol ms)
{
    Symbol * prev_node = selectedNode();
    if (prev_node != NULL && prev_node != 0){
        if (ms == Else)
            node->setPos(QPoint(prev_node->center.x()+80,prev_node->center.y()-80));
        else if (ms == ForBloc)
            node->setPos(QPoint(prev_node->center.x()+40,prev_node->center.y()+40));
        else
            node->setPos(QPoint(prev_node->center.x(),prev_node->center.y()+80));
    }
    else
    {
        node->setPos(QPoint(80, 80 + 80 * seqNumber));
    }

    //node->setPos(QPoint(80 + (100 * (seqNumber % 5)), 80 + (50 * ((seqNumber / 5) % 7))));
    scene->addItem(node);
    ++seqNumber;

    scene->clearSelection();
    node->setSelected(true);
    bringToFront();
}


void flowchart::bringToFront()
{
    ++maxZ;
    setZValue(maxZ);
}

void flowchart::sendToBack()
{
    --minZ;
    setZValue(minZ);
}

void flowchart::setZValue(int z)
{
    Symbol *node = selectedNode();
    if (node)
        node->setZValue(z);
}

void flowchart::addLink()
{
    NodePair nodes = selectedNodePair();
    if (nodes == NodePair())
        return;

    addLink(nodes.first, nodes.second);
}

void flowchart::addLink(Symbol * first, Symbol * second)
{
    if (first != NULL && second != NULL) {
        Link * link = new Link(first, second);
        scene->addItem(link);
    }
}

void flowchart::addLink(Symbol * first, Symbol * second, my_symbol ms)
{
    if (first != NULL && second != NULL) {
        Link * link = new Link(first, second, ms);
        scene->addItem(link);
    }
}

Symbol *flowchart::selectedNode() const
{
    QList<QGraphicsItem *> items = scene->selectedItems();
    if (items.count() == 1) {
        return dynamic_cast<Symbol *>(items.first());
    } else {
        return 0;
    }
}



flowchart::NodePair flowchart::selectedNodePair() const
{
    QList<QGraphicsItem *> items = scene->selectedItems();
    if (items.count() == 2) {
        Symbol *first = dynamic_cast<Symbol *>(items.first());
        Symbol *second = dynamic_cast<Symbol *>(items.last());
        if (first && second)
            return flowchart::NodePair(first, second);
    }
    return flowchart::NodePair();
}

void flowchart::del()
{
    QList<QGraphicsItem *> items = scene->selectedItems();
    QMutableListIterator<QGraphicsItem *> i(items);
    while (i.hasNext()) {
        Link *link = dynamic_cast<Link *>(i.next());
        if (link) {
            delete link;
            i.remove();
        }
    }

    qDeleteAll(items);
}

QString flowchart::generatecpp(){
    QString res = "";
    Symbol * first = selectedNode();
    if (first){
        return first->getcpp(res);
    }

}
