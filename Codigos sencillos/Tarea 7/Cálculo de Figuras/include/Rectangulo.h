#ifndef RECTANGULO_H
#define RECTANGULO_H

#include <iostream>
#include "Figuras.h"

class Rectangulo : public Figuras{
    public:
        double getArea() const;
};

#endif // RECTANGULO_H
