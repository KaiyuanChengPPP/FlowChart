#ifndef FLOWCHART_H
#define FLOWCHART_H
#include <iostream>
#include <symbol.h>
using namespace std;

class flowchart
{
public:
    flowchart();
    ~flowchart();
    void addSymbol(Symbol::my_symbol ms);
    int nb_symbol;
    Symbol * symbol_array;
};

#endif // FLOWCHART_H
