#ifndef YEN_H
#define YEN_H

#include <iostream>
#include "Moneda.h"

class Yen : public Moneda{
    public:
        double getYenAPeso() const;
};

#endif // YEN_H
