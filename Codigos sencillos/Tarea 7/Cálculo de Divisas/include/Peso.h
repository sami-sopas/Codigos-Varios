#ifndef PESO_H
#define PESO_H

#include <iostream>
#include "Moneda.h"

class Peso : public Moneda{
    public:
        double getPesoADolar() const;
        double getPesoAEuro() const;
        double getPesoAYen() const;
        double getPesoAYuan() const;
};

#endif // PESO_H
