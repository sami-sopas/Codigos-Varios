#ifndef PESO_H_INCLUDED
#define PESO_H_INCLUDED
#include"moneda.h"

class Peso : public Moneda{
    private:
        float peso;
    public:
        float CalcularPesoDolar();
        float CalcularPesoEuro();
        float CalcularPesoYen();
        float CalcularPesoYuan();
};


#endif // PESO_H_INCLUDED
