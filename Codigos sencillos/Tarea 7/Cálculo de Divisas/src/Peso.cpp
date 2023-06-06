#include "Peso.h"

using namespace std;

double Peso::getPesoADolar() const{
    return getValor() * 0.05;
}

double Peso::getPesoAEuro() const{
    return getValor() * 0.042;
}

double Peso::getPesoAYen() const{
    return getValor() * 5.44;
}

double Peso::getPesoAYuan() const{
    return getValor() * 0.33;
}
