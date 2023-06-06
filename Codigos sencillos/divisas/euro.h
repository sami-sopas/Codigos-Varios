#ifndef EURO_H_INCLUDED
#define EURO_H_INCLUDED
#include"moneda.h"

class Euro : public Moneda{
    private:
        float euro;
    public:
        float CalcularEuroPeso();
};


#endif // EURO_H_INCLUDED
