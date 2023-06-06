#ifndef POLIGONO_H_INCLUDED
#define POLIGONO_H_INCLUDED
#include"figuras.h"

class Poligono : public Figuras{
    private:
        double area;
    public:
        void CalcularArea();
        double getArea();
};


#endif // POLIGONO_H_INCLUDED
