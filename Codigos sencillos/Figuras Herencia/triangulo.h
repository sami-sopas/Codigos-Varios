#ifndef TRIANGULO_H_INCLUDED
#define TRIANGULO_H_INCLUDED
#include"figuras.h"
class Triangulo: public Figuras{
    private:
        double area;
    public:
        void CalcularArea();
        double getArea();
};

#endif // TRIANGULO_H_INCLUDED
