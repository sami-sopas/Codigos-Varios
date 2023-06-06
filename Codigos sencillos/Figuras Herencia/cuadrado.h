#ifndef CUADRADO_H_INCLUDED
#define CUADRADO_H_INCLUDED
#include"figuras.h"
class Cuadrado: public Figuras{
    private:
        double area;
    public:
        void CalcularArea();
        double getArea();
};




#endif // CUADRADO_H_INCLUDED
