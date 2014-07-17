#include "symbol.h"

Symbol::Symbol()
{
}

Symbol::Symbol(my_symbol ms)
{
    this->ms = ms;
}


Symbol::my_symbol Symbol::getSymbolMeaning()
{
    return this->ms;
}

void Symbol::setSymbolMeaning(Symbol::my_symbol ms)
{
    this->ms = ms;
}

const char* Symbol::getSymbolText()
{
    switch (this->ms)
        {
            case Symbol::If :
                return "If";
            case Symbol::For :
                return "For";
            case Symbol::Bloc :
                return "Bloc";
            default:
               return "";
          }
}
