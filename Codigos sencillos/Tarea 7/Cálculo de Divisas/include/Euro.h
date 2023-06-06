#ifndef EURO_H
#define EURO_H

#include <iostream>
#include "Moneda.h"

class Euro : public Moneda{
    public:
        double getEuroAPeso() const;
};

#endif // EURO_H
