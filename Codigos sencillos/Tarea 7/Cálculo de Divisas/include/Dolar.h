#ifndef DOLAR_H
#define DOLAR_H

#include <iostream>
#include "Moneda.h"

class Dolar : public Moneda{
    public:
        double getDolarAPeso() const;
};

#endif // DOLAR_H
