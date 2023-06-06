#include "Figuras.h"

using namespace std;

void Figuras::setBase(const double& b){
    base = b;
}

void Figuras::setAltura(const double& a){
    altura = a;
}

double Figuras::getBase() const{
    return base;
}

double Figuras::getAltura() const{
    return altura;
}
