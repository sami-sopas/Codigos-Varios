#ifndef DOLAR_H_INCLUDED
#define DOLAR_H_INCLUDED
#include"moneda.h"

class Dolar : public Moneda{
    private:
        float dolar;
    public:
        float CalcularDolarPeso();
};

#endif // DOLAR_H_INCLUDED
