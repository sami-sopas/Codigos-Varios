#ifndef MONEDA_H
#define MONEDA_H

#include <iostream>

class Moneda{
    private:
        double valor;
    public:
        void setValor(const double&);
        double getValor() const;
};

#endif // MONEDA_H
