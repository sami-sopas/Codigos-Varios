#ifndef POLIGONO_H
#define POLIGONO_H

#include <iostream>
#include "Figuras.h"

class Poligono : public Figuras{
    private:
        double numLados;
        double apotema;
    public:
        void setNumLados(const double&);
        void setApotema(const double&);

        double getNumLados() const;
        double getApotema() const;

        double getArea() const;
};

#endif // POLIGONO_H
