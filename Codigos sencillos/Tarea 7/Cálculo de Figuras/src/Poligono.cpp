#include "Poligono.h"

using namespace std;

void Poligono::setNumLados(const double& n){
    numLados = n;
}

void Poligono::setApotema(const double& a){
    apotema = a;
}

double Poligono::getNumLados() const{
    return numLados;
}

double Poligono::getApotema() const{
    return apotema;
}

double Poligono::getArea() const{
    return ((getBase() * numLados) * apotema) / 2;
}
