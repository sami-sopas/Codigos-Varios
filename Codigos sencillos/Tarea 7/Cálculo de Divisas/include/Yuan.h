#ifndef YUAN_H
#define YUAN_H

#include <iostream>
#include "Moneda.h"

class Yuan : public Moneda{
    public:
        double getYuanAPeso() const;
};

#endif // YUAN_H
