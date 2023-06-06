#ifndef RECTANGULO_H_INCLUDED
#define RECTANGULO_H_INCLUDED
#include"figuras.h"

class Rectangulo : public Figuras{
    private:
        double area;
    public:
        void CalcularArea();
        double getArea();
};


#endif // RECTANGULO_H_INCLUDED
