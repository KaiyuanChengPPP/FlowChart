#include "symbol.h"

Symbol::Symbol()
{
}

Symbol::Symbol(my_symbol ms)
{
    this->ms = ms;
}


my_symbol Symbol::getSymbolMeaning()
{
    return this->ms;
}

void Symbol::setSymbolMeaning(my_symbol ms)
{
    this->ms = ms;
}
