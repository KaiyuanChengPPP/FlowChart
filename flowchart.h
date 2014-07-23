#ifndef FLOWCHART_H
#define FLOWCHART_H
#include <iostream>
#include <symbol.h>
using namespace std;

class flowchart
{
public:
    typedef QPair<Symbol *, Symbol *> NodePair;
    flowchart();
    ~flowchart();
    Symbol * addSymbol(my_symbol);
    void setupNode(Symbol *, my_symbol);
    void bringToFront();
    void sendToBack();
    void setZValue(int);
    void del();
    void addLink();
    void addLink(Symbol *,Symbol *);
    void addLink(Symbol *,Symbol *, my_symbol);
    Symbol * selectedNode() const;
    NodePair selectedNodePair() const;
    QString generatecpp();


    int nb_symbol;
    vector<Symbol*> symbols;
    QGraphicsScene *scene;


private:
    int seqNumber;
    int maxZ;
    int minZ;

};

#endif // FLOWCHART_H
