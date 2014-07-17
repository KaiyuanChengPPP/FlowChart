#ifndef FLOWCHART_H
#define FLOWCHART_H
#include <iostream>
#include <symbol.h>
using namespace std;

class flowchart
{
private:
    Symbol * symbol_array;
    int nb_symbol;

public:
    flowchart();
    ~flowchart();
    void addSymbol(my_symbol ms);
};

#endif // FLOWCHART_H
