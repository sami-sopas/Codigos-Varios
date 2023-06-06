#ifndef TRIANGULO_H
#define TRIANGULO_H

#include <iostream>
#include "Figuras.h"

class Triangulo : public Figuras{
    public:
        double getArea() const;
};

#endif // TRIANGULO_H
