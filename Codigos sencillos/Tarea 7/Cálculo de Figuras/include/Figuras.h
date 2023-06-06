#ifndef FIGURAS_H
#define FIGURAS_H

#include <iostream>

class Figuras{
    private:
        double base;
        double altura;
    public:
        void setBase(const double&);
        void setAltura(const double&);

        double getBase() const;
        double getAltura() const;
};

#endif // FIGURAS_H
