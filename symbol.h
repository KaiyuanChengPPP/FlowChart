#ifndef SYMBOL_H
#define SYMBOL_H

enum my_symbol { If, For, Bloc};

class Symbol
{
    my_symbol ms;
public:
    Symbol();
    Symbol(my_symbol);
    my_symbol getSymbolMeaning();
    void setSymbolMeaning(my_symbol ms);
};

#endif // SYMBOL_H
