#ifndef SYMBOL_H
#define SYMBOL_H




class Symbol
{
public:
    enum my_symbol { If, For, Bloc};
    Symbol();
    Symbol(my_symbol);
    my_symbol getSymbolMeaning();
    void setSymbolMeaning(my_symbol ms);
    const char* getSymbolText();
private:
    my_symbol ms;

};

#endif // SYMBOL_H
